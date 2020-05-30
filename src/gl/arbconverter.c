#include "arbconverter.h"

//#define DEBUG
#ifdef DEBUG
// ARBCONV_DBG - general ArbConverter debug logs
#define ARBCONV_DBG(a) a
// ARBCONV_DBG_LP - code loop ArbConverter debug logs
#define ARBCONV_DBG_LP(a) a
// ARBCONV_DBG_AS - reassembly loop (2nd loop) ArbConverter debug logs
#define ARBCONV_DBG_AS(a) a
// ARBCONV_DBG_RE - resolve* error ArbConverter debug logs
#define ARBCONV_DBG_RE(a) a
// ARBCONV_DBG_HEAVY - heavy ArbConverter debug logs and operations (e.g. check for pointer correctness...)
#define ARBCONV_DBG_HEAVY(a) a
#else
// ARBCONV_DBG - general ArbConverter debug logs
#define ARBCONV_DBG(a) 
// ARBCONV_DBG_LP - code loop ArbConverter debug logs
#define ARBCONV_DBG_LP(a)
// ARBCONV_DBG_AS - reassembly loop (2nd loop) ArbConverter debug logs
#define ARBCONV_DBG_AS(a)
// ARBCONV_DBG_RE - param error ArbConverter debug logs
#define ARBCONV_DBG_RE(a)
// ARBCONV_DBG_HEAVY - heavy ArbConverter debug logs and operations (e.g. check for pointer correctness...)
#define ARBCONV_DBG_HEAVY(a)
#endif

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "khash.h"
#include "state.h"

#define DEFAULT_MALLOC_COUNT 32
#define DEFAULT_STRING_CAP 1024
#define DEFAULT_STRING_MALLOC_SIZE (DEFAULT_STRING_CAP * sizeof(char))

#if MAX_TEX != 16
#error Please update the string
#endif
#define MAX_TEX_STR "16"
#define MAX_TEX_STRLEN 2

void *resize(void** obj, size_t* cap, size_t esize) {
	void *reloc = realloc(*obj, (*cap * 2) * esize);
	if (reloc) {
		*obj = reloc;
		*cap *= 2;
	}
	return reloc;
}

typedef struct _sArray {
	void   **objs; // Array of pointers
	size_t size;
	size_t cap;
} sArray;

void initArray(sArray* arr) {
	arr->objs = calloc(DEFAULT_MALLOC_COUNT, sizeof(void*));
	arr->size = 0;
	arr->cap = DEFAULT_MALLOC_COUNT;
}
int pushArray(sArray* arr, void* obj) {
	if (arr->size >= arr->cap) {
		if (!resize((void**)&arr->objs, &arr->cap, sizeof(void*))) {
			return 0;
		}
	}
	
	arr->objs[arr->size] = obj;
	++arr->size;
	return 1;
}
void* popArray(sArray* arr) {
	if (!arr->size) {
		return NULL;
	}
	
	--arr->size;
	void *ret = arr->objs[arr->size];
	arr->objs[arr->size] = NULL;
	return ret;
}
void* popFIFO(sArray* arr) {
	if (!arr->size) {
		return NULL;
	}
	
	--arr->size;
	void *ret = arr->objs[0];
	memmove(arr->objs, arr->objs + 1, arr->size * sizeof(void*));
	arr->objs[arr->size] = NULL;
	return ret;
}
void freeArray(sArray* arr) {
	while (arr->size) {
		--arr->size;
		free(arr->objs[arr->size]);
	}
	free(arr->objs);
	arr->objs = NULL;
}

typedef enum _eVariableType {
	VARTYPE_ADDRESS = 0,
	VARTYPE_ATTRIB,
	VARTYPE_PARAM,
	VARTYPE_PARAM_MULT,
	VARTYPE_TEMP,
	VARTYPE_ALIAS,
	VARTYPE_OUTPUT,
	
	VARTYPE_CONST, // Used when having an anonymous variable
	VARTYPE_TEXTURE, // Not available in vertex programs, fixed name in fragment programs
	VARTYPE_TEXTARGET, // Not available in vertex programs, fixed name in fragment programs
	VARTYPE_UNK
} eVariableType;
typedef struct _sVariableInit { // sArray manipulable
	char          **strings;
	size_t        strings_count;
	size_t        strings_cap;
	
	size_t        strings_total_len;
} sVariableInit;
typedef struct _sVariable { // sArray manipulable
	char          **names;
	size_t        names_count;
	size_t        names_cap;
	
	eVariableType type;
	
	sVariableInit init;
	int           size; // Optional (VARTYPE_PARAM_MULT)
} sVariable;
typedef struct _sVariables {
	sVariable **vars;
	size_t    size;
	size_t    cap;
} sVariables;

sVariable *createVariable(eVariableType type) {
	sVariable *var = (sVariable*)calloc(1, sizeof(sVariable)); // malloc *should* be fine here
	initArray((sArray*)var);
	initArray((sArray*)&var->init);
	var->type = type;
	var->init.strings_total_len = 0;
	var->size = 0;
	return var;
}
void deleteVariable(sVariable **var) {
	freeArray((sArray*)*var);
	
	char *stringPtr;
	while ((stringPtr = popArray((sArray*)&(*var)->init))) {
		free(stringPtr);
	}
	freeArray((sArray*)&(*var)->init);
	free(*var);
	*var = NULL;
}

KHASH_MAP_INIT_STR(variables, sVariable*)
#define kh_truly_exist(h, i) ((i < kh_end(h)) && kh_exist(h, i))
#define kh_str_exist(h, s) kh_truly_exist(h, kh_get(variables, h, s))

typedef enum _eInstruction {
	INST_ABS = 0, INST_ADD, INST_ARL, INST_CMP, INST_COS, INST_DP3, INST_DP4, INST_DPH,
	INST_DST,     INST_EX2, INST_EXP, INST_FLR, INST_FRC, INST_KIL, INST_LG2, INST_LIT,
	INST_LOG,     INST_LRP, INST_MAD, INST_MAX, INST_MIN, INST_MOV, INST_MUL, INST_POW,
	INST_RCP,     INST_RSQ, INST_SCS, INST_SGE, INST_SIN, INST_SLT, INST_SUB, INST_SWZ,
	INST_TEX,     INST_TXB, INST_TXP, INST_XPD,
	
	INST_UNK
} eInstruction;
#define MAX_OPERANDS 4
typedef struct _sInstruction {
	eInstruction type;
	int saturated;
	
	struct _sInstruction_Vars {
		sVariable *var;
		
		int32_t floatArrAddr;
		int     sign;
		enum {
			SWIZ_NONE = 0, SWIZ_X, SWIZ_Y, SWIZ_Z, SWIZ_W
		} swizzle[4];
	} vars[MAX_OPERANDS];
	
	const char *codeLocation;
} sInstruction;
typedef struct _sInstruction_Vars sInstruction_Vars;
typedef struct _sInstructions {
	sInstruction **insts;
	size_t       size;
	size_t       cap;
} sInstructions;

sInstruction *copyInstruction(const sInstruction *orig) {
	sInstruction *dup = (sInstruction*)malloc(sizeof(sInstruction));
	memcpy(dup, orig, sizeof(sInstruction));
	return dup;
}

typedef enum _eStatus {
	ST_LINE_START = 0,
	
	ST_LINE_COMMENT,
	
	ST_VARIABLE,
	ST_VARIABLE_INIT,
	ST_ALIAS,
	ST_ALIASING,
	ST_INSTRUCTION,
	
	ST_OPTION,
	
	ST_DONE,
	ST_ERROR
} eStatus;

typedef enum _eToken {
	TOK_NULL = 0,
	
	TOK_WHITESPACE,
	
	TOK_SIGN,
	TOK_INTEGER,
	TOK_FLOATCONST,
	
	TOK_IDENTIFIER,
	TOK_POINT,
	TOK_UPTO,
	TOK_COMMA,
	TOK_EQUALS,
	TOK_LSQBRACKET,
	TOK_RSQBRACKET,
	TOK_LBRACE,
	TOK_RBRACE,
	TOK_END_OF_INST,
	
	TOK_LINE_COMMENT,
	
	TOK_NEWLINE,
	
	TOK_END,
	
	TOK_UNKNOWN
} eToken;

#define TST_STR_VAL_PREF(str, pref, inst) (!strncmp(str, #inst, strlen(#inst))) ? pref##inst :
#define STR2VARTYPE(str) ( \
	TST_STR_VAL_PREF(str, VARTYPE_, ADDRESS) TST_STR_VAL_PREF(str, VARTYPE_, ATTRIB) \
	TST_STR_VAL_PREF(str, VARTYPE_, PARAM)   TST_STR_VAL_PREF(str, VARTYPE_, TEMP) \
	TST_STR_VAL_PREF(str, VARTYPE_, ALIAS)   TST_STR_VAL_PREF(str, VARTYPE_, OUTPUT) \
	VARTYPE_UNK)
