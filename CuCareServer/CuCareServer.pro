#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T20:21:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = CuCareServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Database.cpp \
    sqlite3.c

HEADERS += \
    Database.h \
    sqlite3.h
