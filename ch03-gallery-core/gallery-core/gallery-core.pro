#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T21:20:51
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = gallery-core
TEMPLATE = lib

DEFINES += GALLERYCORE_LIBRARY

SOURCES += album.cpp \
    picture.cpp \
    DatabaseManager.cpp \
    AlbumDao.cpp \
    picturedao.cpp \
    albummodel.cpp \
    picturemodel.cpp

HEADERS += album.h\
        gallery-core_global.h \
    picture.h \
    DatabaseManager.h \
    AlbumDao.h \
    picturedao.h \
    albummodel.h \
    picturemodel.h
