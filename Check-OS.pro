#-------------------------------------------------
#
# Project created by QtCreator 2014-10-26T13:37:21
#
#-------------------------------------------------

QT       += core gui
CONFIG += qt


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Check-OS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/include/polkit-qt-1
INCLUDEPATH += $QTDIR/include/QtGui