eInstruction STR2INST(char *str, int *sat) {
	if ((str[0] == '\0') || (str[1] == '\0') || (str[2] == '\0')) return INST_UNK;
	*sat = !strcmp(str + 3, "_SAT");
	if ((((str[0] < 'A') || (str[0] > 'Z')) && ((str[0] < '0') || (str[0] > '9')))
	 || (((str[1] < 'A') || (str[1] > 'Z')) && ((str[1] < '0') || (str[1] > '9')))
	 || (((str[2] < 'A') || (str[2] > 'Z')) && ((str[2] < '0') || (str[2] > '9')))
	 || ((str[3] != '\0') && !sat)) {
		return INST_UNK;
	}
	
	switch (str[0]) {
	case 'A':
		switch (str[1]) {
		case 'B':
			return (str[2] == 'S') ? INST_ABS : INST_UNK;
		case 'D':
			return (str[2] == 'D') ? INST_ADD : INST_UNK;
		case 'R':
			return (str[2] == 'L') ? INST_ARL : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'C':
		switch (str[1]) {
		case 'M':
			return (str[2] == 'P') ? INST_CMP : INST_UNK;
		case 'O':
			return (str[2] == 'S') ? INST_COS : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'D':
		switch (str[2]) {
		case '3':
			return (str[1] == 'P') ? INST_DP3 : INST_UNK;
		case '4':
			return (str[1] == 'P') ? INST_DP4 : INST_UNK;
		case 'H':
			return (str[1] == 'P') ? INST_DPH : INST_UNK;
		case 'T':
			return (str[1] == 'S') ? INST_DST : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'E':
		if (str[1] != 'X') return INST_UNK;
		switch (str[2]) {
		case '2':
			return INST_EX2;
		case 'P':
			return INST_EXP;
		default:
			return INST_UNK;
		}
	case 'F':
		switch (str[1]) {
		case 'L':
			return (str[2] == 'R') ? INST_FLR : INST_UNK;
		case 'R':
			return (str[2] == 'C') ? INST_FRC : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'K':
		return ((str[1] == 'I') && (str[2] == 'L')) ? INST_KIL : INST_UNK;
	case 'L':
		switch (str[1]) {
		case 'G':
			return (str[2] == '2') ? INST_LG2 : INST_UNK;
		case 'I':
			return (str[2] == 'T') ? INST_LIT : INST_UNK;
		case 'O':
			return (str[2] == 'G') ? INST_LOG : INST_UNK;
		case 'R':
			return (str[2] == 'P') ? INST_LRP : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'M':
		switch (str[2]) {
		case 'D':
			return (str[1] == 'A') ? INST_MAD : INST_UNK;
		case 'X':
			return (str[1] == 'A') ? INST_MAX : INST_UNK;
		case 'N':
			return (str[1] == 'I') ? INST_MIN : INST_UNK;
		case 'V':
			return (str[1] == 'O') ? INST_MOV : INST_UNK;
		case 'L':
			return (str[1] == 'U') ? INST_MUL : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'P':
		return ((str[1] == 'O') && (str[2] == 'W')) ? INST_POW : INST_UNK;
	case 'R':
		switch (str[1]) {
		case 'C':
			return (str[2] == 'P') ? INST_RCP : INST_UNK;
		case 'S':
			return (str[2] == 'Q') ? INST_RSQ : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'S':
		switch (str[1]) {
		case 'C':
			return (str[2] == 'S') ? INST_SCS : INST_UNK;
		case 'G':
			return (str[2] == 'E') ? INST_SGE : INST_UNK;
		case 'I':
			return (str[2] == 'N') ? INST_SIN : INST_UNK;
		case 'L':
			return (str[2] == 'T') ? INST_SLT : INST_UNK;
		case 'U':
			return (str[2] == 'B') ? INST_SUB : INST_UNK;
		case 'W':
			return (str[2] == 'Z') ? INST_SWZ : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'T':
		switch (str[2]) {
		case 'X':
			return (str[1] == 'E') ? INST_TEX : INST_UNK;
		case 'B':
			return (str[1] == 'X') ? INST_TXB : INST_UNK;
		case 'P':
			return (str[1] == 'X') ? INST_TXP : INST_UNK;
		default:
			return INST_UNK;
		}
	case 'X':
		return ((str[1] == 'P') && (str[2] == 'D')) ? INST_XPD : INST_UNK;
	default:
		return INST_UNK;
	}
}
#define INSTTEX(i) (((i) == INST_TEX) || ((i) == INST_TXB) || ((i) == INST_TXP))

// Debug macros
#define ENUMVALUE2STR(v, e, v2) (v == e##v2) ? #v2 :
#define VARTYPE2STR(vartype) ( \
	ENUMVALUE2STR(vartype, VARTYPE_,ADDRESS) \
	ENUMVALUE2STR(vartype, VARTYPE_,ATTRIB) \
	ENUMVALUE2STR(vartype, VARTYPE_,PARAM) \
	ENUMVALUE2STR(vartype, VARTYPE_,PARAM_MULT) \
	ENUMVALUE2STR(vartype, VARTYPE_,TEMP) \
	ENUMVALUE2STR(vartype, VARTYPE_,OUTPUT) \
	ENUMVALUE2STR(vartype, VARTYPE_,CONST) \
	"???")
#define INST2STR(inst) ( \
	ENUMVALUE2STR(inst, INST_,ABS) ENUMVALUE2STR(inst, INST_,ADD) \
	ENUMVALUE2STR(inst, INST_,ARL) ENUMVALUE2STR(inst, INST_,CMP) \
	ENUMVALUE2STR(inst, INST_,COS) ENUMVALUE2STR(inst, INST_,DP3) \
	ENUMVALUE2STR(inst, INST_,DP4) ENUMVALUE2STR(inst, INST_,DPH) \
	ENUMVALUE2STR(inst, INST_,DST) ENUMVALUE2STR(inst, INST_,EX2) \
	ENUMVALUE2STR(inst, INST_,EXP) ENUMVALUE2STR(inst, INST_,FLR) \
	ENUMVALUE2STR(inst, INST_,FRC) ENUMVALUE2STR(inst, INST_,KIL) \
	ENUMVALUE2STR(inst, INST_,LG2) ENUMVALUE2STR(inst, INST_,LIT) \
	ENUMVALUE2STR(inst, INST_,LOG) ENUMVALUE2STR(inst, INST_,LRP) \
	ENUMVALUE2STR(inst, INST_,MAD) ENUMVALUE2STR(inst, INST_,MAX) \
	ENUMVALUE2STR(inst, INST_,MIN) ENUMVALUE2STR(inst, INST_,MOV) \
	ENUMVALUE2STR(inst, INST_,MUL) ENUMVALUE2STR(inst, INST_,POW) \
	ENUMVALUE2STR(inst, INST_,RCP) ENUMVALUE2STR(inst, INST_,RSQ) \
	ENUMVALUE2STR(inst, INST_,SCS) ENUMVALUE2STR(inst, INST_,SGE) \
	ENUMVALUE2STR(inst, INST_,SIN) ENUMVALUE2STR(inst, INST_,SLT) \
	ENUMVALUE2STR(inst, INST_,SUB) ENUMVALUE2STR(inst, INST_,SWZ) \
	ENUMVALUE2STR(inst, INST_,TEX) ENUMVALUE2STR(inst, INST_,TXB) \
	ENUMVALUE2STR(inst, INST_,TXP) ENUMVALUE2STR(inst, INST_,XPD) \
	"???")
#define STATUS2STR(s) (\
	ENUMVALUE2STR(s, ST_,LINE_START) \
	ENUMVALUE2STR(s, ST_,LINE_COMMENT) \
	ENUMVALUE2STR(s, ST_,VARIABLE) \
	ENUMVALUE2STR(s, ST_,VARIABLE_INIT) \
	ENUMVALUE2STR(s, ST_,ALIAS) \
	ENUMVALUE2STR(s, ST_,ALIASING) \
	ENUMVALUE2STR(s, ST_,INSTRUCTION) \
	ENUMVALUE2STR(s, ST_,OPTION) \
	ENUMVALUE2STR(s, ST_,DONE) \
	ENUMVALUE2STR(s, ST_,ERROR) \
	"???")
#define TOKEN2STR(t) (\
	ENUMVALUE2STR(t, TOK_,NULL) \
	ENUMVALUE2STR(t, TOK_,WHITESPACE) \
	ENUMVALUE2STR(t, TOK_,SIGN) \
	ENUMVALUE2STR(t, TOK_,INTEGER) \
	ENUMVALUE2STR(t, TOK_,FLOATCONST) \
	ENUMVALUE2STR(t, TOK_,IDENTIFIER) \
	ENUMVALUE2STR(t, TOK_,POINT) \
	ENUMVALUE2STR(t, TOK_,UPTO) \
	ENUMVALUE2STR(t, TOK_,COMMA) \
	ENUMVALUE2STR(t, TOK_,EQUALS) \
	ENUMVALUE2STR(t, TOK_,LSQBRACKET) \
	ENUMVALUE2STR(t, TOK_,RSQBRACKET) \
	ENUMVALUE2STR(t, TOK_,LBRACE) \
	ENUMVALUE2STR(t, TOK_,RBRACE) \
	ENUMVALUE2STR(t, TOK_,END_OF_INST) \
	ENUMVALUE2STR(t, TOK_,LINE_COMMENT) \
	ENUMVALUE2STR(t, TOK_,NEWLINE) \
	ENUMVALUE2STR(t, TOK_,END) \
	ENUMVALUE2STR(t, TOK_,UNKNOWN) \
	"???")

typedef struct _sCurStatus {
	eStatus      status;
	
	int          arbVersion;
	
	const char   *codePtr;
	
	const char   *endOfToken;
	eToken       curToken;
	unsigned int tokInt;
	float        tokFloat;
	
	char         *outputString;
	char         *outputEnd;
	size_t       outLen;
	size_t       outCap;
	size_t       outLeft;
	
	enum {
		TYPE_NONE, TYPE_INST_DECL, TYPE_VARIABLE_DECL, TYPE_ALIAS_DECL, TYPE_OPTION_DECL
	} valueType;
	union {
		struct _sCurStatus_NewInst {
			sInstruction inst; // duplicateInstruction(&newInst);
			unsigned int curArg;
			int          state;    // Dependant on variable type and current status
		} newInst;
		struct _sCurStatus_NewVar { // sArray manipulable
			char         **strParts; // copyToken();
			size_t       strLen;
			size_t       strCap;
			
			sVariable    *var;     // createVariable();
			int          state;    // Dependant on variable type and current status
		} newVar;
		char *string; // getToken();
		struct _sCurStatus_NewOpt {
			char *optName;
		} newOpt;
	} curValue;
	
	struct _sCurStatus_NewVar _fixedNewVar;
	
	sVariable     **texVars;
	sVariable     *tex1D;
	sVariable     *tex2D;
	sVariable     *tex3D;
	sVariable     *texCUBE;
	sVariable     *texRECT;
	
	khash_t(variables) *varsMap;
	sVariables    variables;
	sInstructions instructions;
} sCurStatus;
typedef struct _sCurStatus_NewInst sCurStatus_NewInst;
typedef struct _sCurStatus_NewVar sCurStatus_NewVar;

ptrdiff_t getTokenLength(const sCurStatus* curStatus) {
	return curStatus->endOfToken - curStatus->codePtr;
}
int compareTokenWith(const sCurStatus* curStatus, const char* compWith, const int len) {
	return (getTokenLength(curStatus) == len) ? strncmp(curStatus->codePtr, compWith, len) : 1;
}

eToken readNextToken(sCurStatus *curStatus) {
	curStatus->codePtr = curStatus->endOfToken;
	
	switch (*curStatus->codePtr) {
	case '\0':
		curStatus->curToken = TOK_NULL;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
	case ' ':
	case '\t':
		curStatus->curToken = TOK_WHITESPACE;
		curStatus->endOfToken = curStatus->codePtr + 1;
		while ((*curStatus->endOfToken == ' ') || (*curStatus->endOfToken == '\t')) {
			++curStatus->endOfToken;
		}
		break;
	case '\n':
	case '\r':
		curStatus->curToken = TOK_NEWLINE;
		curStatus->endOfToken = curStatus->codePtr + 1;
		if ((*curStatus->endOfToken == '\n') || (*curStatus->endOfToken == '\r')) {
			++curStatus->endOfToken;
		}
		break;
		
	case '-':
	case '+':
		curStatus->curToken = TOK_SIGN;
		curStatus->endOfToken = curStatus->codePtr + 1;
		curStatus->tokInt = (*curStatus->codePtr == '+') ? 1 : 0;
		break;
		
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		curStatus->curToken = TOK_INTEGER;
		curStatus->endOfToken = curStatus->codePtr + 1;
		
		curStatus->tokInt = *curStatus->codePtr - '0';
		while ((*curStatus->endOfToken >= '0') && (*curStatus->endOfToken <= '9')) {
			curStatus->tokInt = curStatus->tokInt * 10 + *curStatus->endOfToken - '0';
			++curStatus->endOfToken;
		}
		
		if ((curStatus->endOfToken[0] == '.') && (curStatus->endOfToken[1] == '.')) {
			break;
		}
		
		curStatus->tokFloat = curStatus->tokInt;
		if (*curStatus->endOfToken == '.') {
			curStatus->curToken = TOK_FLOATCONST;
			++curStatus->endOfToken;
			
			if ((*curStatus->endOfToken >= '0') && (*curStatus->endOfToken <= '9')) {
				float exp = 0.1f;
				
				while ((*curStatus->endOfToken >= '0') && (*curStatus->endOfToken <= '9')) {
					curStatus->tokFloat += (*curStatus->endOfToken - '0') * exp;
					exp /= 10.f;
					++curStatus->endOfToken;
				}
			}
		}
		
		if ((*curStatus->endOfToken == 'e') || (*curStatus->endOfToken == 'E')) {
			curStatus->curToken = TOK_FLOATCONST;
			++curStatus->endOfToken;
			
			int s = 1;
			if (*curStatus->endOfToken == '-') {
				s = 0;
				++curStatus->endOfToken;
			} else if (*curStatus->endOfToken == '+') {
				++curStatus->endOfToken;
			}
			
			if ((*curStatus->endOfToken < '0') || (*curStatus->endOfToken > '9')) {
				curStatus->curToken = TOK_UNKNOWN;
				break;
			}
			
			int e = 0;
			while ((*curStatus->endOfToken >= '0') && (*curStatus->endOfToken <= '9')) {
				e = e * 10 + *curStatus->endOfToken - '0';
				++curStatus->endOfToken;
			}
			
			while (e-- != 0) curStatus->tokFloat *= s ? 10.f : 0.1f;
		}
		
		break;
		
	case '.':
		curStatus->endOfToken = curStatus->codePtr + 1;
		
		// Plain '.' is TOK_POINT, '..' is TOK_UPTO
		if (*curStatus->endOfToken == '.') {
			curStatus->curToken = TOK_UPTO;
			curStatus->endOfToken = curStatus->codePtr + 2;
			break;
		} else if ((*curStatus->endOfToken < '0') || (*curStatus->endOfToken > '9')) {
			curStatus->curToken = TOK_POINT;
			break;
		}
		
		float exp = 0.1f;
		
		curStatus->curToken = TOK_FLOATCONST;
		curStatus->tokFloat = 0;
		while ((*curStatus->endOfToken >= '0') && (*curStatus->endOfToken <= '9')) {
			curStatus->tokFloat += (*curStatus->endOfToken - '0') * exp;
			exp /= 10.f;
			++curStatus->endOfToken;
		}
		
		if ((*curStatus->endOfToken == 'e') || (*curStatus->endOfToken == 'E')) {
			++curStatus->endOfToken;
			
			int s = 1;
			if (*curStatus->endOfToken == '-') {
				s = 0;
				++curStatus->endOfToken;
			} else if (*curStatus->endOfToken == '+') {
				++curStatus->endOfToken;
			} else if ((*curStatus->endOfToken < '0') || (*curStatus->endOfToken > '9')) {
				curStatus->curToken = TOK_UNKNOWN;
				break;
			}
			
			int e = 0;
			while ((*curStatus->endOfToken >= '0') && (*curStatus->endOfToken <= '9')) {
				e = e * 10 + *curStatus->endOfToken - '0';
				++curStatus->endOfToken;
			}
			
			while (e-- != 0) curStatus->tokFloat *= s ? 10.f : 0.1f;
		}
		
		break;
		
	case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
	case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
	case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
	case 'V': case 'W': case 'X': case 'Y': case 'Z':
	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
	case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
	case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
	case 'v': case 'w': case 'x': case 'y': case 'z':
	case '_': case '$':
		curStatus->curToken = TOK_IDENTIFIER;
		curStatus->endOfToken = curStatus->codePtr + 1;
		while (((*curStatus->endOfToken >= '0') && (*curStatus->endOfToken <= '9'))
		    || ((*curStatus->endOfToken >= 'A') && (*curStatus->endOfToken <= 'Z'))
		    || ((*curStatus->endOfToken >= 'a') && (*curStatus->endOfToken <= 'z'))
		    || (*curStatus->endOfToken == '_') || (*curStatus->endOfToken == '$')) {
			++curStatus->endOfToken;
		}
		
		if ((curStatus->endOfToken == curStatus->codePtr + 3) && (curStatus->codePtr[0] == 'E')
		 && (curStatus->codePtr[1] == 'N') && (curStatus->codePtr[2] == 'D')) {
			curStatus->curToken = TOK_END;
		}
		break;
		
	case ',':
		curStatus->curToken = TOK_COMMA;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
	case '=':
		curStatus->curToken = TOK_EQUALS;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
	case '[':
		curStatus->curToken = TOK_LSQBRACKET;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
	case ']':
		curStatus->curToken = TOK_RSQBRACKET;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
	case '{':
		curStatus->curToken = TOK_LBRACE;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
	case '}':
		curStatus->curToken = TOK_RBRACE;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
	case ';':
		curStatus->curToken = TOK_END_OF_INST;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
	case '#':
		curStatus->curToken = TOK_LINE_COMMENT;
		curStatus->endOfToken = curStatus->codePtr + 1;
		break;
		
	default:
		if (curStatus->status == ST_LINE_COMMENT) {
			// Ignore errors in comments
			curStatus->endOfToken = curStatus->codePtr + 1;
			curStatus->curToken = TOK_UNKNOWN;
		} else {
			curStatus->endOfToken = curStatus->codePtr;
			curStatus->curToken = TOK_UNKNOWN;
			curStatus->status = ST_ERROR;
		}
	}
	
	return curStatus->curToken;
}
void copyToken(const sCurStatus* curStatus, char* dest) {
	// Token length
	ptrdiff_t tokLen = getTokenLength(curStatus);
	
	// Copy token into destination
	memcpy(dest, curStatus->codePtr, tokLen);
	
	// Null-terminate the token
	dest[tokLen] = '\0';
}
char *getToken(const sCurStatus* curStatus) {
	// Allocate (exactly enough) space
	char *tok = (char*)malloc((getTokenLength(curStatus) + 1) * sizeof(char));
	
	// Copy token
	copyToken(curStatus, tok);
	
	// Return token
	return tok;
}

void initStatus(sCurStatus* curStatus, const char* code) {
	curStatus->status = ST_LINE_START;
	curStatus->arbVersion = 10; // Todo?
	curStatus->codePtr = code;
	curStatus->endOfToken = code;
	
	curStatus->outputString = malloc(DEFAULT_STRING_MALLOC_SIZE);
	curStatus->outputString[0] = '\0';
	curStatus->outputEnd = curStatus->outputString;
	curStatus->outLen = 0;
	curStatus->outCap = DEFAULT_STRING_CAP;
	curStatus->outLeft = DEFAULT_STRING_CAP - 1;
	
	curStatus->valueType = TYPE_NONE;
	
	curStatus->texVars = (sVariable**)malloc(MAX_TEX * sizeof(sVariable*));
	for (size_t i = 0; i < MAX_TEX; ++i) {
		curStatus->texVars[i] = createVariable(VARTYPE_TEXTURE);
	}
	curStatus->tex1D = (sVariable*)malloc(sizeof(sVariable));
	curStatus->tex1D->type = VARTYPE_TEXTARGET;
	curStatus->tex2D = (sVariable*)malloc(sizeof(sVariable));
	curStatus->tex2D->type = VARTYPE_TEXTARGET;
	curStatus->tex3D = (sVariable*)malloc(sizeof(sVariable));
	curStatus->tex3D->type = VARTYPE_TEXTARGET;
	curStatus->texCUBE = (sVariable*)malloc(sizeof(sVariable));
	curStatus->texCUBE->type = VARTYPE_TEXTARGET;
	curStatus->texRECT = (sVariable*)malloc(sizeof(sVariable));
	curStatus->texRECT->type = VARTYPE_TEXTARGET;
	
	curStatus->varsMap = kh_init(variables);
	initArray((sArray*)&curStatus->variables);
	initArray((sArray*)&curStatus->instructions);
	
	initArray((sArray*)&curStatus->_fixedNewVar);
	curStatus->_fixedNewVar.var = NULL;
	
	readNextToken(curStatus);
}

void freeStatus(sCurStatus* curStatus) {
	if (curStatus->valueType == TYPE_VARIABLE_DECL) {
		char *strPtr;
		while ((strPtr = (char*)popArray((sArray*)&curStatus->curValue.newVar))) {
			free(strPtr);
		}
		freeArray((sArray*)&curStatus->curValue.newVar);
		
		deleteVariable(&curStatus->curValue.newVar.var);
	} else if (curStatus->valueType == TYPE_ALIAS_DECL) {
		if (curStatus->curValue.string) {
			free(curStatus->curValue.string);
		}
	} else if (curStatus->valueType == TYPE_OPTION_DECL) {
		if (curStatus->curValue.newOpt.optName) {
			free(curStatus->curValue.newOpt.optName);
		}
	}
	curStatus->valueType = TYPE_NONE;
	
	for (size_t i = 0; i < MAX_TEX; ++i) {
		deleteVariable(&curStatus->texVars[i]);
	}
	free(curStatus->texVars);
	free(curStatus->tex1D);
	free(curStatus->tex2D);
	free(curStatus->tex3D);
	free(curStatus->texCUBE);
	free(curStatus->texRECT);
	
	kh_destroy(variables, curStatus->varsMap);
	
	sVariable *varPtr;
	while ((varPtr = (sVariable*)popArray((sArray*)&curStatus->variables))) {
		deleteVariable(&varPtr);
	}
	
	freeArray((sArray*)&curStatus->variables);
	freeArray((sArray*)&curStatus->instructions);
	
	freeArray((sArray*)&curStatus->_fixedNewVar);
}

int appendString(sCurStatus *curStatus, const char *str, size_t strLen) {
	if (strLen == (size_t)-1) {
		strLen = strlen(str);
	}
	
	if (curStatus->outLeft < strLen) {
		char *oldOut = curStatus->outputString;
		while (curStatus->outLeft < strLen) {
			curStatus->outLeft += curStatus->outCap;
			if (!resize((void**)&curStatus->outputString, &curStatus->outCap, sizeof(char))) {
				return 1;
			}
		}
		curStatus->outputEnd += curStatus->outputString - oldOut;
	}
	
	ARBCONV_DBG_HEAVY(ARBCONV_DBG(printf(
		"Appending to %p (%p + %ld = %p)\n",
		curStatus->outputEnd,
		curStatus->outputString,
		curStatus->outLen,
		curStatus->outputString+curStatus->outLen
	);)
	if (curStatus->outputEnd != curStatus->outputString+curStatus->outLen) {
		printf("\033[01;31mERROR!!!\033[m\n%s\n", str);
		curStatus->status = ST_ERROR;
		return 1;
	})
	
	strcpy(curStatus->outputEnd, str);
	curStatus->outLen += strLen;
	curStatus->outLeft -= strLen;
	curStatus->outputEnd += strLen;
	
	return 0;
}

#define IS_SWIZZLE(str) (((str)[0] >= 'w') && ((str)[0] <= 'z') && \
 (((str)[1] == '\0') || (((str)[1] >= 'w') && ((str)[1] <= 'z') && \
 (((str)[2] == '\0') || (((str)[2] >= 'w') && ((str)[2] <= 'z') && \
 (((str)[3] == '\0') || (((str)[3] >= 'w') && ((str)[3] <= 'z') && \
  ((str)[4] == '\0'))))))))
#define IS_NEW_STR_OR_SWIZZLE(str, t) (((str)[0] == ',') || ((t == 1) && IS_SWIZZLE(str)))
#define IS_NONE_OR_SWIZZLE (!newVar->strLen || IS_SWIZZLE(newVar->strParts[0]))

int resolveAttrib(sCurStatus_NewVar *newVar, int vertex) {
	char *tok = popFIFO((sArray*)newVar);
	
	if (!tok) {
		ARBCONV_DBG_RE(printf("Failed to get attrib: (tok NULL)\n");)
		return 1;
	} else if (vertex && !strcmp(tok, "vertex")) {
		free(tok);
		tok = popFIFO((sArray*)newVar);
		
		if (!tok) {
			ARBCONV_DBG_RE(printf("Failed to get attrib: vertex(tok NULL)\n");)
			return 1;
		} else if (!strcmp(tok, "position")) {
			// vertex.position => gl_Vertex
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("gl_Vertex"));
			newVar->var->init.strings_total_len = 9;
		} else if (!strcmp(tok, "normal")) {
			// vertex.normal => vec4(gl_Normal, 1.)
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("vec4(gl_Normal, 1.)"));
			newVar->var->init.strings_total_len = 19;
		} else if (!strcmp(tok, "color")) {
			free(tok);
			
			if (IS_NONE_OR_SWIZZLE) {
				// vertex.color => gl_Color
				pushArray((sArray*)&newVar->var->init, strdup("gl_Color"));
				newVar->var->init.strings_total_len = 8;
				return 0;
			}
			
			tok = popFIFO((sArray*)newVar);
			if (!strcmp(tok, "primary")) {
				// vertex.color.primary => gl_Color
				free(tok);
				pushArray((sArray*)&newVar->var->init, strdup("gl_Color"));
				newVar->var->init.strings_total_len = 8;
			} else if (!strcmp(tok, "secondary")) {
				// vertex.color.secondary => gl_SecondaryColor
				free(tok);
				pushArray((sArray*)&newVar->var->init, strdup("gl_SecondaryColor"));
				newVar->var->init.strings_total_len = 17;
			} else {
				ARBCONV_DBG_RE(printf("Failed to get attrib: vertex.color.%s\n", tok);)
				free(tok);
				return 1;
			}
		} else if (!strcmp(tok, "fogcoord")) {
			// vertex.fogcoord => gl_FogCoord
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("gl_FogCoord"));
			newVar->var->init.strings_total_len = 11;
		} else if (!strcmp(tok, "texcoord")) {
			free(tok);
			if (!IS_NONE_OR_SWIZZLE) {
				tok = popFIFO((sArray*)newVar);
				if ((tok[0] == '[') && (newVar->strLen >= 2) && (newVar->strParts[1][0] == ']')
				 && (newVar->strParts[0][0] >= '0') && (newVar->strParts[0][0] <= '9')) {
					free(tok);
					char *tex = popFIFO((sArray*)newVar);
					free(popFIFO((sArray*)newVar));
					size_t bufLen = 16 + strlen(tex);
					char *buf = (char*)malloc((bufLen + 1) * sizeof(char));
					sprintf(buf, "gl_MultiTexCoord%s", tex);
					pushArray((sArray*)&newVar->var->init, buf);
					free(tex);
					newVar->var->init.strings_total_len = bufLen;
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: vertex.texcoord.%s\n", tok);)
					free(tok);
					return 1;
				}
			} else {
				pushArray((sArray*)&newVar->var->init, strdup("gl_MultiTexCoord0"));
				newVar->var->init.strings_total_len = 17;
			}
		} else {
			ARBCONV_DBG_RE(printf("Failed to get attrib: vertex.%s\n", tok);)
			free(tok);
			return 1;
		}
	} else if (!vertex && !strcmp(tok, "fragment")) {
		free(tok);
		tok = popFIFO((sArray*)newVar);
		
		if (!tok) {
			ARBCONV_DBG_RE(printf("Failed to get attrib: fragment(tok NULL)\n");)
			return 1;
		} else if (!strcmp(tok, "color")) {
			free(tok);
			
			if (IS_NONE_OR_SWIZZLE) {
				// fragment.color => gl_Color
				pushArray((sArray*)&newVar->var->init, strdup("gl_Color"));
				newVar->var->init.strings_total_len = 8;
				return 0;
			}
			
			tok = popFIFO((sArray*)newVar);
			if (!strcmp(tok, "primary")) {
				// fragment.color.primary => gl_Color
				free(tok);
				pushArray((sArray*)&newVar->var->init, strdup("gl_Color"));
				newVar->var->init.strings_total_len = 8;
			} else if (!strcmp(tok, "secondary")) {
				// fragment.color.secondary => gl_SecondaryColor
				free(tok);
				pushArray((sArray*)&newVar->var->init, strdup("gl_SecondaryColor"));
				newVar->var->init.strings_total_len = 17;
			} else {
				ARBCONV_DBG_RE(printf("Failed to get attrib: fragment.color.%s\n", tok);)
				free(tok);
				return 1;
			}
		} else if (!strcmp(tok, "texcoord")) {
			free(tok);
			if (!IS_NONE_OR_SWIZZLE) {
				tok = popFIFO((sArray*)newVar);
				if ((tok[0] == '[') && (newVar->strLen >= 2) && (newVar->strParts[1][0] == ']')
				 && (newVar->strParts[0][0] >= '0') && (newVar->strParts[0][0] <= '9')) {
					free(tok);
					char *tex = popFIFO((sArray*)newVar);
					free(popFIFO((sArray*)newVar));
					size_t bufLen = 13 + strlen(tex);
					char *buf = (char*)malloc((bufLen + 1) * sizeof(char));
					sprintf(buf, "gl_TexCoord[%s]", tex);
					pushArray((sArray*)&newVar->var->init, buf);
					free(tex);
					newVar->var->init.strings_total_len = bufLen;
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: fragment.texcoord.%s\n", tok);)
					free(tok);
					return 1;
				}
			} else {
				pushArray((sArray*)&newVar->var->init, strdup("gl_TexCoord[0]"));
				newVar->var->init.strings_total_len = 14;
			}
		} else if (!strcmp(tok, "fogcoord")) {
			// fragment.fogcoord => vec4(gl_FogFragCoord, 0., 0., 1.)
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("vec4(gl_FogFragCoord, 0., 0., 1.)"));
			newVar->var->init.strings_total_len = 33;
		} else if (!strcmp(tok, "position")) {
			// fragment.position => gl_Position
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("gl_Position"));
			newVar->var->init.strings_total_len = 11;
		} else {
			ARBCONV_DBG_RE(printf("Failed to get attrib: fragment.%s\n", tok);)
			free(tok);
			return 1;
		}
	} else {
		ARBCONV_DBG_RE(printf("Failed to get attrib: %s\n", tok);)
		free(tok);
		return 1;
	}
	/* TODO:
	 V "vertex" "." "position"
	 X "vertex" "." "weight" <vtxOptWeightNum>
	 V "vertex" "." "normal"
	 V "vertex" "." "color"
	 V "vertex" "." "color" "." "primary"
	 V "vertex" "." "color" "." "secondary"
	 V "vertex" "." "fogcoord"
	 V "vertex" "." "texcoord"
	 V "vertex" "." "texcoord" "[" <texCoordNum> "]"
	 * "vertex" "." "matrixindex" "[" <vtxWeightNum> "]"
	 * "vertex" "." "attrib" "[" <vtxAttribNum> "]"
	 * 
	 V "fragment" "." "color"
	 V "fragment" "." "color" "." "primary"
	 V "fragment" "." "color" "." "secondary"
	 V "fragment" "." "texcoord"
	 V "fragment" "." "texcoord" "[" <texCoordNum> "]"
	 V "fragment" "." "fogcoord"
	 W "fragment" "." "position"
	 */
	
	return 0;
}
int resolveOutput(sCurStatus_NewVar *newVar, int vertex) {
	char *tok = popFIFO((sArray*)newVar);
	
	if (!tok) {
		ARBCONV_DBG_RE(printf("Failed to get output: (tok NULL)\n");)
		return 1;
	} else if (vertex && !strcmp(tok, "result")) {
		free(tok);
		tok = popFIFO((sArray*)newVar);
		
		if (!tok) {
			ARBCONV_DBG_RE(printf("Failed to get output: result(tok NULL)\n");)
			return 1;
		} else if (!strcmp(tok, "position")) {
			// result.position => gl_Position
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("gl_Position"));
			newVar->var->init.strings_total_len = 11;
		} else if (!strcmp(tok, "color")) {
			free(tok);
			
			if (IS_NONE_OR_SWIZZLE) {
				// result.color => gl_FrontColor
				pushArray((sArray*)&newVar->var->init, strdup("gl_FrontColor"));
				newVar->var->init.strings_total_len = 13;
				return 0;
			}
			
			tok = popFIFO((sArray*)newVar);
			if (!strcmp(tok, "front")) {
				free(tok);
				
				if (IS_NONE_OR_SWIZZLE) {
					// result.color.front => gl_FrontColor
					pushArray((sArray*)&newVar->var->init, strdup("gl_FrontColor"));
					newVar->var->init.strings_total_len = 13;
				}
				
				tok = popFIFO((sArray*)newVar);
				if (!strcmp(tok, "primary")) {
					// result.color.front.primary => gl_FrontColor
					free(tok);
					pushArray((sArray*)&newVar->var->init, strdup("gl_FrontColor"));
					newVar->var->init.strings_total_len = 13;
				} else if (!strcmp(tok, "secondary")) {
					// result.color.front.secondary => gl_FrontSecondaryColor
					free(tok);
					pushArray((sArray*)&newVar->var->init, strdup("gl_FrontSecondaryColor"));
					newVar->var->init.strings_total_len = 22;
				} else {
					ARBCONV_DBG_RE(printf("Failed to get output: result.color.front.%s\n", tok);)
					free(tok);
					return 1;
				}
			} else if (!strcmp(tok, "back")) {
				free(tok);
				
				if (IS_NONE_OR_SWIZZLE) {
					// result.color.back => gl_BackColor
					pushArray((sArray*)&newVar->var->init, strdup("gl_BackColor"));
					newVar->var->init.strings_total_len = 12;
				}
				
				tok = popFIFO((sArray*)newVar);
				if (!strcmp(tok, "primary")) {
					// result.color.back.primary => gl_BackColor
					free(tok);
					pushArray((sArray*)&newVar->var->init, strdup("gl_BackColor"));
					newVar->var->init.strings_total_len = 12;
				} else if (!strcmp(tok, "secondary")) {
					// result.color.back.secondary => gl_BackSecondaryColor
					free(tok);
					pushArray((sArray*)&newVar->var->init, strdup("gl_BackSecondaryColor"));
					newVar->var->init.strings_total_len = 21;
				} else {
					ARBCONV_DBG_RE(printf("Failed to get output: result.color.back.%s\n", tok);)
					free(tok);
					return 1;
				}
			} else if (!strcmp(tok, "primary")) {
				// result.color.primary => gl_FrontColor
				free(tok);
				pushArray((sArray*)&newVar->var->init, strdup("gl_FrontColor"));
				newVar->var->init.strings_total_len = 8;
			} else if (!strcmp(tok, "secondary")) {
				// result.color.secondary => gl_SecondaryColor
				free(tok);
				pushArray((sArray*)&newVar->var->init, strdup("gl_SecondaryColor"));
				newVar->var->init.strings_total_len = 17;
			} else {
				ARBCONV_DBG_RE(printf("Failed to get output: result.color.%s\n", tok);)
				free(tok);
				return 1;
			}
		} else if (!strcmp(tok, "fogcoord")) {
			// result.fogcoord => gl_FogFragCoord
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("gl_FogFragCoord"));
			newVar->var->init.strings_total_len = 15;
		} else if (!strcmp(tok, "pointsize")) {
			// result.pointsize => gl_Point.size
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("vec4(gl_Point.size, 0., 0., 0.)"));
			newVar->var->init.strings_total_len = 31;
		} else if (!strcmp(tok, "texcoord")) {
			free(tok);
			if (!IS_NONE_OR_SWIZZLE) {
				tok = popFIFO((sArray*)newVar);
				if ((tok[0] == '[')
				 && (newVar->strLen >= 2) && (newVar->strParts[1][0] == ']')
				 && (newVar->strParts[0][0] >= '0') && (newVar->strParts[0][0] <= '9')) {
					free(tok);
					char *tex = popFIFO((sArray*)newVar);
					free(popFIFO((sArray*)newVar));
					size_t bufLen = 13 + strlen(tex);
					char *buf = (char*)malloc((bufLen + 1) * sizeof(char));
					sprintf(buf, "gl_TexCoord[%s]", tex);
					pushArray((sArray*)&newVar->var->init, buf);
					free(tex);
					newVar->var->init.strings_total_len = bufLen;
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: result.texcoord.%s\n", tok);)
					free(tok);
					return 1;
				}
			} else {
				pushArray((sArray*)&newVar->var->init, strdup("gl_TexCoord[0]"));
				newVar->var->init.strings_total_len = 14;
			}
		} else {
			ARBCONV_DBG_RE(printf("Failed to get output: result.%s\n", tok);)
			free(tok);
			return 1;
		}
	} else if (!vertex && !strcmp(tok, "result")) {
		free(tok);
		tok = popFIFO((sArray*)newVar);
		
		if (!tok) {
			ARBCONV_DBG_RE(printf("Failed to get output: result(tok NULL)\n");)
			return 1;
		} else if (!strcmp(tok, "color")) {
			// result.color => gl_FragColor
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("gl_FragColor"));
			newVar->var->init.strings_total_len = 12;
		} else if (!strcmp(tok, "depth")) {
			// result.depth => gl_FragDepth
			free(tok);
			pushArray((sArray*)&newVar->var->init, strdup("gl_FragDepth"));
			newVar->var->init.strings_total_len = 12;
		} else {
			ARBCONV_DBG_RE(printf("Failed to get output: result.%s\n", tok);)
			free(tok);
			return 1;
		}
	} else {
		ARBCONV_DBG_RE(printf("Failed to get output: %s\n", tok);)
		free(tok);
		return 1;
	}
	/* TODO:
	 V "result" "." "position"
	 V "result" "." "color"
	 V "result" "." "color" "." "primary"
	 V "result" "." "color" "." "secondary"
	 V "result" "." "color" "." "front"
	 V "result" "." "color" "." "front" "." "primary"
	 V "result" "." "color" "." "front" "." "secondary"
	 V "result" "." "color" "." "back"
	 V "result" "." "color" "." "back" "." "primary"
	 V "result" "." "color" "." "back" "." "secondary"
	 V "result" "." "fogcoord"
	 V "result" "." "pointsize"
	 V "result" "." "texcoord"
	 V "result" "." "texcoord" "[" <texCoordNum> "]"
	 * 
	 V "result" "." "color"
	 V "result" "." "depth"
	 */
	
	return 0;
}

