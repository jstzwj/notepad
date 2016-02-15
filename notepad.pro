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
    finddialog.cpp

HEADERS  += mainwindow.h \
    finddialog.h

FORMS    += mainwindow.ui \
    finddialog.ui

DISTFILES += \
    res/notepad.png
#设置图标
RC_ICONS = res/np_mi.ico
