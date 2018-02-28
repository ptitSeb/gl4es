#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "preproc.h"
#include "string_utils.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

typedef enum _eTokenType {
    TK_NULL = 0,
    TK_SPACE,
    TK_SHARP,
    TK_NEWLINE,
    TK_INT,
    TK_FLOAT,
    TK_PLUS,
    TK_MINUS,
    TK_EQUAL,
    TK_SLASH,
    TK_DOUBLESLASH,
    TK_MULTIPLY,
    TK_BACKSLASH,
    TK_OPENBRACE,
    TK_CLOSEBRACE,
    TK_OPENCURLY,
    TK_CLOSECURLY,
    TK_OPENBRAKET,
    TK_CLOSEBRAKET,
    TK_OPENCOMMENT,
    TK_CLOSECOMMENT,
    TK_AMP,
    TK_POW,
    TK_PIPE,
    TK_EXCLAM,
    TK_POINT,
    TK_GREATER,
    TK_LESS,
    TK_DOUBLEEQUAL,
    TK_TILDE,
    TK_TEXT,
    TK_TEXTCOMMENT
} eTokenType;

#define MAXSTR 500

typedef struct _uToken {
    eTokenType type;
    char    str[MAXSTR];
    int     integer;
    float   real;
} uToken;

eTokenType NextTokenComment(char **p, uToken *tok) {
    tok->type = TK_NULL;
    tok->str[0] = 0;
    if(!**p) return tok->type;

    char c = **p;
    (*p)++;
    char nextc = **p;
    int nb = 0;
    int isfloat = 0;
    int isneg = 1;  // multiply by it...
    float fnb = 0.f;
    int cnt = 0;
    float fcnt = 0.f;

    tok->str[0]=c; tok->str[1]=0;

    switch (c) {
        case 10:
            if(nextc==13)
                (*p)++;
            strcpy(tok->str, "\n");
            tok->type = TK_NEWLINE;
            break;
        case 13:
            if(nextc==10)
                (*p)++;
            strcpy(tok->str, "\n");
            tok->type = TK_NEWLINE;
            break;
        case ' ':
        case '\t':
            while(nextc==' ' || nextc=='\t') { int l=strlen(tok->str); tok->str[l]=nextc; tok->str[l+1]=0; (*p)++; nextc=**p; }
            tok->type = TK_SPACE;
            break;
        case '/':
            if(nextc=='/') {
                (*p)++;
                tok->type=TK_DOUBLESLASH;
                strcpy(tok->str, "//");
            } else if(nextc=='*') {
                (*p)++;
                tok->type=TK_OPENCOMMENT;
                strcpy(tok->str, "/*");
            } else {
                tok->type=TK_SLASH;
            }
            break;
        case '*':
            if(nextc=='/') {
                (*p)++;
                tok->type=TK_CLOSECOMMENT;
                strcpy(tok->str, "*/");
            } else {
                tok->type=TK_MULTIPLY;
            }
            break;
        default:
            // all other are plain Ids...
            cnt=1;
            tok->type=TK_TEXTCOMMENT;
            while(cnt!=(MAXSTR-1) && (nextc=='_' || (nextc>='0' && nextc<='9') || (nextc>='A' && nextc<='Z') || (nextc>='a' && nextc<='z'))) {
                tok->str[cnt]=nextc;
                (*p)++; nextc=**p;
                ++cnt;
            }
            tok->str[cnt]=0;
    }

    return tok->type;
}

