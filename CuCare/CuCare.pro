#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T19:38:21
#
#-------------------------------------------------

QT       += core gui network

TARGET = CuCare
TEMPLATE = app


SOURCES += main.cpp\
    ObjectInterpreter/ObjectInterpreter.cpp \
    ClientDataStorage/Factory.cpp \
    ClientDataStorage/Warehouse.cpp

HEADERS  += \
    ObjectInterpreter/ObjectInterpreter.h \
    ClientDataStorage/Factory.h \
    ClientDataStorage/Warehouse.h

FORMS    += \
    patientselectdialog.ui \
    loginwindowdialog.ui \
    mainwindow.ui \
    followuptypeselectdialog.ui


unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareModel/ -lCuCareModel

INCLUDEPATH += $$PWD/../CuCareModel
DEPENDPATH += $$PWD/../CuCareModel

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareModel/libCuCareModel.a

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareCommunications/Communications/ -lCommunications

INCLUDEPATH += $$PWD/../CuCareCommunications/Communications
DEPENDPATH += $$PWD/../CuCareCommunications/Communications

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareCommunications/Communications/libCommunications.a

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareCommunications/qjson/build/lib/ -lqjson

INCLUDEPATH += $$PWD/../CuCareCommunications/qjson/build
DEPENDPATH += $$PWD/../CuCareCommunications/qjson/build
