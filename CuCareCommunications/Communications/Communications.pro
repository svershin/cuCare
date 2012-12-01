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
    AbstractNetworkMessenger.cpp \
    ServerNetworkInterface.cpp \
    ServerNetworkRequestInterpreter.cpp \
    AbstractNetworkTranslator.cpp \
    ServerNetworkConnection.cpp \
    ClientNetworkTranslator.cpp \
    ServerNetworkTranslator.cpp \
    ServerController.cpp \
    AuditTimer.cpp

HEADERS += \
    ClientNetworkInterface.h \
    ClientNetworkConnection.h \
    ServerNetworkListener.h \
    AbstractNetworkMessenger.h \
    ServerNetworkInterface.h \
    ServerNetworkRequestInterpreter.h \
    AbstractNetworkTranslator.h \
    ServerNetworkConnection.h \
    ClientNetworkTranslator.h \
    ServerNetworkTranslator.h \
    ServerController.h \
    AuditTimer.h
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
