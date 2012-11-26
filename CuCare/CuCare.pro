#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T19:38:21
#
#-------------------------------------------------

QT       += core gui network

TARGET = CuCare
TEMPLATE = app


SOURCES += main.cpp\
    patientselectdialog.cpp \
    loginwindowdialog.cpp \
    mainwindow.cpp \
    MasterController/MasterController.cpp \
    MasterController/Request.cpp \
    followuptypeselectdialog.cpp \
    ObjectInterpreter/ObjectInterpreter.cpp

HEADERS  += \
    patientselectdialog.h \
    loginwindowdialog.h \
    mainwindow.h \
    MasterController/MasterController.h \
    MasterController/Request.h \
    followuptypeselectdialog.h \
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
