#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "colorTools.h"
#include "dllTools.h"

#ifdef QT_DEBUG
#include <iostream>
#endif

#ifndef DWM_FUNCTIONS
#define DWM_FUNCTIONS
#include <Windows.h>
#include "colorTools.h"
HRESULT(WINAPI *getDwmStatus) (BOOL *ok);
HRESULT(WINAPI *setDwmColors) (DwmColor *color, UINT unknown);
HRESULT(WINAPI *getDwmColors) (DwmColor *color);
#include "dllTools.cpp" // Don't ask, don't tell
#include "dllTools.h"
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getDwmColors(&initialDwmColor);

    currentAHSV.x = 0;
    currentAHSV.y = 0;
    currentAHSV.z = 0;
    currentAHSV.w = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateColor()
{
    if (!ui->previewColorCheckbox->isChecked()) { // preview is disabled
        return;
    }

    Color myColor;
    myColor.SetAHSV(this->currentAHSV);
    myColor.SetBalance(80); // to be overridden

#ifdef QT_DEBUG
    std::cout << std::hex << myColor.GetMerged() << std::endl;
#endif

    DwmColor myDwmColor = exportColor(myColor);
    setDwmColors(&myDwmColor, 0);
}


void MainWindow::on_previewColorCheckbox_stateChanged(int arg1)
{
    if (!arg1) { // Checkbox now unchecked
        setDwmColors(&initialDwmColor, 0); // reset colors to initial values
    }
}

void MainWindow::on_hueSlider_sliderMoved(int position)
{
    currentAHSV.x = (int)position;
    updateColor();
}

void MainWindow::on_satSlider_sliderMoved(int position)
{
    currentAHSV.y = (int)position;
    updateColor();
}

void MainWindow::on_valueSlider_sliderMoved(int position)
{
    currentAHSV.z = (int)position;
    updateColor();
}

void MainWindow::on_alphaSlider_sliderMoved(int position)
{
    currentAHSV.w = (int)position;
    updateColor();
}
