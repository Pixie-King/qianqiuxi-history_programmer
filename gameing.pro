#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T18:59:12
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gameing
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
        ProCombine.cpp \
        azcombine.cpp \
        combine.cpp \
        main.cpp \
        mainwindow.cpp \
        mycard.cpp \
        mylabel.cpp \
        mymainscene.cpp \
        mypushbutton1.cpp \
        proai.cpp \
        procard.cpp \
        promainwindow.cpp

HEADERS += \
    ProCombine.h \
    azcombine.h \
    combine.h \
    mainwindow.h \
    mycard.h \
    mylabel.h \
    mymainscene.h \
    mypushbutton1.h \
    proai.h \
    procard.h \
    promainwindow.h

FORMS += \
    mainwindow.ui \
    mymainscene.ui \
    promainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    aimage.qrc \
    image.qrc

RC_FILE = qqx.rc
