#-------------------------------------------------
#
# Project created by QtCreator 2018-04-25T15:32:13
#
#-------------------------------------------------

QT       += core gui
CONFIG   += C++14
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ch02-sysinfo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SysInfo.cpp \
    SysInfoWidget.cpp

HEADERS  += mainwindow.h \
    SysInfo.h \
    SysInfoWidget.h

macx {
    SOURCES += SysInfoMacImpl.cpp
    HEADERS += SysInfoMacImpl.h
}

FORMS    += mainwindow.ui
