QT += core gui sql printsupport charts svg serialport network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RESOURCES += ressource.qrc
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    consult.cpp \
    main.cpp \
    mainwindow.cpp \
    todo.cpp

HEADERS += \
    connection.h \
    consult.h \
    mainwindow.h \
    todo.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

