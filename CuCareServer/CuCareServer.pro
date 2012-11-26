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
    Tests.cpp \
    Storage/sqlite3.c \
    Storage/QueryResult.cpp \
    Storage/Database.cpp \
    Storage/StorageObject.cpp \
    Storage/Repository.cpp \
    Storage/RepoModel.cpp \
    Storage/Sqlite3Database.cpp

HEADERS += \
    Tests.h \
    Storage/sqlite3.h \
    Storage/QueryResult.h \
    Storage/Database.h \
    Storage/StorageObject.h \
    Storage/Repository.h \
    Storage/RepoModel.h \
    Storage/Sqlite3Database.h

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareModel/ -lCuCareModel

INCLUDEPATH += $$PWD/../CuCareModel
DEPENDPATH += $$PWD/../CuCareModel

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareModel/libCuCareModel.a

OTHER_FILES += \
    Storage/dbcreate.sql
