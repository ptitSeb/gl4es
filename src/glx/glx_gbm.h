#ifndef _GLX_GBM_H_
#define _GLX_GBM_H_

void LoadGBMFunctions();
void CloseGBMFunctions();

void* OpenGBMDisplay(void* display);

void* CreateGBMWindow(int w, int h);
void DeleteGBMWindow(void* win);

#if !defined(NOEGL) && !defined(ANDROID)
int FindGBMConfig(EGLConfig *configs, int numFounds);
#endif

#endif // _GLX_GBM_H_