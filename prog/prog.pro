#-------------------------------------------------
#
# Project created by QtCreator 2016-03-29T19:57:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prog
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    firfilter.cpp \
    plotdialog.cpp

HEADERS  += mainwindow.h \
    Fixed.h \
    filtercoefs.h \
    firfilter.h \
    fircoefs.h \
    plotdialog.h


FORMS    += mainwindow.ui \
    plotdialog.ui

CXXFLAGS += -O0

#unix:!macx: LIBS += -L/usr/lib/ -lqwt

#INCLUDEPATH += /usr/include/qwt
#DEPENDPATH += /usr/include/qwt

mac: LIBS += -F$$PWD/../../../../../../../../../../usr/local/Cellar/qwt/6.1.2/lib/ -framework qwt

INCLUDEPATH += $$PWD/../../../../../../../../../../usr/local/Cellar/qwt/6.1.2
DEPENDPATH += $$PWD/../../../../../../../../../../usr/local/Cellar/qwt/6.1.2
INCLUDEPATH += /usr/local/Cellar/qwt/6.1.2/lib/qwt.framework/Versions/6/Headers

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib

QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.7
#QMAKE_CXXFLAGS = -mmacosx-version-min=10.7 -stdlib=libc++
