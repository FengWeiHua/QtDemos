#-------------------------------------------------
#
# Project created by QtCreator 2018-04-25T10:26:13
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = todo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Task.cpp

HEADERS  += mainwindow.h \
    Task.h

FORMS    += mainwindow.ui \
    Task.ui
