#-------------------------------------------------
#
# Project created by QtCreator 2012-11-09T15:13:13
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = OutsideTester
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

unix:!macx:!symbian: LIBS += -L$$PWD/../Communications/ -lCommunications

INCLUDEPATH += $$PWD/../Communications
DEPENDPATH += $$PWD/../Communications

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../Communications/libCommunications.a



