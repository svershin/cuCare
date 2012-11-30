#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T19:38:21
#
#-------------------------------------------------

QT       += core gui network

TARGET = CuCare
TEMPLATE = app


SOURCES += main.cpp\
    ObjectInterpreter/ObjectInterpreter.cpp

HEADERS  += \
    ObjectInterpreter/ObjectInterpreter.h

FORMS    += \
    patientselectdialog.ui \
    loginwindowdialog.ui \
    mainwindow.ui \
    followuptypeselectdialog.ui


unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareModel/ -lCuCareModel

INCLUDEPATH += $$PWD/../CuCareModel
DEPENDPATH += $$PWD/../CuCareModel

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareModel/libCuCareModel.a
