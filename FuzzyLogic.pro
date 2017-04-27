#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T21:44:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets\
                                        printsupport

TARGET = FuzzyLogic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    SistemasdeControle/headers/graphicLibs/QCustomPlot/qcustomplot.cpp \
    membershipfunction.cpp

HEADERS  += mainwindow.h \
    SistemasdeControle/headers/graphicLibs/QCustomPlot/qcustomplot.h \
    SistemasdeControle/headers/graphicLibs/plot.h \
    SistemasdeControle/headers/modelLibs/model.h \
    SistemasdeControle/headers/modelLibs/transferfunction.h \
    SistemasdeControle/src/graphicLibs/plot.hpp \
    SistemasdeControle/src/modelLibs/model.hpp \
    SistemasdeControle/src/modelLibs/transferfunction.hpp \
    membershipfunction.h \
    fuzzy.h \
    fuzzy.hpp \
    triangular.h \
    triangular.hpp \
    trapezoidal.h \
    trapezoidal.hpp \
    gaussiana.h \
    gaussiana.hpp

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

