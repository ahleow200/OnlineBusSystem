#-------------------------------------------------
#
# Project created by QtCreator 2014-03-30T03:30:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OnlineBusSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    busstoplist.cpp \
    bus.cpp \
    busstop.cpp \
    bussimulator.cpp

HEADERS  += mainwindow.h \
    busstoplist.h \
    bus.h \
    busstop.h \
    bussimulator.h

FORMS    += mainwindow.ui
