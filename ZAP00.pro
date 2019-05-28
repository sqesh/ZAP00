TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    interface.cpp

HEADERS += \
    matrix.h \
    ludecomposition.h \
    functions.h \
    interface.h
