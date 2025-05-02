QT       += core gui sql
QT += core gui widgets printsupport
QT += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rf
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    employe.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    modelphotoemploye.cpp

HEADERS += \
    arduino.h \
    connection.h \
    employe.h \
    mainwindow.h \
    modelphotoemploye.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    ressource.qrc

DISTFILES += \
    img/logo.png \
    style.qss

# Default rules for deployment.
/qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# === OpenCV Integration ===
# Chemin d'inclusion pour les fichiers header OpenCV
#INCLUDEPATH += C:/opencv/include
#LIBS += -LC:/opencv/x64/mingw/bin \
 #       -lopencv_core455 \
  #      -lopencv_highgui455 \
   #     -lopencv_imgproc455 \
    #    -lopencv_videoio455 \
     #   -lopencv_objdetect455 \
      #  -lopencv_calib3d455 \
       # -lopencv_imgcodecs455 \
        #-lopencv_face455




