#-------------------------------------------------
#
# Project created by QtCreator 2018-03-05T11:19:04
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = poplproject
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14 -no-openssl

QMAKE_CXXFLAGS += --std=c++0x


SOURCES += main.cpp\
    src/enemy.cpp \
    src/myrect.cpp \
    src/Bullet.cpp \
    src/Button.cpp \
    src/Game.cpp \
    src/Score.cpp \
    src/Score2.cpp

HEADERS  += \
    include/Bullet.h \
    include/enemy.h \
    include/myrect.h \
    include/Button.h \
    include/Game.h \
    include/Score.h \
    include/Score2.h

FORMS    +=

INCLUDEPATH += $$PWD/include

RESOURCES += \
    resources.qrc

