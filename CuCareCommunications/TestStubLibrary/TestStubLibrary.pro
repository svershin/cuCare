#-------------------------------------------------
#
# Project created by QtCreator 2012-11-28T10:13:20
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = TestStubLibrary
TEMPLATE = lib
CONFIG += staticlib

SOURCES += Repository.cpp \
    StorageObject.cpp

HEADERS += Repository.h \
    StorageObject.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
