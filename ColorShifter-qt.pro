#-------------------------------------------------
#
# Project created by QtCreator 2014-07-09T16:43:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorShifter-qt
TEMPLATE = app


SOURCES += \
    mainwindow.cpp \
main.cpp\
    dllTools.cpp \
    Color.cpp \
    colorTools.cpp \
    interpolate.cpp \
    main2.cpp \
    palette.cpp \
    hacks.cpp \
    aboutwindow.cpp


HEADERS  += \
    dllTools.h \
    mainwindow.h \
    colorTools.h \
    exitCodes.h \
    palette.h \
    table.ipp \
    table.hpp \
    hacks.h \
    aboutwindow.h

FORMS    += mainwindow.ui \
    aboutwindow.ui

RESOURCES += \
    defaultpalettes.qrc

OTHER_FILES += \
    colorshifter.rc \
    todo.txt \
    readme.md

RC_FILE = colorshifter.rc
