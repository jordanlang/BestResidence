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
    annoncewindow.cpp \
    annonce.cpp \
    client.cpp \
    ajoutclient.cpp \
    stats_immo.cpp \
    stats_clients.cpp \
    choix_client.cpp \
    clientwindow.cpp

HEADERS  += mainwindow.h \
    ajout.h \
    annoncewindow.h \
    annonce.h \
    client.h \
    ajoutclient.h \
    stats_immo.h \
    stats_clients.h \
    choix_client.h \
    clientwindow.h

FORMS    += mainwindow.ui \
    ajout.ui \
    ajoutclient.ui \
    annoncewindow.ui \
    stats_immo.ui \
    stats_clients.ui \
    choix_client.ui \
    clientwindow.ui

DISTFILES += \
    annonces.xml
