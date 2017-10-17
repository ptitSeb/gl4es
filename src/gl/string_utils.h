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

#endif //__STRING_UTILS_H__