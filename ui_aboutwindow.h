/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QLabel *icon;
    QPushButton *closeButton;
    QLabel *text;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QStringLiteral("AboutWindow"));
        AboutWindow->resize(240, 360);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutWindow->sizePolicy().hasHeightForWidth());
        AboutWindow->setSizePolicy(sizePolicy);
        AboutWindow->setMinimumSize(QSize(240, 360));
        AboutWindow->setMaximumSize(QSize(240, 360));
        icon = new QLabel(AboutWindow);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setGeometry(QRect(50, 10, 141, 131));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/icon-128.png")));
        icon->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(AboutWindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(80, 330, 81, 21));
        text = new QLabel(AboutWindow);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(15, 150, 211, 171));
        text->setTextFormat(Qt::RichText);
        text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        text->setOpenExternalLinks(true);

        retranslateUi(AboutWindow);

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "About ColorShifter", 0));
#ifndef QT_NO_WHATSTHIS
        icon->setWhatsThis(QApplication::translate("AboutWindow", "Also check out Hacker School!", 0));
#endif // QT_NO_WHATSTHIS
        icon->setText(QString());
        closeButton->setText(QApplication::translate("AboutWindow", "Close", 0));
        text->setText(QApplication::translate("AboutWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#414141;\">ColorShifter 1.0.1</span></p><p><span style=\" font-size:10pt;\">By Mihai Radu Popescu (</span><a href=\"https://twitter.com/elfakyn\"><span style=\" font-size:10pt; text-decoration: underline; color:#414141;\">@elfakyn</span></a><span style=\" font-size:10pt;\">)</span></p><p><span style=\" font-size:10pt;\">Browse </span><a href=\"https://github.com/elfakyn/ColorShifter-qt\"><span style=\" font-size:10pt; text-decoration: underline; color:#414141;\">the source code</span></a><span style=\" font-size:10pt;\">!<br/>Explore </span><a href=\"https://github.com/elfakyn\"><span style=\" font-size:10pt; text-decoration: underline; color:#414141;\">my GitHub</span></a><span style=\" font-size:10pt;\">!<br/>Check out </span><a href=\"http://www.sthaskell.com/\"><span style=\" font-size:10pt; text-decoration: underline; color:#414141;\">my Haskell book</span></a><span style=\" font-size:10pt;\">!<br/>Read </span><a "
                        "href=\"https://docs.google.com/document/d/1ByVNHsiWWF6shWj5DtPqO2uFuoVD5aPw54XgHibNvz0/\"><span style=\" font-size:10pt; text-decoration: underline; color:#414141;\">my resume</span></a><span style=\" font-size:10pt;\">!</span></p><p><span style=\" font-size:10pt;\">This application uses Qt 5, which is</span><br/><a href=\"http://qt-project.org/doc/qt-5/lgpl.html\"><span style=\" font-size:10pt; text-decoration: underline; color:#414141;\">licensed under the LGPL</span></a><span style=\" font-size:10pt;\">.</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
