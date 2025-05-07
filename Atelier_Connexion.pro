QT += core gui widgets sql
QT += network
QT += sql charts


CONFIG += c++11

TARGET = Atelier_Connexion
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    Reclamation.cpp \
    stmpclient.cpp

HEADERS += \
    mainwindow.h \
    connection.h \
    Reclamation.h \
    stmpclient.h

FORMS += \
    mainwindow.ui
