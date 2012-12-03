#-------------------------------------------------
#
# Project created by QtCreator 2012-10-30T18:21:11
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = Communications
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    ClientNetworkInterface.cpp \
    ClientNetworkConnection.cpp \
    ServerNetworkListener.cpp \
    ServerNetworkInterface.cpp \
    ServerNetworkRequestInterpreter.cpp \
    ServerNetworkConnection.cpp \
    ClientNetworkTranslator.cpp \
    ServerNetworkTranslator.cpp \
    ServerController.cpp \
    AuditTimer.cpp \
    BaseNetworkMessenger.cpp \
    BaseNetworkTranslator.cpp

HEADERS += \
    ClientNetworkInterface.h \
    ClientNetworkConnection.h \
    ServerNetworkListener.h \
    ServerNetworkInterface.h \
    ServerNetworkRequestInterpreter.h \
    ServerNetworkConnection.h \
    ClientNetworkTranslator.h \
    ServerNetworkTranslator.h \
    ServerController.h \
    AuditTimer.h \
    BaseNetworkMessenger.h \
    BaseNetworkTranslator.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}



unix:!macx:!symbian: LIBS += -L$$PWD/../../CuCareStorage/ -lCuCareStorage

INCLUDEPATH += $$PWD/../../CuCareStorage
DEPENDPATH += $$PWD/../../CuCareStorage



unix:!macx:!symbian: LIBS += -L$$PWD/../qjson/build/lib/ -lqjson

INCLUDEPATH += $$PWD/../qjson/build
DEPENDPATH += $$PWD/../qjson/build
