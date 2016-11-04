#-------------------------------------------------
#
# Project created by QtCreator 2016-11-04T21:09:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = notepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    finddialog.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    finddialog.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    finddialog.ui

QT += printsupport

RESOURCES += \
    icon.qrc \
    rec.qrc

RC_FILE=ico.rc
