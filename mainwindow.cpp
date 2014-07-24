#include <math.h>

#include <QDropEvent>
#include <QMimeData>
#include <QScrollBar>
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

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
#include "hacks.h"
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // UI initialization
    ui->setupUi(this);
    ui->paletteTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->colorTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->paletteTable->setItemDelegate(new TableBorderSelection(this));
    ui->colorTable->setItemDelegate(new TableBorderSelection(this));

    ui->sliderGroup->setEnabled(false);
    ui->colorGroup->setEnabled(false);
    ui->mainButton->setEnabled(false);

    // Variable initialization

    getDwmColors(&initialDwmColor);
    currentDwmColor = initialDwmColor;

    currentARGB.x = 0;
    currentARGB.y = 0;
    currentARGB.z = 0;
    currentARGB.w = 0;

#define CONFIG_DIR QStandardPaths::standardLocations(QStandardPaths::DataLocation).first()

    // Misc initialization
    settings = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);

    SET_HACK_FLAG(HACK_INHIBIT_START_WINDOWS_CHECKBOX);
    if (settings->contains("ColorShifter")) {
        ui->startWindowsCheckbox->setChecked(true);
        this->on_mainButton_clicked();
    } else {
        ui->startWindowsCheckbox->setChecked(false);
    }
    CLEAR_HACK_FLAG(HACK_INHIBIT_START_WINDOWS_CHECKBOX);

    configFile.setFileName(CONFIG_DIR + QString("/ColorShifter.json"));

    if (!QDir(CONFIG_DIR).exists()) {
        QDir().mkpath(CONFIG_DIR);
    }

    if (configFile.exists()) {
        loadPalettes(configFile.fileName());
    } else {
        loadPalettes(":/palettes.json");
        savePalettes(configFile.fileName());
    }

    timer = new(QTimer);
    connect(timer, SIGNAL(timeout()), this, SLOT(next_color()));

    // UI values initialization
    ui->balanceBox->setValue(initialDwmColor.colorBalance);

    // System tray icon initialization
    minimizeAction = new QAction(tr("Minimize"), this);
    restoreAction = new QAction(tr("Restore"), this);
    startStopAction = new QAction(tr("Start shifting"), this);
    quitAction = new QAction(tr("Stop and quit"), this);

    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(startStopAction, SIGNAL(triggered()), this, SLOT(on_mainButton_clicked()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(on_quitButton_clicked()));

    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(startStopAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon(":/icon-bw.png"));
    trayIcon->setToolTip("ColorShifter (stopped)");

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

    startStopAction->setEnabled(false);

    trayIcon->show();

    ////////////////////////////////////////////////////////////////////////////
    // TEMPORARY FOR TESTING

    // END TEMPORARY FOR TESTING
    ////////////////////////////////////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
    setDwmColors(&initialDwmColor, 0);
}

void MainWindow::on_previewColorCheckbox_stateChanged(int arg1)
{
    if (arg1) { // checkbox checked
        updateColorAndPreview();
    } else {
        setDwmColors(&initialDwmColor, 0); // revert to original colors
    }
}

void MainWindow::on_hueRedSlider_valueChanged(int position)
{
    if (ui->hsvRadio->isChecked()) { // sliders are AHSV
        int4 ahsv = AHSVfromSliders();
        ahsv.x = position;
        currentARGB = ARGBfromAHSV(ahsv);
    } else {
        currentARGB.x = position;
    }
    updateColorAndPreview();
}

void MainWindow::on_satGreenSlider_valueChanged(int position)
{
    if (ui->hsvRadio->isChecked()) { // sliders are AHSV
        int4 ahsv = AHSVfromSliders();
        ahsv.y = position;
        currentARGB = ARGBfromAHSV(ahsv);
    } else {
        currentARGB.y = position;
    }
    updateColorAndPreview();
}

void MainWindow::on_valueBlueSlider_valueChanged(int position)
{
    if (ui->hsvRadio->isChecked()) { // sliders are AHSV
        int4 ahsv = AHSVfromSliders();
        ahsv.z = position;
        currentARGB = ARGBfromAHSV(ahsv);
    } else {
        currentARGB.z = position;
    }
    updateColorAndPreview();
}

void MainWindow::on_alphaSlider_valueChanged(int position)
{
    currentARGB.w = position; // AHSV and ARGB have same alpha channel
    updateColorAndPreview();
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
    int row = ui->colorTable->selectedItems().first()->row();
    int paletteIndex = ui->paletteTable->selectedItems().first()->row();
    ui->colorTable->removeRow(row);

    ui->addColorButton->setEnabled(true);
    if (ui->colorTable->rowCount() <= 1) { // disable button when one color left
        ui->removeColorButton->setEnabled(false);
    }

    palettes.at(ui->paletteTable->selectedItems().first()->row())->removeAt(row);

    updateAtPaletteTable(paletteIndex);
}

