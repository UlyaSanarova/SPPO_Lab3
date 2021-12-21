QT       += core gui 
 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += charts
 
CONFIG += c++17 
 
# You can make your code fail to compile if it uses deprecated APIs. 
# In order to do so, uncomment the following line. 
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0 
 
SOURCES += \
    bardiagramitem.cpp \
    byfiletype_calculationstrategy.cpp \
    byfolder_calculationstrategy.cpp \
    calculationstrategy.cpp \
    dataview.cpp \
    main.cpp \
    mainwindow.cpp \
    tableviewitem.cpp \
    tableviewmodel.cpp \
    treeviewmodel.cpp
 
# Default rules for deployment. 
qnx: target.path = /tmp/$${TARGET}/bin 
else: unix:!android: target.path = /opt/$${TARGET}/bin 
!isEmpty(target.path): INSTALLS += target 

HEADERS += \
    bardiagramitem.h \
    byfiletype_calculationstrategy.h \
    byfolder_calculationstrategy.h \
    calculationstrategy.h \
    dataview.h \
    dataviewitem.h \
    mainwindow.h \
    tableviewitem.h \
    tableviewmodel.h \
    treeviewmodel.h
