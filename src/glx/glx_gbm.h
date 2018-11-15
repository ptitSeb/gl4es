#ifndef __GLX_GBM_H_
#define __GLX_GBM_H_

void LoadGBMFunctions();
void CloseGBMFunctions();

void* OpenGBMDisplay(void* display);

void* CreateGBMWindow(int w, int h);
void DeleteGBMWindow(void* win);

#if !defined(NOEGL)
int gl(EGLConfig *configs, int numFounds);
#endif

#endif //__GLX_GBM_H_