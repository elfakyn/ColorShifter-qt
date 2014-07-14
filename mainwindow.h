#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "colorTools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_previewColorCheckbox_stateChanged(int arg1);

    void on_hueRedSlider_valueChanged(int position);

    void on_satGreenSlider_valueChanged(int position);

    void on_valueBlueSlider_valueChanged(int position);

    void on_alphaSlider_valueChanged(int position);

    void on_hsvRadio_toggled(bool checked);

    void on_rgbRadio_toggled(bool checked);

    void on_randomizeColorButton_clicked();

    void on_removeColorButton_clicked();

    void on_addColorButton_clicked();

    void on_colorTable_itemSelectionChanged();

    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;
    void updateColor(void);
    DwmColor initialDwmColor;
    int4 currentARGB;
};

#endif // MAINWINDOW_H
