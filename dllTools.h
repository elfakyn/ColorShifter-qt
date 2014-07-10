#pragma once

#include "Windows.h"
#include "colorTools.h"

int loadDwmDll(HRESULT(WINAPI *&getDwmStatus_) (BOOL *ok),
    HRESULT(WINAPI *&setDwmColors_) (DwmColor *color, UINT unknown),
    HRESULT (WINAPI *&getDwmColors_) (DwmColor *color)
    );
