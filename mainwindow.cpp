#include <math.h>

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

    currentARGB.x = 0;
    currentARGB.y = 0;
    currentARGB.z = 0;
    currentARGB.w = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
    setDwmColors(&initialDwmColor, 0);
}

void MainWindow::updateColor()
{
    if (!ui->previewColorCheckbox->isChecked()) { // preview is disabled
        return;
    }

    Color myColor;
    myColor.SetARGB(this->currentARGB);
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

void MainWindow::on_hueRedSlider_valueChanged(int position)
{
    if (ui->hsvRadio->isChecked()) { // sliders are AHSV
        int4 ahsv = AHSVfromARGB(currentARGB);
        ahsv.x = position;
        currentARGB = ARGBfromAHSV(ahsv);
    } else {
        currentARGB.x = position;
    }
    updateColor();
}

void MainWindow::on_satGreenSlider_valueChanged(int position)
{
    if (ui->hsvRadio->isChecked()) { // sliders are AHSV
        int4 ahsv = AHSVfromARGB(currentARGB);
        ahsv.y = position;
        currentARGB = ARGBfromAHSV(ahsv);
    } else {
        currentARGB.y = position;
    }
    updateColor();
}

void MainWindow::on_valueBlueSlider_valueChanged(int position)
{
    if (ui->hsvRadio->isChecked()) { // sliders are AHSV
        int4 ahsv = AHSVfromARGB(currentARGB);
        ahsv.z = position;
        currentARGB = ARGBfromAHSV(ahsv);
    } else {
        currentARGB.z = position;
    }
    updateColor();
}

void MainWindow::on_alphaSlider_valueChanged(int position)
{
    currentARGB.w = position; // AHSV and ARGB have same alpha channel
    updateColor();
}

void MainWindow::on_hsvRadio_toggled(bool checked)
{
    if (!checked) { // nothing to do
        return;
    }

    // update text on labels
    ui->hueRedLabel->setText("Hue");
    ui->satGreenLabel->setText("Sat");
    ui->valueBlueLabel->setText("Value");

    // move sliders to correct positions
    int4 ahsv = AHSVfromARGB(currentARGB);
    ui->hueRedSlider->setValue(ahsv.x);
    ui->satGreenSlider->setValue(ahsv.y);
    ui->valueBlueSlider->setValue(ahsv.z);
}


void MainWindow::on_rgbRadio_toggled(bool checked)
{
    if (!checked) { // nothing to do
        return;
    }

    // update text on labels
    ui->hueRedLabel->setText("Red");
    ui->satGreenLabel->setText("Green");
    ui->valueBlueLabel->setText("Blue");

    // move sliders to correct positions
    ui->hueRedSlider->setValue(currentARGB.x);
    ui->satGreenSlider->setValue(currentARGB.y);
    ui->valueBlueSlider->setValue(currentARGB.z);
}

void MainWindow::on_randomizeColorButton_clicked()
{
    if (ui->hsvRadio->isChecked()) {
        // for HSV we will prefer high saturation, light colors
        if (rand() % 3) { // 66% chance of high saturation
            ui->satGreenSlider->setValue(rand() % 128 + 128);
        } else {
            ui->satGreenSlider->setValue(rand() % 256);
        }

        if (rand() % 4) { // 75% chance of light color
            ui->valueBlueSlider->setValue(rand() % 64 + 192);
        } else {
            ui->satGreenSlider->setValue(rand() % 256);
        }

        // choose between hues equally
        ui->hueRedSlider->setValue(rand() % 256);

    } else {
        // for RGB we want to avoid all 3 sliders in the same position

        int seed = rand() % 6 + 1;

        if (rand() % 2) { // 50% chance of respecting seed
            if (seed / 4) {
                ui->hueRedSlider->setValue(rand() % 64 + 192);
            } else {
                ui->hueRedSlider->setValue(rand() % 64);
            }
        } else {
            ui->hueRedSlider->setValue(rand() % 256);
        }

        if (rand() % 2) { // 50% chance of respecting seed
            if (seed / 2 % 2) {
                ui->satGreenSlider->setValue(rand() % 64 + 192);
            } else {
                ui->satGreenSlider->setValue(rand() % 64);
            }
        } else {
            ui->satGreenSlider->setValue(rand() % 256);
        }

        if (rand() % 2) { // 50% chance of respecting seed
            if (seed % 2) {
                ui->valueBlueSlider->setValue(rand() % 64 + 192);
            } else {
                ui->valueBlueSlider->setValue(rand() % 64);
            }
        } else {
            ui->valueBlueSlider->setValue(rand() % 256);
        }
    }

    // prefer higher alphas

    if (rand() % 2) { // 50% chance of high alpha
        ui->alphaSlider->setValue(rand() % 192 + 64);
    } else {
        ui->alphaSlider->setValue(rand() % 256);
    }
}
