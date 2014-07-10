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

    void on_hueSlider_sliderMoved(int position);

    void on_satSlider_sliderMoved(int position);

    void on_valueSlider_sliderMoved(int position);

    void on_alphaSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    void updateColor(void);
    DwmColor initialDwmColor;
    int4 currentAHSV;
};

#endif // MAINWINDOW_H
