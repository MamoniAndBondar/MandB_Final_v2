#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T20:35:31
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MandB_Final_v2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dialogdel.cpp \
    dialogupdate.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dialogdel.h \
    dialogupdate.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialogdel.ui \
    dialogupdate.ui
