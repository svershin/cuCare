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
    Tests.cpp

HEADERS += \
    Tests.h

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareModel/ -lCuCareModel

INCLUDEPATH += $$PWD/../CuCareModel
DEPENDPATH += $$PWD/../CuCareModel

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareModel/libCuCareModel.a

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCureStorage/ -lCuCureStorage

INCLUDEPATH += $$PWD/../CuCureStorage
DEPENDPATH += $$PWD/../CuCureStorage
