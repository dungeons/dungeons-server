#-------------------------------------------------
#
# Project created by QtCreator 2013-03-13T08:47:37
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = untitled
TEMPLATE = lib

DEFINES += UNTITLED_LIBRARY

SOURCES += socket.cpp

HEADERS += socket.h\
        untitled_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE0B129CF
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = untitled.dll
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
