#========================================================================================

TARGET = ImageEditor

#========================================================================================

QT += widgets
QT += gui

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

#========================================================================================

MAIN_DIR = $$PWD

include( $$PWD/src/src.pri )

#========================================================================================

INCLUDEPATH += $$PWD

RESOURCES += images/images.qrc

#========================================================================================
