#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>

#include "colorTools.h"
#include "palette.h"

#define PALETTE_MAX_PALETTES 30

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

    void on_overrideCheckbox_toggled(bool checked);

    void on_balanceBox_valueChanged(int arg1);

    void on_loadPalettesButton_clicked();

    void on_savePalettesButton_clicked();

private:
    Ui::MainWindow *ui;
    DwmColor initialDwmColor;
    int4 currentARGB;
    table <Palette> palettes;
    int n_palettes;

    void updateColor(void);
    void updateColorTableRowBackground(int row);
    void updateColorTable(int index);
    void loadPalettesFromJSON(QJsonObject json);
    void loadPalettes(QString loadFileName);
    void savePalettes(QString saveFileName);
    QJsonObject savePalettesToJSON(void);

public:
    void updateColorTableDragDrop(int dest, int src);
    void updatePaletteTableDragDrop(int dest, int src);


};

#endif // MAINWINDOW_H
