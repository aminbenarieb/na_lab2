#-------------------------------------------------
#
# Project created by QtCreator 2016-03-17T12:58:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qpaintwidget.cpp \
    calculationkit.cpp \
    addpointdialog.cpp

HEADERS  += mainwindow.h \
    congif.h \
    qpaintwidget.h \
    calculationkit.h \
    addpointdialog.h

FORMS    += mainwindow.ui
