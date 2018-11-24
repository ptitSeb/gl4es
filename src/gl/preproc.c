#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "preproc.h"
#include "string_utils.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#pragma GCC optimize 0
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
    TK_COLUMN,
    TK_SEMICOLUMN,
    TK_COMMA,
    TK_DOT,
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
                    nb=nb*16;
                    if(nextc>='0' && nextc<='9')
                        nb+=nextc-'0';
                    else if(nextc>='a' && nextc<='f')
                        nb+=nextc-'a'+10;
                    else if(nextc>='A' && nextc<='F')
                        nb+=nextc-'A'+10;
                    (*p)++; nextc=**p;
                }
                tok->type = TK_INT;
                tok->integer = nb;
                sprintf(tok->str, "0x%x", nb);
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
        case ':': tok->type=TK_COLUMN; break;
        case ';': tok->type=TK_SEMICOLUMN; break;
        case ',': tok->type=TK_COMMA; break;
        case '.': tok->type=TK_DOT; break;
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

char* preproc(const char* code, int keepcomments, int gl_es, extensions_t* exts) {
    DBG(printf("Preproc on: =========\n%s\n=================\n", code);)

    uToken tok;
    char* p = (char*)code;
    char* oldp = NULL;
    int cap=1000;
    char* ncode = (char*)malloc(1000);
    ncode[0]=0;
    int sz=1;
    int status=0;
    int write=1;
    int incomment=0;
    int newline=0;
    int gettok=0;
    int ifdef_gl_es = 0;
    int nowrite_gl_es = 0;
    int notok = 0;
    char extname[50];
    GetToken(&p, &tok, incomment);
    while(tok.type!=TK_NULL) {
        // pre get token switch
        switch(status) {
            case 110:   // line comment done...
            case 210:   // block comment done
                if(!write && newline) {
                    gettok=0;
                    tok.type=TK_NEWLINE;
                    strcpy(tok.str, "\n");
                }
                write = 1;
                status = (status==210)?1:0;
                incomment=0;
                newline=0;
            break;
        }
        // get token (if needed)
        if (gettok) GetToken(&p, &tok, incomment);
        gettok=1;
        // post get token switch
        if(tok.type!=TK_NULL) {
            switch(status) {
                case 0: // regular...
                case 1:
                    if(tok.type==TK_DOUBLESLASH) {
                        status = 100; // line comment
                        incomment = 1;
                        newline = 1;
                        if(!keepcomments) write=0;
                    } else if(tok.type==TK_OPENCOMMENT) {
                        status = 200; // multi-line comment
                        incomment = 1;
                        if(!keepcomments) write=0;
                    } else if(tok.type==TK_SHARP && !incomment && status==0) {
                        oldp = p-1; // lets buffer the line
                        status = 300;
                    } else if(tok.type==TK_NEWLINE)
                        status = 0;
                    else if(tok.type!=TK_SPACE)
                        status = 1; // everything else but space set status to 1...
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
                    if(tok.type==TK_NEWLINE)
                        newline=1;
                    if(tok.type==TK_CLOSECOMMENT) {
                        status=210;
                    }
                    break;
                
                // # (of ifdef or extension)
                case 300:
                    if(tok.type!=TK_SPACE)
                    if(tok.type==TK_TEXT) {
                        if(!strcmp(tok.str, "ifdef"))
                            status=gl_es?310:399;
                        else if(!strcmp(tok.str, "ifndef"))
                            status=gl_es?320:399;
                        else if(!strcmp(tok.str, "if")) {
                            // #if defined(GL_ES) not supported for now
                            if(ifdef_gl_es)
                                ifdef_gl_es++;
                            status = 399;
                        }
                        else if(!strcmp(tok.str, "else")) {
                            status = 399;
                            if(ifdef_gl_es==1) {
                                nowrite_gl_es = 1 - nowrite_gl_es;
                                notok = 1;
                                status = 1;
                            }
                        } else if(!strcmp(tok.str, "endif")) {
                            status = 399;
                            if(ifdef_gl_es) {
                                --ifdef_gl_es;
                                if(!ifdef_gl_es) {
                                    nowrite_gl_es = 0;
                                    notok = 1;
                                    status = 1;
                                    oldp = NULL;
                                }
                            }
                        } else if(!strcmp(tok.str, "extension")) {
                            status = 410;
                        } else if(!strcmp(tok.str, "pragma")) {
                            status = 510;
                        } else status=399;
                    } else status = 399;  // meh?
                    break;

                // ifdef
                case 310:
                    if(tok.type==TK_SPACE)
                        status = 310;
                    else if(tok.type==TK_TEXT) {
                        if(!ifdef_gl_es && !strcmp(tok.str, "GL_ES")) {
                            ifdef_gl_es++;
                            nowrite_gl_es = 1;   // multiple level of #if(n)def GL_ES will fail!
                            status = 398;
                        } else {
                            if(ifdef_gl_es)
                                ifdef_gl_es++;
                            status = 399;
                        }
                    } else status = 399;
                    break;
                
                // ifndef
                case 320:
                    if(tok.type==TK_SPACE)
                        status = 320;
                    else if(tok.type==TK_TEXT) {
                        if(!ifdef_gl_es && !strcmp(tok.str, "GL_ES")) {
                            ifdef_gl_es++;
                            nowrite_gl_es = 0;
                            status = 398;
                        } else {
                            if(ifdef_gl_es)
                                ifdef_gl_es++;
                            status = 399;
                        }
                    } else status = 399;
                    break;

                // end of #ifdef GL_ES and variant..
                case 398:
                    if(tok.type==TK_NEWLINE) {
                        oldp = NULL;
                        status = 0;
                    }
                    break;

                // fallback for #ifdef GL_ES, write the line back...
                case 399:
                    {
                        int l = p - oldp;
                        memcpy(tok.str, oldp, l);
                        tok.str[l]='\0';
                        oldp = 0;
                    }
                    status = 1;
                    break;
                // #extension
                case 410:
                    if(tok.type==TK_SPACE) {
                        // nothing...
                    } else if(tok.type==TK_TEXT && strlen(tok.str)<50) {
                        strcpy(extname, tok.str);
                        status = 420;
                    } else {
                        status = 399; // fallback, syntax error...
                    }
                    break;
                // after the name and before the ':' of #extension
                case 420:
                    if(tok.type==TK_SPACE) {
                        // nothing...
                    } else if (tok.type==TK_COLUMN) {
                        status=430;
                    } else {
                        status = 399; // fallback, syntax error...
                    }
                    break;
                // after the ':' of #extension
                case 430:
                    if(tok.type==TK_SPACE) {
                        // nothing...
                    } else if(tok.type==TK_TEXT) {
                        int state = -1;
                        if(!strcmp(tok.str, "disable"))
                            state = 0;
                        else if(!strcmp(tok.str, "warn"))
                            state = 1;
                        else if(!strcmp(tok.str, "enable"))
                            state = 1;
                        else if(!strcmp(tok.str, "require"))
                            state = 1;
                        if(state!=-1) {
                            if(exts->size==exts->cap) {
                                exts->cap += 4;
                                exts->ext = (extension_t*)realloc(exts->ext, sizeof(exts)*exts->cap);
                            }
                            strcpy(exts->ext[exts->size].name, extname);
                            exts->ext[exts->size].state = state;
                            ++exts->size;
                            status = 398;   // all done
                        } else
                            status = 399; // error, unknown keyword
                    } else {
                        status = 399; // fallback, syntax error...
                    }
                    break;
                // #pragma
                case 510:
                    if(tok.type==TK_SPACE) {
                        // nothing...
                    } else if(tok.type==TK_TEXT && strlen(tok.str)<50) {
                        if(strcmp(tok.str, "message")==0)
                            status = 398; //pragma message are removed
                        else if(strcmp(tok.str, "parameter")==0)
                            status = 398; //pragma message are removed
                        else
                            status = 399;   // other pragma as left as-is
                    } else {
                        status = 399; // fallback, syntax error...
                    }
                    break;
            }
            if(notok)
                notok=0;
            else
                if(write && !oldp && !nowrite_gl_es) {
                    int l = strlen(tok.str);
                    if(sz+l>=cap) {
                        cap+=2000;
                        ncode = (char*)realloc(ncode, cap);
                    }
                    strcat(ncode, tok.str);
                    sz+=l;
                }
        }
    }

    DBG(printf("New code is: ------------\n%s\n------------------\n", ncode);)

    return ncode;
}