void MainWindow::on_addColorButton_clicked()
{
    ui->removeColorButton->setEnabled(true); // re-enable delete button

    if (ui->colorTable->rowCount() >= TABLE_MAX_ELEMENTS - 1) {
        ui->addColorButton->setEnabled(false);
    }

    int row = ui->colorTable->selectedItems().first()->row() + 1;
    ui->colorTable->insertRow(row);
    ui->colorTable->selectRow(row);

    // copy contents over from previously selected row
    for (int i = 0; i < ui->colorTable->columnCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(*ui->colorTable->item(row - 1, i));
        ui->colorTable->setItem(row, i, item);
    }

    int paletteIndex = ui->paletteTable->selectedItems().first()->row();
    palettes.at(paletteIndex)->addAt(row - 1, palettes.at(paletteIndex)->getAt(row - 1));

    updateAtPaletteTable(paletteIndex);

    ui->sliderGroup->setEnabled(true);

    if (!(ui->copyColorCheckbox->isChecked())) {
        on_randomizeColorButton_clicked();
    }

}

void MainWindow::on_colorTable_itemSelectionChanged()
{
    SET_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
    if (HACK_FLAG(HACK_INHIBIT_COLOR_TABLE_UPDATE)) {
        return; // massive hack, grand finale
    }

    if(ui->colorTable->selectedItems().empty()) {
        ui->sliderGroup->setEnabled(false);
        CLEAR_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
        return;
    }
    if (ui->colorTable->selectedItems().first()->row() < ui->colorTable->property("immutableRows").toInt()) {
        // cannot delete immutable object
        ui->removeColorButton->setEnabled(false);
    } else {
        // TODO: move this into a recalculateButtonState() function
        ui->removeColorButton->setEnabled(true);
    }

    if (ui->colorTable->rowCount() < TABLE_MAX_ELEMENTS - 1) {
        ui->addColorButton->setEnabled(true);
    } else {
        ui->addColorButton->setEnabled(false);
    }

    if (ui->colorTable->selectedItems().first()->row() >= ui->colorTable->rowCount()) {
        CLEAR_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
        return; // should never happen
    }

    ui->sliderGroup->setEnabled(true);

    // speed hack
    int paletteIndex = ui->paletteTable->selectedItems().first()->row();
    int row = ui->colorTable->selectedItems().first()->row();

    currentARGB = palettes.at(paletteIndex)->getAt(row);

    bool ahsvSelected = ui->hsvRadio->isChecked();
    ui->rgbRadio->setChecked(true);

    ui->alphaSlider->setValue(palettes.at(paletteIndex)->at(row)->w);
    ui->hueRedSlider->setValue(palettes.at(paletteIndex)->at(row)->x);
    ui->satGreenSlider->setValue(palettes.at(paletteIndex)->at(row)->y);
    ui->valueBlueSlider->setValue(palettes.at(paletteIndex)->at(row)->z);

    if (ahsvSelected) {
        ui->hsvRadio->setChecked(true);
    }
    CLEAR_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}

void MainWindow::on_quitButton_clicked()
{
    stopShifting();
    savePalettes(configFile.fileName());
    if (ui->startWindowsCheckbox->isChecked()) {
        // update file path in case it's moved
        settings->setValue("ColorShifter", QCoreApplication::applicationFilePath().replace('/','\\'));
    }
    delete trayIcon;
    exit(EXIT_OK);

    // exit and revert
}

void MainWindow::on_overrideCheckbox_toggled(bool checked)
{
    ui->balanceBox->setEnabled(checked);
    updateColorAndPreview();
}

void MainWindow::on_balanceBox_valueChanged(int arg1)
{
    updateColorAndPreview();
}



void MainWindow::on_loadPalettesButton_clicked()
{
    SET_HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2);

    QFileDialog loadDialog(this);
    loadDialog.setFileMode(QFileDialog::ExistingFile);
    loadPalettes(loadDialog.getOpenFileName(this, "Load palette file", QDir::homePath(), "Palette files (*.json);;All files (*.*)"));

    CLEAR_HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2);
}

void MainWindow::on_savePalettesButton_clicked()
{
    QFileDialog saveDialog(this);
    saveDialog.setFileMode(QFileDialog::AnyFile);
    saveDialog.setAcceptMode(QFileDialog::AcceptSave);
    savePalettes(saveDialog.getSaveFileName(this, "Save palette file", QDir::homePath(), "Palette files (*.json);;All files (*.*)"));
}

void MainWindow::updateColorTableDragDrop(int dest, int src)
{
    if (ui->paletteTable->selectedItems().empty()) {
#ifdef QT_DEBUG
        std::cout<<"WARN: updateColorTableDragDrop: no palette selected"<<std::endl;
#endif
        return;
    }

    int crt = ui->paletteTable->selectedItems().first()->row();

    palettes.at(crt)->moveInternal(dest, src);
    updateAtPaletteTable(crt);
}

void MainWindow::updatePaletteTableDragDrop(int dest, int src)
{
    palettes.moveInternal(dest, src);
}

