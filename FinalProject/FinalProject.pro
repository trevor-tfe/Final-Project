QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delivery.cpp \
    inventory.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    delivery.h \
    inventory.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

LIBS +=
    E:\msys64\mingw64\lib
    E:\msys64\usr\lib

INCLUDEPATH +=
    E:\msys64\mingw64\include
    E:\msys64\usr\include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
