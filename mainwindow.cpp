#include <math.h>

#include <QDropEvent>
#include <QMimeData>
#include <QScrollBar>
#include <QHeaderView>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "colorTools.h"
#include "dllTools.h"
#include "flags.h"

#include "palette.h"

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

#define PALETTE_MAX_PALETTES 30

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

    Palette palettes[PALETTE_MAX_PALETTES];

    ui->paletteTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
    setDwmColors(&initialDwmColor, 0);
}

// override the drag-and-drop handler to swap instead of overwrite
void QTableWidget::dropEvent(QDropEvent *event)
{

    if (!event->source()) {
#ifdef QT_DEBUG
        std::cout<< "Table move: external (ignored)" << std::endl;
#endif
        event->ignore();
        return;
    }

    QModelIndex srcIndex = selectedIndexes().first();
    QModelIndex destIndex = indexAt(event->pos());
    int srcRow = srcIndex.row();
    int destRow = destIndex.row();
    int scrollValue = verticalScrollBar()->value();

    if (destRow < 0) { // all the way to the bottom
        destIndex = indexFromItem(item(rowCount()-1, 0));
        destRow = destIndex.row();
    }

#ifdef QT_DEBUG
    std::cout<<"Table move: "<<srcRow<<" "<<destRow;
#endif

    // Cutting corners
    // Without this if statement the drag and drops are offset by one.
    if (srcRow > destRow) {
        srcRow++;
    } else {
        destRow++;
    }

    if (srcRow < property("immutableRows").toInt() || destRow < property("immutableRows").toInt()) {
        // move into forbidden area
#ifdef QT_DEBUG
        std::cout<<", immutable (ignored)"<<std::endl;
#endif
        event->ignore();
        return;
    }

    // copy data over to new row
    insertRow(destRow);
    for (int i = 0; i < columnCount(); i++) {
        QTableWidgetItem *item = takeItem(srcRow, i);
        setItem(destRow, i, item);
    }
    removeRow(srcRow);

    // scroll to correct position and select destination
    selectionModel()->select(destIndex, QItemSelectionModel::ClearAndSelect);
    update();
    verticalScrollBar()->setValue(scrollValue);
    scrollTo(destIndex, QAbstractItemView::EnsureVisible);

#ifdef QT_DEBUG
    std::cout<<" (ok)"<<std::endl;
#endif
    event->ignore(); // override default handler
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
    if (arg1) { // checkbox checked
        updateColor();
    } else {
        setDwmColors(&initialDwmColor, 0); // revert to original colors
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
    if(ui->smartRandomizeCheckbox->isChecked()) {

        // We'll use a "smart" randomizer that prefers nice colors

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
            ui->alphaSlider->setValue(rand() % 128 + 64);
        } else {
            ui->alphaSlider->setValue(rand() % 256);
        }

    } else {

        // dumb randomizer
        ui->hueRedSlider->setValue(rand() % 256);
        ui->satGreenSlider->setValue(rand() % 256);
        ui->valueBlueSlider->setValue(rand() % 256);
        ui->alphaSlider->setValue(rand() % 256);
    }
}

void MainWindow::on_removeColorButton_clicked()
{
    ui->colorTable->removeRow(ui->colorTable->selectedItems().first()->row());

    if (ui->colorTable->rowCount() == 0) { // disable button when table is empty
        ui->removeColorButton->setEnabled(false);
    }
}

void MainWindow::on_addColorButton_clicked()
{
    if (ui->colorTable->rowCount() == 0) { // no rows to insert into
        ui->colorTable->insertRow(0);
        ui->colorTable->selectRow(0);

        ui->removeColorButton->setEnabled(true); // re-enable the remove color button

        // TODO: populate item with default value

        return;
    }

    // insert and select specified row
    int row = ui->colorTable->selectedItems().first()->row() + 1;
    ui->colorTable->insertRow(row);
    ui->colorTable->selectRow(row);

    // copy contents over from previously selected row
    for (int i = 0; i < ui->colorTable->columnCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(*ui->colorTable->item(row - 1, i));
        ui->colorTable->setItem(row, i, item);
    }
}

void MainWindow::on_colorTable_itemSelectionChanged()
{
    if(ui->colorTable->selectedItems().empty()) {
        return; // FIXME: make sure thing is stuff.
    }
    if (ui->colorTable->selectedItems().first()->row() < ui->colorTable->property("immutableRows").toInt()) {
        // cannot delete immutable object
        ui->removeColorButton->setEnabled(false);
    } else {
        // TODO: move this into a recalculateButtonState() function
        ui->removeColorButton->setEnabled(true);
    }
}

void MainWindow::on_quitButton_clicked()
{
    // FIXME: TEMPORARY
    for (int i = 0; i < ui->colorTable->rowCount(); i++) {

        if(ui->colorTable->item(i, 0)) {
            ui->colorTable->item(i,0)->setText(QString::number(i+1));
        } else {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(QString::number(i+1));
            ui->colorTable->setItem(i,0,item);
        }
    }
}
