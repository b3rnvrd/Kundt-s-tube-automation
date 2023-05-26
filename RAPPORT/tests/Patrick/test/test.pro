TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32: LIBS += -L$$PWD/'../../../../Program Files (x86)/IVI Foundation/VISA/WinNT/lib/msc/' -lvisa32

INCLUDEPATH += $$PWD/'../../../../Program Files (x86)/IVI Foundation/VISA/WinNT/include'
DEPENDPATH += $$PWD/'../../../../Program Files (x86)/IVI Foundation/VISA/WinNT/include'
