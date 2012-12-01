#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T20:21:42
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = CuCareServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Tests.cpp

HEADERS += \
    Tests.h



unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareCommunications/Communications/ -lCommunications

INCLUDEPATH += $$PWD/../CuCareCommunications/Communications
DEPENDPATH += $$PWD/../CuCareCommunications/Communications

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareCommunications/Communications/libCommunications.a


unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareStorage/ -lCuCareStorage

INCLUDEPATH += $$PWD/../CuCareStorage
DEPENDPATH += $$PWD/../CuCareStorage



unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareCommunications/qjson/build/lib/ -lqjson

INCLUDEPATH += $$PWD/../CuCareCommunications/qjson/build
DEPENDPATH += $$PWD/../CuCareCommunications/qjson/build
