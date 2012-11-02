#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T19:38:21
#
#-------------------------------------------------

QT       += core gui

TARGET = CuCare
TEMPLATE = app


SOURCES += main.cpp\
    patientselectdialog.cpp \
    loginwindowdialog.cpp \
    mainwindow.cpp

HEADERS  += \
    patientselectdialog.h \
    loginwindowdialog.h \
    mainwindow.h

FORMS    += \
    patientselectdialog.ui \
    loginwindowdialog.ui \
    mainwindow.ui


unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareModel/ -lCuCareModel

INCLUDEPATH += $$PWD/../CuCareModel
DEPENDPATH += $$PWD/../CuCareModel

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareModel/libCuCareModel.a
