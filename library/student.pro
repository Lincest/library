#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T09:56:56
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = student
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    student.cpp \
    admin.cpp \
    admin_change.cpp \
    dele.cpp \
    student_change.cpp

HEADERS += \
        mainwindow.h \
    student.h \
    admin.h \
    admin_change.h \
    dele.h \
    student_change.h

FORMS += \
        mainwindow.ui \
    student.ui \
    admin.ui \
    admin_change.ui \
    dele.ui \
    student_change.ui

RESOURCES += \
    C:/Users/47461/Pictures/rocco.qrc
