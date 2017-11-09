#-------------------------------------------------
#
# Project created by QtCreator 2017-10-13T15:36:32
#
#-------------------------------------------------

QT       += core gui

QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Warehouse
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inventoryedit.cpp \
    stockedit.cpp \
    purchaseinvoiceedit.cpp \
    salesinvoiceedit.cpp \
    textvalidation.cpp

HEADERS  += mainwindow.h \
    inventoryedit.h \
    stockedit.h \
    purchaseinvoiceedit.h \
    salesinvoiceedit.h \
    textvalidation.h

FORMS    += mainwindow.ui
