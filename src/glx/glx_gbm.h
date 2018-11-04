#ifndef __GLX_GBM_H_
#define __GLX_GBM_H_

void LoadGBMFunctions();
void CloseGBMFunctions();

void* OpenGBMDisplay(void* display);

void* CreateGBMWindow(int w, int h);
void DeleteGBMWindow(void* win);

int FindGBMConfig(EGLConfig *configs, int numFounds);

#endif //__GLX_GBM_H_