void MainWindow::on_paletteTable_itemSelectionChanged()
{

    if(HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE)) {
        return; // massive hack reloaded
    }

    if(ui->paletteTable->selectedItems().empty()) {
        clearColorTable();
        ui->colorGroup->setEnabled(false);
        ui->mainButton->setEnabled(false);
        startStopAction->setEnabled(false);
        ui->addPaletteButton->setEnabled(false);
        ui->removePaletteButton->setEnabled(false);
        ui->previewPaletteButton->setEnabled(false);
        return;
    }

    SET_HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2);

    ui->previewPaletteButton->setEnabled(true);

    int rows = ui->paletteTable->rowCount();

    if (rows >= 1 && rows < TABLE_MAX_ELEMENTS - 1) {
        ui->addPaletteButton->setEnabled(true);
    }

    if (rows > 1 && rows <= TABLE_MAX_ELEMENTS - 1) {
        ui->removePaletteButton->setEnabled(true);
    }

    fillColorTable(ui->paletteTable->selectedItems().first()->row());
    ui->colorGroup->setEnabled(true);
    ui->mainButton->setEnabled(true);
    startStopAction->setEnabled(true);

    CLEAR_HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2);
}

////////////////////////////////////////////////////////////////////////////////
// Save/load helper functions

void MainWindow::loadPalettes(QString loadFileName)
{
    QFile loadFile(loadFileName);

    if (loadFile.open(QIODevice::ReadOnly)) {
#ifdef QT_DEBUG
        std::cout<<"Load OK: "<<loadFileName.toLocal8Bit().data()<<std::endl;
#endif
    } else {
#ifdef QT_DEBUG
        std::cout<<"WARN: Load fail: "<<loadFileName.toLocal8Bit().data()<<std::endl;
#endif
        return;
    }

    loadPalettesFromJSON(QJsonDocument::fromJson(loadFile.readAll()).object());

#ifdef QT_DEBUG
    for (int i = 0; i < palettes.size(); i++) {
        char crt[50];
        palettes.at(i)->getName(crt);
#ifdef ARR_HACK
        strcpy(crt, globalNames[i]); // ARR_HACK
#endif
        std::cout<<"Palette loaded: "<<crt<<": ";
        for (int j = 0; j < palettes.at(i)->size(); j++) {
            std::cout<<std::hex<<palettes.at(i)->getMergedAt(j)<<std::dec<<" ";
        }
        std::cout<<std::endl;
    }
#endif

    loadFile.close();
}

void MainWindow::loadPalettesFromJSON(QJsonObject json)
{
    try {
        // TODO: only clear when user checks box or other sane behavior
        clearPaletteTable();
        palettes.clear();

        QJsonArray paletteArray = json["palettes"].toArray();

        bool buttonsReenabled = false;
        for (int i = 0; i < paletteArray.size(); i++) {
            if (i >= TABLE_MAX_ELEMENTS) {
                break; // can't add any more palettes
            }

            QJsonObject crt = paletteArray.at(i).toObject();
            QByteArray name_ = crt["name"].toString().toLocal8Bit();
            char *name__ = name_.data();
            Palette toAdd;
            toAdd.setName(name__);
#ifdef ARR_HACK
            strcpy(globalNames[i], name__); // ARR_HACK
#endif

            QJsonArray colors_ = crt["colors"].toArray();

            for (int j = 0; j < colors_.size(); j++) {
                if (j >= TABLE_MAX_ELEMENTS) {
                    break; // can't add any more colors
                }

                QJsonObject crt_ = colors_.at(j).toObject();
                int4 color_; // ARGB
                color_.w = crt_["a"].toInt();
                color_.x = crt_["r"].toInt();
                color_.y = crt_["g"].toInt();
                color_.z = crt_["b"].toInt();
                toAdd.addAt(j, color_);
            }

            if (toAdd.size() == 0) { // empty palette
                continue;
            }

            palettes.addAt(i, toAdd);
            addAtPaletteTable(i);

            if (i >= 0 && !buttonsReenabled) {
                ui->savePalettesButton->setEnabled(true);
                buttonsReenabled = true;
            }
        }

        QJsonObject settings = json["settings"].toObject();
        QJsonObject time = settings["time"].toObject();
        ui->timeEdit->time().setHMS(time["h"].toInt(), time["m"].toInt(), time["s"].toInt());
        ui->smoothnessSlider->setValue(settings["smoothness"].toInt());
        ui->randomCheckbox->setChecked(settings["random"].toBool());
        ui->smartCheckbox->setChecked(settings["smart"].toBool());
        ui->overrideCheckbox->setChecked(settings["override"].toBool());
        ui->balanceBox->setValue(settings["balance"].toInt());
    } catch (...) {
        QMessageBox couldntLoad;
        couldntLoad.setIcon(QMessageBox::Critical);
        couldntLoad.setWindowTitle("Uh-oh");
        couldntLoad.setText("Could not load file.");
        couldntLoad.exec();
    }
}

