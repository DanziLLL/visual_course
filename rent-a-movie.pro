#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T21:41:51
#
#-------------------------------------------------

QT       += core gui sql webkitwidgets
QTPLUGIN += QSQLMYSQL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rent-a-movie
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    admin_workspace.cpp \
    addmovie.cpp \
    viewtable.cpp \
    adduser.cpp \
    ratemovie.cpp

HEADERS += \
        mainwindow.h \
    admin_workspace.h \
    addmovie.h \
    viewtable.h \
    adduser.h \
    ratemovie.h

FORMS += \
        mainwindow.ui \
    admin_workspace.ui \
    user_workspace.ui \
    addmovie.ui \
    viewtable.ui \
    adduser.ui \
    ratemovie.ui
