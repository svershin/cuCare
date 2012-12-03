#-------------------------------------------------
#
# Project created by QtCreator 2012-12-01T13:39:18
#
#-------------------------------------------------

QT       -= gui

TARGET = CuCareStorage
TEMPLATE = lib

DEFINES += CUCURESTORAGE_LIBRARY

SOURCES += \
    StorageObject.cpp \
    sqlite3.c \
    Sqlite3Database.cpp \
    Repository.cpp \
    RepoModel.cpp \
    QueryResult.cpp \
    Database.cpp

HEADERS += \
    StorageObject.h \
    sqlite3.h \
    Sqlite3Database.h \
    Repository.h \
    RepoModel.h \
    QueryResult.h \
    Database.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE64BC03B
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = CuCureStorage.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES += \
    dbcreate.sql

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareModel/ -lCuCareModel

INCLUDEPATH += $$PWD/../CuCareModel
DEPENDPATH += $$PWD/../CuCareModel

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../CuCareModel/libCuCareModel.a
