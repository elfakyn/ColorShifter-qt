/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QStringLiteral("HelpWindow"));
        HelpWindow->resize(640, 480);
        gridLayout_2 = new QGridLayout(HelpWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(HelpWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);


        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QDialog *HelpWindow)
    {
        HelpWindow->setWindowTitle(QApplication::translate("HelpWindow", "ColorShifter Help", 0));
        textBrowser->setHtml(QApplication::translate("HelpWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"colorshifter\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:xx-large; font-weight:600;\">C</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:xx-large; font-weight:600;\">olorShifter</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">ColorShifter dynamically changes the Windows 7/8 theme colors by tapping into an undocumented AP"
                        "I</span></p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"notworking\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:x-large; font-weight:600;\">N</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:x-large; font-weight:600;\">ot working?</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">If you have your theme set to very transparent, ColorShifter's changes will not be too visible. Try the following:</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press"
                        " &quot;Stop and quit&quot; on ColorShifter</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Right click on your Desktop, select Personalize</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Click &quot;Color&quot; on the bottom, move the color intensity slider to the right</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You can also uncheck &quot;transparency&quot; if you're using Windows 7</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Start Col"
                        "orShifter</li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">This works because ColorShifter takes the color intensity and transparency settings from what you set in &quot;Personalize&quot;.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Alternatively, check the &quot;Override balance&quot; checkbox in ColorShifter and increase the value to about 80-100. This manually sets the color intensity settings.</span></p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"usage\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:x-large; font-weight:600;\">U</span><span style=\" font-family:'verdana,h"
                        "elvetica,arial,sans-serif'; font-size:x-large; font-weight:600;\">sage</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">The main interface is split into three sections:</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Settings</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Palettes</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inde"
                        "nt:0px;\">Colors</li></ul>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"settings-group\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">S</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">ettings group</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">The settings group contains the following options:</span></p>\n"
"<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\"><thead>\n"
"<tr>\n"
"<td bgcolor=\"#414141\" style=\" padding-left:7; padding-right:7; padding-top:4; padding-bottom:4;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
                        "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-weight:600; color:#ffffff; background-color:#414141;\">Item</span></p></td>\n"
"<td bgcolor=\"#414141\" style=\" padding-left:7; padding-right:7; padding-top:4; padding-bottom:4;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-weight:600; color:#ffffff; background-color:#414141;\">Description</span></p></td></tr></thead>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Smootness</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p st"
                        "yle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Changes the smoothness of the transitions. Smoother settings consume more resources. &quot;Disco&quot; disables transitions.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Cycle time</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Sets the duration of a cycle, i.e. the time until the palette wraps around back to the first color. Mini"
                        "mum value: 00:00:01. Maximum value: 23:59:59.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Shift colors in random order</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Picks colors at random from the palette instead of cycling between them sequentially</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-fa"
                        "mily:'verdana,helvetica,arial,sans-serif';\">Transition by hue</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Uses Hue-Saturation-Value representation when transitioning between colors, e.g. Red-&gt;Green goes through yellow instead of brown. May have a few visual glitches.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Override balance</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Forces the colorBalance value in Window's DwmColorizationParameters to the value in the box. Play with this if colors are too washed out or jump around.</span></p></td></tr></table>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"palette-group\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">P</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">alette group</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Using the palette table you can rename palettes (double-click on the name) or drag and drop them around. There are also several buttons:</span"
                        "></p>\n"
"<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\"><thead>\n"
"<tr>\n"
"<td bgcolor=\"#414141\" style=\" padding-left:7; padding-right:7; padding-top:4; padding-bottom:4;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-weight:600; color:#ffffff; background-color:#414141;\">Item</span></p></td>\n"
"<td bgcolor=\"#414141\" style=\" padding-left:7; padding-right:7; padding-top:4; padding-bottom:4;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-weight:600; color:#ffffff; background-color:#414141;\">Description</span></p></td></tr></thead>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-rig"
                        "ht:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">+</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Adds a new palette to the table. If &quot;copy&quot; is checked, it copies the currently selected palette.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">-</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:"
                        "3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Removes palette from the table. You cannot remove the last palette.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Preview</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Displays a quick preview of how the current palette looks like in action. Click again to stop preview.</span></p></td></tr>\n"
"<tr"
                        ">\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Copy</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">If this is checked, adding a new palette will copy the currently selected one.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Save</span></p></td>\n"
"<td style=\" padding-left:7; paddi"
                        "ng-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Saves all current palettes to a file, as well as all the settings in the settings group.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Load</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Loads palettes and settings from a file, replacing the existing ones.</span></p></td></tr"
                        "></table>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"color-group\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">C</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">olor group</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Using the color group you can manually set the hex value of the color (double-click on the value) or drag and drop them around.</span></p>\n"
"<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\"><thead>\n"
"<tr>\n"
"<td bgcolor=\"#414141\" style=\" padding-left:7; padding-right:7; padding-top:4; padding-bottom:4;\">\n"
"<p align=\"center\" style=\""
                        " margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-weight:600; color:#ffffff; background-color:#414141;\">Item</span></p></td>\n"
"<td bgcolor=\"#414141\" style=\" padding-left:7; padding-right:7; padding-top:4; padding-bottom:4;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-weight:600; color:#ffffff; background-color:#414141;\">Description</span></p></td></tr></thead>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">+</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; "
                        "padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Adds a new color to the table. If &quot;copy&quot; is checked, it copies the currently selected color. Otherwise it adds a random color.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">-</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Removes the selected color from the table. You cannot re"
                        "move the last color.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Preview</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">If this is checked, the windows theme colors will change to the currently selected color. Useful for choosing colors that don't prevent you from reading the window titles.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Hue, Sat, Value, Alpha</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Controls the hue, saturation, value, and transparency of the color. (HSV is checked)</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Red, Green, Blue, Alpha</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Controls the red, green, blue, and alpha channels of the color. (RGB is checked)</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">RGB, HSV</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Determines whether the sliders control the RGB or the HSV components of the spectrum.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bot"
                        "tom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Randomize</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Chooses a random color.</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Smart</span></p></td>\n"
"<td style=\" padding-left:7; padding-right:7; padding-top:3; padding-bottom:2;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
                        "style=\" font-family:'verdana,helvetica,arial,sans-serif';\">If this is checked, randomize will prefer nice colors over ugly ones.</span></p></td></tr></table>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"other-buttons\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">O</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">ther buttons</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">About</span> displays some brief information about the program and its author</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-se"
                        "rif';\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Help</span> displays this text</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Stop and quit</span> stops shifting and exits the application</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Start with Windows</span> controls whether or not the application will automatically run when you log into Windows.</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style"
                        "=\" font-weight:600;\">Shift the colors!</span> starts shifting the Windows theme colors according to the selected palette. You need to select a palette before this button becomes available. Click again to stop.</li></ul>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"system-tray\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">S</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:large; font-weight:600;\">ystem tray</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">When the application is loaded, it will display an icon in the system tray. Pressing &quot;X&quot; on the main application window will not close the application. Use &quot;Stop and quit&quot; instead.</span></p>\n"
"<p sty"
                        "le=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Double-clicking on the icon will minimize the main application if it's maximized and maximize it if it's minimized. Middle-clicking on the icon will start/stop shifting the colors. Right clicking the application will bring up a menu where you can minimize, restore, start/stop shifting the colors as well as close the application.</span></p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"known-issues\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:x-large; font-weight:600;\">K</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:x-large; font-weight:600;\">nown Issues</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent:"
                        " 1;\"><li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Pressing &quot;preview&quot; on a palette with &quot;shift colors in random order&quot; checked will stop after a random amount of time instead of a single cycle.</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Manually typing in the hex code for a color while the HSV radio button is selected may result in small changes to the inputted value.</li>\n"
"<li style=\" font-family:'verdana,helvetica,arial,sans-serif';\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Setting smoothness too high, cycle time too low and adding too many colors at the same time might slow down your system.</li></ul>\n"
"<p style=\" margin"
                        "-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"how-to-use-the-undocumented-api-for-your-own-purposes\"></a><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:x-large; font-weight:600;\">H</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif'; font-size:x-large; font-weight:600;\">ow to use the undocumented API for your own purposes</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">I only know how to do this in C++. First, declare your function pointers and load the dwmapi DLL. This is Windows black magic and I won't even pretend to know what's going on here.</span></p>\n"
"<pre style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">hlib ="
                        " LoadLibrary(&quot;dwmapi.dll&quot;); // load the Window Manager API</span></pre>\n"
"<pre style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"><br /></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">if (!hlib) {</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">    std::cerr &lt;&lt; &quot;Could not load dwmapi.dll&quot; &lt;&lt; std::endl;</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">    return -1;</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margi"
                        "n-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">}</span></pre>\n"
"<pre style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"><br /></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">*(FARPROC *)&amp;DwmGetColorizationParameters = GetProcAddress(hlib, (LPCSTR)127);</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">*(FARPROC *)&amp;DwmSetColorizationParameters = GetProcAddress(hlib, (LPCSTR)131);</span></pre>\n"
"<pre style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-"
                        "indent:0px; font-family:'Courier New,courier';\"><br /></pre>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">You then need the DwmColorizationParameters struct that will get passed to the functions:</span></p>\n"
"<pre style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">typedef struct { // DwmColorizationParameters</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">    int color;</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">    int afterglow;</span></pre>\n"
"<pre st"
                        "yle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">    int colorBalance;</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">    int afterglowBalance;</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">    int blurBalance;</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">    int glassReflectionIntensity;</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier Ne"
                        "w,courier';\">    int opaqueBlend;</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">} DwmColorizationParameters;</span></pre>\n"
"<pre style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"><br /></pre>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">The </span><span style=\" font-family:'Courier New,courier';\">color</span><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\"> field is an 4-byte integer containing the alpha, red, green, and blue components (0xAARRGGBB). The </span><span style=\" font-family:'Courier New,courier';\">colorBalance</span><span style=\" font-family:'verdana,helve"
                        "tica,arial,sans-serif';\"> field is an integer setting some sort of saturation for the colors, between 0 and 127. I'm not really sure what the others do. They don't seem to have an effect on Windows 8, and on Windows 7 I think they control the intensity/opacity of different glass efects.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">Now you can use the functions.</span></p>\n"
"<pre style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">DwmColorizationParameters myColor; // declare the struct that we'll be using</span></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">DwmGetColorizationParameters(&amp;myColo"
                        "r); // myColor now contains the current values of the Windows interface</span></pre>\n"
"<pre style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"><br /></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">myColor.color = 0xFF00FF00; // Alpha: 255, Red: 0, Green: 255, Blue: 0</span></pre>\n"
"<pre style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"><br /></pre>\n"
"<pre style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">DwmSetColorizationParameters(&amp;myColor, 0); // I don't know what the 0 does but you need it</sp"
                        "an></pre>\n"
"<pre style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"><br /></pre>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">By knowing this basic implementation you can do all sorts of things with the Windows theme colors. I'm not sure why Microsoft chose to leave these functions undocumented; I think they're pretty neat.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'verdana,helvetica,arial,sans-serif';\">One other thing: I can't take the credit for finding out how to fish into the Window Manager DLL. I realized it was possible when I was playing with the display settings and the theme color changed instantly -- sure"
                        "ly there must be a mechanism with which to do that. After hours of intense searching, I managed to string together a few incomplete tutorials to make it work. If you were the first person to figure it out, let me know and I'll credit you and link to your tutorial/website.</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