void MainWindow::savePalettes(QString saveFileName)
{
    QJsonDocument doc(savePalettesToJSON());
    QFile saveFile(saveFileName);
    if (saveFile.open(QIODevice::WriteOnly)) {
#ifdef QT_DEBUG
        std::cout<<"Save OK: "<<saveFileName.toLocal8Bit().data()<<std::endl;
#endif
    } else {
#ifdef QT_DEBUG
        std::cout<<"WARN: Save fail: "<<saveFileName.toLocal8Bit().data()<<std::endl;
#endif
        return;
    }

    saveFile.write(doc.toJson());
    saveFile.close();
}

QJsonObject MainWindow::savePalettesToJSON()
{
    try {
    QJsonArray paletteArray;
    for (int i = 0; i < palettes.size(); i++) {
        QJsonArray colorArray;
        for (int j = 0; j < palettes.at(i)->size(); j++) {
            QJsonObject crt_;
            int4 color_ = palettes.at(i)->getAt(j);
            crt_["a"] = color_.w;
            crt_["r"] = color_.x;
            crt_["g"] = color_.y;
            crt_["b"] = color_.z;
            colorArray.append(crt_);
        }
        QJsonObject crt;
        char name[50];
        palettes.at(i)->getName(name);
#ifdef ARR_HACK
        strcpy(name, globalNames[i]); // ARR_HACK
#endif
        crt["name"] = name;
        crt["colors"] = colorArray;

        paletteArray.append(crt);
    }

    QJsonObject json;
    json["palettes"] = paletteArray;

    // save the settings
    QJsonObject settings;
    settings["smoothness"] = ui->smoothnessSlider->value();
    QJsonObject time;
    time["h"] = ui->timeEdit->time().hour();
    time["m"] = ui->timeEdit->time().minute();
    time["s"] = ui->timeEdit->time().second();
    settings["time"] = time;
    settings["random"] = ui->randomCheckbox->isChecked();
    settings["smart"] = ui->smartCheckbox->isChecked();
    settings["override"] = ui->overrideCheckbox->isChecked();
    settings["balance"] = ui->balanceBox->value();
    json["settings"] = settings;

    return json;
    } catch (...) {
        QMessageBox couldntSave;
        couldntSave.setIcon(QMessageBox::Critical);
        couldntSave.setText("Could not save file");
        couldntSave.setWindowTitle("Uh-oh");
        couldntSave.exec();

        QJsonObject x;
        return x;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Palette table helper functions

void MainWindow::clearPaletteTable()
{
    clearColorTable(); // don't remove this or it crashes
    for (int i = ui->paletteTable->rowCount() - 1; i >= 0; i--) {
        ui->paletteTable->removeRow(i);
    }

    ui->removePaletteButton->setEnabled(false);
    ui->addPaletteButton->setEnabled(false);
    ui->savePalettesButton->setEnabled(false);
}

void MainWindow::addAtPaletteTable(int row)
{

    ui->paletteTable->insertRow(row);

    // populate cells with items
    for (int i = 0; i < ui->paletteTable->columnCount(); i++) { // WARNING: starts at 1
        QTableWidgetItem *item = new QTableWidgetItem();

        // disable all cells except one that contains name
        if (i) {
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }

        ui->paletteTable->setItem(row, i, item);
    }

    updateAtPaletteTable(row);
}

void MainWindow::updateAtPaletteTable(int row)
{
    // update name
    char name[50];
    palettes.at(row)->getName(name);
#ifdef ARR_HACK
    strcpy(name, globalNames[row]); // ARR_HACK
#endif
    ui->paletteTable->item(row, 0)->setText(name);

    for (int i = 0; i < ui->paletteTable->columnCount()-1; i++) {
        if (i < palettes.at(row)->size()) {
            // within bounds, set color that's in the palette
            ui->paletteTable->item(row,i+1)->setBackgroundColor(QColor(
                                                                  palettes.at(row)->at(i)->x,
                                                                  palettes.at(row)->at(i)->y,
                                                                  palettes.at(row)->at(i)->z));
        } else {
            ui->paletteTable->item(row,i+1)->setBackgroundColor(QColor(255,255,255,0));
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Color table helper functions

void MainWindow::clearColorTable()
{
    ui->colorTable->selectionModel()->clearSelection();

    /* // for some reason this doesn't work
    for (int i = ui->colorTable->rowCount() - 1; i >= 0; i--) {
        ui->colorTable->removeRow(i);
    }
    */

    while (ui->colorTable->rowCount()) {
        ui->colorTable->removeRow(0);
    }
}

void MainWindow::fillColorTable(int index)
{
    clearColorTable();

    for (int i = 0; i < palettes.at(index)->size(); i++) {
        ui->colorTable->insertRow(i);

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(palettes.at(index)->getMergedAt(i),16).rightJustified(8, '0'));
        ui->colorTable->setItem(i, 0, item);

        QTableWidgetItem *item_ = new QTableWidgetItem;
        item_->setFlags(item_->flags() & ~Qt::ItemIsEditable);
        ui->colorTable->setItem(i, 1, item_);

        updateAtColorTable(index, i);
    }

    if (palettes.at(index)->size() <= 1) {
        ui->removeColorButton->setEnabled(false);
    }
}

void MainWindow::updateAtColorTable(int index, int row)
{
    ui->colorTable->item(row, 1)->setBackgroundColor(QColor(
                                                         palettes.at(index)->at(row)->x,
                                                         palettes.at(index)->at(row)->y,
                                                         palettes.at(index)->at(row)->z));
    ui->colorTable->item(row, 0)->setText(QString::number(palettes.at(index)->getMergedAt(row),16).rightJustified(8, '0'));
}

////////////////////////////////////////////////////////////////////////////////
// Misc helper functions

void MainWindow::updateColorAndPreview()
{
    if (HACK_FLAG(HACK_INHIBIT_COLOR_TABLE_UPDATE) || HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2)) {
        return;
    }
    if(ui->paletteTable->selectedItems().empty() || ui->colorTable->selectedItems().empty()) {
        // should never happen.
    } else {
        int paletteIndex = ui->paletteTable->selectedItems().first()->row();
        int row = ui->colorTable->selectedItems().first()->row();
        palettes.at(paletteIndex)->setAt(row, currentARGB);
        updateAtColorTable(paletteIndex, row);
        updateAtPaletteTable(paletteIndex);
    }

    if (!ui->previewColorCheckbox->isChecked() ||
           // !ui->paletteGroup->isEnabled() ||
           // !ui->sliderGroup->isEnabled() ||
            !ui->previewColorCheckbox->isEnabled()) { // preview is disabled
#ifdef QT_DEBUG
        std::cout<<"preview disabled, reset initial colors"<<std::endl;
#endif
        setDwmColors(&initialDwmColor, 0);
        return;
    }

    currentDwmColor.color = mergedFromInt4(this->currentARGB);
    if (ui->overrideCheckbox->isChecked()) {
        currentDwmColor.colorBalance = ui->balanceBox->value();
    } else {
        currentDwmColor.colorBalance = initialDwmColor.colorBalance;
    }

#ifdef QT_DEBUG
    std::cout << std::hex << currentDwmColor.color << std::endl;
#endif

    setDwmColors(&currentDwmColor, 0);
}

int4 MainWindow::AHSVfromSliders()
{
    int4 ahsv;
    ahsv.w = ui->alphaSlider->value();
    ahsv.x = ui->hueRedSlider->value();
    ahsv.y = ui->satGreenSlider->value();
    ahsv.z = ui->valueBlueSlider->value();
    return ahsv;
}

////////////////////////////////////////////////////////////////////////////////
// Override drag and drop behavior

// override the drag-and-drop handler to swap instead of overwrite
void QTableWidget::dropEvent(QDropEvent *event)
{
#ifdef QT_DEBUG
    std::cout<<this->objectName().toLocal8Bit().data()<<": ";
#endif

    if (!event->source() || event->source()->objectName() != this->objectName()) {
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

    if (destRow < 0) { // all the way to the bottom; assumes rows are populated with items
        destIndex = indexFromItem(item(rowCount()-1, 0));
        destRow = destIndex.row();

        if (destRow < 0) { // destination row still not correct
#ifdef QT_DEBUG
            std::cout<<"destinaton row still not updated. Are all cells populated?"<<std::endl;
#endif
            return;
        }
    }

#ifdef QT_DEBUG
    std::cout<<"Table move: "<<std::dec<<srcRow<<" "<<destRow;
#endif

    // to be used by ugly hack
    int srcRow_ = srcRow;
    int destRow_ = destRow;

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

    SET_HACK_FLAG(HACK_INHIBIT_COLOR_TABLE_UPDATE); // massive hack, act 1
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

    CLEAR_HACK_FLAG(HACK_INHIBIT_COLOR_TABLE_UPDATE); // massive hack, act 2

#ifdef QT_DEBUG
    std::cout<<" (ok)"<<std::endl;
#endif
    event->ignore(); // override default handler

    // Ugly hack.
    // Check which table is performing the movement and call the appropriate function to update
    // the indexes inside the arrays.
    if (this->objectName() == "colorTable") {
        ((MainWindow*)parent()->parent()->parent())->updateColorTableDragDrop(destRow_, srcRow_);
    } else if (this->objectName() == "paletteTable") {
        ((MainWindow*)parent()->parent()->parent())->updatePaletteTableDragDrop(destRow_, srcRow_);
    } else {
#ifdef QT_DEBUG
        std::cout<<"WARN: undefined drag-drop behavior for "<<this->objectName().toLocal8Bit().data()<<std::endl;
#endif
    }
}

////////////////////////////////////////////////////////////////////////////////
// more slot stuff

void MainWindow::on_paletteTable_cellChanged(int row, int column)
{
    if (column) {
        return; // not text area
    }

    if (!ui->paletteTable->isItemSelected(ui->paletteTable->item(row, column))) {
        return; // not edited by user
    }

#ifdef QT_DEBUG
    std::cout<<"palette name changed "<<row<<" "<<column<<": ";
#endif

    QByteArray name = ui->paletteTable->item(row, column)->text().toLocal8Bit();
#ifdef QT_DEBUG
    std::cout<<ui->paletteTable->item(row, column)->text().toLocal8Bit().data()<<std::endl;
#endif
    name.truncate(PALETTE_MAX_NAME - 1);
    palettes.at(row)->setName(name.data());
#ifdef ARR_HACK
    strcpy(globalNames[row], name.data()); // ARR_HACK
#endif
}

void MainWindow::on_removePaletteButton_clicked()
{
    SET_HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2);

    int row = ui->paletteTable->selectedItems().first()->row();
    ui->paletteTable->removeRow(row);

    ui->addPaletteButton->setEnabled(true);
    if (ui->paletteTable->rowCount() <= 1) {
        ui->removePaletteButton->setEnabled(false);
    }

    palettes.removeAt(row);

    CLEAR_HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2);
}

void MainWindow::on_addPaletteButton_clicked()
{
    SET_HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2);

    ui->removePaletteButton->setEnabled(true);
    if (ui->paletteTable->rowCount() >= TABLE_MAX_ELEMENTS - 1) {
        ui->addPaletteButton->setEnabled(false);
    }

    int row = ui->paletteTable->selectedItems().first()->row() + 1;
    ui->paletteTable->insertRow(row);

    // copy contents over from previously selected row

    for (int i = 0; i < ui->paletteTable->columnCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(*ui->paletteTable->item(row - 1, i));
        ui->paletteTable->setItem(row, i, item);
    }

    if (ui->copyPaletteCheckbox->isChecked()) {
        palettes.addAt(row, palettes.getAt(row - 1));
    } else {
        Palette placeholder;
        placeholder.addAt(0, int4 {255, 0, 0, 0});
        palettes.addAt(row, placeholder);
    }

    ui->paletteTable->selectRow(row);
    ui->colorTable->selectRow(0);

    CLEAR_HACK_FLAG(HACK_INHIBIT_DWM_TABLE_UPDATE2);
    updateColorAndPreview();
}

void MainWindow::on_smoothnessSlider_valueChanged(int value)
{
    switch(value) {
    case 0:
        ui->smoothnessStatusLabel->setText("Disco!");
        break;
    case 1:
        ui->smoothnessStatusLabel->setText("Choppy");
        break;
    case 2:
        ui->smoothnessStatusLabel->setText("Very rough");
        break;
    case 3:
        ui->smoothnessStatusLabel->setText("Rough");
        break;
    case 4:
        ui->smoothnessStatusLabel->setText("Coarse");
        break;
    case 5:
        ui->smoothnessStatusLabel->setText("Average");
        break;
    case 6:
        ui->smoothnessStatusLabel->setText("Decent");
        break;
    case 7:
        ui->smoothnessStatusLabel->setText("Smooth");
        break;
    case 8:
        ui->smoothnessStatusLabel->setText("Very smooth");
        break;
    case 9:
        ui->smoothnessStatusLabel->setText("Seamless");
        break;
    case 10:
        ui->smoothnessStatusLabel->setText("Perfect");
        break;
    }

    // do some other stuff
}

void MainWindow::on_timeSlider_valueChanged(int value)
{
    if(HACK_FLAG(HACK_INHIBIT_TIME_SLIDER)) {
        return;
    }

    ui->timeEdit->setTime(QTime(value/3600, value/60 % 60, value % 60));
}


void MainWindow::on_timeEdit_timeChanged(const QTime &time)
{
    SET_HACK_FLAG(HACK_INHIBIT_TIME_SLIDER);

    ui->timeSlider->setValue(3600 * time.hour() + 60 * time.minute() + time.second());

    CLEAR_HACK_FLAG(HACK_INHIBIT_TIME_SLIDER);
}

// hackity hack
#define SAVE_GROUP_STATE_AND_DISABLE(group) if(ui->##group##Group->isEnabled()) { \
        SET_HACK_FLAG(HACK_##group##_GROUP_ENABLED); \
    } else { \
        CLEAR_HACK_FLAG(HACK_##group##_GROUP_ENABLED); \
    } \
    ui->##group##Group->setEnabled(false)
#define RESTORE_GROUP_STATE(group) ui->##group##Group->setEnabled(HACK_FLAG(HACK_##group##_GROUP_ENABLED))

void MainWindow::on_mainButton_clicked()
{
    TOGGLE_HACK_FLAG(HACK_MAIN_BUTTON_ON);
    CLEAR_HACK_FLAG(HACK_PREVIEW_ENABLED);

    if (HACK_FLAG(HACK_MAIN_BUTTON_ON)) {
        trayIcon->setIcon(QIcon(":/icon.png"));
        trayIcon->setToolTip("ColorShifter (running)");
#ifdef QT_DEBUG
        std::cout<<"Started shifting"<<std::endl;
#endif

        ui->mainButton->setText("Stop shifting");
        ui->mainButton->setToolTip("Stop changing the colors and revert to current theme");
        startStopAction->setText("Stop shifting");

        SAVE_GROUP_STATE_AND_DISABLE(color);
        SAVE_GROUP_STATE_AND_DISABLE(palette);
        SAVE_GROUP_STATE_AND_DISABLE(settings);

        startShifting();

    } else {
        trayIcon->setIcon(QIcon(":/icon-bw.png"));
        trayIcon->setToolTip("ColorShifter (stopped)");
#ifdef QT_DEBUG
        std::cout<<"Stopped shifting"<<std::endl;
#endif

        ui->mainButton->setText("Shift the colors!");
        ui->mainButton->setToolTip("Start shifting colors");
        startStopAction->setText("Start shifting");

        RESTORE_GROUP_STATE(color);
        RESTORE_GROUP_STATE(palette);
        RESTORE_GROUP_STATE(settings);

        stopShifting();
    }

}

////////////////////////////////////////////////////////////////////////////////
// Shifting the colors

void MainWindow::startShifting()
{
    TSH(MAX_IDX) = ui->smoothnessSlider->value() ?
                256 / (21 - 2 * ui->smoothnessSlider->value()) :
                1;
    TSH(CRT_PAL) = ui->paletteTable->selectedItems().first()->row();
    TSH(MAX_CLR) = ui->colorTable->rowCount();
    TSH(CRT_IDX) = 0;
    TSH(CRT_CIX) = 1 % TSH(MAX_CLR);
    TSH(PRV_CLR) = palettes.at(TSH(CRT_PAL))->getMergedAt(0 % TSH(MAX_CLR));
    TSH(NXT_CLR) = palettes.at(TSH(CRT_PAL))->getMergedAt(1 % TSH(MAX_CLR));
    TSH(IS_RAND) = ui->randomCheckbox->isChecked();
    TSH(IS_AHSV) = ui->smartCheckbox->isChecked();

    next_color();
    if (HACK_FLAG(HACK_PREVIEW_ENABLED)) {
        SET_HACK_FLAG(HACK_PREVIEW_FIRST_PASS);
        TSH(MAX_IDX) = 64;
        timer->start(15);
    } else {
        timer->start((ui->timeEdit->time().hour() * 3600 +
                     ui->timeEdit->time().minute() * 60 +
                     ui->timeEdit->time().second()) * 1000 / (TSH(MAX_IDX) * TSH(MAX_CLR)));
    }
}

void MainWindow::stopShifting()
{
    timer->stop();

    if (HACK_FLAG(HACK_PREVIEW_ENABLED)) {
        RESTORE_GROUP_STATE(color);
        RESTORE_GROUP_STATE(settings);
        RESTORE_GROUP_STATE(saveLoad);
        RESTORE_GROUP_STATE(plusMinus);
        ui->previewPaletteButton->setText("Preview");
        ui->previewPaletteButton->setToolTip("Preview the current palette transitions");
        ui->paletteTable->setEnabled(true);
        ui->mainButton->setEnabled(true);
        startStopAction->setEnabled(true);
        CLEAR_HACK_FLAG(HACK_PREVIEW_FIRST_PASS);
        CLEAR_HACK_FLAG(HACK_PREVIEW_BUTTON_ON);
    }

    updateColorAndPreview();
}

void MainWindow::next_color()
{
    // this will contain lots of speed hacks because it's called so often
    // see hacks.h
    // you have been warned

    ++TSH(CRT_IDX) %= TSH(MAX_IDX); // increment the current color index
    if (!(TSH(CRT_IDX) % TSH(MAX_IDX))) { // reached a new color
        ++TSH(CRT_CIX) %= TSH(MAX_CLR); // increment the current color
        if (!TSH(CRT_CIX)) { // rolled over
#ifdef QT_DEBUG
            std::cout<<"Rolled over!"<<std::endl;
#endif
            if(HACK_FLAG(HACK_PREVIEW_ENABLED)) {
                CLEAR_HACK_FLAG(HACK_PREVIEW_FIRST_PASS);
            }
        }

        TSH(PRV_CLR) = TSH(NXT_CLR); // update old color
        if (TSH(IS_RAND)) { // update new color with random value
            TSH(NXT_CLR) = palettes.at(TSH(CRT_PAL))->getMergedAt(rand() % TSH(MAX_CLR));
        } else { // update new color with next value
            TSH(NXT_CLR) = palettes.at(TSH(CRT_PAL))->getMergedAt(TSH(CRT_CIX));
        }
    }
    if (HACK_FLAG(HACK_PREVIEW_ENABLED) && TSH(CRT_CIX) && !HACK_FLAG(HACK_PREVIEW_FIRST_PASS)) {
        stopShifting();
        return;
    }

#ifdef QT_DEBUG
    std::cout<<"TSH: ";
    for (int i = 0; i < TSH_LENGTH; i++) {
        std::cout<<std::hex<<tsh[i]<<"\t";
    }
    std::cout<<std::endl;
#endif

    if (TSH(IS_AHSV)) {
        currentDwmColor.color = mergedFromInt4(
                    ARGBfromAHSV(
                        interpolate_(
                            AHSVfromARGB(int4FromMerged(TSH(PRV_CLR))),
                            AHSVfromARGB(int4FromMerged(TSH(NXT_CLR))),
                            (double)TSH(CRT_IDX) / TSH(MAX_IDX),
                            true)));
    } else {
        currentDwmColor.color = mergedFromInt4(
                    interpolate_(
                        int4FromMerged(TSH(PRV_CLR)),
                        int4FromMerged(TSH(NXT_CLR)),
                        (double)TSH(CRT_IDX) / TSH(MAX_IDX)));
    }

    setDwmColors(&currentDwmColor, 0);
}

////////////////////////////////////////////////////////////////////////////////
// More slot stuff

void MainWindow::on_previewPaletteButton_clicked()
{
    TOGGLE_HACK_FLAG(HACK_PREVIEW_BUTTON_ON);

    SET_HACK_FLAG(HACK_PREVIEW_ENABLED);
    SET_HACK_FLAG(HACK_PREVIEW_FIRST_PASS);

    if (HACK_FLAG(HACK_PREVIEW_BUTTON_ON)) {
        SAVE_GROUP_STATE_AND_DISABLE(color);
        SAVE_GROUP_STATE_AND_DISABLE(settings);
        SAVE_GROUP_STATE_AND_DISABLE(saveLoad);
        SAVE_GROUP_STATE_AND_DISABLE(plusMinus);
        ui->previewPaletteButton->setText("Stop");
        ui->previewPaletteButton->setToolTip("Stop previewing the palette and revert to current theme");
        ui->mainButton->setEnabled(false);
        startStopAction->setEnabled(false);
        startShifting();
    } else {
        stopShifting();
    }
}

void MainWindow::on_colorTable_cellChanged(int row, int column)
{ 
    if (column) {
        return; // not text area
    }

    if (!ui->colorTable->isItemSelected(ui->colorTable->item(row,column))) {
        return; // not edited by user
    }

    if (HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE) || HACK_FLAG(HACK_INHIBIT_COLOR_TABLE_UPDATE)) {
        return;
    }

    for (int i = 0; i < ui->colorTable->columnCount(); i++) {
        if (!ui->colorTable->item(row, i)) {
            return; // just created
        }
    }

#ifdef QT_DEBUG
    std::cout<<"color hex changed " << row << " " << column << ": ";
#endif

    bool ok;
    unsigned int hex = ui->colorTable->item(row, column)->text().toUInt(&ok, 16);

    if (ok) {
        palettes.at(ui->paletteTable->selectedItems().first()->row())->setAt(row, int4FromMerged(hex));
    }

    this->on_colorTable_itemSelectionChanged(); // hack
}

void MainWindow::on_hueRedSlider_sliderPressed()
{
    SET_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}


void MainWindow::on_satGreenSlider_sliderPressed()
{
    SET_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}

void MainWindow::on_valueBlueSlider_sliderPressed()
{
    SET_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}


void MainWindow::on_alphaSlider_sliderPressed()
{
    SET_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}


void MainWindow::on_hueRedSlider_sliderReleased()
{
    CLEAR_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}

void MainWindow::on_satGreenSlider_sliderReleased()
{
    CLEAR_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}

void MainWindow::on_valueBlueSlider_sliderReleased()
{
    CLEAR_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}

void MainWindow::on_alphaSlider_sliderReleased()
{
    CLEAR_HACK_FLAG(HACK_INHIBIT_COLOR_CELL_CHANGE);
}

////////////////////////////////////////////////////////////////////////////////
// Tray stuff

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        if (!this->isHidden()) {
            this->raise();
            this->activateWindow();
        }
        break;
    case QSystemTrayIcon::DoubleClick:
        if (this->isHidden()) {
            this->showNormal();
            this->raise();
            this->activateWindow();
        } else {
            this->hide();
        }
        break;
    case QSystemTrayIcon::MiddleClick:
        if (ui->mainButton->isEnabled()) {
            this->on_mainButton_clicked();
        }
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        this->hide();
        event->ignore();
    } else {
#ifdef QT_DEBUG
        std::cout<<"WARN: close window: tray icon not visible"<<std::endl;
#endif
        event->accept();
    }
}

////////////////////////////////////////////////////////////////////////////////
// Even more slots


void MainWindow::on_startWindowsCheckbox_stateChanged(int arg1)
{
    if (HACK_FLAG(HACK_INHIBIT_START_WINDOWS_CHECKBOX)) {
        return;
    }
    if (arg1) { // checked
        settings->setValue("ColorShifter", QCoreApplication::applicationFilePath().replace('/','\\'));
    } else {
        settings->remove("ColorShifter");
    }
}

void MainWindow::on_aboutButton_clicked()
{
    AboutWindow about;
    about.exec();
    about.deleteLater();
}

void MainWindow::on_helpButton_clicked()
{
    HelpWindow help;
    help.exec();
    help.deleteLater();
}