eTokenType NextToken(char **p, uToken *tok) {
    tok->type = TK_NULL;
    tok->str[0] = 0;
    if(!**p) return tok->type;

    char c = **p;
    (*p)++;
    char nextc = **p;
    int nb = 0;
    int isfloat = 0;
    int isneg = 1;  // multiply by it...
    float fnb = 0.f;
    int cnt = 0;
    float fcnt = 0.f;

    tok->str[0]=c; tok->str[1]=0;

    switch (c) {
        case 10:
            if(nextc==13)
                (*p)++;
            tok->type = TK_NEWLINE;
            strcpy(tok->str, "\n");
            break;
        case 13:
            if(nextc==10)
                (*p)++;
            tok->type = TK_NEWLINE;
            strcpy(tok->str, "\n");
            break;
        case ' ':
        case '\t':
            while(nextc==' ' || nextc=='\t') { int l=strlen(tok->str); tok->str[l]=nextc; tok->str[l+1]=0; (*p)++; nextc=**p; }
            tok->type = TK_SPACE;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            nb=c-'0';
            // we don't know if it's an int or a float at first...
            if(nextc=='x' && nb==0) {
                // hex number, so int...
                (*p)++; nextc=**p;
                while((nextc>='0' && nextc<='9') || (nextc>='a' && nextc<='f') || (nextc>='A' && nextc<='F')) { 
                    nb=nb*10;
                    if(nextc>='0' && nextc<='9')
                        nb+=nextc-'0';
                    else if(nextc>='a' && nextc<='f')
                        nb+=nextc-'a'+10;
                    else if(nextc>='A' && nextc<='F')
                        nb+=nextc-'a'+10;
                    (*p)++; nextc=**p;
                }
                tok->type = TK_INT;
                tok->integer = nb;
                sprintf(tok->str, "%x", nb);
            } else {
                while(nextc>='0' && nextc<='9') { nb=nb*10+nextc-'0'; (*p)++; nextc=**p;}
                if(nextc=='.' || nextc=='f' || nextc=='e') {
                    isfloat = 1;
                    fnb=nb;
                    if(nextc=='.') {
                        (*p)++; nextc=**p;
                        fcnt = 0.1f;
                        while(nextc>='0' && nextc<='9') { 
                            fnb+=(nextc-'0')*fcnt;
                            fcnt/=10.f;
                            (*p)++; nextc=**p;
                        }
                    }
                    if(nextc=='e') {
                        // exponent
                        (*p)++; nextc=**p;
                        nb=0;
                        int expsign = 1;
                        if(nextc=='-' || nextc=='+') {
                            if(nextc=='-') expsign = -1;
                            (*p)++; nextc=**p;
                        }
                        while(nextc>='0' && nextc<='9') { nb=nb*10+nextc-'0'; (*p)++; nextc=**p;}
                        fnb=powf(fnb, nb*expsign);
                    }
                    if(nextc=='f') {
                        (*p)++; nextc=**p;
                    }
                    fnb*=isneg;
                    tok->type = TK_FLOAT;
                    tok->real = fnb;
                    sprintf(tok->str, "%f", fnb);
                } else {
                    tok->type = TK_INT;
                    tok->integer = nb;
                    sprintf(tok->str, "%d", nb);
                }
            }
            break;
        case '/':
            if(nextc=='/') {
                (*p)++;
                tok->type=TK_DOUBLESLASH;
                strcpy(tok->str, "//");
            } else if(nextc=='*') {
                (*p)++;
                tok->type=TK_OPENCOMMENT;
                strcpy(tok->str, "/*");
            } else {
                tok->type=TK_SLASH;
            }
            break;
        case '*':
            if(nextc=='/') {
                (*p)++;
                tok->type=TK_CLOSECOMMENT;
                strcpy(tok->str, "*/");
            } else {
                tok->type=TK_MULTIPLY;
            }
            break;
        case '=': tok->type=TK_EQUAL; break;
        case '~': tok->type=TK_TILDE; break;
        case '#': tok->type=TK_SHARP; break;
        case '(': tok->type=TK_OPENBRACE; break;
        case ')': tok->type=TK_CLOSEBRACE; break;
        case '{': tok->type=TK_OPENCURLY; break;
        case '}': tok->type=TK_CLOSECURLY; break;
        case '[': tok->type=TK_OPENBRAKET; break;
        case ']': tok->type=TK_CLOSEBRAKET; break;
        case '&': tok->type=TK_AMP; break;
        case '^': tok->type=TK_POW; break;
        case '|': tok->type=TK_PIPE; break;
        case '\\': tok->type=TK_BACKSLASH; break;
        case '<': tok->type=TK_LESS; break;
        case '>': tok->type=TK_GREATER; break;
        case '+': tok->type=TK_PLUS; break;
        case '-': tok->type=TK_MINUS; break;
        // todo: char and string?
        default:
            // all other are plain Ids...
            cnt=1;
            tok->type=TK_TEXT;
            while(cnt!=(MAXSTR-1) && (nextc=='_' || (nextc>='0' && nextc<='9') || (nextc>='A' && nextc<='Z') || (nextc>='a' && nextc<='z'))) {
                tok->str[cnt]=nextc;
                (*p)++; nextc=**p;
                ++cnt;
            }
            tok->str[cnt]=0;
    }

    return tok->type;
}

eTokenType GetToken(char **p, uToken *tok, int incomment) {
    eTokenType ret;
    if (incomment)
        ret = NextTokenComment(p, tok);
    else
        ret = NextToken(p, tok);
    return ret;
}

char* preproc(const char* code, int keepcomments) {
    DBG(printf("Preproc on: =========\n%s\n=================\n", code);)

    uToken tok;
    char* p = (char*)code;
    int cap=1000;
    char* ncode = (char*)malloc(1000);
    ncode[0]=0;
    int sz=1;
    int status=0;
    int write=1;
    int incomment=0;
    while(GetToken(&p, &tok, incomment)!=TK_NULL) {
        switch(status) {
            case 210:   // block comment done
            case 110:   // line comment done...
                write = 1;
                status = 0;
                incomment=0;
            case 0: // regular...
                if(tok.type==TK_DOUBLESLASH) {
                    status = 100; // line comment
                    incomment = 1;
                    if(!keepcomments) write=0;
                } else if(tok.type==TK_OPENCOMMENT) {
                    status = 200; // multi-line comment
                    incomment = 1;
                    if(!keepcomments) write=0;
                }
                break;

            // line comment...
            case 100:
                if(tok.type==TK_BACKSLASH) {
                    status = 120;   // is it backslash+endline for multiline?
                } else if(tok.type==TK_NEWLINE) {
                    status = 110;
                }
                break;
            case 120:
                status = 100;   // continue comment, what ever follow (NewLine or anything else)
                break;

            // block comment...
            case 200:
                if(tok.type==TK_CLOSECOMMENT) {
                    status=210;
                }
                break;
        }
        if(write) {
            int l = strlen(tok.str);
            if(sz+l>=cap) {
                cap+=2000;
                ncode = (char*)realloc(ncode, cap);
            }
            strcat(ncode, tok.str);
            sz+=l;
        }
    }

    DBG(printf("New code is: ------------\n%s\n------------------\n", ncode);)

    return ncode;
}