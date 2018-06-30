#ifndef __STRING_UTILS_H__
#define __STRING_UTILS_H__

const char* AllSeparators;

int CountString(char* pBuffer, const char* S);
char* ResizeIfNeeded(char* pBuffer, int *size, int addsize);
char* InplaceReplace(char* pBuffer, int* size, const char* S, const char* D);
char* Append(char* pBuffer, int* size, const char* S);
void InplaceInsert(char* pBuffer, const char* S);
char* GetLine(char* pBuffer, int num);
int CountLine(const char* pBuffer);
int CountString(char* pBuffer, const char* S);
char* StrNext(char *pBuffer, const char* S); // mostly as strstr, but go after the substring if found
//"blank" (space, tab, cr, lf,":", ",", ";", ".", "/")
char* NextStr(char* pBuffer);   // go to next non "blank"
char* NextBlank(char* pBuffer);   // go to next "blank"
char* NextLine(char* pBuffer);   // go to next new line (crlf not included)

#endif //__STRING_UTILS_H__