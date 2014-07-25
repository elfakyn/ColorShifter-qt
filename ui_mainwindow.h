/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *colorGroup;
    QPushButton *removeColorButton;
    QPushButton *addColorButton;
    QTableWidget *colorTable;
    QWidget *sliderGroup;
    QCheckBox *smartRandomizeCheckbox;
    QLabel *valueBlueLabel;
    QLabel *alphaLabel;
    QCheckBox *previewColorCheckbox;
    QRadioButton *hsvRadio;
    QLabel *hueRedLabel;
    QSlider *satGreenSlider;
    QSlider *valueBlueSlider;
    QSlider *alphaSlider;
    QRadioButton *rgbRadio;
    QSlider *hueRedSlider;
    QLabel *satGreenLabel;
    QPushButton *randomizeColorButton;
    QCheckBox *copyColorCheckbox;
    QCheckBox *startWindowsCheckbox;
    QPushButton *mainButton;
    QGroupBox *settingsGroup;
    QSlider *smoothnessSlider;
    QLabel *smoothnessLabel;
    QSlider *timeSlider;
    QLabel *timeLabel;
    QLabel *smoothnessStatusLabel;
    QCheckBox *randomCheckbox;
    QCheckBox *smartCheckbox;
    QTimeEdit *timeEdit;
    QGroupBox *advancedGroup;
    QCheckBox *overrideCheckbox;
    QSpinBox *balanceBox;
    QGroupBox *paletteGroup;
    QPushButton *previewPaletteButton;
    QTableWidget *paletteTable;
    QWidget *plusMinusGroup;
    QPushButton *removePaletteButton;
    QPushButton *addPaletteButton;
    QWidget *saveLoadGroup;
    QPushButton *loadPalettesButton;
    QPushButton *savePalettesButton;
    QCheckBox *copyPaletteCheckbox;
    QPushButton *aboutButton;
    QPushButton *quitButton;
    QPushButton *helpButton;
    QPushButton *resetButton;
    QButtonGroup *radioGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(640, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        colorGroup = new QGroupBox(centralWidget);
        colorGroup->setObjectName(QStringLiteral("colorGroup"));
        colorGroup->setGeometry(QRect(380, 10, 251, 431));
        removeColorButton = new QPushButton(colorGroup);
        removeColorButton->setObjectName(QStringLiteral("removeColorButton"));
        removeColorButton->setEnabled(false);
        removeColorButton->setGeometry(QRect(60, 250, 41, 21));
        addColorButton = new QPushButton(colorGroup);
        addColorButton->setObjectName(QStringLiteral("addColorButton"));
        addColorButton->setEnabled(false);
        addColorButton->setGeometry(QRect(10, 250, 41, 21));
        colorTable = new QTableWidget(colorGroup);
        if (colorTable->columnCount() < 2)
            colorTable->setColumnCount(2);
        colorTable->setObjectName(QStringLiteral("colorTable"));
        colorTable->setGeometry(QRect(10, 20, 231, 221));
        colorTable->setFocusPolicy(Qt::NoFocus);
        colorTable->setStyleSheet(QStringLiteral("QTableView::item::selected:inactive{background-color: transparent;}"));
        colorTable->setFrameShape(QFrame::StyledPanel);
        colorTable->setFrameShadow(QFrame::Sunken);
        colorTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        colorTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        colorTable->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        colorTable->setDragEnabled(false);
        colorTable->setDragDropOverwriteMode(false);
        colorTable->setDragDropMode(QAbstractItemView::DragDrop);
        colorTable->setDefaultDropAction(Qt::MoveAction);
        colorTable->setAlternatingRowColors(false);
        colorTable->setSelectionMode(QAbstractItemView::SingleSelection);
        colorTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        colorTable->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        colorTable->setShowGrid(false);
        colorTable->setWordWrap(false);
        colorTable->setCornerButtonEnabled(false);
        colorTable->setRowCount(0);
        colorTable->setColumnCount(2);
        colorTable->setProperty("immutableRows", QVariant(0));
        colorTable->horizontalHeader()->setVisible(false);
        colorTable->horizontalHeader()->setCascadingSectionResizes(false);
        colorTable->horizontalHeader()->setDefaultSectionSize(120);
        colorTable->horizontalHeader()->setHighlightSections(false);
        colorTable->horizontalHeader()->setStretchLastSection(false);
        colorTable->verticalHeader()->setVisible(false);
        sliderGroup = new QWidget(colorGroup);
        sliderGroup->setObjectName(QStringLiteral("sliderGroup"));
        sliderGroup->setGeometry(QRect(0, 250, 251, 181));
        smartRandomizeCheckbox = new QCheckBox(sliderGroup);
        smartRandomizeCheckbox->setObjectName(QStringLiteral("smartRandomizeCheckbox"));
        smartRandomizeCheckbox->setGeometry(QRect(190, 150, 61, 21));
        smartRandomizeCheckbox->setChecked(true);
        valueBlueLabel = new QLabel(sliderGroup);
        valueBlueLabel->setObjectName(QStringLiteral("valueBlueLabel"));
        valueBlueLabel->setGeometry(QRect(10, 90, 41, 21));
        alphaLabel = new QLabel(sliderGroup);
        alphaLabel->setObjectName(QStringLiteral("alphaLabel"));
        alphaLabel->setGeometry(QRect(10, 120, 41, 21));
        previewColorCheckbox = new QCheckBox(sliderGroup);
        previewColorCheckbox->setObjectName(QStringLiteral("previewColorCheckbox"));
        previewColorCheckbox->setGeometry(QRect(110, 0, 61, 21));
        previewColorCheckbox->setChecked(true);
        hsvRadio = new QRadioButton(sliderGroup);
        radioGroup = new QButtonGroup(MainWindow);
        radioGroup->setObjectName(QStringLiteral("radioGroup"));
        radioGroup->addButton(hsvRadio);
        hsvRadio->setObjectName(QStringLiteral("hsvRadio"));
        hsvRadio->setGeometry(QRect(60, 150, 41, 21));
        hsvRadio->setChecked(true);
        hueRedLabel = new QLabel(sliderGroup);
        hueRedLabel->setObjectName(QStringLiteral("hueRedLabel"));
        hueRedLabel->setGeometry(QRect(10, 30, 41, 21));
        satGreenSlider = new QSlider(sliderGroup);
        satGreenSlider->setObjectName(QStringLiteral("satGreenSlider"));
        satGreenSlider->setGeometry(QRect(49, 60, 191, 21));
        satGreenSlider->setMinimum(0);
        satGreenSlider->setMaximum(255);
        satGreenSlider->setValue(192);
        satGreenSlider->setOrientation(Qt::Horizontal);
        valueBlueSlider = new QSlider(sliderGroup);
        valueBlueSlider->setObjectName(QStringLiteral("valueBlueSlider"));
        valueBlueSlider->setGeometry(QRect(49, 90, 191, 21));
        valueBlueSlider->setMinimum(0);
        valueBlueSlider->setMaximum(255);
        valueBlueSlider->setValue(128);
        valueBlueSlider->setOrientation(Qt::Horizontal);
        alphaSlider = new QSlider(sliderGroup);
        alphaSlider->setObjectName(QStringLiteral("alphaSlider"));
        alphaSlider->setGeometry(QRect(49, 120, 191, 21));
        alphaSlider->setMinimum(0);
        alphaSlider->setMaximum(255);
        alphaSlider->setValue(255);
        alphaSlider->setOrientation(Qt::Horizontal);
        rgbRadio = new QRadioButton(sliderGroup);
        radioGroup->addButton(rgbRadio);
        rgbRadio->setObjectName(QStringLiteral("rgbRadio"));
        rgbRadio->setGeometry(QRect(10, 150, 41, 21));
        hueRedSlider = new QSlider(sliderGroup);
        hueRedSlider->setObjectName(QStringLiteral("hueRedSlider"));
        hueRedSlider->setGeometry(QRect(49, 30, 191, 21));
        hueRedSlider->setMinimum(0);
        hueRedSlider->setMaximum(255);
        hueRedSlider->setValue(0);
        hueRedSlider->setOrientation(Qt::Horizontal);
        satGreenLabel = new QLabel(sliderGroup);
        satGreenLabel->setObjectName(QStringLiteral("satGreenLabel"));
        satGreenLabel->setGeometry(QRect(10, 60, 41, 21));
        randomizeColorButton = new QPushButton(sliderGroup);
        randomizeColorButton->setObjectName(QStringLiteral("randomizeColorButton"));
        randomizeColorButton->setGeometry(QRect(110, 150, 71, 21));
        copyColorCheckbox = new QCheckBox(sliderGroup);
        copyColorCheckbox->setObjectName(QStringLiteral("copyColorCheckbox"));
        copyColorCheckbox->setEnabled(true);
        copyColorCheckbox->setGeometry(QRect(180, 0, 51, 21));
        copyColorCheckbox->setCheckable(true);
        copyColorCheckbox->setChecked(false);
        sliderGroup->raise();
        removeColorButton->raise();
        addColorButton->raise();
        colorTable->raise();
        startWindowsCheckbox = new QCheckBox(centralWidget);
        startWindowsCheckbox->setObjectName(QStringLiteral("startWindowsCheckbox"));
        startWindowsCheckbox->setGeometry(QRect(400, 450, 121, 21));
        mainButton = new QPushButton(centralWidget);
        mainButton->setObjectName(QStringLiteral("mainButton"));
        mainButton->setGeometry(QRect(530, 450, 101, 21));
        settingsGroup = new QGroupBox(centralWidget);
        settingsGroup->setObjectName(QStringLiteral("settingsGroup"));
        settingsGroup->setGeometry(QRect(10, 10, 361, 141));
        smoothnessSlider = new QSlider(settingsGroup);
        smoothnessSlider->setObjectName(QStringLiteral("smoothnessSlider"));
        smoothnessSlider->setGeometry(QRect(80, 20, 191, 21));
        smoothnessSlider->setMinimum(0);
        smoothnessSlider->setMaximum(10);
        smoothnessSlider->setPageStep(2);
        smoothnessSlider->setValue(8);
        smoothnessSlider->setSliderPosition(8);
        smoothnessSlider->setOrientation(Qt::Horizontal);
        smoothnessSlider->setInvertedAppearance(false);
        smoothnessSlider->setInvertedControls(false);
        smoothnessSlider->setTickPosition(QSlider::TicksAbove);
        smoothnessSlider->setTickInterval(0);
        smoothnessLabel = new QLabel(settingsGroup);
        smoothnessLabel->setObjectName(QStringLiteral("smoothnessLabel"));
        smoothnessLabel->setGeometry(QRect(10, 20, 71, 21));
        timeSlider = new QSlider(settingsGroup);
        timeSlider->setObjectName(QStringLiteral("timeSlider"));
        timeSlider->setGeometry(QRect(80, 50, 191, 21));
        timeSlider->setMinimum(10);
        timeSlider->setMaximum(3600);
        timeSlider->setSingleStep(10);
        timeSlider->setPageStep(300);
        timeSlider->setValue(60);
        timeSlider->setTracking(true);
        timeSlider->setOrientation(Qt::Horizontal);
        timeLabel = new QLabel(settingsGroup);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(10, 50, 71, 21));
        smoothnessStatusLabel = new QLabel(settingsGroup);
        smoothnessStatusLabel->setObjectName(QStringLiteral("smoothnessStatusLabel"));
        smoothnessStatusLabel->setGeometry(QRect(280, 20, 71, 21));
        randomCheckbox = new QCheckBox(settingsGroup);
        randomCheckbox->setObjectName(QStringLiteral("randomCheckbox"));
        randomCheckbox->setGeometry(QRect(10, 80, 161, 21));
        smartCheckbox = new QCheckBox(settingsGroup);
        smartCheckbox->setObjectName(QStringLiteral("smartCheckbox"));
        smartCheckbox->setGeometry(QRect(10, 110, 161, 21));
        smartCheckbox->setChecked(false);
        timeEdit = new QTimeEdit(settingsGroup);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(280, 50, 71, 21));
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timeEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 1, 0)));
        timeEdit->setMinimumTime(QTime(0, 0, 1));
        timeEdit->setTime(QTime(0, 1, 0));
        advancedGroup = new QGroupBox(settingsGroup);
        advancedGroup->setObjectName(QStringLiteral("advancedGroup"));
        advancedGroup->setGeometry(QRect(170, 80, 181, 51));
        overrideCheckbox = new QCheckBox(advancedGroup);
        overrideCheckbox->setObjectName(QStringLiteral("overrideCheckbox"));
        overrideCheckbox->setGeometry(QRect(10, 20, 111, 21));
        balanceBox = new QSpinBox(advancedGroup);
        balanceBox->setObjectName(QStringLiteral("balanceBox"));
        balanceBox->setEnabled(false);
        balanceBox->setGeometry(QRect(130, 20, 42, 22));
        balanceBox->setMaximum(127);
        paletteGroup = new QGroupBox(centralWidget);
        paletteGroup->setObjectName(QStringLiteral("paletteGroup"));
        paletteGroup->setGeometry(QRect(10, 160, 361, 281));
        previewPaletteButton = new QPushButton(paletteGroup);
        previewPaletteButton->setObjectName(QStringLiteral("previewPaletteButton"));
        previewPaletteButton->setEnabled(false);
        previewPaletteButton->setGeometry(QRect(110, 250, 61, 21));
        paletteTable = new QTableWidget(paletteGroup);
        if (paletteTable->columnCount() < 8)
            paletteTable->setColumnCount(8);
        paletteTable->setObjectName(QStringLiteral("paletteTable"));
        paletteTable->setGeometry(QRect(10, 20, 341, 221));
        paletteTable->setFocusPolicy(Qt::NoFocus);
        paletteTable->setStyleSheet(QStringLiteral("QTableView::item::selected:inactive{background-color: transparent;}"));
        paletteTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        paletteTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        paletteTable->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        paletteTable->setDragDropOverwriteMode(false);
        paletteTable->setDragDropMode(QAbstractItemView::DragDrop);
        paletteTable->setDefaultDropAction(Qt::MoveAction);
        paletteTable->setSelectionMode(QAbstractItemView::SingleSelection);
        paletteTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        paletteTable->setShowGrid(false);
        paletteTable->setSortingEnabled(false);
        paletteTable->setCornerButtonEnabled(false);
        paletteTable->setRowCount(0);
        paletteTable->setColumnCount(8);
        paletteTable->setProperty("immutableRows", QVariant(0));
        paletteTable->horizontalHeader()->setVisible(false);
        paletteTable->horizontalHeader()->setDefaultSectionSize(30);
        paletteTable->horizontalHeader()->setHighlightSections(false);
        paletteTable->horizontalHeader()->setMinimumSectionSize(33);
        paletteTable->horizontalHeader()->setStretchLastSection(false);
        paletteTable->verticalHeader()->setVisible(false);
        plusMinusGroup = new QWidget(paletteGroup);
        plusMinusGroup->setObjectName(QStringLiteral("plusMinusGroup"));
        plusMinusGroup->setGeometry(QRect(10, 240, 91, 41));
        removePaletteButton = new QPushButton(plusMinusGroup);
        removePaletteButton->setObjectName(QStringLiteral("removePaletteButton"));
        removePaletteButton->setEnabled(false);
        removePaletteButton->setGeometry(QRect(50, 10, 41, 21));
        addPaletteButton = new QPushButton(plusMinusGroup);
        addPaletteButton->setObjectName(QStringLiteral("addPaletteButton"));
        addPaletteButton->setEnabled(false);
        addPaletteButton->setGeometry(QRect(0, 10, 41, 21));
        saveLoadGroup = new QWidget(paletteGroup);
        saveLoadGroup->setObjectName(QStringLiteral("saveLoadGroup"));
        saveLoadGroup->setGeometry(QRect(230, 240, 131, 41));
        loadPalettesButton = new QPushButton(saveLoadGroup);
        loadPalettesButton->setObjectName(QStringLiteral("loadPalettesButton"));
        loadPalettesButton->setGeometry(QRect(70, 10, 51, 21));
        savePalettesButton = new QPushButton(saveLoadGroup);
        savePalettesButton->setObjectName(QStringLiteral("savePalettesButton"));
        savePalettesButton->setGeometry(QRect(10, 10, 51, 21));
        copyPaletteCheckbox = new QCheckBox(paletteGroup);
        copyPaletteCheckbox->setObjectName(QStringLiteral("copyPaletteCheckbox"));
        copyPaletteCheckbox->setEnabled(true);
        copyPaletteCheckbox->setGeometry(QRect(180, 250, 51, 21));
        copyPaletteCheckbox->setChecked(true);
        saveLoadGroup->raise();
        plusMinusGroup->raise();
        previewPaletteButton->raise();
        paletteTable->raise();
        copyPaletteCheckbox->raise();
        aboutButton = new QPushButton(centralWidget);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setGeometry(QRect(10, 450, 71, 21));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(280, 450, 91, 21));
        helpButton = new QPushButton(centralWidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(90, 450, 71, 21));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(180, 450, 91, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ColorShifter", 0));
        colorGroup->setTitle(QApplication::translate("MainWindow", "Colors", 0));
#ifndef QT_NO_TOOLTIP
        removeColorButton->setToolTip(QApplication::translate("MainWindow", "Remove selected color", 0));
#endif // QT_NO_TOOLTIP
        removeColorButton->setText(QApplication::translate("MainWindow", "\342\200\223", 0));
#ifndef QT_NO_TOOLTIP
        addColorButton->setToolTip(QApplication::translate("MainWindow", "Add a new color", 0));
#endif // QT_NO_TOOLTIP
        addColorButton->setText(QApplication::translate("MainWindow", "+", 0));
#ifndef QT_NO_TOOLTIP
        smartRandomizeCheckbox->setToolTip(QApplication::translate("MainWindow", "Prefer nicer colors when pressing \"Randomize\"", 0));
#endif // QT_NO_TOOLTIP
        smartRandomizeCheckbox->setText(QApplication::translate("MainWindow", "Smart", 0));
        valueBlueLabel->setText(QApplication::translate("MainWindow", "Value", 0));
        alphaLabel->setText(QApplication::translate("MainWindow", "Alpha", 0));
#ifndef QT_NO_TOOLTIP
        previewColorCheckbox->setToolTip(QApplication::translate("MainWindow", "Preview theme colors to currently selected color", 0));
#endif // QT_NO_TOOLTIP
        previewColorCheckbox->setText(QApplication::translate("MainWindow", "Preview", 0));
#ifndef QT_NO_TOOLTIP
        hsvRadio->setToolTip(QApplication::translate("MainWindow", "Adjust colors using hue/saturation/value components", 0));
#endif // QT_NO_TOOLTIP
        hsvRadio->setText(QApplication::translate("MainWindow", "HSV", 0));
        hueRedLabel->setText(QApplication::translate("MainWindow", "Hue", 0));
#ifndef QT_NO_TOOLTIP
        satGreenSlider->setToolTip(QApplication::translate("MainWindow", "Adjust component value", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        valueBlueSlider->setToolTip(QApplication::translate("MainWindow", "Adjust component value", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        alphaSlider->setToolTip(QApplication::translate("MainWindow", "Adjust component value", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        rgbRadio->setToolTip(QApplication::translate("MainWindow", "Adjust colors using red/green/blue components", 0));
#endif // QT_NO_TOOLTIP
        rgbRadio->setText(QApplication::translate("MainWindow", "RGB", 0));
#ifndef QT_NO_TOOLTIP
        hueRedSlider->setToolTip(QApplication::translate("MainWindow", "Adjust component value", 0));
#endif // QT_NO_TOOLTIP
        satGreenLabel->setText(QApplication::translate("MainWindow", "Sat", 0));
#ifndef QT_NO_TOOLTIP
        randomizeColorButton->setToolTip(QApplication::translate("MainWindow", "Choose a random color", 0));
#endif // QT_NO_TOOLTIP
        randomizeColorButton->setText(QApplication::translate("MainWindow", "Randomize", 0));
#ifndef QT_NO_TOOLTIP
        copyColorCheckbox->setToolTip(QApplication::translate("MainWindow", "Copy selected color when pressing \"+\"", 0));
#endif // QT_NO_TOOLTIP
        copyColorCheckbox->setText(QApplication::translate("MainWindow", "Copy", 0));
#ifndef QT_NO_TOOLTIP
        startWindowsCheckbox->setToolTip(QApplication::translate("MainWindow", "Run ColorShifter when Windows starts", 0));
#endif // QT_NO_TOOLTIP
        startWindowsCheckbox->setText(QApplication::translate("MainWindow", "Start with Windows", 0));
#ifndef QT_NO_TOOLTIP
        mainButton->setToolTip(QApplication::translate("MainWindow", "Start shifting colors", 0));
#endif // QT_NO_TOOLTIP
        mainButton->setText(QApplication::translate("MainWindow", "Shift the colors!", 0));
        settingsGroup->setTitle(QApplication::translate("MainWindow", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        smoothnessSlider->setToolTip(QApplication::translate("MainWindow", "Adjust the smoothness of the transitions", 0));
#endif // QT_NO_TOOLTIP
        smoothnessLabel->setText(QApplication::translate("MainWindow", "Smoothness", 0));
#ifndef QT_NO_TOOLTIP
        timeSlider->setToolTip(QApplication::translate("MainWindow", "Set the time it takes to go through all the colors", 0));
#endif // QT_NO_TOOLTIP
        timeLabel->setText(QApplication::translate("MainWindow", "Cycle time", 0));
        smoothnessStatusLabel->setText(QApplication::translate("MainWindow", "Very smooth", 0));
#ifndef QT_NO_TOOLTIP
        randomCheckbox->setToolTip(QApplication::translate("MainWindow", "Shift the colors in a random order (only colors from palette will be used)", 0));
#endif // QT_NO_TOOLTIP
        randomCheckbox->setText(QApplication::translate("MainWindow", "Shift colors in random order", 0));
#ifndef QT_NO_TOOLTIP
        smartCheckbox->setToolTip(QApplication::translate("MainWindow", "Use HSV color space for transitions, not RGB. May have graphical glitches", 0));
#endif // QT_NO_TOOLTIP
        smartCheckbox->setText(QApplication::translate("MainWindow", "Transition by hue", 0));
        timeEdit->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm:ss", 0));
        advancedGroup->setTitle(QApplication::translate("MainWindow", "Advanced", 0));
#ifndef QT_NO_TOOLTIP
        overrideCheckbox->setToolTip(QApplication::translate("MainWindow", "Override the colorBalance value from dwmapi.dll", 0));
#endif // QT_NO_TOOLTIP
        overrideCheckbox->setText(QApplication::translate("MainWindow", "Override balance", 0));
#ifndef QT_NO_TOOLTIP
        balanceBox->setToolTip(QApplication::translate("MainWindow", "Value for colorBalance. Between 0 and 127.", 0));
#endif // QT_NO_TOOLTIP
        paletteGroup->setTitle(QApplication::translate("MainWindow", "Palettes", 0));
#ifndef QT_NO_TOOLTIP
        previewPaletteButton->setToolTip(QApplication::translate("MainWindow", "Preview the current palette transitions", 0));
#endif // QT_NO_TOOLTIP
        previewPaletteButton->setText(QApplication::translate("MainWindow", "Preview", 0));
#ifndef QT_NO_TOOLTIP
        removePaletteButton->setToolTip(QApplication::translate("MainWindow", "Remove selected palette", 0));
#endif // QT_NO_TOOLTIP
        removePaletteButton->setText(QApplication::translate("MainWindow", "\342\200\223", 0));
#ifndef QT_NO_TOOLTIP
        addPaletteButton->setToolTip(QApplication::translate("MainWindow", "Add a new palette", 0));
#endif // QT_NO_TOOLTIP
        addPaletteButton->setText(QApplication::translate("MainWindow", "+", 0));
#ifndef QT_NO_TOOLTIP
        loadPalettesButton->setToolTip(QApplication::translate("MainWindow", "Load palettes and settings from file", 0));
#endif // QT_NO_TOOLTIP
        loadPalettesButton->setText(QApplication::translate("MainWindow", "Load", 0));
#ifndef QT_NO_TOOLTIP
        savePalettesButton->setToolTip(QApplication::translate("MainWindow", "Save palettes and settings to file", 0));
#endif // QT_NO_TOOLTIP
        savePalettesButton->setText(QApplication::translate("MainWindow", "Save", 0));
#ifndef QT_NO_TOOLTIP
        copyPaletteCheckbox->setToolTip(QApplication::translate("MainWindow", "Copy selected palette when pressing \"+\".", 0));
#endif // QT_NO_TOOLTIP
        copyPaletteCheckbox->setText(QApplication::translate("MainWindow", "Copy", 0));
#ifndef QT_NO_TOOLTIP
        aboutButton->setToolTip(QApplication::translate("MainWindow", "About ColorShifter", 0));
#endif // QT_NO_TOOLTIP
        aboutButton->setText(QApplication::translate("MainWindow", "About", 0));
#ifndef QT_NO_TOOLTIP
        quitButton->setToolTip(QApplication::translate("MainWindow", "Stops shifting and completely quits the application", 0));
#endif // QT_NO_TOOLTIP
        quitButton->setText(QApplication::translate("MainWindow", "Stop and quit", 0));
#ifndef QT_NO_TOOLTIP
        helpButton->setToolTip(QApplication::translate("MainWindow", "Detailed help", 0));
#endif // QT_NO_TOOLTIP
        helpButton->setText(QApplication::translate("MainWindow", "Help", 0));
#ifndef QT_NO_TOOLTIP
        resetButton->setToolTip(QApplication::translate("MainWindow", "Detailed help", 0));
#endif // QT_NO_TOOLTIP
        resetButton->setText(QApplication::translate("MainWindow", "Reset defaults", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