char *resolveParam(sCurStatus_NewVar *newVar, int vertex, int type, size_t *outLen) {
	(void)vertex;
	
	const char *matrixName = NULL;
	char *matrixNameMallocd = NULL;
	size_t mtxNameLen;
	int start = 0;
	int end = 3;
	int isMatrix = 0;
	int refuseEndGT4 = 1;
	
	char *tok = popFIFO((sArray*)newVar);
	if (!tok) {
		ARBCONV_DBG_RE(printf("Failed to get param: (tok NULL)\n");)
		return NULL;
	} else if (!strcmp(tok, "state")) {
		free(tok);
		tok = popFIFO((sArray*)newVar);
		
		if (!tok) {
			ARBCONV_DBG_RE(printf("Failed to get param: state.(tok NULL)\n");)
			return NULL;
		} else if (!strcmp(tok, "material")) {
			size_t propLen;
			const char *prop;
			
			free(tok);
			tok = popFIFO((sArray*)newVar);
			if (!tok) {
				ARBCONV_DBG_RE(printf("Failed to get param: state.material(tok NULL)\n");)
				return NULL;
			} else if (!strcmp(tok, "front")) {
				free(tok);
				tok = popFIFO((sArray*)newVar);
				mtxNameLen = 16;
				matrixName = "gl_FrontMaterial";
			} else if (!strcmp(tok, "back")) {
				free(tok);
				tok = popFIFO((sArray*)newVar);
				mtxNameLen = 15;
				matrixName = "gl_BackMaterial";
			} else {
				mtxNameLen = 16;
				matrixName = "gl_FrontMaterial";
			}
			
			if (!tok) {
				ARBCONV_DBG_RE(printf("Failed to get param: [%s].(tok NULL)\n", matrixName);)
				return NULL;
			} else if (!strcmp(tok, "ambient")) {
				free(tok);
				propLen = 7;
				prop = "ambient";
			} else if (!strcmp(tok, "diffuse")) {
				free(tok);
				propLen = 7;
				prop = "diffuse";
			} else if (!strcmp(tok, "specular")) {
				free(tok);
				propLen = 8;
				prop = "specular";
			} else if (!strcmp(tok, "emission")) {
				free(tok);
				propLen = 8;
				prop = "emission";
			} else if (!strcmp(tok, "shininess")) {
				free(tok);
				*outLen = mtxNameLen + 16;
				matrixNameMallocd = (char*)malloc((*outLen + 1) * sizeof(char));
				sprintf(matrixNameMallocd, "vec4(%s.shininess)", matrixName);
				return matrixNameMallocd;
			} else {
				ARBCONV_DBG_RE(printf("Failed to get param: [%s].%s\n", matrixName, tok);)
				free(tok);
				return NULL;
			}
			
			*outLen = mtxNameLen + propLen + 1;
			matrixNameMallocd = (char*)malloc((*outLen + 1) * sizeof(char));
			sprintf(matrixNameMallocd, "%s.%s", matrixName, prop);
			return matrixNameMallocd;
		} else if (!strcmp(tok, "light")) {
			free(tok);
			if (newVar->strParts[0][0] == '[') {
				free(popFIFO((sArray*)newVar));
				char *sln = popFIFO((sArray*)newVar);
				
				if ((sln[0] >= '0') && (sln[0] <= '9')) {
					if (newVar->strParts[0][0] != ']') {
						ARBCONV_DBG_RE(printf("Failed to get param: state.light[%s(not ])\n", sln);)
						return NULL;
					}
					free(popFIFO((sArray*)newVar));
					
					tok = popFIFO((sArray*)newVar);
					if (!tok) {
						ARBCONV_DBG_RE(printf("Failed to get param: state.light[%s](tok NULL)\n", sln);)
						return NULL;
					} else if (!strcmp(tok, "ambient")) {
						free(tok);
						mtxNameLen = 7;
						matrixName = "ambient";
					} else if (!strcmp(tok, "diffuse")) {
						free(tok);
						mtxNameLen = 7;
						matrixName = "diffuse";
					} else if (!strcmp(tok, "specular")) {
						free(tok);
						mtxNameLen = 8;
						matrixName = "specular";
					} else if (!strcmp(tok, "position")) {
						free(tok);
						mtxNameLen = 8;
						matrixName = "position";
					} else if (!strcmp(tok, "attenuation")) {
						free(tok);
						*outLen = 148 + 4 * strlen(sln);
						matrixNameMallocd = (char*)malloc((*outLen + 1) * sizeof(char));
						sprintf(
							matrixNameMallocd,
							"vec4(gl_LightSource[%s].constantAttenuation, gl_LightSource[%s].linearAttenuation, "
							"gl_LightSource[%s].quadraticAttenuation, gl_LightSource[%s].spotExponent)",
							sln, sln, sln, sln
						);
						return matrixNameMallocd;
					} else if (!strcmp(tok, "spot")) {
						free(tok);
						tok = popFIFO((sArray*)newVar);
						if (!tok) {
							ARBCONV_DBG_RE(printf("Failed to get param: state.light[%s].spot(tok NULL)\n", sln);)
							return NULL;
						} else if (!strcmp(tok, "direction")) {
							mtxNameLen = 9;
							matrixName = "spotDirection";
						} else {
							ARBCONV_DBG_RE(printf("Failed to get param: state.light[%s].spot.%s\n", sln, tok);)
							free(tok);
							return NULL;
						}
					} else if (!strcmp(tok, "half")) {
						free(tok);
						mtxNameLen = 10;
						matrixName = "halfVector";
					} else {
						ARBCONV_DBG_RE(printf("Failed to get param: state.light[%s].%s\n", sln, tok);)
						free(tok);
						return NULL;
					}
					
					*outLen = mtxNameLen + 17 + strlen(sln);
					matrixNameMallocd = (char*)malloc((*outLen + 1) * sizeof(char));
					sprintf(matrixNameMallocd, "gl_LightSource[%s].%s", sln, matrixName);
					free(sln);
					return matrixNameMallocd;
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: state.light.%s\n", sln);)
					free(sln);
					return NULL;
				}
			} else {
				ARBCONV_DBG_RE(printf("Failed to get param: state.light(not [)\n");)
				return NULL;
			}
		} else if (!strcmp(tok, "lightmodel")) {
			free(tok);
			tok = popFIFO((sArray*)newVar);
			if (!tok) {
				ARBCONV_DBG_RE(printf("Failed to get param: state.lightmodel(tok NULL)\n");)
				return NULL;
			} else if (!strcmp(tok, "ambient")) {
				free(tok);
				*outLen = 21;
				return "gl_LightModel.ambient";
			} else if (!strcmp(tok, "scenecolor")) {
				free(tok);
				*outLen = 36;
				return "gl_FrontLightModelProduct.sceneColor";
			} else if (!strcmp(tok, "front")) {
				free(tok);
				tok = popFIFO((sArray*)newVar);
				if (!tok) {
					ARBCONV_DBG_RE(printf("Failed to get param: state.lightmodel.front(tok NULL)\n");)
					return NULL;
				} else if (!strcmp(tok, "scenecolor")) {
					free(tok);
					*outLen = 36;
					return "gl_FrontLightModelProduct.sceneColor";
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: state.lightmodel.front.%s\n", tok);)
					free(tok);
					return NULL;
				}
			} else if (!strcmp(tok, "back")) {
				free(tok);
				tok = popFIFO((sArray*)newVar);
				if (!tok) {
					ARBCONV_DBG_RE(printf("Failed to get param: state.lightmodel.back(tok NULL)\n");)
					return NULL;
				} else if (!strcmp(tok, "scenecolor")) {
					free(tok);
					*outLen = 36;
					return "gl_BackLightModelProduct.sceneColor";
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: state.lightmodel.back.%s\n", tok);)
					free(tok);
					return NULL;
				}
			} else {
				ARBCONV_DBG_RE(printf("Failed to get param: state.lightmodel.%s\n", tok);)
				free(tok);
				return NULL;
			}
		} else if (!strcmp(tok, "lightprod")) {
			free(tok);
			if (newVar->strParts[0][0] == '[') {
				free(popFIFO((sArray*)newVar));
				char *sln = popFIFO((sArray*)newVar);
				
				if ((sln[0] >= '0') && (sln[0] <= '9')) {
					size_t propLen;
					const char *prop;
					
					if (newVar->strParts[0][0] != ']') {
						ARBCONV_DBG_RE(printf("Failed to get param: state.lightprod[%s(not ])\n", sln);)
						return NULL;
					}
					
					free(popFIFO((sArray*)newVar));
					tok = popFIFO((sArray*)newVar);
					if (!tok) {
						ARBCONV_DBG_RE(printf("Failed to get param: state.material(tok NULL)\n");)
						return NULL;
					} else if (!strcmp(tok, "front")) {
						free(tok);
						tok = popFIFO((sArray*)newVar);
						mtxNameLen = 20;
						matrixName = "gl_FrontLightProduct";
					} else if (!strcmp(tok, "back")) {
						free(tok);
						tok = popFIFO((sArray*)newVar);
						mtxNameLen = 19;
						matrixName = "gl_BackLightProduct";
					} else {
						mtxNameLen = 20;
						matrixName = "gl_FrontLightProduct";
					}
					
					if (!tok) {
						ARBCONV_DBG_RE(printf("Failed to get param: [%s][%s](tok NULL)\n", matrixName, sln);)
						return NULL;
					} else if (!strcmp(tok, "ambient")) {
						free(tok);
						propLen = 7;
						prop = "ambient";
					} else if (!strcmp(tok, "diffuse")) {
						free(tok);
						propLen = 7;
						prop = "diffuse";
					} else if (!strcmp(tok, "specular")) {
						free(tok);
						propLen = 8;
						prop = "specular";
					} else {
						ARBCONV_DBG_RE(printf("Failed to get param: [%s][%s].%s\n", matrixName, sln, tok);)
						free(tok);
						return NULL;
					}
					
					*outLen = mtxNameLen + propLen + 3 + strlen(sln);
					matrixNameMallocd = (char*)malloc((*outLen + 1) * sizeof(char));
					sprintf(matrixNameMallocd, "%s[%s].%s", matrixName, sln, prop);
					free(sln);
					return matrixNameMallocd;
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: state.lightprod.%s\n", sln);)
					free(sln);
					return NULL;
				}
			} else {
				ARBCONV_DBG_RE(printf("Failed to get param: state.lightprod(not [)\n");)
				return NULL;
			}
		} else if (!strcmp(tok, "matrix")) {
			isMatrix = 1;
			
			free(tok);
			tok = popFIFO((sArray*)newVar);
			
			if (!tok) {
				ARBCONV_DBG_RE(printf("Failed to get param: state.matrix(tok NULL)\n");)
				return NULL;
			} else if (!strcmp(tok, "modelview")) {
				free(tok);
				if (newVar->strLen && !IS_NEW_STR_OR_SWIZZLE(newVar->strParts[0], type)) {
					int mvmtx = 0;
					int mvmtxsz = 0;
					if (newVar->strParts[0][0] == '[') {
						free(popFIFO((sArray*)newVar));
						tok = popFIFO((sArray*)newVar);
						if ((tok[0] >= '0') && (tok[0] <= '9')) {
							for (char *numPtr = tok; *numPtr; ++numPtr) {
								++mvmtxsz;
								mvmtx = mvmtx * 10 + *numPtr - '0';
							}
						} else {
							ARBCONV_DBG_RE(printf("Failed to get param: state.modelview[(NaN)\n");)
							free(tok);
							return NULL;
						}
						free(tok);
						
						tok = popFIFO((sArray*)newVar);
						if (tok[0] != ']') {
							ARBCONV_DBG_RE(printf("Failed to get param: state.modelview[%d(not ])\n", mvmtx);)
							free(tok);
							return NULL;
						}
						free(tok);
						
						if (mvmtx != 0) {
							ARBCONV_DBG_RE(printf("Failed to get param: state.modelview[%d(!=0)]\n", mvmtx);)
						}
					}
					
					if (!strcmp(newVar->strParts[0], "invtrans")) {
						free(popFIFO((sArray*)newVar));
						matrixName = "gl_ModelViewMatrixInverseTranspose";
						mtxNameLen = 34;
					} else if (!strcmp(newVar->strParts[0], "inverse")) {
						free(popFIFO((sArray*)newVar));
						matrixName = "gl_ModelViewMatrixInverse";
						mtxNameLen = 25;
					} else if (!strcmp(newVar->strParts[0], "transpose")) {
						free(popFIFO((sArray*)newVar));
						matrixName = "gl_ModelViewMatrixTranspose";
						mtxNameLen = 27;
					} else {
						matrixName = "gl_ModelViewMatrix";
						mtxNameLen = 18;
					}
					
					if (newVar->strLen && !IS_NEW_STR_OR_SWIZZLE(newVar->strParts[0], type)) {
						tok = popFIFO((sArray*)newVar);
						if (!strcmp(tok, "row")
						 && newVar->strLen && (newVar->strParts[0][0] >= '0') && (newVar->strParts[0][0] <= '9')) {
							free(tok);
							tok = popFIFO((sArray*)newVar);
							for (char *numPtr = tok; *numPtr; ++numPtr) {
								start = start * 10 + *numPtr - '0';
							}
							free(tok);
							
							if ((newVar->strLen >= 3) && (newVar->strParts[0][0] == '.')
							 && (newVar->strParts[0][1] == '.')
							 && (newVar->strParts[1][0] >= '0') && (newVar->strParts[1][0] <= '9')) {
								end = 0;
								free(popFIFO((sArray*)newVar));
								tok = popFIFO((sArray*)newVar);
								for (char *numPtr = tok; *numPtr; ++numPtr) {
									end = end * 10 + *numPtr - '0';
								}
								free(tok);
							} else {
								end = start;
							}
						} else {
							ARBCONV_DBG_RE(printf("Failed to get param: [%s].%s\n", matrixName, tok);)
							free(tok);
							return NULL;
						}
					}
					
					if (mvmtxsz && mvmtx) {
						mtxNameLen += 2 + mvmtxsz;
						matrixNameMallocd = malloc((mtxNameLen + 1) * sizeof(char));
						sprintf(matrixNameMallocd, "%s", matrixName);
					}
				} else {
					matrixName = "gl_ModelViewMatrix";
					mtxNameLen = 18;
				}
			} else if (!strcmp(tok, "mvp")) {
				free(tok);
				if (newVar->strLen && !IS_NEW_STR_OR_SWIZZLE(newVar->strParts[0], type)) {
					if (!strcmp(newVar->strParts[0], "invtrans")) {
						free(popFIFO((sArray*)newVar));
						matrixName = "gl_ModelViewProjectionMatrixInverseTranspose";
						mtxNameLen = 44;
					} else if (!strcmp(newVar->strParts[0], "inverse")) {
						free(popFIFO((sArray*)newVar));
						matrixName = "gl_ModelViewProjectionMatrixInverse";
						mtxNameLen = 35;
					} else if (!strcmp(newVar->strParts[0], "transpose")) {
						free(popFIFO((sArray*)newVar));
						matrixName = "gl_ModelViewProjectionMatrixTranspose";
						mtxNameLen = 37;
					} else {
						matrixName = "gl_ModelViewProjectionMatrix";
						mtxNameLen = 28;
					}
					
					if (newVar->strLen && !IS_NEW_STR_OR_SWIZZLE(newVar->strParts[0], type)) {
						tok = popFIFO((sArray*)newVar);
						if (!strcmp(tok, "row")
						 && (newVar->strLen >= 3) && (newVar->strParts[0][0] == '[')
						 && (newVar->strParts[1][0] >= '0') && (newVar->strParts[1][0] <= '9')) {
							free(tok);
							free(popFIFO((sArray*)newVar));
							tok = popFIFO((sArray*)newVar);
							for (char *numPtr = tok; *numPtr; ++numPtr) {
								start = start * 10 + *numPtr - '0';
							}
							free(tok);
							
							if ((newVar->strLen >= 3) && (newVar->strParts[0][0] == '.')
							 && (newVar->strParts[0][1] == '.')
							 && (newVar->strParts[1][0] >= '0') && (newVar->strParts[1][0] <= '9')) {
								end = 0;
								free(popFIFO((sArray*)newVar));
								tok = popFIFO((sArray*)newVar);
								for (char *numPtr = tok; *numPtr; ++numPtr) {
									end = end * 10 + *numPtr - '0';
								}
								free(tok);
							} else {
								end = start;
							}
							
							tok = popFIFO((sArray*)newVar);
							if (tok[0] != ']') {
								ARBCONV_DBG_RE(printf("Failed to get param: [%s].row[%d..%d(not ])\n", matrixName, start, end);)
								free(tok);
								return NULL;
							}
							free(tok);
						} else {
							ARBCONV_DBG_RE(printf("Failed to get param: [%s].%s\n", matrixName, tok);)
							free(tok);
							return NULL;
						}
					}
				} else {
					matrixName = "gl_ModelViewProjectionMatrix";
					mtxNameLen = 28;
				}
			} else {
				ARBCONV_DBG_RE(printf("Failed to get param: state.matrix.%s\n", tok);)
				free(tok);
				return NULL;
			}
		} else {
			ARBCONV_DBG_RE(printf("Failed to get param: state.%s\n", tok);)
			free(tok);
			return NULL;
		}
	} else if (!strcmp(tok, "program")) {
		refuseEndGT4 = 0;
		free(tok);
		tok = popFIFO((sArray*)newVar);
		
		if (!tok) {
			ARBCONV_DBG_RE(printf("Failed to get param: program(tok NULL)\n");)
			return NULL;
		} else if (!strcmp(tok, "env")) {
			matrixName = "gl_ProgramEnv";
			mtxNameLen = 13;
			isMatrix = 1;
			
			free(tok);
			tok = popFIFO((sArray*)newVar);
			
			if (!tok) {
				ARBCONV_DBG_RE(printf("Failed to get param: program.env(tok NULL)\n");)
				return NULL;
			} else if (tok[0] == '[') {
				free(tok);
				tok = popFIFO((sArray*)newVar);
				if ((tok[0] >= '0') && (tok[0] <= '9')) {
					for (char *numPtr = tok; *numPtr; ++numPtr) {
						start = start * 10 + *numPtr - '0';
					}
					free(tok);
					
					if ((newVar->strLen >= 3) && (newVar->strParts[0][0] == '.') && (newVar->strParts[0][1] == '.')
					 && (newVar->strParts[1][0] >= '0') && (newVar->strParts[1][0] <= '9')) {
						end = 0;
						free(popFIFO((sArray*)newVar));
						tok = popFIFO((sArray*)newVar);
						for (char *numPtr = tok; *numPtr; ++numPtr) {
							end = end * 10 + *numPtr - '0';
						}
						free(tok);
					} else {
						end = start;
					}
					
					tok = popFIFO((sArray*)newVar);
					if (tok[0] != ']') {
						ARBCONV_DBG_RE(printf("Failed to get param: program.env[%d..%d(not ])\n", start, end);)
						free(tok);
						return NULL;
					}
					free(tok);
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: program.env[%s\n", tok);)
					free(tok);
					return NULL;
				}
			} else {
				ARBCONV_DBG_RE(printf("Failed to get param: program.env.%s\n", tok);)
				free(tok);
				return NULL;
			}
		} else if (!strcmp(tok, "local")) {
			matrixName = "gl_ProgramLocal";
			mtxNameLen = 15;
			isMatrix = 1;
			
			free(tok);
			tok = popFIFO((sArray*)newVar);
			
			if (!tok) {
				ARBCONV_DBG_RE(printf("Failed to get param: program.local(tok NULL)\n");)
				return NULL;
			} else if (tok[0] == '[') {
				free(tok);
				tok = popFIFO((sArray*)newVar);
				if ((tok[0] >= '0') && (tok[0] <= '9')) {
					for (char *numPtr = tok; *numPtr; ++numPtr) {
						start = start * 10 + *numPtr - '0';
					}
					free(tok);
					
					if ((newVar->strLen >= 3) && (newVar->strParts[0][0] == '.') && (newVar->strParts[0][1] == '.')
					 && (newVar->strParts[1][0] >= '0') && (newVar->strParts[1][0] <= '9')) {
						end = 0;
						free(popFIFO((sArray*)newVar));
						tok = popFIFO((sArray*)newVar);
						for (char *numPtr = tok; *numPtr; ++numPtr) {
							end = end * 10 + *numPtr - '0';
						}
						free(tok);
					} else {
						end = start;
					}
					
					tok = popFIFO((sArray*)newVar);
					if (tok[0] != ']') {
						ARBCONV_DBG_RE(printf("Failed to get param: program.local[%d..%d(not ])\n", start, end);)
						free(tok);
						return NULL;
					}
					free(tok);
				} else {
					ARBCONV_DBG_RE(printf("Failed to get param: program.local[%s\n", tok);)
					free(tok);
					return NULL;
				}
			} else {
				ARBCONV_DBG_RE(printf("Failed to get param: program.local.%s\n", tok);)
				free(tok);
				return NULL;
			}
		} else {
			ARBCONV_DBG_RE(printf("Failed to get param: program.%s\n", tok);)
			free(tok);
			return NULL;
		}
	} else if (tok[0] == '{') {
		sCurStatus pseudoSt;
		pseudoSt.curValue.newVar.state = 0;
		pseudoSt.status = ST_VARIABLE_INIT;
		pseudoSt.outputString = malloc(DEFAULT_STRING_MALLOC_SIZE);
		pseudoSt.outputString[0] = 'v';
		pseudoSt.outputString[1] = 'e';
		pseudoSt.outputString[2] = 'c';
		pseudoSt.outputString[3] = '4';
		pseudoSt.outputString[4] = '(';
		pseudoSt.outputString[5] = '\0';
		pseudoSt.outputEnd = pseudoSt.outputString + 5;
		pseudoSt.outLen = 5;
		pseudoSt.outCap = DEFAULT_STRING_CAP;
		pseudoSt.outLeft = DEFAULT_STRING_CAP - 6;
		
		do {
			free(tok);
			tok = popFIFO((sArray*)newVar);
			pseudoSt.endOfToken = tok; // Yes, this is weird...
			readNextToken(&pseudoSt);
			switch (pseudoSt.curToken) {
			case TOK_SIGN:
				if ((pseudoSt.curValue.newVar.state % 3) || appendString(&pseudoSt, pseudoSt.tokInt ? "+" : "-", 1)) {
					pseudoSt.status = ST_ERROR;
					continue;
				}
				
				++pseudoSt.curValue.newVar.state;
				break;
				
			case TOK_FLOATCONST:
				if (pseudoSt.curValue.newVar.state % 3 == 2) {
					pseudoSt.status = ST_ERROR;
					continue;
				}
				
				if (appendString(&pseudoSt, tok, (size_t)-1)) {
					free(tok);
					pseudoSt.status = ST_ERROR;
					continue;
				}
				pseudoSt.curValue.newVar.state = 3*(pseudoSt.curValue.newVar.state / 3) + 2;
				break;
				
			case TOK_COMMA:
				if ((pseudoSt.curValue.newVar.state % 3 != 2) || (pseudoSt.curValue.newVar.state > 8)) {
					pseudoSt.status = ST_ERROR;
					continue;
				}
				
				++pseudoSt.curValue.newVar.state;
				if (appendString(&pseudoSt, ", ", 2)) {
					pseudoSt.status = ST_ERROR;
					continue;
				}
				break;
				
			case TOK_RBRACE:
				if (pseudoSt.curValue.newVar.state % 3 != 2) {
					pseudoSt.status = ST_ERROR;
					continue;
				}
				break;
				
			case TOK_NULL:
			case TOK_WHITESPACE:
			case TOK_INTEGER:
			case TOK_IDENTIFIER:
			case TOK_POINT:
			case TOK_UPTO:
			case TOK_EQUALS:
			case TOK_LSQBRACKET:
			case TOK_RSQBRACKET:
			case TOK_LBRACE:
			case TOK_END_OF_INST:
			case TOK_LINE_COMMENT:
			case TOK_NEWLINE:
			case TOK_END:
			case TOK_UNKNOWN:
				pseudoSt.status = ST_ERROR;
				continue;
			}
		} while (tok && (pseudoSt.status != ST_ERROR) && (pseudoSt.curToken != TOK_RBRACE));
		free(tok);
		if (pseudoSt.status == ST_ERROR) {
			ARBCONV_DBG_RE(printf("Failed to get param: %s tok (%s))\n",
			 TOKEN2STR(pseudoSt.curToken), pseudoSt.outputString);)
			free(pseudoSt.outputString);
			return NULL;
		}
		
		if (appendString(&pseudoSt, ")", 1)) {
			free(pseudoSt.outputString);
			ARBCONV_DBG_RE(printf("Failed to get param: not enough memory?\n");)
			return NULL;
		}
		
		*outLen = pseudoSt.outLen;
		return pseudoSt.outputString;
	} else {
		ARBCONV_DBG_RE(printf("Failed to get param: %s\n", tok);)
		free(tok);
		return NULL;
	}
	/* TODO:
	 * <paramSingleItemDecl>
	 \ V "state" "." "material" "." "ambient"
	 \ V "state" "." "material" "." "diffuse"
	 \ V "state" "." "material" "." "specular"
	 \ V "state" "." "material" "." "emission"
	 \ V "state" "." "material" "." "shininess"
	 \ V "state" "." "material" "." "front" "." "ambient"
	 \ V "state" "." "material" "." "front" "." "diffuse"
	 \ V "state" "." "material" "." "front" "." "specular"
	 \ V "state" "." "material" "." "front" "." "emission"
	 \ V "state" "." "material" "." "front" "." "shininess"
	 \ V "state" "." "material" "." "back" "." "ambient"
	 \ V "state" "." "material" "." "back" "." "diffuse"
	 \ V "state" "." "material" "." "back" "." "specular"
	 \ V "state" "." "material" "." "back" "." "emission"
	 \ V "state" "." "material" "." "back" "." "shininess"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "diffuse" 
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "position"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "attenuation"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "spot" "." "direction"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "half"
	 \ V "state" "." "lightmodel" "." "ambient"
	 \ V "state" "." "lightmodel" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "front" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "back" "." "scenecolor"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "specular"
	 \ ! "state" "." "texgen" "." "eye" "." "s"
	 \ ! "state" "." "texgen" "." "eye" "." "t"
	 \ ! "state" "." "texgen" "." "eye" "." "r"
	 \ ! "state" "." "texgen" "." "eye" "." "q"
	 \ ! "state" "." "texgen" "." "object" "." "s"
	 \ ! "state" "." "texgen" "." "object" "." "t"
	 \ ! "state" "." "texgen" "." "object" "." "r"
	 \ ! "state" "." "texgen" "." "object" "." "q"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "s"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "t"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "r"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "q"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "s"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "t"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "r"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "q"
	 \ * "state" "." "fog" "." "color"
	 \ * "state" "." "fog" "." "params"
	 \ ! "state" "." "clip" "[" <stateClipPlaneNum> "]" "." "plane"
	 \ ! "state" "." "point" "." "size"
	 \ ! "state" "." "point" "." "attenuation"
	 \ V "state" "." "matrix" "." "modelview" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "program" "." "env" "[" <progEnvParamNum> "]"
	 \ V "program" "." "local" "[" <progLocalParamNum> "]"
	 \ * <optionalSign> <floatConstant>
	 \ V "{" <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 * ---
	 * <paramSingleItemUse>
	 \ V "state" "." "material" "." "ambient"
	 \ V "state" "." "material" "." "diffuse"
	 \ V "state" "." "material" "." "specular"
	 \ V "state" "." "material" "." "emission"
	 \ V "state" "." "material" "." "shininess"
	 \ V "state" "." "material" "." "front" "." "ambient"
	 \ V "state" "." "material" "." "front" "." "diffuse"
	 \ V "state" "." "material" "." "front" "." "specular"
	 \ V "state" "." "material" "." "front" "." "emission"
	 \ V "state" "." "material" "." "front" "." "shininess"
	 \ V "state" "." "material" "." "back" "." "ambient"
	 \ V "state" "." "material" "." "back" "." "diffuse"
	 \ V "state" "." "material" "." "back" "." "specular"
	 \ V "state" "." "material" "." "back" "." "emission"
	 \ V "state" "." "material" "." "back" "." "shininess"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "diffuse" 
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "position"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "attenuation"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "spot" "." "direction"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "half"
	 \ V "state" "." "lightmodel" "." "ambient"
	 \ V "state" "." "lightmodel" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "front" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "back" "." "scenecolor"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "specular"
	 \ ! "state" "." "texgen" "." "eye" "." "s"
	 \ ! "state" "." "texgen" "." "eye" "." "t"
	 \ ! "state" "." "texgen" "." "eye" "." "r"
	 \ ! "state" "." "texgen" "." "eye" "." "q"
	 \ ! "state" "." "texgen" "." "object" "." "s"
	 \ ! "state" "." "texgen" "." "object" "." "t"
	 \ ! "state" "." "texgen" "." "object" "." "r"
	 \ ! "state" "." "texgen" "." "object" "." "q"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "s"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "t"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "r"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "q"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "s"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "t"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "r"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "q"
	 \ * "state" "." "fog" "." "color"
	 \ * "state" "." "fog" "." "params"
	 \ ! "state" "." "clip" "[" <stateClipPlaneNum> "]" "." "plane"
	 \ ! "state" "." "point" "." "size"
	 \ ! "state" "." "point" "." "attenuation"
	 \ V "state" "." "matrix" "." "modelview" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "program" "." "env" "[" <progEnvParamNum> "]"
	 \ V "program" "." "local" "[" <progLocalParamNum> "]"
	 \ * <floatConstant>
	 \ V "{" <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 * ---
	 * <paramMultipleItem>
	 \ V "state" "." "material" "." "ambient"
	 \ V "state" "." "material" "." "diffuse"
	 \ V "state" "." "material" "." "specular"
	 \ V "state" "." "material" "." "emission"
	 \ V "state" "." "material" "." "shininess"
	 \ V "state" "." "material" "." "front" "." "ambient"
	 \ V "state" "." "material" "." "front" "." "diffuse"
	 \ V "state" "." "material" "." "front" "." "specular"
	 \ V "state" "." "material" "." "front" "." "emission"
	 \ V "state" "." "material" "." "front" "." "shininess"
	 \ V "state" "." "material" "." "back" "." "ambient"
	 \ V "state" "." "material" "." "back" "." "diffuse"
	 \ V "state" "." "material" "." "back" "." "specular"
	 \ V "state" "." "material" "." "back" "." "emission"
	 \ V "state" "." "material" "." "back" "." "shininess"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "diffuse" 
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "position"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "attenuation"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "spot" "." "direction"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "half"
	 \ V "state" "." "lightmodel" "." "ambient"
	 \ V "state" "." "lightmodel" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "front" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "back" "." "scenecolor"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "specular"
	 \ ! "state" "." "texgen" "." "eye" "." "s"
	 \ ! "state" "." "texgen" "." "eye" "." "t"
	 \ ! "state" "." "texgen" "." "eye" "." "r"
	 \ ! "state" "." "texgen" "." "eye" "." "q"
	 \ ! "state" "." "texgen" "." "object" "." "s"
	 \ ! "state" "." "texgen" "." "object" "." "t"
	 \ ! "state" "." "texgen" "." "object" "." "r"
	 \ ! "state" "." "texgen" "." "object" "." "q"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "s"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "t"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "r"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "eye" "." "q"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "s"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "t"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "r"
	 \ ! "state" "." "texgen" "[" <texCoordNum> "]" "." "object" "." "q"
	 \ * "state" "." "fog" "." "color"
	 \ * "state" "." "fog" "." "params"
	 \ ! "state" "." "clip" "[" <stateClipPlaneNum> "]" "." "plane"
	 \ ! "state" "." "point" "." "size"
	 \ ! "state" "." "point" "." "attenuation"
	 \ V "state" "." "matrix" "." "modelview" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans"
	 \ V "state" "." "matrix" "." "modelview" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection"
	 \ * "state" "." "matrix" "." "projection" "." "inverse"
	 \ * "state" "." "matrix" "." "projection" "." "transpose"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans"
	 \ * "state" "." "matrix" "." "projection" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans"
	 \ V "state" "." "matrix" "." "mvp" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans"
	 \ ? "state" "." "matrix" "." "texture" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "program" "." "env" "[" <progEnvParamNum> "]"
	 \ V "program" "." "env" "[" <progEnvParamNum> ".." <progEnvParamNum> "]"
	 \ V "program" "." "local" "[" <progLocalParamNum> "]"
	 \ V "program" "." "local" "[" <progLocalParamNum> ".." <progLocalParamNum> "]"
	 \ * <optionalSign> <floatConstant>
	 \ V "{" <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 * ---
	 * <optionalSign>
	 \ * ""
	 \ * "-"
	 \ * "+"
	 * ---
	 * <stateLightNumber>
	 \ * <integer> from 0 to MAX_LIGHTS-1
	 * ---
	 * <stateClipPlaneNum>
	 \ * <integer> from 0 to MAX_CLIP_PLANES-1
	 * ---
	 * <stateMatrixRowNum>
	 \ * <integer> from 0 to 3
	 * ---
	 * <stateModMatNum>
	 \ * <integer> from 0 to MAX_VERTEX_UNITS_ARB-1
	 * ---
	 * <statePaletteMatNum>
	 \ * <integer> from 0 to MAX_PALETTE_MATRICES_ARB-1
	 * ---
	 * <stateProgramMatNum>
	 \ * <integer> from 0 to MAX_PROGRAM_MATRICES_ARB-1
	 * ---
	 * <progEnvParamNum>
	 \ * <integer> from 0 to MAX_PROGRAM_ENV_PARAMETERS_ARB - 1
	 * ---
	 * <progLocalParamNum>
	 \ * <integer> from 0 to MAX_PROGRAM_LOCAL_PARAMETERS_ARB - 1
	 * 
	 * ==========================================================
	 * 
	 * <paramSingleItemDecl>
	 \ V "state" "." "material" "." "ambient"
	 \ V "state" "." "material" "." "diffuse"
	 \ V "state" "." "material" "." "specular"
	 \ V "state" "." "material" "." "emission"
	 \ V "state" "." "material" "." "shininess"
	 \ V "state" "." "material" "." "front" "." "ambient"
	 \ V "state" "." "material" "." "front" "." "diffuse"
	 \ V "state" "." "material" "." "front" "." "specular"
	 \ V "state" "." "material" "." "front" "." "emission"
	 \ V "state" "." "material" "." "front" "." "shininess"
	 \ V "state" "." "material" "." "back" "." "ambient"
	 \ V "state" "." "material" "." "back" "." "diffuse"
	 \ V "state" "." "material" "." "back" "." "specular"
	 \ V "state" "." "material" "." "back" "." "emission"
	 \ V "state" "." "material" "." "back" "." "shininess"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "diffuse" 
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "position"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "attenuation"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "spot" "." "direction"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "half"
	 \ V "state" "." "lightmodel" "." "ambient"
	 \ V "state" "." "lightmodel" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "front" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "back" "." "scenecolor"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "specular"
	 \ ! "state" "." "texenv" "." "color"
	 \ ! "state" "." "texenv" "[" <legacyTexUnitNum> "]" "." "color"
	 \ * "state" "." "fog" "." "color"
	 \ * "state" "." "fog" "." "params"
	 \ ! "state" "." "depth" "." "range"
	 \ V "state" "." "matrix" "." "modelview" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "program" "." "env" "[" <progEnvParamNum> "]"
	 \ V "program" "." "local" "[" <progLocalParamNum> "]"
	 \ * <optionalSign> <floatConstant>
	 \ V "{" <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 * ---
	 * <paramSingleItemUse>
	 \ V "state" "." "material" "." "ambient"
	 \ V "state" "." "material" "." "diffuse"
	 \ V "state" "." "material" "." "specular"
	 \ V "state" "." "material" "." "emission"
	 \ V "state" "." "material" "." "shininess"
	 \ V "state" "." "material" "." "front" "." "ambient"
	 \ V "state" "." "material" "." "front" "." "diffuse"
	 \ V "state" "." "material" "." "front" "." "specular"
	 \ V "state" "." "material" "." "front" "." "emission"
	 \ V "state" "." "material" "." "front" "." "shininess"
	 \ V "state" "." "material" "." "back" "." "ambient"
	 \ V "state" "." "material" "." "back" "." "diffuse"
	 \ V "state" "." "material" "." "back" "." "specular"
	 \ V "state" "." "material" "." "back" "." "emission"
	 \ V "state" "." "material" "." "back" "." "shininess"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "diffuse" 
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "position"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "attenuation"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "spot" "." "direction"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "half"
	 \ V "state" "." "lightmodel" "." "ambient"
	 \ V "state" "." "lightmodel" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "front" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "back" "." "scenecolor"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "specular"
	 \ ! "state" "." "texenv" "." "color"
	 \ ! "state" "." "texenv" "[" <legacyTexUnitNum> "]" "." "color"
	 \ * "state" "." "fog" "." "color"
	 \ * "state" "." "fog" "." "params"
	 \ ! "state" "." "depth" "." "range"
	 \ V "state" "." "matrix" "." "modelview" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "program" "." "env" "[" <progEnvParamNum> "]"
	 \ V "program" "." "local" "[" <progLocalParamNum> "]"
	 \ * <floatConstant>
	 \ V "{" <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 * ---
	 * <paramMultipleItem>
	 \ V "state" "." "material" "." "ambient"
	 \ V "state" "." "material" "." "diffuse"
	 \ V "state" "." "material" "." "specular"
	 \ V "state" "." "material" "." "emission"
	 \ V "state" "." "material" "." "shininess"
	 \ V "state" "." "material" "." "front" "." "ambient"
	 \ V "state" "." "material" "." "front" "." "diffuse"
	 \ V "state" "." "material" "." "front" "." "specular"
	 \ V "state" "." "material" "." "front" "." "emission"
	 \ V "state" "." "material" "." "front" "." "shininess"
	 \ V "state" "." "material" "." "back" "." "ambient"
	 \ V "state" "." "material" "." "back" "." "diffuse"
	 \ V "state" "." "material" "." "back" "." "specular"
	 \ V "state" "." "material" "." "back" "." "emission"
	 \ V "state" "." "material" "." "back" "." "shininess"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "diffuse" 
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "position"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "attenuation"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "spot" "." "direction"
	 \ V "state" "." "light" "[" <stateLightNumber> "]" "." "half"
	 \ V "state" "." "lightmodel" "." "ambient"
	 \ V "state" "." "lightmodel" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "front" "." "scenecolor"
	 \ V "state" "." "lightmodel" "." "back" "." "scenecolor"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "front" "." "specular"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "ambient"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "diffuse"
	 \ V "state" "." "lightprod" "[" <stateLightNumber> "]" "." "back" "." "specular"
	 \ ! "state" "." "texenv" "." "color"
	 \ ! "state" "." "texenv" "[" <legacyTexUnitNum> "]" "." "color"
	 \ * "state" "." "fog" "." "color"
	 \ * "state" "." "fog" "." "params"
	 \ ! "state" "." "depth" "." "range"
	 \ V "state" "." "matrix" "." "modelview" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans"
	 \ V "state" "." "matrix" "." "modelview" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "modelview" "[" <stateModMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection"
	 \ * "state" "." "matrix" "." "projection" "." "inverse"
	 \ * "state" "." "matrix" "." "projection" "." "transpose"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans"
	 \ * "state" "." "matrix" "." "projection" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ * "state" "." "matrix" "." "projection" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans"
	 \ V "state" "." "matrix" "." "mvp" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "state" "." "matrix" "." "mvp" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans"
	 \ ? "state" "." "matrix" "." "texture" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "texture" "[" <texCoordNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "palette" "[" <statePaletteMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "inverse" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "transpose" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ ? "state" "." "matrix" "." "program" "[" <stateProgramMatNum> "]" "." "invtrans" "." "row" "[" <stateMatrixRowNum> ".." <stateMatrixRowNum> "]"
	 \ V "program" "." "env" "[" <progEnvParamNum> "]"
	 \ V "program" "." "env" "[" <progEnvParamNum> ".." <progEnvParamNum> "]"
	 \ V "program" "." "local" "[" <progLocalParamNum> "]"
	 \ V "program" "." "local" "[" <progLocalParamNum> ".." <progLocalParamNum> "]"
	 \ * <optionalSign> <floatConstant>
	 \ V "{" <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 \ V "{" <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "," <optionalSign> <floatConstant> "}"
	 * ---
	 * <optionalSign>
	 \ * ""
	 \ * "-"
	 \ * "+"
	 * ---
	 * <stateLightNumber>
	 \ * <integer> from 0 to MAX_LIGHTS-1
	 * ---
	 * <legacyTexUnitNum>
	 \ * <integer> from 0 to MAX_TEXTURE_UNITS-1
	 * ---
	 * <stateMatrixRowNum>
	 \ * <integer> from 0 to 3
	 * ---
	 * <stateModMatNum>
	 \ * <integer> from 0 to MAX_VERTEX_UNITS_ARB-1
	 * ---
	 * <texCoordNum>
	 \ * <integer> from 0 to MAX_TEXTURE_COORDS_ARB-1
	 * ---
	 * <statePaletteMatNum>
	 \ * <integer> from 0 to MAX_PALETTE_MATRICES_ARB-1
	 * ---
	 * <stateProgramMatNum>
	 \ * <integer> from 0 to MAX_PROGRAM_MATRICES_ARB-1
	 * ---
	 * <progEnvParamNum>
	 \ * <integer> from 0 to MAX_PROGRAM_ENV_PARAMETERS_ARB - 1 
	 * ---
	 * <progLocalParamNum>
	 \ * <integer> from 0 to MAX_PROGRAM_LOCAL_PARAMETERS_ARB - 1 
	 */
	
	if (isMatrix) {
		if ((start > end) || ((end > 3) && refuseEndGT4)) {
			ARBCONV_DBG_RE(printf("Failed to get param: [%s] (se)\n", matrixNameMallocd?matrixNameMallocd:matrixName);)
			if (matrixNameMallocd) free(matrixNameMallocd);
			return NULL;
		}
		
		if (((type == 0) || (type == 1)) && (start != end)) {
			// type = 0 and 1 are paramSingleItem*
			ARBCONV_DBG_RE(printf("Failed to get param: [%s] (t)\n", matrixNameMallocd?matrixNameMallocd:matrixName);)
			if (matrixNameMallocd) free(matrixNameMallocd);
			return NULL;
		}
		
		if (matrixNameMallocd) {
			matrixName = matrixNameMallocd;
		}
		*outLen = (mtxNameLen + 4) * (end - start + 1) - 2;
		size_t maxLen = mtxNameLen + 5;
		for (int i = start; i <= end; ++i) {
			++*outLen;
			for (int j = i / 10; j; j /= 10) ++*outLen;
		}
		for (int j = end / 10; j; j /= 10) ++maxLen;
		
		char *ret = (char*)malloc((*outLen + 1) * sizeof(char));
		sprintf(ret, "%s[%d]", matrixName, start);
		
		char *buf = (char*)malloc((maxLen + 1) * sizeof(char));
		for (int i = start + 1; i <= end; ++i) {
			sprintf(buf, ", %s[%d]", matrixName, i);
			strcat(ret, buf);
		}
		free(buf);
		
		if (matrixNameMallocd) {
			free(matrixNameMallocd);
		}
		
		return ret;
	}
	
	return (char*)0xFFFFFFFFU; // Unreachable
}

char* gl4es_convertARB(const char* const code, int vertex, glsl_t *glsl) {
	glsl->error_ptr = -1; // Reinit error pointer
	
	const char *codeStart = code;
	if ((codeStart[0] != '!') || (codeStart[1] != '!')) {
		while (1) {
			while ((*codeStart != '!') && (*codeStart != '\0')) {
				++codeStart;
			}
			if (*codeStart == '\0') {
				// Invalid start
				if (glsl->error_msg)
					free(glsl->error_msg);
				glsl->error_msg = strdup("Invalid program start");
				glsl->error_ptr = 0;
				return NULL;
			}
			if ((codeStart[0] == '!') && (codeStart[1] == '!')) {
				break;
			}
			++codeStart;
		}
	}
	if (vertex) {
		if (strncmp(codeStart, "!!ARBvp1.0", 10)) {
			if (glsl->error_msg)
				free(glsl->error_msg);
			glsl->error_msg = strdup("Invalid program start");
			glsl->error_ptr = codeStart - code;
			return NULL;
		}
	} else {
		if (strncmp(codeStart, "!!ARBfp1.0", 10)) {
			if (glsl->error_msg)
				free(glsl->error_msg);
			glsl->error_msg = strdup("Invalid program start");
			glsl->error_ptr = codeStart - code;
			return NULL;
		}
	}
	
	codeStart += 10;
	
	sCurStatus curStatus;
	initStatus(&curStatus, codeStart);
	if (curStatus.curToken != TOK_NEWLINE) {
		curStatus.status = ST_ERROR;
	} else {
		readNextToken(&curStatus);
	}
	
#define FAIL(str) curStatus.status = ST_ERROR; if (glsl->error_msg) free(glsl->error_msg); \
		glsl->error_msg = strdup(str); continue
	// TODO: replace '$' in variable names with something else that is also valid in GLSL
	while ((curStatus.status != ST_ERROR) && (curStatus.status != ST_DONE)) {
		ARBCONV_DBG_LP(
			printf(
				"%-13s",
				STATUS2STR(curStatus.status)
			);
			if (curStatus.valueType == TYPE_INST_DECL) {
				printf(
					"-%3s%4s    (%2d)",
					INST2STR(curStatus.curValue.newInst.inst.type),
					curStatus.curValue.newInst.inst.saturated ? "_SAT" : "    ",
					curStatus.curValue.newInst.state
				);
			} else if (curStatus.valueType == TYPE_VARIABLE_DECL) {
				printf(
					"-%-10s (%2d)",
					VARTYPE2STR(curStatus.curValue.newVar.var->type),
					curStatus.curValue.newVar.state
				);
			} else if (curStatus.valueType == TYPE_ALIAS_DECL) {
				printf("-(string)       ");
			} else if (curStatus.valueType == TYPE_OPTION_DECL) {
				printf("-%15s", curStatus.curValue.newOpt.optName ? curStatus.curValue.newOpt.optName : "");
			} else {
				printf("                ");
			}
			printf(" / %-11s: %p - %p (%ld)\n",
				TOKEN2STR(curStatus.curToken),
				curStatus.codePtr,
				curStatus.endOfToken,
				curStatus.endOfToken - curStatus.codePtr
			);
			fflush(stdout);
		)
		
		if (((curStatus.curToken == TOK_UNKNOWN) && (curStatus.status != ST_LINE_COMMENT))
		 || (curStatus.curToken == TOK_NULL)) {
			FAIL("Unknown token");
		}
		
		switch (curStatus.status) {
		case ST_LINE_START:
			switch (curStatus.curToken) {
			case TOK_IDENTIFIER: {
				char *tok = getToken(&curStatus);
				eInstruction inst;
				eVariableType vtype;
				if ((inst = STR2INST(tok, &curStatus.curValue.newInst.inst.saturated)) != INST_UNK) {
					if (vertex && curStatus.curValue.newInst.inst.saturated) {
						FAIL("Instruction cannot be saturated in ARB vertex shaders");
					}
					curStatus.status = ST_INSTRUCTION;
					curStatus.valueType = TYPE_INST_DECL;
					curStatus.curValue.newInst.curArg = 0;
					curStatus.curValue.newInst.state = 0;
					curStatus.curValue.newInst.inst.type = inst;
					for (int i = 0; i < MAX_OPERANDS; ++i) {
						curStatus.curValue.newInst.inst.vars[i].var = NULL;
						curStatus.curValue.newInst.inst.vars[i].floatArrAddr = -1;
						curStatus.curValue.newInst.inst.vars[i].sign = 0;
						curStatus.curValue.newInst.inst.vars[i].swizzle[0] = SWIZ_NONE;
						curStatus.curValue.newInst.inst.vars[i].swizzle[1] = SWIZ_NONE;
						curStatus.curValue.newInst.inst.vars[i].swizzle[2] = SWIZ_NONE;
						curStatus.curValue.newInst.inst.vars[i].swizzle[3] = SWIZ_NONE;
					}
					curStatus.curValue.newInst.inst.codeLocation = curStatus.codePtr;
				} else if ((vtype = STR2VARTYPE(tok)) != VARTYPE_UNK) {
					if (vtype == VARTYPE_ALIAS) {
						curStatus.status = ST_ALIAS;
						curStatus.valueType = TYPE_ALIAS_DECL;
						curStatus.curValue.string = NULL;
					} else {
						curStatus.status = ST_VARIABLE;
						curStatus.valueType = TYPE_VARIABLE_DECL;
						curStatus.curValue.newVar.var = createVariable(vtype);
						curStatus.curValue.newVar.state = 0;
						if ((vtype != VARTYPE_ADDRESS) && (vtype != VARTYPE_TEMP)) {
							initArray((sArray*)&curStatus.curValue.newVar);
						}
					}
				} else if (!strcmp(tok, "OPTION")) {
					curStatus.status = ST_OPTION;
					curStatus.valueType = TYPE_OPTION_DECL;
					curStatus.curValue.newOpt.optName = NULL;
				} else {
					free(tok);
					FAIL("Unknown operand");
				}
				free(tok);
				break; }
				
			case TOK_LINE_COMMENT:
				curStatus.status = ST_LINE_COMMENT;
				break;
				
			case TOK_WHITESPACE:
			case TOK_NEWLINE:
				curStatus.status = ST_LINE_START;
				break;
				
			case TOK_END:
				curStatus.status = ST_DONE;
				continue;
				
			default:
				FAIL("Invalid token");
			}
			break;
			
		case ST_LINE_COMMENT:
			if (curStatus.curToken == TOK_NEWLINE) {
				curStatus.status = ST_LINE_START;
			}
			break;
			
		case ST_VARIABLE:
			switch (curStatus.curValue.newVar.var->type) {
			case VARTYPE_ADDRESS:
			case VARTYPE_TEMP:
				switch (curStatus.curToken) {
				case TOK_IDENTIFIER: {
					if (curStatus.curValue.newVar.state != 0) {
						// Already identified
						FAIL("Invalid state");
					}
					
					char *tok = getToken(&curStatus);
					if (kh_str_exist(curStatus.varsMap, tok)) {
						// Identifier already exists
						free(tok);
						FAIL("Cannot redefine variable");
					}
					pushArray((sArray*)curStatus.curValue.newVar.var, tok);
					curStatus.curValue.newVar.state = 1;
					break; }
					
				case TOK_COMMA: {
					if (curStatus.curValue.newVar.state != 1) {
						FAIL("Invalid state");
					}
					
					int ret;
					uint32_t varIdx = kh_put(
						variables,
						curStatus.varsMap,
						curStatus.curValue.newVar.var->names[0],
						&ret
					);
					if (ret < 0) {
						FAIL("Unknown error");
					}
					kh_val(curStatus.varsMap, varIdx) = curStatus.curValue.newVar.var;
					pushArray((sArray*)&curStatus.variables, curStatus.curValue.newVar.var);
					curStatus.curValue.newVar.var = createVariable(curStatus.curValue.newVar.var->type);
					curStatus.curValue.newVar.state = 0;
					break; }
					
				case TOK_END_OF_INST: {
					if (curStatus.curValue.newVar.state != 1) {
						FAIL("Invalid state");
					}
					
					int ret;
					uint32_t varIdx = kh_put(
						variables,
						curStatus.varsMap,
						curStatus.curValue.newVar.var->names[0],
						&ret
					);
					if (ret < 0) {
						FAIL("Unknown error");
					}
					kh_val(curStatus.varsMap, varIdx) = curStatus.curValue.newVar.var;
					pushArray((sArray*)&curStatus.variables, curStatus.curValue.newVar.var);
					curStatus.valueType = TYPE_NONE;
					curStatus.status = ST_LINE_START;
					break; }
					
				case TOK_WHITESPACE:
				case TOK_NEWLINE:
					break;
					
				default:
					FAIL("Invalid token");
				}
				break;
				
			case VARTYPE_ATTRIB:
			case VARTYPE_OUTPUT:
			case VARTYPE_PARAM:
				switch (curStatus.curToken) {
				case TOK_IDENTIFIER: {
					if (curStatus.curValue.newVar.state != 0) {
						// Already identified
						FAIL("Invalid state");
					}
					
					char *tok = getToken(&curStatus);
					if (kh_str_exist(curStatus.varsMap, tok)) {
						// Identifier already exists
						free(tok);
						FAIL("Cannot redefine variable");
					}
					pushArray((sArray*)curStatus.curValue.newVar.var, tok);
					curStatus.curValue.newVar.state = 1;
					break; }
					
				case TOK_EQUALS:
					if (curStatus.curValue.newVar.state != 1) {
						FAIL("Invalid state");
					}
					
					curStatus.status = ST_VARIABLE_INIT;
					curStatus.curValue.newVar.state = 0;
					break;
					
				case TOK_WHITESPACE:
				case TOK_NEWLINE:
					break;
					
				case TOK_LSQBRACKET:
					if (curStatus.curValue.newVar.var->type == VARTYPE_PARAM) {
						if (curStatus.curValue.newVar.state != 1) {
							FAIL("Invalid state");
						}
						
						curStatus.curValue.newVar.var->type = VARTYPE_PARAM_MULT;
						pushArray((sArray*)&curStatus.curValue.newVar, strdup(","));
						curStatus.curValue.newVar.state = 0;
						break;
					}
					
					/* FALLTHROUGH */
				default:
					FAIL("Invalid token");
				}
				break;
				
			case VARTYPE_PARAM_MULT:
				switch (curStatus.curToken) {
				case TOK_INTEGER:
					if (curStatus.curValue.newVar.state != 0) {
						FAIL("Invalid state");
					}
					
					curStatus.curValue.newVar.var->size = curStatus.tokInt;
					curStatus.curValue.newVar.state = 1;
					break;
					
				case TOK_EQUALS:
					if (curStatus.curValue.newVar.state != 2) {
						FAIL("Invalid state");
					}
					
					curStatus.status = ST_VARIABLE_INIT;
					curStatus.curValue.newVar.state = 0;
					break;
					
				case TOK_WHITESPACE:
				case TOK_NEWLINE:
					break;
					
				case TOK_RSQBRACKET:
					if (curStatus.curValue.newVar.state == 2) {
						FAIL("Invalid state");
					}
					
					curStatus.curValue.newVar.state = 2;
					
					break;
					
				default:
					FAIL("Invalid token");
				}
				break;
				
			case VARTYPE_ALIAS:
			case VARTYPE_CONST:
			case VARTYPE_TEXTURE:
			case VARTYPE_TEXTARGET:
			case VARTYPE_UNK:
				// Cannot happen (fallthrough?)
				FAIL("Unknown error (unintended fallthrough?)");
			}
			break;
		case ST_VARIABLE_INIT:
			switch (curStatus.curValue.newVar.var->type) {
			case VARTYPE_ATTRIB:
				switch (curStatus.curToken) {
				case TOK_IDENTIFIER: {
					if (curStatus.curValue.newVar.state != 0) {
						FAIL("Invalid state");
					}
					
					char *tok = getToken(&curStatus);
					pushArray((sArray*)&curStatus.curValue.newVar, tok);
					
					curStatus.curValue.newVar.state = 1;
					
					break; }
					
				case TOK_POINT:
					if (curStatus.curValue.newVar.state == 0) {
						FAIL("Invalid state");
					}
					curStatus.curValue.newVar.state = 0;
					break;
					
				case TOK_END_OF_INST: {
					char *tok = NULL;
					
					if (curStatus.curValue.newVar.state != 1) {
						FAIL("Invalid state");
					}
					
					if (resolveAttrib(&curStatus.curValue.newVar, vertex)) {
						FAIL("Not a valid attribute");
					}
					
					if ((tok = popFIFO((sArray*)&curStatus.curValue.newVar))) {
						free(tok);
						FAIL("Not a valid attribute");
					}
					
					int ret;
					uint32_t varIdx = kh_put(
						variables,
						curStatus.varsMap,
						curStatus.curValue.newVar.var->names[0],
						&ret
					);
					if (ret < 0) {
						FAIL("Unknown error");
					}
					kh_val(curStatus.varsMap, varIdx) = curStatus.curValue.newVar.var;
					pushArray((sArray*)&curStatus.variables, curStatus.curValue.newVar.var);
					freeArray((sArray*)&curStatus.curValue.newVar);
					curStatus.valueType = TYPE_NONE;
					curStatus.status = ST_LINE_START;
					
					break; }
					
				case TOK_WHITESPACE:
				case TOK_NEWLINE:
					break;
					
				default:
					FAIL("Invalid token");
				}
				break;
				
			case VARTYPE_OUTPUT:
				switch (curStatus.curToken) {
				case TOK_IDENTIFIER: {
					if (curStatus.curValue.newVar.state != 0) {
						FAIL("Invalid state");
					}
					
					char *tok = getToken(&curStatus);
					pushArray((sArray*)&curStatus.curValue.newVar, tok);
					
					curStatus.curValue.newVar.state = 1;
					
					break; }
					
				case TOK_POINT:
					if (curStatus.curValue.newVar.state == 0) {
						FAIL("Invalid state");
					}
					curStatus.curValue.newVar.state = 0;
					break;
					
				case TOK_END_OF_INST: {
					char *tok = NULL;
					
					if (curStatus.curValue.newVar.state != 1) {
						FAIL("Invalid state");
					}
					
					if (resolveOutput(&curStatus.curValue.newVar, vertex)) {
						FAIL("Not a valid output");
					}
					
					if ((tok = popFIFO((sArray*)&curStatus.curValue.newVar))) {
						free(tok);
						FAIL("Not a valid output");
					}
					
					int ret;
					uint32_t varIdx = kh_put(
						variables,
						curStatus.varsMap,
						curStatus.curValue.newVar.var->names[0],
						&ret
					);
					if (ret < 0) {
						FAIL("Unknown error");
					}
					kh_val(curStatus.varsMap, varIdx) = curStatus.curValue.newVar.var;
					pushArray((sArray*)&curStatus.variables, curStatus.curValue.newVar.var);
					freeArray((sArray*)&curStatus.curValue.newVar);
					curStatus.valueType = TYPE_NONE;
					curStatus.status = ST_LINE_START;
					
					break; }
					
				case TOK_WHITESPACE:
				case TOK_NEWLINE:
					break;
					
				default:
					FAIL("Invalid token");
				}
				break;
				
			case VARTYPE_PARAM:
				switch (curStatus.curToken) {
				case TOK_INTEGER:
					/* ...
					if (curStatus.curValue.newVar.state != 2) {
						FAIL("Invalid state");
					} */
					if ((curStatus.curValue.newVar.state < 2) || (curStatus.curValue.newVar.state > 10)
					 || (curStatus.curValue.newVar.state % 2)) {
						FAIL("Invalid state");
					}
					
					if (curStatus.curValue.newVar.state > 2) {
						size_t tokLen = getTokenLength(&curStatus);
						char *tok = (char*)malloc((tokLen + 2) * sizeof(char));
						copyToken(&curStatus, tok);
						tok[tokLen] = '.';
						tok[tokLen + 1] = '\0';
						pushArray((sArray*)&curStatus.curValue.newVar, tok);
						++curStatus.curValue.newVar.state;
					} else {
						pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
						curStatus.curValue.newVar.state = 3;
					}
					break;
					
				case TOK_FLOATCONST:
					if ((curStatus.curValue.newVar.state < 4) || (curStatus.curValue.newVar.state > 10)
					 || (curStatus.curValue.newVar.state % 2)) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					++curStatus.curValue.newVar.state;
					break;
					
				case TOK_IDENTIFIER:
					if (curStatus.curValue.newVar.state != 0) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 1;
					break;
					
				case TOK_POINT:
					if (curStatus.curValue.newVar.state != 1) {
						FAIL("Invalid state");
					}
					
					curStatus.curValue.newVar.state = 0;
					break;
					
				case TOK_COMMA:
					if ((curStatus.curValue.newVar.state < 5) || (curStatus.curValue.newVar.state > 9)
					 || !(curStatus.curValue.newVar.state % 2)) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					++curStatus.curValue.newVar.state;
					break;
					
				case TOK_LSQBRACKET:
					if (curStatus.curValue.newVar.state != 1) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 2;
					break;
					
				case TOK_RSQBRACKET:
					if (curStatus.curValue.newVar.state != 3) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 1;
					break;
					
				case TOK_LBRACE:
					if (curStatus.curValue.newVar.state != 0) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 4;
					break;
				case TOK_RBRACE:
					if ((curStatus.curValue.newVar.state != 5) && (curStatus.curValue.newVar.state != 11)) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 12;
					break;
					
				case TOK_END_OF_INST:
					if ((curStatus.curValue.newVar.state != 1) && (curStatus.curValue.newVar.state != 12)) {
						FAIL("Invalid state");
					}
					
					if (!curStatus.curValue.newVar.strLen) {
						FAIL("No parameter given");
					}
					
					char *param = resolveParam(
						&curStatus.curValue.newVar,
						vertex,
						0,
						&curStatus.curValue.newVar.var->init.strings_total_len
					);
					
					if (!param) {
						FAIL("Not a valid param");
					}
					
					if (curStatus.curValue.newVar.strLen) {
						free(param);
						FAIL("Not a valid single param");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar.var->init, param);
					
					int ret;
					uint32_t varIdx = kh_put(
						variables,
						curStatus.varsMap,
						curStatus.curValue.newVar.var->names[0],
						&ret
					);
					if (ret < 0) {
						FAIL("Unknown error");
					}
					kh_val(curStatus.varsMap, varIdx) = curStatus.curValue.newVar.var;
					pushArray((sArray*)&curStatus.variables, curStatus.curValue.newVar.var);
					freeArray((sArray*)&curStatus.curValue.newVar);
					curStatus.valueType = TYPE_NONE;
					curStatus.status = ST_LINE_START;
					
					break;
					
				case TOK_WHITESPACE:
				case TOK_NEWLINE:
					break;
					
				default:
					FAIL("Invalid token");
				}
				break;
				
			case VARTYPE_PARAM_MULT:
				switch (curStatus.curToken) {
				case TOK_SIGN:
					if ((curStatus.curValue.newVar.state < 6) || (curStatus.curValue.newVar.state == 15)
					 || !(curStatus.curValue.newVar.state % 2)) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					break;
					
				case TOK_INTEGER:
					if ((curStatus.curValue.newVar.state == 1) || (curStatus.curValue.newVar.state == 15)
					 || !(curStatus.curValue.newVar.state % 2)) {
						FAIL("Invalid state");
					}
					
					if (curStatus.curValue.newVar.state < 6) {
						pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					} else {
						size_t tokLen = getTokenLength(&curStatus);
						char *tok = (char*)malloc((tokLen + 2) * sizeof(char));
						copyToken(&curStatus, tok);
						tok[tokLen] = '.';
						tok[tokLen + 1] = '\0';
						pushArray((sArray*)&curStatus.curValue.newVar, tok);
					}
					++curStatus.curValue.newVar.state;
					break;
					
				case TOK_FLOATCONST:
					if ((curStatus.curValue.newVar.state < 6) || (curStatus.curValue.newVar.state == 15)
					 || !(curStatus.curValue.newVar.state % 2)) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					++curStatus.curValue.newVar.state;
					break;
					
				case TOK_IDENTIFIER:
					if (curStatus.curValue.newVar.state != 1) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 2;
					break;
					
				case TOK_POINT:
					if (curStatus.curValue.newVar.state != 2) {
						FAIL("Invalid state");
					}
					
					curStatus.curValue.newVar.state = 1;
					break;
					
				case TOK_UPTO:
					if (curStatus.curValue.newVar.state != 4) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 5;
					
					break;
					
				case TOK_COMMA:
					if (curStatus.curValue.newVar.state == 2) {
						pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
						curStatus.curValue.newVar.state = 1;
					} else if ((curStatus.curValue.newVar.state > 7) && !(curStatus.curValue.newVar.state % 2)) {
						pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
						++curStatus.curValue.newVar.state;
					} else {
						FAIL("Invalid state");
					}
					break;
					
				case TOK_LSQBRACKET:
					if (curStatus.curValue.newVar.state != 2) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 3;
					break;
					
				case TOK_RSQBRACKET:
					if ((curStatus.curValue.newVar.state != 4) && (curStatus.curValue.newVar.state != 6)) {
						FAIL("Invalid state");
					}
					
					pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
					curStatus.curValue.newVar.state = 2;
					break;
					
				case TOK_LBRACE:
					if (curStatus.curValue.newVar.state == 0) {
						curStatus.curValue.newVar.state = 1;
					} else if (curStatus.curValue.newVar.state == 1) {
						pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
						curStatus.curValue.newVar.state = 7;
					} else {
						FAIL("Invalid state");
					}
					break;
				case TOK_RBRACE:
					if (curStatus.curValue.newVar.state == 2) {
						curStatus.curValue.newVar.state = 15;
					} else if ((curStatus.curValue.newVar.state > 7) && !(curStatus.curValue.newVar.state % 2)) {
						while (curStatus.curValue.newVar.state < 14) {
							pushArray((sArray*)&curStatus.curValue.newVar, strdup(","));
							pushArray((sArray*)&curStatus.curValue.newVar, strdup("0."));
							curStatus.curValue.newVar.state += 2;
						}
						pushArray((sArray*)&curStatus.curValue.newVar, getToken(&curStatus));
						curStatus.curValue.newVar.state = 2;
					} else {
						FAIL("Invalid state");
					}
					break;
					
				case TOK_END_OF_INST:
					if (curStatus.curValue.newVar.state != 15) {
						FAIL("Invalid state");
					}
					
					if (curStatus.curValue.newVar.strLen == 1) {
						FAIL("No param given");
					}
					
					curStatus.curValue.newVar.var->init.strings_total_len = 0;
					do {
						// Remove the comma
						free(popFIFO((sArray*)&curStatus.curValue.newVar));
						
						size_t strsz;
						char *param = resolveParam(&curStatus.curValue.newVar, vertex, 2, &strsz);
						// If param is not resolved, fail
						if (!param) {
							curStatus.status = ST_ERROR;
							break;
						}
						
						pushArray((sArray*)&curStatus.curValue.newVar.var->init, param);
						curStatus.curValue.newVar.var->init.strings_total_len += strsz + 2;
						
						// Repeat until list empty OR not a comma
					} while (curStatus.curValue.newVar.strLen
					  && (curStatus.curValue.newVar.strParts[0][0] == ','));
					// Actually fail if failed
					if ((curStatus.status == ST_ERROR) || curStatus.curValue.newVar.strLen) {
						FAIL("Invalid param given");
					}
					
					curStatus.curValue.newVar.var->init.strings_total_len -= 2;
					
					if (curStatus.curValue.newVar.strLen) {
						// Is this even possible?
						FAIL("Too many arguments");
					}
					
					int ret;
					uint32_t varIdx = kh_put(
						variables,
						curStatus.varsMap,
						curStatus.curValue.newVar.var->names[0],
						&ret
					);
					if (ret < 0) {
						FAIL("Unknown error");
					}
					kh_val(curStatus.varsMap, varIdx) = curStatus.curValue.newVar.var;
					pushArray((sArray*)&curStatus.variables, curStatus.curValue.newVar.var);
					freeArray((sArray*)&curStatus.curValue.newVar);
					curStatus.valueType = TYPE_NONE;
					curStatus.status = ST_LINE_START;
					
					break;
					
				case TOK_WHITESPACE:
				case TOK_NEWLINE:
					break;
					
				default:
					FAIL("Invalid token");
				}
				break;
				
			case VARTYPE_ADDRESS:
			case VARTYPE_TEMP:
			case VARTYPE_ALIAS:
			case VARTYPE_CONST:
			case VARTYPE_TEXTURE:
			case VARTYPE_TEXTARGET:
			case VARTYPE_UNK:
				// Cannot happen (fallthrough?)
				FAIL("Unknown error (unintended fallthrough?)");
			}
			break;
			
		case ST_ALIAS:
			switch (curStatus.curToken) {
			case TOK_IDENTIFIER: {
				if (curStatus.curValue.string) {
					// Already have a string
					FAIL("Too many names");
				}
				
				char *tok = getToken(&curStatus);
				if (kh_str_exist(curStatus.varsMap, tok)) {
					// Identifier already exists
					free(tok);
					FAIL("Cannot redeclare variable");
				}
				curStatus.curValue.string = tok;
				
				break; }
				
			case TOK_WHITESPACE:
			case TOK_NEWLINE:
				break;
				
			case TOK_EQUALS:
				curStatus.status = ST_ALIASING;
				break;
				
			default:
				FAIL("Unknown token");
			}
			break;
		case ST_ALIASING:
			switch (curStatus.curToken) {
			case TOK_IDENTIFIER:
				if (curStatus.valueType != TYPE_ALIAS_DECL) {
					// Already aliased
					FAIL("Too many identifiers");
				}
				
				char *tok = getToken(&curStatus);
				uint32_t varIdx = kh_get(variables, curStatus.varsMap, tok);
				free(tok);
				if (!kh_truly_exist(curStatus.varsMap, varIdx)) {
					// Aliasing to empty space
					FAIL("Cannot alias to inexistant variable");
				}
				
				sVariable *var = kh_val(curStatus.varsMap, varIdx);
				
				pushArray((sArray*)var, curStatus.curValue.string);
				curStatus.valueType = TYPE_NONE;
				break;
				
			case TOK_WHITESPACE:
			case TOK_NEWLINE:
				break;
				
			case TOK_END_OF_INST:
				if (curStatus.valueType == TYPE_NONE) {
					curStatus.status = ST_LINE_START;
				} else {
					FAIL("No alias target");
				}
				break;
				
			default:
				FAIL("Invalid token");
			}
			break;
			
		case ST_INSTRUCTION: {
			sInstruction_Vars *curVarPtr = &curStatus.curValue.newInst.inst.vars[curStatus.curValue.newInst.curArg];
			switch (curStatus.curToken) {
			case TOK_SIGN:
				if (curStatus.curValue.newInst.state != 0) {
					FAIL("Invalid state");
				}
				
				curStatus.curValue.newInst.state = 1;
				curVarPtr->sign = curStatus.tokInt ? 1 : -1;
				
				break;
				
			case TOK_INTEGER:
				if (curStatus.curValue.newInst.state <= 1) {
					// Constant
					sVariable *cst = createVariable(VARTYPE_CONST);
					pushArray((sArray*)&cst->init, getToken(&curStatus));
					pushArray((sArray*)&curStatus.variables, cst);
					curVarPtr->var = cst;
					
					curStatus.curValue.newInst.state = 2;
				} else if (curStatus.curValue.newInst.state == 3) {
					curVarPtr->floatArrAddr = curStatus.tokInt;
					curStatus.curValue.newInst.state = 4;
				} else if (curStatus.curValue.newInst.state == 10) {
					pushArray((sArray*)&curStatus._fixedNewVar, getToken(&curStatus));
					curStatus.curValue.newInst.state = 11;
				} else {
					FAIL("Invalid state");
				}
				break;
				
			case TOK_FLOATCONST: {
				if (curStatus.curValue.newInst.state > 1) {
					FAIL("Invalid state");
				}
				
				sVariable *cst = createVariable(VARTYPE_CONST);
				pushArray((sArray*)&cst->init, getToken(&curStatus));
				pushArray((sArray*)&curStatus.variables, cst);
				curVarPtr->var = cst;
				
				curStatus.curValue.newInst.state = 2;
				break; }
				
			case TOK_IDENTIFIER: {
				// Variable helper
				char *tok = getToken(&curStatus);
				
				switch (curStatus.curValue.newInst.state) {
				case 0:
				case 1: {
					uint32_t varIdx = kh_get(variables, curStatus.varsMap, tok);
					if (kh_truly_exist(curStatus.varsMap, varIdx)) {
						sVariable *var = kh_val(curStatus.varsMap, varIdx);
						
						curVarPtr->var = var;
						curStatus.curValue.newInst.state = 2;
					} else {
						pushArray((sArray*)&curStatus._fixedNewVar, strdup(tok));
						curStatus.curValue.newInst.state = 9;
					}
					
					break; }
					
				case 2:
					if (!INSTTEX(curStatus.curValue.newInst.inst.type) || (curStatus.curValue.newInst.curArg != 3)) {
						// Not a texture query, 4th argument instruction...
						free(tok);
						FAIL("Invalid state");
					}
					
					// If there was no integer/float before (AKA, constant) fail
					if (curStatus.variables.vars[curStatus.variables.size - 1] != curVarPtr->var) {
						free(tok);
						FAIL("Invalid state");
					}
					
					// Transform into a type 9
					pushArray((sArray*)&curStatus._fixedNewVar, strdup(curVarPtr->var->init.strings[0]));
					pushArray((sArray*)&curStatus._fixedNewVar, strdup(tok));
					curStatus.curValue.newInst.state = 9;
					
					// Identifier after a constant, so free allocated variable
					sVariable *v = (sVariable*)popArray((sArray*)&curStatus.variables);
					deleteVariable(&v);
					curVarPtr->var = NULL;
					
					break;
					
				case 6: {
					int e = 0;
					for (int i = 0; !e && (tok[i] != '\0'); ++i) {
						if (i > 3) {
							e = 1;
							break;
						}
						switch (tok[i]) {
						case 'r': case 'x':
							curVarPtr->swizzle[i] = SWIZ_X;
							break;
						case 'g': case 'y':
							curVarPtr->swizzle[i] = SWIZ_Y;
							break;
						case 'b': case 'z':
							curVarPtr->swizzle[i] = SWIZ_Z;
							break;
						case 'a': case 'w':
							curVarPtr->swizzle[i] = SWIZ_W;
							break;
						default:
							e = 1; break;
						}
					}
					if (e) {
						free(tok);
						FAIL("Invalid swizzle value");
					}
					
					curStatus.curValue.newInst.state = 7;
					
					break; }
					
				case 8:
					pushArray((sArray*)&curStatus._fixedNewVar, strdup(tok));
					curStatus.curValue.newInst.state = 9;
					break;
					
				default:
					free(tok);
					FAIL("Invalid state");
				}
				
				free(tok);
				
				break; }
				
			case TOK_POINT:
				if (curStatus.curValue.newInst.state == 9) {
					curStatus.curValue.newInst.state = 8;
				} else if ((curStatus.curValue.newInst.state == 2) || (curStatus.curValue.newInst.state == 5)) {
					curStatus.curValue.newInst.state = 6;
				} else {
					FAIL("Invalid state");
				}
				break;
				
			case TOK_COMMA:
			case TOK_END_OF_INST:
				if ((curStatus.curValue.newInst.state != 2) && (curStatus.curValue.newInst.state != 5)
				 && (curStatus.curValue.newInst.state != 7) && (curStatus.curValue.newInst.state != 9)) {
					FAIL("Invalid state");
				}
				
				if (curStatus.curValue.newInst.state == 9) {
					int failure;
					
					if (INSTTEX(curStatus.curValue.newInst.inst.type)) {
						int b = 0;
						
						switch (curStatus.curValue.newInst.curArg) {
						case 2:
							if ((curStatus._fixedNewVar.strLen != 4) || (curStatus._fixedNewVar.strParts[1][0] != '[')
							 || (curStatus._fixedNewVar.strParts[3][0] != ']')
							 || strcmp(curStatus._fixedNewVar.strParts[0], "texture")) {
								FAIL("Invalid texture instruction");
							}
							
							unsigned int id = 0;
							
							char *idPtr = curStatus._fixedNewVar.strParts[2];
							while ((*idPtr >= '0') && (*idPtr <= '9')) {
								id = id * 10 + *idPtr - '0';
								++idPtr;
							}
							if (*idPtr != '\0') {
								FAIL("Invalid texture ID");
							}
							
							if (id > MAX_TEX) {
								FAIL("Invalid texture ID (ID too big)");
							}
							
							if (!curStatus.texVars[id]->size) {
								pushArray((sArray*)curStatus.texVars[id], strdup(curStatus._fixedNewVar.strParts[2]));
							}
							
							curVarPtr->var = curStatus.texVars[id];
							
							freeArray((sArray*)&curStatus._fixedNewVar);
							initArray((sArray*)&curStatus._fixedNewVar);
							
							b = 1;
							break;
							
						case 3:
							if (curStatus._fixedNewVar.strLen == 1) {
								if (!strcmp(curStatus._fixedNewVar.strParts[0], "CUBE")) {
									curVarPtr->var = curStatus.texCUBE;
								} else if (!strcmp(curStatus._fixedNewVar.strParts[0], "RECT")) {
									curVarPtr->var = curStatus.texRECT;
								} else {
									FAIL("Invalid texture target");
								}
							} else if (curStatus._fixedNewVar.strLen == 2) {
								if ((curStatus._fixedNewVar.strParts[1][0] != 'D')
								 || (curStatus._fixedNewVar.strParts[1][1] != '\0')
								 || (curStatus._fixedNewVar.strParts[0][1] != '\0')) {
									FAIL("Invalid texture target");
								}
								if (curStatus._fixedNewVar.strParts[0][0] == '1') {
									curVarPtr->var = curStatus.tex1D;
								} else if (curStatus._fixedNewVar.strParts[0][0] == '2') {
									curVarPtr->var = curStatus.tex2D;
								} else if (curStatus._fixedNewVar.strParts[0][0] == '3') {
									curVarPtr->var = curStatus.tex3D;
								} else {
									FAIL("Invalid texture target");
								}
							} else {
								FAIL("Invalid texture target");
							}
							
							freeArray((sArray*)&curStatus._fixedNewVar);
							initArray((sArray*)&curStatus._fixedNewVar);
							
							b = 1;
							break;
						}
						
						if (b) {
							if (curStatus.curToken == TOK_COMMA) {
								curStatus.curValue.newInst.state = 0;
								++curStatus.curValue.newInst.curArg;
								if (curStatus.curValue.newInst.curArg >= MAX_OPERANDS) {
									FAIL("Too many operands");
								}
							} else {
								pushArray(
									(sArray*)&curStatus.instructions,
									copyInstruction(&curStatus.curValue.newInst.inst)
								);
								curStatus.valueType = TYPE_NONE;
								curStatus.status = ST_LINE_START;
							}
							
							break;
						}
					}
					
					if ((vertex && !strcmp(curStatus._fixedNewVar.strParts[0], "vertex"))
					 || (!vertex && !strcmp(curStatus._fixedNewVar.strParts[0], "fragment"))) {
						curStatus._fixedNewVar.var = createVariable(VARTYPE_CONST);
						
						failure = resolveAttrib(&curStatus._fixedNewVar, vertex);
					} else if (!strcmp(curStatus._fixedNewVar.strParts[0], "result")) {
						curStatus._fixedNewVar.var = createVariable(VARTYPE_CONST);
						
						failure = resolveOutput(&curStatus._fixedNewVar, vertex);
					} else {
						curStatus._fixedNewVar.var = createVariable(VARTYPE_CONST);
						
						char *resolved = resolveParam(
							&curStatus._fixedNewVar,
							vertex,
							1,
							&curStatus._fixedNewVar.var->init.strings_total_len
						);
						
						if (!resolved) {
							deleteVariable(&curStatus._fixedNewVar.var);
							FAIL("Invalid value (implicit param?)");
						}
						failure = 0;
						
						pushArray((sArray*)&curVarPtr->var->init, resolved);
					}
					
					if (failure) {
						deleteVariable(&curStatus._fixedNewVar.var);
						FAIL("Invalid value (implicit attrib or output)");
					}
					
					if (curStatus._fixedNewVar.strLen) {
						if (!IS_SWIZZLE(curStatus._fixedNewVar.strParts[0]) || (curStatus._fixedNewVar.strLen > 1)) {
							// Too many elements
							deleteVariable(&curStatus._fixedNewVar.var);
							FAIL("Invalid value");
						}
						
						// Swizzle
						int e = 0;
						char *swiz = popArray((sArray*)&curStatus._fixedNewVar);
						for (int i = 0; !e && (swiz[i] != '\0'); ++i) {
							if (i > 3) {
								e = 1;
								break;
							}
							switch (swiz[i]) {
							case 'r': case 'x':
								curVarPtr->swizzle[i] = SWIZ_X;
								break;
							case 'g': case 'y':
								curVarPtr->swizzle[i] = SWIZ_Y;
								break;
							case 'b': case 'z':
								curVarPtr->swizzle[i] = SWIZ_Z;
								break;
							case 'a': case 'w':
								curVarPtr->swizzle[i] = SWIZ_W;
								break;
							default:
								e = 1; continue;
							}
						}
						free(swiz);
						if (e) {
							deleteVariable(&curStatus._fixedNewVar.var);
							FAIL("Invalid swizzle");
						}
					}
					
					pushArray((sArray*)&curStatus.variables, curStatus._fixedNewVar.var);
					curVarPtr->var = curStatus._fixedNewVar.var;
					
					freeArray((sArray*)&curStatus._fixedNewVar);
					initArray((sArray*)&curStatus._fixedNewVar);
					curStatus._fixedNewVar.var = NULL;
				}
				
				if (curStatus.curToken == TOK_COMMA) {
					curStatus.curValue.newInst.state = 0;
					++curStatus.curValue.newInst.curArg;
					if (curStatus.curValue.newInst.curArg >= MAX_OPERANDS) {
						FAIL("Too many operands");
					}
				} else {
					// Not a texture query instruction, since they are already took care of
					if (INSTTEX(curStatus.curValue.newInst.inst.type)) {
						FAIL("Invalid texture instruction");
					}
					
					pushArray((sArray*)&curStatus.instructions, copyInstruction(&curStatus.curValue.newInst.inst));
					curStatus.valueType = TYPE_NONE;
					curStatus.status = ST_LINE_START;
				}
				
				break;
				
			case TOK_LSQBRACKET:
				if ((curStatus.curValue.newInst.state != 2) && (curStatus.curValue.newInst.state != 9)) {
					FAIL("Invalid state");
				}
				
				if (curStatus.curValue.newInst.state == 9) {
					pushArray((sArray*)&curStatus._fixedNewVar, getToken(&curStatus));
				}
				
				++curStatus.curValue.newInst.state;
				
				break;
				
			case TOK_RSQBRACKET:
				if (curStatus.curValue.newInst.state == 4) {
					curStatus.curValue.newInst.state = 5;
				} else if (curStatus.curValue.newInst.state == 11) {
					pushArray((sArray*)&curStatus._fixedNewVar, getToken(&curStatus));
					curStatus.curValue.newInst.state = 9;
				} else {
					FAIL("Invalid state");
				}
				
				break;
				
			case TOK_WHITESPACE:
			case TOK_NEWLINE:
				break;
				
			default:
				FAIL("Invalid token");
			}
			break; }
			
		case ST_OPTION:
			switch (curStatus.curToken) {
			case TOK_IDENTIFIER:
				if (curStatus.curValue.newOpt.optName) {
					FAIL("Too many options");
				}
				
				curStatus.curValue.newOpt.optName = getToken(&curStatus);
				break;
				
			case TOK_WHITESPACE:
			case TOK_NEWLINE:
				break;
				
			case TOK_END_OF_INST:
				if (!strcmp(curStatus.curValue.newOpt.optName, "ARB_precision_hint_fastest")) {
					// Nothing to do
				} else {
					FAIL("Unknown option");
				}
				
				free(curStatus.curValue.newOpt.optName);
				
				curStatus.valueType = TYPE_NONE;
				curStatus.status = ST_LINE_START;
				break;
				
			default:
				FAIL("Invalid token");
			}
			break;
			
		case ST_DONE:
		case ST_ERROR:
			// Shouldn't happen (fallthrough?)
			continue;
		}
		
		readNextToken(&curStatus);
	}
#undef FAIL
	
	if (curStatus.status == ST_ERROR) {
		ARBCONV_DBG(
		char *codeDup = strdup(code);
		codeDup[curStatus.codePtr - code] = '\0';
		printf(
			"Failure, copy until EOF\n\n%s\033[91m%s\033[m\n",
			codeDup,
			curStatus.codePtr
		);
		free(codeDup);
		
		printf("\nVariables:\n==========\n");
		{
			const char *kvar;
			sVariable *vvar;
			kh_foreach(curStatus.varsMap, kvar, vvar, 
				if (vvar) {
					printf("Variable %10s pointing to %p (%10s)\n", kvar, vvar, vvar->names[0]);
				} else {
					printf("\033[91mVariable %10s pointing to NULLptr!\033[m\n", kvar);
				}
			)
		}
		for (size_t i = 0; i < curStatus.variables.size; ++i) {
			sVariable *varPtr = curStatus.variables.vars[i];
			printf("Variable %p %10s (%lu): %-10s (init = %3lu %s)\n", varPtr, varPtr->names[0], varPtr->names_count, VARTYPE2STR(varPtr->type), varPtr->init.strings_total_len, varPtr->init.strings_count ? varPtr->init.strings[0] : "(none)");
		}
		printf("\nInstructions:\n=============\n");
		for (size_t i = 0; i < curStatus.instructions.size; ++i) {
			sInstruction *instPtr = curStatus.instructions.insts[i];
			instPtr = curStatus.instructions.insts[i];
			if (INSTTEX(instPtr->type)) {
				printf("Instruction %3s%4s %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %ctexture[%2s]      %c%19s\n", INST2STR(instPtr->type), instPtr->saturated ? "_SAT" : "    ",
					instPtr->vars[0].sign ? (instPtr->vars[0].sign == -1 ? '-' : '+') : ' ', instPtr->vars[0].var ? ((instPtr->vars[0].var->type == VARTYPE_CONST) ? instPtr->vars[0].var->init.strings[0] : instPtr->vars[0].var->names[0]) : "(none)", instPtr->vars[0].floatArrAddr, (instPtr->vars[0].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[1].sign ? (instPtr->vars[1].sign == -1 ? '-' : '+') : ' ', instPtr->vars[1].var ? ((instPtr->vars[1].var->type == VARTYPE_CONST) ? instPtr->vars[1].var->init.strings[0] : instPtr->vars[1].var->names[0]) : "(none)", instPtr->vars[1].floatArrAddr, (instPtr->vars[1].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[2].sign ? (instPtr->vars[2].sign == -1 ? '-' : '+') : ' ', instPtr->vars[2].var->names[0],
					instPtr->vars[3].sign ? (instPtr->vars[3].sign == -1 ? '-' : '+') : ' ', (instPtr->vars[3].var == curStatus.tex1D) ? "1D" : (instPtr->vars[3].var == curStatus.tex2D) ? "2D" : (instPtr->vars[3].var == curStatus.tex3D) ? "3D" : (instPtr->vars[3].var == curStatus.texCUBE) ? "CUBE" : (instPtr->vars[3].var == curStatus.texRECT) ? "RECT" : "!!!"
				);
			} else {
				printf("Instruction %3s%4s %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c\n", INST2STR(instPtr->type), instPtr->saturated ? "_SAT" : "    ",
					instPtr->vars[0].sign ? (instPtr->vars[0].sign == -1 ? '-' : '+') : ' ', instPtr->vars[0].var ? ((instPtr->vars[0].var->type == VARTYPE_CONST) ? instPtr->vars[0].var->init.strings[0] : instPtr->vars[0].var->names[0]) : "(none)", instPtr->vars[0].floatArrAddr, (instPtr->vars[0].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[1].sign ? (instPtr->vars[1].sign == -1 ? '-' : '+') : ' ', instPtr->vars[1].var ? ((instPtr->vars[1].var->type == VARTYPE_CONST) ? instPtr->vars[1].var->init.strings[0] : instPtr->vars[1].var->names[0]) : "(none)", instPtr->vars[1].floatArrAddr, (instPtr->vars[1].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[2].sign ? (instPtr->vars[2].sign == -1 ? '-' : '+') : ' ', instPtr->vars[2].var ? ((instPtr->vars[2].var->type == VARTYPE_CONST) ? instPtr->vars[2].var->init.strings[0] : instPtr->vars[2].var->names[0]) : "(none)", instPtr->vars[2].floatArrAddr, (instPtr->vars[2].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[3].sign ? (instPtr->vars[3].sign == -1 ? '-' : '+') : ' ', instPtr->vars[3].var ? ((instPtr->vars[3].var->type == VARTYPE_CONST) ? instPtr->vars[3].var->init.strings[0] : instPtr->vars[3].var->names[0]) : "(none)", instPtr->vars[3].floatArrAddr, (instPtr->vars[3].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[3] == SWIZ_W) ? 'w' : ' '
				);
			}
		}
		printf("\n");)
		
		glsl->error_ptr = curStatus.codePtr - code;
		
		// We have errored, output NULL
		freeStatus(&curStatus);
		free(curStatus.outputString);
		return NULL;
	}
	
	ARBCONV_DBG(printf("Success!\n");)
	
	// Variables are automatically created, only need to write main()
	size_t varIdx = (size_t)0;
	sVariable *varPtr;
	size_t instIdx = (size_t)0;
	sInstruction *instPtr;
#define FAIL(str) curStatus.status = ST_ERROR; if (glsl->error_msg) free(glsl->error_msg); \
		glsl->error_msg = strdup(str); continue
#define APPEND_OUTPUT(str, len) \
		if (appendString(&curStatus, str, len)) {      \
			FAIL("Unknown error (not enough memory?"); \
		}
#define APPEND_OUTPUT2(str) APPEND_OUTPUT(str, (size_t)-1)
	
	do {
		APPEND_OUTPUT("#version 120\n", 13)
		
		if (!vertex) {
			// sampler2DRect is not in the GLSL 1.20 specification and is a reserved keyword...
			APPEND_OUTPUT(
				"uniform sampler1D samplers1D[" MAX_TEX_STR "];\n"
				"uniform sampler2D samplers2D[" MAX_TEX_STR "];\n"
				"uniform sampler3D samplers3D[" MAX_TEX_STR "];\n"
				"uniform samplerCube samplersCube[" MAX_TEX_STR "];\n"
				/* "uniform sampler2DRect samplersRect[" MAX_TEX_STR "];\n" */,
				/* 170 + 5 * MAX_TEX_STRLEN */
				132 + 4 * MAX_TEX_STRLEN
			)
		}
		
		APPEND_OUTPUT("\nvoid main() {\n", 15)
		
		for (; (varIdx < curStatus.variables.size) && (curStatus.status != ST_ERROR); ++varIdx) {
			varPtr = curStatus.variables.vars[varIdx];
			
			ARBCONV_DBG_AS(
				printf("Variable #%2ld: %10s (%10s)\n", varIdx, varPtr->names[0], VARTYPE2STR(varPtr->type));
				fflush(stdout);
			)
			
			if (varPtr->type == VARTYPE_CONST) {
				continue;
			}
			
			APPEND_OUTPUT("\tvec4 ", 6)
			APPEND_OUTPUT2(varPtr->names[0])
			
			switch (varPtr->type) {
			case VARTYPE_ADDRESS:
			case VARTYPE_ATTRIB:
			case VARTYPE_OUTPUT:
			case VARTYPE_PARAM:
				APPEND_OUTPUT(" = ", 3)
				APPEND_OUTPUT(varPtr->init.strings[0], varPtr->init.strings_total_len)
				break;
				
			case VARTYPE_PARAM_MULT:
				APPEND_OUTPUT("[", 1)
				if (varPtr->size > 0) {
					char buf[11]; /* Assume 32-bits array address, should never overflow... */
					sprintf(buf, "%d", varPtr->size);
					APPEND_OUTPUT2(buf)
				}
				APPEND_OUTPUT("]", 1)
			
				APPEND_OUTPUT(" = ", 3)
				APPEND_OUTPUT("vec4[](", 7)
				for (size_t i = 0; i < varPtr->init.strings_count; ++i) {
					APPEND_OUTPUT2(varPtr->init.strings[i])
					APPEND_OUTPUT(", ", 2)
				}
				--curStatus.outputEnd;
				--curStatus.outLen;
				++curStatus.outLeft;
				curStatus.outputEnd[-1] = ')';
				break;
				
			case VARTYPE_CONST:
			case VARTYPE_TEMP:
				break;
				
			case VARTYPE_ALIAS:
			case VARTYPE_TEXTURE:
			case VARTYPE_TEXTARGET:
			case VARTYPE_UNK:
				FAIL("Invalid variable type (unintended fallthrough?)");
			}
			
			APPEND_OUTPUT(";\n", 2)
		}
		if (curStatus.status == ST_ERROR) {
			--varIdx;
			glsl->error_ptr = 1;
			break;
		}
		
		APPEND_OUTPUT("\t\n", 2)
		for (; (instIdx < curStatus.instructions.size) && (curStatus.status != ST_ERROR); ++instIdx) {
			instPtr = curStatus.instructions.insts[instIdx];
			
			ARBCONV_DBG_AS(
				if (INSTTEX(instPtr->type)) {
					printf("Instruction #%3ld: %3s%4s %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %ctexture[%2s]      %c%19s\n", instIdx, INST2STR(instPtr->type), instPtr->saturated ? "_SAT" : "    ",
						instPtr->vars[0].sign ? (instPtr->vars[0].sign == -1 ? '-' : '+') : ' ', instPtr->vars[0].var ? ((instPtr->vars[0].var->type == VARTYPE_CONST) ? instPtr->vars[0].var->init.strings[0] : instPtr->vars[0].var->names[0]) : "(none)", instPtr->vars[0].floatArrAddr, (instPtr->vars[0].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[3] == SWIZ_W) ? 'w' : ' ',
						instPtr->vars[1].sign ? (instPtr->vars[1].sign == -1 ? '-' : '+') : ' ', instPtr->vars[1].var ? ((instPtr->vars[1].var->type == VARTYPE_CONST) ? instPtr->vars[1].var->init.strings[0] : instPtr->vars[1].var->names[0]) : "(none)", instPtr->vars[1].floatArrAddr, (instPtr->vars[1].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[3] == SWIZ_W) ? 'w' : ' ',
						instPtr->vars[2].sign ? (instPtr->vars[2].sign == -1 ? '-' : '+') : ' ', instPtr->vars[2].var->names[0],
						instPtr->vars[3].sign ? (instPtr->vars[3].sign == -1 ? '-' : '+') : ' ', (instPtr->vars[3].var == curStatus.tex1D) ? "1D" : (instPtr->vars[3].var == curStatus.tex2D) ? "2D" : (instPtr->vars[3].var == curStatus.tex3D) ? "3D" : (instPtr->vars[3].var == curStatus.texCUBE) ? "CUBE" : (instPtr->vars[3].var == curStatus.texRECT) ? "RECT" : "!!!"
					);
				} else {
					printf("Instruction #%3ld: %3s%4s %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c\n", instIdx, INST2STR(instPtr->type), instPtr->saturated ? "_SAT" : "    ",
						instPtr->vars[0].sign ? (instPtr->vars[0].sign == -1 ? '-' : '+') : ' ', instPtr->vars[0].var ? ((instPtr->vars[0].var->type == VARTYPE_CONST) ? instPtr->vars[0].var->init.strings[0] : instPtr->vars[0].var->names[0]) : "(none)", instPtr->vars[0].floatArrAddr, (instPtr->vars[0].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[3] == SWIZ_W) ? 'w' : ' ',
						instPtr->vars[1].sign ? (instPtr->vars[1].sign == -1 ? '-' : '+') : ' ', instPtr->vars[1].var ? ((instPtr->vars[1].var->type == VARTYPE_CONST) ? instPtr->vars[1].var->init.strings[0] : instPtr->vars[1].var->names[0]) : "(none)", instPtr->vars[1].floatArrAddr, (instPtr->vars[1].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[3] == SWIZ_W) ? 'w' : ' ',
						instPtr->vars[2].sign ? (instPtr->vars[2].sign == -1 ? '-' : '+') : ' ', instPtr->vars[2].var ? ((instPtr->vars[2].var->type == VARTYPE_CONST) ? instPtr->vars[2].var->init.strings[0] : instPtr->vars[2].var->names[0]) : "(none)", instPtr->vars[2].floatArrAddr, (instPtr->vars[2].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[3] == SWIZ_W) ? 'w' : ' ',
						instPtr->vars[3].sign ? (instPtr->vars[3].sign == -1 ? '-' : '+') : ' ', instPtr->vars[3].var ? ((instPtr->vars[3].var->type == VARTYPE_CONST) ? instPtr->vars[3].var->init.strings[0] : instPtr->vars[3].var->names[0]) : "(none)", instPtr->vars[3].floatArrAddr, (instPtr->vars[3].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[3] == SWIZ_W) ? 'w' : ' '
					);
				}
				fflush(stdout);
			)
			
			// Data access and output
#define SWIZ(i, s) instPtr->vars[i].swizzle[s]
#define PUSH_SWIZZLE(s) \
		switch (s) {               \
		case SWIZ_X:               \
			APPEND_OUTPUT("x", 1); \
			break;                 \
		case SWIZ_Y:               \
			APPEND_OUTPUT("y", 1); \
			break;                 \
		case SWIZ_Z:               \
			APPEND_OUTPUT("z", 1); \
			break;                 \
		case SWIZ_W:               \
			APPEND_OUTPUT("w", 1); \
			break;                 \
		case SWIZ_NONE:            \
			break;                 \
		}
			
			// Instruction assertions
#define ASSERT_COUNT(cnt) \
		if (((cnt < MAX_OPERANDS) && instPtr->vars[cnt].var) || (cnt && !instPtr->vars[cnt - 1].var)) { \
			FAIL("Invalid instruction (not enough/too many arguments)");                                \
		}
#define ASSERT_MASKDST(i) \
		if ((instPtr->vars[i].var->type != VARTYPE_TEMP) && (instPtr->vars[i].var->type != VARTYPE_OUTPUT) \
		 && (instPtr->vars[i].var->type != VARTYPE_CONST)) {                                               \
			FAIL("Variable is not a valid masked destination register");                                   \
		}                                                                                                  \
		if (instPtr->vars[i].sign != 0) {                                                                  \
			FAIL("Variable is not a valid masked destination register");                                   \
		}                                                                                                  \
		if (instPtr->vars[i].floatArrAddr != -1) {                                                         \
			FAIL("Variable is not a valid masked destination register");                                   \
		}                                                                                                  \
		for (int sw = 0; (sw < 3) && (SWIZ(i, sw + 1) != SWIZ_NONE); ++sw) {                               \
			if ((SWIZ(i, sw) >= SWIZ(i, sw + 1))) {                                                        \
				FAIL("Variable is not a valid masked destination register");                               \
			}                                                                                              \
		}                                                                                                  \
		if (curStatus.status == ST_ERROR) {                                                                \
			continue;                                                                                      \
		}
#define ASSERT_VECTSRC(i) \
		if ((instPtr->vars[i].var->type != VARTYPE_TEMP) && (instPtr->vars[i].var->type != VARTYPE_ATTRIB) \
		 && (instPtr->vars[i].var->type != VARTYPE_PARAM) && (instPtr->vars[i].var->type != VARTYPE_CONST) \
		 && (instPtr->vars[i].var->type != VARTYPE_PARAM_MULT)) {                                          \
			FAIL("Variable is not a valid vector source register");                                        \
		}                                                                                                  \
		if ((SWIZ(i, 1) != SWIZ_NONE) && (SWIZ(i, 3) == SWIZ_NONE)) {                                      \
			FAIL("Variable is not a valid vector source register");                                        \
		}
#define ASSERT_SCALSRC(i) \
		if ((instPtr->vars[i].var->type != VARTYPE_TEMP) && (instPtr->vars[i].var->type != VARTYPE_ATTRIB) \
		 && (instPtr->vars[i].var->type != VARTYPE_PARAM) && (instPtr->vars[i].var->type != VARTYPE_CONST) \
		 && (instPtr->vars[i].var->type != VARTYPE_PARAM_MULT)) {                                          \
			FAIL("Variable is not a valid vector source scalar");                                          \
		}                                                                                                  \
		if ((SWIZ(i, 0) == SWIZ_NONE) || (SWIZ(i, 1) != SWIZ_NONE)) {                                      \
			FAIL("Variable is not a valid vector source scalar");                                          \
		}
#define INST_VECTOR \
		ASSERT_COUNT(2)   \
		ASSERT_MASKDST(0) \
		ASSERT_VECTSRC(1)
#define INST_SCALAR \
		ASSERT_COUNT(2)   \
		ASSERT_MASKDST(0) \
		ASSERT_SCALSRC(1)
#define INST_BINSCL \
		ASSERT_COUNT(3)   \
		ASSERT_MASKDST(0) \
		ASSERT_SCALSRC(1) \
		ASSERT_SCALSRC(2)
#define INST_BINVEC \
		ASSERT_COUNT(3)   \
		ASSERT_MASKDST(0) \
		ASSERT_VECTSRC(1) \
		ASSERT_VECTSRC(2)
#define INST_TRIVEC \
		ASSERT_COUNT(4)   \
		ASSERT_MASKDST(0) \
		ASSERT_VECTSRC(1) \
		ASSERT_VECTSRC(2) \
		ASSERT_VECTSRC(3)
#define INST_SAMPLE \
		ASSERT_COUNT(4)                                                                              \
		ASSERT_MASKDST(0)                                                                            \
		ASSERT_VECTSRC(1)                                                                            \
		if (instPtr->vars[2].var->type != VARTYPE_TEXTURE) {                                         \
			FAIL("Invalid texture variable");                                                        \
		}                                                                                            \
		if ((instPtr->vars[3].var != curStatus.tex1D) && (instPtr->vars[3].var != curStatus.tex2D)   \
		 && (instPtr->vars[3].var != curStatus.tex3D) && (instPtr->vars[3].var != curStatus.texCUBE) \
		 /* && (instPtr->vars[3].var != curStatus.texRECT) */) {                                           \
			FAIL("Invalid texture sampler target");                                                  \
		}
			
			// Misc pushing
#define PUSH_DSTMASK(i) \
		if (SWIZ(i, 0) != SWIZ_NONE) {                                       \
			APPEND_OUTPUT(".", 1)                                            \
			for (int sw = 0; (sw < 4) && (SWIZ(i, sw) != SWIZ_NONE); ++sw) { \
				PUSH_SWIZZLE(SWIZ(i, sw))                                    \
			}                                                                \
		}
#define PUSH_VARNAME(i) \
		if (instPtr->vars[i].sign == -1) {                        \
			APPEND_OUTPUT("-", 1)                                 \
		}                                                         \
		if (instPtr->vars[i].var->type == VARTYPE_CONST) {        \
			APPEND_OUTPUT2(instPtr->vars[i].var->init.strings[0]) \
		} else {                                                  \
			APPEND_OUTPUT2(instPtr->vars[i].var->names[0])        \
		}                                                         \
		if (instPtr->vars[i].floatArrAddr != -1) {                \
			char buf[11];                                         \
			sprintf(buf, "%d", instPtr->vars[i].floatArrAddr);    \
			APPEND_OUTPUT("[", 1)                                 \
			APPEND_OUTPUT2(buf)                                   \
			APPEND_OUTPUT("]", 1)                                 \
		}
#define PUSH_PRE_SAT(p) \
		if (instPtr->saturated) {      \
			APPEND_OUTPUT("clamp(", 6) \
		} else if (p) {                \
			APPEND_OUTPUT("(", 1)      \
		}
#define PUSH_POSTSAT(p) \
		if (instPtr->saturated) {         \
			APPEND_OUTPUT(", 0., 1.)", 9) \
		} else if (p) {                   \
			APPEND_OUTPUT(")", 1)         \
		}
			
			// Instruction variable pushing
			// TODO: MOV, LG2 and similar use only (a) specific component(s) (mask), optimize generated code
#define PUSH_MASKDST(i) \
		PUSH_VARNAME(i) \
		PUSH_DSTMASK(i)
#define PUSH_VECTSRC(i) \
		PUSH_VARNAME(i)                    \
		if (SWIZ(i, 0) != SWIZ_NONE) {     \
			APPEND_OUTPUT(".", 1)          \
			PUSH_SWIZZLE(SWIZ(i, 0))       \
			if (SWIZ(i, 3) == SWIZ_NONE) { \
				PUSH_SWIZZLE(SWIZ(i, 0))   \
				PUSH_SWIZZLE(SWIZ(i, 0))   \
				PUSH_SWIZZLE(SWIZ(i, 0))   \
			} else {                       \
				PUSH_SWIZZLE(SWIZ(i, 1))   \
				PUSH_SWIZZLE(SWIZ(i, 2))   \
				PUSH_SWIZZLE(SWIZ(i, 3))   \
			}                              \
		}
/* Append a VEctor SouRCe ComponenT */
#define PUSH_VESRCCT(i, s) \
		PUSH_VARNAME(i)                    \
		APPEND_OUTPUT(".", 1)              \
		if (SWIZ(i, 0) == SWIZ_NONE) {     \
			PUSH_SWIZZLE(s + 1)            \
		} else {                           \
			if (SWIZ(i, 3) == SWIZ_NONE) { \
				PUSH_SWIZZLE(SWIZ(i, 0))   \
			} else {                       \
				PUSH_SWIZZLE(SWIZ(i, s))   \
			}                              \
		}
#define PUSH_SCALSRC(i) \
		PUSH_VARNAME(i)          \
		APPEND_OUTPUT(".", 1)    \
		PUSH_SWIZZLE(SWIZ(i, 0)) \
		PUSH_SWIZZLE(SWIZ(i, 0)) \
		PUSH_SWIZZLE(SWIZ(i, 0)) \
		PUSH_SWIZZLE(SWIZ(i, 0))
			
			// Textures
/* Append a VECTor SaMPler */
#define PUSH_VECTSMP(i, j) \
		PUSH_VECTSRC(i)                                         \
		if (instPtr->vars[j].var == curStatus.tex1D) {          \
			APPEND_OUTPUT(".x", 2)                              \
		} else if (instPtr->vars[j].var == curStatus.tex2D) {   \
			APPEND_OUTPUT(".xy", 3)                             \
		} else if (instPtr->vars[j].var == curStatus.tex3D) {   \
			APPEND_OUTPUT(".xyz", 4)                            \
		} else if (instPtr->vars[j].var == curStatus.texCUBE) { \
			APPEND_OUTPUT(".xyz", 4)                            \
		} else if (instPtr->vars[j].var == curStatus.texRECT) { \
			FAIL("Unsupported variable texture target RECT"); /*APPEND_OUTPUT(".xy", 3)*/                             \
		} else {                                                \
			FAIL("Invalid variable texture target");            \
		}
/* Append a texture SAMPLER */
#define PUSH_SAMPLER(i, j) \
		if (instPtr->vars[i].var->type != VARTYPE_TEXTURE) {    \
			FAIL("Invalid variable type");                      \
		}                                                       \
		APPEND_OUTPUT("samplers", 8)                            \
		if (instPtr->vars[j].var == curStatus.tex1D) {          \
			APPEND_OUTPUT("1D", 2)                              \
		} else if (instPtr->vars[j].var == curStatus.tex2D) {   \
			APPEND_OUTPUT("2D", 2)                              \
		} else if (instPtr->vars[j].var == curStatus.tex3D) {   \
			APPEND_OUTPUT("3D", 2)                              \
		} else if (instPtr->vars[j].var == curStatus.texCUBE) { \
			APPEND_OUTPUT("Cube", 4)                            \
		} else if (instPtr->vars[j].var == curStatus.texRECT) { \
			FAIL("Unsupported variable texture target RECT"); /*APPEND_OUTPUT("Rect", 4)*/                             \
		} else {                                                \
			FAIL("Invalid variable texture target");            \
		}                                                       \
		APPEND_OUTPUT("[", 1)                                   \
		APPEND_OUTPUT2(instPtr->vars[i].var->names[0])          \
		APPEND_OUTPUT("]", 1)
/* Append a SAMPler FunCtioN */
#define PUSH_SAMPFCN(i) \
		if (instPtr->vars[i].var == curStatus.tex1D) {          \
			APPEND_OUTPUT("1D", 2)                              \
		} else if (instPtr->vars[i].var == curStatus.tex2D) {   \
			APPEND_OUTPUT("2D", 2)                              \
		} else if (instPtr->vars[i].var == curStatus.tex3D) {   \
			APPEND_OUTPUT("3D", 2)                              \
		} else if (instPtr->vars[i].var == curStatus.texCUBE) { \
			APPEND_OUTPUT("Cube", 4)                            \
		} else if (instPtr->vars[i].var == curStatus.texRECT) { \
			FAIL("Unsupported variable texture target RECT"); /*APPEND_OUTPUT("Rect", 4)*/                             \
		} else {                                                \
			FAIL("Invalid variable texture target");            \
		}
			
			// Misc
#define FINISH_INST \
		PUSH_DSTMASK(0)         \
		APPEND_OUTPUT(";\n", 2) \
		break;
			
			switch (instPtr->type) {
			case INST_ABS:
				INST_VECTOR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("abs(", 4)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_ADD:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(1)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(" + ", 3)
				PUSH_VECTSRC(2)
				PUSH_POSTSAT(1)
				FINISH_INST
				
			case INST_ARL:
				// TODO
				FAIL("ARBconv TODO: ARL");
				break;
				
				/* Old version
				if (!vertex) {
					FAIL("Invalid instruction in fragment shaders");
				}
				ASSERT_COUNT(2)
				APPEND_OUTPUT("\t", 1)
				PUSH_SCAL(0)
				APPEND_OUTPUT(" = floor(", 9)
				if (instPtr->vars[1].var->type != VARTYPE_ADDRESS) {
					FAIL("Variable is not an address");
				}
				if ((SWIZ(1, 0) != SWIZ_X) || (SWIZ(1, 1) != SWIZ_NONE)) {
					FAIL("Variable is not an address");
				}
				if (instPtr->vars[1].floatArrAddr != -1) {
					FAIL("Variable is not an address");
				}
				APPEND_OUTPUT2(instPtr->vars[1].var->names[0])
				APPEND_OUTPUT(".x", 2)
				APPEND_OUTPUT(")", 1)
				FINISH_INST
				break; */
				
			case INST_CMP:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				INST_TRIVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4((", 6)
				PUSH_VESRCCT(1, 0)
				APPEND_OUTPUT(" < 0.) ? ", 9)
				PUSH_VESRCCT(2, 0)
				APPEND_OUTPUT(" : ", 3)
				PUSH_VESRCCT(3, 0)
				APPEND_OUTPUT(", (", 3)
				PUSH_VESRCCT(1, 1)
				APPEND_OUTPUT(" < 0.) ? ", 9)
				PUSH_VESRCCT(2, 1)
				APPEND_OUTPUT(" : ", 3)
				PUSH_VESRCCT(3, 1)
				APPEND_OUTPUT(", (", 3)
				PUSH_VESRCCT(1, 2)
				APPEND_OUTPUT(" < 0.) ? ", 9)
				PUSH_VESRCCT(2, 2)
				APPEND_OUTPUT(" : ", 3)
				PUSH_VESRCCT(3, 2)
				APPEND_OUTPUT(", (", 3)
				PUSH_VESRCCT(1, 3)
				APPEND_OUTPUT(" < 0.) ? ", 9)
				PUSH_VESRCCT(2, 3)
				APPEND_OUTPUT(" : ", 3)
				PUSH_VESRCCT(3, 3)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_COS:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(cos(", 9)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT("))", 2)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_DP3:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(dot(", 9)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(".xyz, ", 6)
				PUSH_VECTSRC(2)
				APPEND_OUTPUT(".xyz))", 6)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_DP4:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(dot(", 9)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(", ", 2)
				PUSH_VECTSRC(2)
				APPEND_OUTPUT("))", 2)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_DPH:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(dot(", 9)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(".xyz, ", 6)
				PUSH_VECTSRC(2)
				APPEND_OUTPUT("))", 2)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_DST:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(1., ", 9)
				PUSH_VESRCCT(1, 1)
				APPEND_OUTPUT(" * ", 3)
				PUSH_VESRCCT(2, 1)
				APPEND_OUTPUT(", ", 2)
				PUSH_VESRCCT(1, 2)
				APPEND_OUTPUT(", ", 2)
				PUSH_VESRCCT(2, 3)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_EX2: // "Exact"
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(1)
				APPEND_OUTPUT("exp2(", 5)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(1)
				FINISH_INST
				
			case INST_EXP: // Approximate
				if (!vertex) {
					FAIL("Invalid instruction in fragment shaders");
				}
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = vec4(exp2(floor(", 19)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT(")), fract(", 10)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT("), exp2(", 8)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT("), 1.)", 6)
				FINISH_INST
				
			case INST_FLR:
				INST_VECTOR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("floor(", 6)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_FRC:
				INST_VECTOR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("fract(", 6)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_KIL:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				ASSERT_COUNT(1)
				APPEND_OUTPUT("\tif ((", 6)
				PUSH_VESRCCT(0, 0)
				APPEND_OUTPUT(" < 0.) || (", 11)
				PUSH_VESRCCT(0, 1)
				APPEND_OUTPUT(" < 0.) || (", 11)
				PUSH_VESRCCT(0, 2)
				APPEND_OUTPUT(" < 0.) || (", 11)
				PUSH_VESRCCT(0, 3)
				APPEND_OUTPUT(" < 0.)) return;\n", 16);
				break;
				
			case INST_LG2: // "Exact"
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(1)
				APPEND_OUTPUT("log2(", 5)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(1)
				FINISH_INST
				
			case INST_LIT:
				INST_VECTOR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(1.0, max(", 14)
				PUSH_VESRCCT(1, 0)
				APPEND_OUTPUT(", 0.0), (", 9)
				PUSH_VESRCCT(1, 0)
				APPEND_OUTPUT(" > 0.0) ? pow(max(", 18)
				PUSH_VESRCCT(1, 1)
				APPEND_OUTPUT(", 0.0), clamp(", 14)
				PUSH_VESRCCT(1, 3)
				APPEND_OUTPUT(", -180., 180.)) : 0.0, 1.0)", 27)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_LOG: // Approximate
				if (!vertex) {
					FAIL("Invalid instruction in fragment shaders");
				}
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = vec4(floor(log2(abs(", 23)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT("))), abs(", 9)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT(") / exp2(floor(log2(abs(", 24)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT(")))), log2(abs(", 15)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT(")), 1.)", 7)
				FINISH_INST
				
			case INST_LRP:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				INST_TRIVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("mix(", 4)
				PUSH_VECTSRC(3)
				APPEND_OUTPUT(", ", 2)
				PUSH_VECTSRC(2)
				APPEND_OUTPUT(", ", 2)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_MAD:
				INST_TRIVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(1)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(" * ", 3)
				PUSH_VECTSRC(2)
				APPEND_OUTPUT(" + ", 3)
				PUSH_VECTSRC(3)
				PUSH_POSTSAT(1)
				FINISH_INST
				
			case INST_MAX:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("max(", 4)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(", ", 2)
				PUSH_VECTSRC(2)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_MIN:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("min(", 4)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(", ", 2)
				PUSH_VECTSRC(2)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_MOV:
				INST_VECTOR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				PUSH_VECTSRC(1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_MUL:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(1)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(" * ", 3)
				PUSH_VECTSRC(2)
				PUSH_POSTSAT(1)
				FINISH_INST
				
			case INST_POW:
				INST_BINSCL
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("pow(", 4)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT(", ", 2)
				PUSH_SCALSRC(2)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_RCP:
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("(1 / ", 5)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_RSQ:
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("(sqrt(1 / ", 10)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT("))", 2)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_SCS:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(cos(", 9)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT("), sin(", 7)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT("), 0., 0.)", 10)
				PUSH_POSTSAT(0)
				FINISH_INST
				break;
				
			case INST_SGE:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = vec4((", 9)
				PUSH_VESRCCT(1, 0)
				APPEND_OUTPUT(" >= ", 4)
				PUSH_VESRCCT(2, 0)
				APPEND_OUTPUT(") ? 1. : 0., (", 14)
				PUSH_VESRCCT(1, 1)
				APPEND_OUTPUT(" >= ", 4)
				PUSH_VESRCCT(2, 1)
				APPEND_OUTPUT(") ? 1. : 0., (", 14)
				PUSH_VESRCCT(1, 2)
				APPEND_OUTPUT(" >= ", 4)
				PUSH_VESRCCT(2, 2)
				APPEND_OUTPUT(") ? 1. : 0., (", 14)
				PUSH_VESRCCT(1, 3)
				APPEND_OUTPUT(" >= ", 4)
				PUSH_VESRCCT(2, 3)
				APPEND_OUTPUT(") ? 1. : 0.)", 12)
				FINISH_INST
				
			case INST_SIN:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				INST_SCALAR
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(sin(", 9)
				PUSH_SCALSRC(1)
				APPEND_OUTPUT("))", 2)
				PUSH_POSTSAT(0)
				FINISH_INST
				break;
				
			case INST_SLT:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = vec4((", 9)
				PUSH_VESRCCT(1, 0)
				APPEND_OUTPUT(" < ", 3)
				PUSH_VESRCCT(2, 0)
				APPEND_OUTPUT(") ? 1. : 0., (", 14)
				PUSH_VESRCCT(1, 1)
				APPEND_OUTPUT(" < ", 3)
				PUSH_VESRCCT(2, 1)
				APPEND_OUTPUT(") ? 1. : 0., (", 14)
				PUSH_VESRCCT(1, 2)
				APPEND_OUTPUT(" < ", 3)
				PUSH_VESRCCT(2, 2)
				APPEND_OUTPUT(") ? 1. : 0., (", 14)
				PUSH_VESRCCT(1, 3)
				APPEND_OUTPUT(" < ", 3)
				PUSH_VESRCCT(2, 3)
				APPEND_OUTPUT(") ? 1. : 0.)", 12)
				FINISH_INST
				
			case INST_SUB:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(1)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(" - ", 3)
				PUSH_VECTSRC(2)
				PUSH_POSTSAT(1)
				FINISH_INST
				
			case INST_SWZ:
				// TODO
				FAIL("ARBconv TODO: SWZ");
				break;
				
			case INST_TEX:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				INST_SAMPLE
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				// APPEND_OUTPUT("texture(", 8)
				APPEND_OUTPUT("texture", 7) // Deprecated! (but texture is not official until 1.30)
				PUSH_SAMPFCN(3)
				APPEND_OUTPUT("(", 1)
				PUSH_SAMPLER(2, 3)
				APPEND_OUTPUT(", ", 2)
				PUSH_VECTSMP(1, 3)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_TXB:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				INST_SAMPLE
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				// APPEND_OUTPUT("texture(", 8)
				APPEND_OUTPUT("texture", 7) // Deprecated! (but texture is not official until 1.30)
				PUSH_SAMPFCN(3)
				APPEND_OUTPUT("(", 1)
				PUSH_SAMPLER(2, 3)
				APPEND_OUTPUT(", ", 2)
				PUSH_VECTSMP(1, 3)
				APPEND_OUTPUT(", ", 2)
				PUSH_VESRCCT(1, 3)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_TXP:
				if (vertex) {
					FAIL("Invalid instruction in vertex shader");
				}
				INST_SAMPLE
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				// APPEND_OUTPUT("textureProj(", 12)
				APPEND_OUTPUT("texture", 7) // Deprecated! (but texture is not official until 1.30)
				PUSH_SAMPFCN(3)
				APPEND_OUTPUT("Proj(", 5)
				PUSH_SAMPLER(2, 3)
				APPEND_OUTPUT(", ", 2)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(")", 1)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_XPD:
				INST_BINVEC
				APPEND_OUTPUT("\t", 1)
				PUSH_MASKDST(0)
				APPEND_OUTPUT(" = ", 3)
				PUSH_PRE_SAT(0)
				APPEND_OUTPUT("vec4(cross(", 11)
				PUSH_VECTSRC(1)
				APPEND_OUTPUT(".xyz, ", 6)
				PUSH_VECTSRC(2)
				APPEND_OUTPUT(".xyz), 0.)", 10)
				PUSH_POSTSAT(0)
				FINISH_INST
				
			case INST_UNK:
				FAIL("Unknown instruction (unexpected fallthrough?)");
			}
			
#undef FINISH_INST
#undef PUSH_SAMPFCN
#undef PUSH_SAMPLER
#undef PUSH_VECTSMP
#undef PUSH_SCALSRC
#undef PUSH_VESRCCT
#undef PUSH_VECTSRC
#undef PUSH_MASKDST
#undef PUSH_POSTSAT
#undef PUSH_PRE_SAT
#undef PUSH_VARNAME
#undef PUSH_DSTMASK
#undef INST_SAMPLE
#undef INST_TRIVEC
#undef INST_BINVEC
#undef INST_BINSCL
#undef INST_SCALAR
#undef INST_VECTOR
#undef ASSERT_SCALSRC
#undef ASSERT_VECTSRC
#undef ASSERT_MASKDST
#undef ASSERT_COUNT
#undef PUSH_SWIZZLE
#undef SWIZ
		}
		if (curStatus.status == ST_ERROR) {
			--instIdx;
			glsl->error_ptr = curStatus.instructions.insts[instIdx]->codeLocation - code;
			break;
		}
		
		APPEND_OUTPUT("\t\n", 2)
		for (varIdx = 0; (varIdx < curStatus.variables.size) && (curStatus.status != ST_ERROR); ++varIdx) {
			varPtr = curStatus.variables.vars[varIdx];
			
			if (varPtr->type != VARTYPE_OUTPUT) {
				continue;
			}
			
			ARBCONV_DBG_AS(
				printf("Variable #%2ld (output): %10s (%10s)\n", varIdx, varPtr->names[0], VARTYPE2STR(varPtr->type));
				fflush(stdout);
			)
			
			APPEND_OUTPUT("\t", 1)
			APPEND_OUTPUT(varPtr->init.strings[0], varPtr->init.strings_total_len)
			APPEND_OUTPUT(" = ", 3)
			APPEND_OUTPUT2(varPtr->names[0])
			APPEND_OUTPUT(";\n", 2)
		}
		if (curStatus.status == ST_ERROR) {
			--varIdx;
			glsl->error_ptr = 2;
			break;
		}
		
		APPEND_OUTPUT("}\n", 2)
	} while (0);
	
#undef FAIL
#undef APPEND_OUTPUT
#undef APPEND_OUTPUT2
	
	if (curStatus.status == ST_ERROR) {
		ARBCONV_DBG(printf("Failure!\n");
		
		printf("\nVariables:\n==========\n");
		{
			const char *kvar;
			sVariable *vvar;
			kh_foreach(curStatus.varsMap, kvar, vvar, 
				if (vvar) {
					printf("Variable %10s pointing to %p (%10s)\n", kvar, vvar, vvar->names[0]);
				} else {
					printf("\033[91mVariable %10s pointing to NULLptr!\033[m\n", kvar);
				}
			)
		}
		for (size_t i = 0; i < curStatus.variables.size; ++i) {
			varPtr = curStatus.variables.vars[i];
			printf("%sVariable %p %10s (%lu): %-10s (init = %3lu %s)\033[m\n", (i < varIdx) ? "" : "\033[91m", varPtr, varPtr->names[0], varPtr->names_count, VARTYPE2STR(varPtr->type), varPtr->init.strings_total_len, varPtr->init.strings_count ? varPtr->init.strings[0] : "(none)");
		}
		printf("\nInstructions:\n=============\n");
		for (size_t i = 0; i < curStatus.instructions.size; ++i) {
			instPtr = curStatus.instructions.insts[i];
			if (INSTTEX(instPtr->type)) {
				printf("%sInstruction %3s%4s %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %ctexture[%2s]      %c%19s\033[m\n", (i < instIdx) ? "" : "\033[91m", INST2STR(instPtr->type), instPtr->saturated ? "_SAT" : "    ",
					instPtr->vars[0].sign ? (instPtr->vars[0].sign == -1 ? '-' : '+') : ' ', instPtr->vars[0].var ? ((instPtr->vars[0].var->type == VARTYPE_CONST) ? instPtr->vars[0].var->init.strings[0] : instPtr->vars[0].var->names[0]) : "(none)", instPtr->vars[0].floatArrAddr, (instPtr->vars[0].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[1].sign ? (instPtr->vars[1].sign == -1 ? '-' : '+') : ' ', instPtr->vars[1].var ? ((instPtr->vars[1].var->type == VARTYPE_CONST) ? instPtr->vars[1].var->init.strings[0] : instPtr->vars[1].var->names[0]) : "(none)", instPtr->vars[1].floatArrAddr, (instPtr->vars[1].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[2].sign ? (instPtr->vars[2].sign == -1 ? '-' : '+') : ' ', instPtr->vars[2].var->names[0],
					instPtr->vars[3].sign ? (instPtr->vars[3].sign == -1 ? '-' : '+') : ' ', (instPtr->vars[3].var == curStatus.tex1D) ? "1D" : (instPtr->vars[3].var == curStatus.tex2D) ? "2D" : (instPtr->vars[3].var == curStatus.tex3D) ? "3D" : (instPtr->vars[3].var == curStatus.texCUBE) ? "CUBE" : (instPtr->vars[3].var == curStatus.texRECT) ? "RECT" : "!!!"
				);
			} else {
				printf("%sInstruction %3s%4s %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c %c%10s[%2d].%c%c%c%c\033[m\n", (i < instIdx) ? "" : "\033[91m", INST2STR(instPtr->type), instPtr->saturated ? "_SAT" : "    ",
					instPtr->vars[0].sign ? (instPtr->vars[0].sign == -1 ? '-' : '+') : ' ', instPtr->vars[0].var ? ((instPtr->vars[0].var->type == VARTYPE_CONST) ? instPtr->vars[0].var->init.strings[0] : instPtr->vars[0].var->names[0]) : "(none)", instPtr->vars[0].floatArrAddr, (instPtr->vars[0].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[0].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[0].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[0].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[0].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[1].sign ? (instPtr->vars[1].sign == -1 ? '-' : '+') : ' ', instPtr->vars[1].var ? ((instPtr->vars[1].var->type == VARTYPE_CONST) ? instPtr->vars[1].var->init.strings[0] : instPtr->vars[1].var->names[0]) : "(none)", instPtr->vars[1].floatArrAddr, (instPtr->vars[1].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[1].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[1].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[1].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[1].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[2].sign ? (instPtr->vars[2].sign == -1 ? '-' : '+') : ' ', instPtr->vars[2].var ? ((instPtr->vars[2].var->type == VARTYPE_CONST) ? instPtr->vars[2].var->init.strings[0] : instPtr->vars[2].var->names[0]) : "(none)", instPtr->vars[2].floatArrAddr, (instPtr->vars[2].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[2].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[2].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[2].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[2].swizzle[3] == SWIZ_W) ? 'w' : ' ',
					instPtr->vars[3].sign ? (instPtr->vars[3].sign == -1 ? '-' : '+') : ' ', instPtr->vars[3].var ? ((instPtr->vars[3].var->type == VARTYPE_CONST) ? instPtr->vars[3].var->init.strings[0] : instPtr->vars[3].var->names[0]) : "(none)", instPtr->vars[3].floatArrAddr, (instPtr->vars[3].swizzle[0] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[0] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[0] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[0] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[1] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[1] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[1] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[1] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[2] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[2] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[2] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[2] == SWIZ_W) ? 'w' : ' ', (instPtr->vars[3].swizzle[3] == SWIZ_X) ? 'x' : (instPtr->vars[3].swizzle[3] == SWIZ_Y) ? 'y' : (instPtr->vars[3].swizzle[3] == SWIZ_Z) ? 'z' : (instPtr->vars[3].swizzle[3] == SWIZ_W) ? 'w' : ' '
				);
			}
		}
		
		printf("\nBuffered output:\n%s\n", curStatus.outputString);)
		
		if (glsl->error_ptr != -1) {
			if (glsl->error_msg)
				free(glsl->error_msg);
			glsl->error_msg = strdup("Not enough memory(?)");
			glsl->error_ptr = 0;
		}
		
		// We have errored, output NULL
		freeStatus(&curStatus);
		free(curStatus.outputString);
		return NULL;
	}
	
	ARBCONV_DBG(printf("Success!\n\nOutput:\n%s", curStatus.outputString);)
	
	freeStatus(&curStatus);
	return curStatus.outputString;
}
