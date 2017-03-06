#-------------------------------------------------
#
# Project created by QtCreator 2016-02-09T10:40:17
#
#-------------------------------------------------

QT      += widgets
QT      += qml quick core
QT      += multimedia
QT      += sql
QT      += network


TARGET   = KugouMusic
TEMPLATE = app

#QMAKE_CXXFLAGS += -Wno-iCCP-known-incorrect-sRGB-profile
#QMAKE_CXXFLAGS += -Wno-iCCP-cHRM-chunk-does-not-match-sRGB

include(src/ui/ui.pri)
include(src/core/core.pri)
include(src/application/application.pri)
include(src/helper/helper.pri)
include(src/database/database.pri)          #���ݿ���ز���

INCLUDEPATH += $$PWD/src/ui
INCLUDEPATH += $$PWD/src/core
INCLUDEPATH += $$PWD/src/application
INCLUDEPATH += $$PWD/src/helper
INCLUDEPATH += $$PWD/src/database

MOC_DIR = temp/moc        #
RCC_DIR = temp/rcc        #Դ�ļ��м��ļ�
UI_DIR = temp/ui          #UI�м��ļ�
OBJECTS_DIR = temp/obj    #
DESTDIR = bin             #������ִ���ļ�����Ŀ¼

TRANSLATIONS += image/translator/qt_zh_CN.ts

RESOURCES += \
    image.qrc
win32:RC_FILE=main.rc
