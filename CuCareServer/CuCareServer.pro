#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T20:21:42
#
#-------------------------------------------------

QT       += network core

QT       -= gui

TARGET = CuCareServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Database.cpp \
    sqlite3.c \
    QueryResult.cpp \
    Tests.cpp \
    Repository.cpp

HEADERS += \
    Database.h \
    sqlite3.h \
    QueryResult.h \
    Tests.h \
    Repository.h

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareModel/ -lCuCareModel

INCLUDEPATH += $$PWD/../CuCareModel
DEPENDPATH += $$PWD/../CuCareModel

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareModel/libCuCareModel.a

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareCommunications/qjson/lib/ -lqjson

INCLUDEPATH += $$PWD/../CuCareCommunications/qjson/include
DEPENDPATH += $$PWD/../CuCareCommunications/qjson/include

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareCommunications/Communications/ -lCommunications

INCLUDEPATH += $$PWD/../CuCareCommunications/Communications
DEPENDPATH += $$PWD/../CuCareCommunications/Communications

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareCommunications/Communications/libCommunications.a
