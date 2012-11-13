#-------------------------------------------------
#
# Project created by QtCreator 2012-10-30T18:21:11
#
#-------------------------------------------------

QT       += network xml

QT       -= gui

TARGET = Communications
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    ClientNetworkInterface.cpp \
    Translator.cpp \
    ClientSocket.cpp \
    ServerNetworkInterface.cpp \
    ServerSocket.cpp

HEADERS += \
    ClientNetworkInterface.h \
    Translator.h \
    ClientSocket.h \
    ServerNetworkInterface.h \
    ServerSocket.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
