#-------------------------------------------------
#
# Project created by QtCreator 2016-02-15T10:58:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = notepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    finddialog.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    finddialog.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    finddialog.ui \
    aboutdialog.ui

DISTFILES += \
    res/notepad.png \
    res/win10_1.png \
    res/win10_2.png \
    res/win10_3.png \
    res/1.bmp
#设置图标
RC_ICONS = res/np_mi.ico

RESOURCES += \
    rec.qrc \
    icon.qrc
