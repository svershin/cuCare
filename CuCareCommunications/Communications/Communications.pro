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
    request.cpp \
    requesthandler.cpp \
    messageparser.cpp \
    messagegenerator.cpp \
    testclass2.cpp \
    messenger.cpp

HEADERS += \
    request.h \
    requesthandler.h \
    messageparser.h \
    messagegenerator.h \
    commsinclude.h \
    messenger.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

unix:!macx:!symbian: LIBS += -L$$PWD/../../CuCareModel/ -lCuCareModel

INCLUDEPATH += $$PWD/../../CuCareModel
DEPENDPATH += $$PWD/../../CuCareModel

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../../CuCareModel/libCuCareModel.a



unix:!macx:!symbian: LIBS += -L$$PWD/../qjson/lib/ -lqjson

INCLUDEPATH += $$PWD/../qjson/include
DEPENDPATH += $$PWD/../qjson/include
