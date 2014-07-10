#pragma once

#include "dllTools.h"

#ifdef QT_DEBUG
#include <iostream>
#endif

int loadDwmDll(HRESULT(WINAPI *&getDwmStatus_) (BOOL *ok),
    HRESULT(WINAPI *&setDwmColors_) (DwmColor *color, UINT unknown),
    HRESULT (WINAPI *&getDwmColors_) (DwmColor *color)
    )
{
    HMODULE hlib = LoadLibrary((LPCWSTR)L"dwmapi.dll"); // load the Window Manager API

    if (!hlib) {
#ifdef QT_DEBUG
        std::cerr << "Could not load dwmapi.dll" << std::endl;
#endif
        return 0;
    }
    *(FARPROC *)&getDwmStatus_ = GetProcAddress(hlib, (LPCSTR)"DwmIsCompositionEnabled");
    *(FARPROC *)&getDwmColors_ = GetProcAddress(hlib, (LPCSTR)127);
    *(FARPROC *)&setDwmColors_ = GetProcAddress(hlib, (LPCSTR)131);

    return 1;
}
