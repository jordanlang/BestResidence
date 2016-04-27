#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T16:01:05
#
#-------------------------------------------------

QT += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BestResidence
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ajout.cpp \
    annonce.cpp

HEADERS  += mainwindow.h \
    ajout.h \
    annonce.h

FORMS    += mainwindow.ui \
    ajout.ui \
    annonce.ui \
    ajoutclient.ui

DISTFILES += \
    annonces.xml
