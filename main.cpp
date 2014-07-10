#pragma once

#ifdef QT_DEBUG
#include <iostream>
#endif

#ifndef DWM_FUNCTIONS
#define DWM_FUNCTIONS
#include <Windows.h>
#include "colorTools.h"
extern HRESULT(WINAPI *getDwmStatus) (BOOL *ok);
extern HRESULT(WINAPI *setDwmColors) (DwmColor *color, UINT unknown);
extern HRESULT(WINAPI *getDwmColors) (DwmColor *color);
#include "dllTools.h"
#endif


#include "mainwindow.h"
#include <QApplication>

#include "exitCodes.h"

int main(int argc, char *argv[])
{

    if (!loadDwmDll(getDwmStatus, setDwmColors, getDwmColors)) {
        exit(EXIT_DLL_LOAD_FAIL);
    }

    BOOL ok;
    getDwmStatus(&ok);
    if (!ok) {
        // TODO: replace with a warning inside the window
        exit(EXIT_COMPOSITION_DISABLED);
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    /*
    Color color1, color2;
    DwmColor crt = { 0 };

    color1.SetMerged(0xFFFF0000);
    color2.SetMerged(0xFF0000FF);
    crt = exportColor(color1);
    setDwmColors(&crt, 0);

    for (int i = 0; i < 100; i++) {
        crt = exportColor(interpolate(color1, color2, i * 1.0 / 100));
        setDwmColors(&crt, 0);
        Sleep(60);
    }
    */

    exit(EXIT_A_EXEC_DID_NOT_RETURN);
}
