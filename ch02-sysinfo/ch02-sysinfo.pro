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
    SysInfoWidget.cpp \
    CpuWidget.cpp \
    MemoryWidgedt.cpp

HEADERS  += mainwindow.h \
    SysInfo.h \
    SysInfoWidget.h \
    CpuWidget.h \
    MemoryWidget.h

COMPILE_MSG = "Compiling on"

windows {
    SOURCES += SysInfoWindowsImpl.cpp
    HEADERS += SysInfoWindowsImpl.h
    message($$COMPILE_MSG windows)
}

linux {
    SOURCES += SysInfoLinuxImpl.cpp
    HEADERS += SysInfoLinuxImpl.h
    message($$COMPILE_MSG linux)
}

macx {
    SOURCES += SysInfoMacImpl.cpp
    HEADERS += SysInfoMacImpl.h
    message($$COMPILE_MSG mac)
}

FORMS    += mainwindow.ui
