QT += core gui 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
include(config.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    streamthread.cpp

HEADERS += \
    mainwindow.h \
    streamthread.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Set OpenCV paths based on the operating system
win32 {
    INCLUDEPATH += $$OPENCV_PATH
    LIBS += -LC:OPENCV_LIBS_PATH
    LIBS += -lopencv_highgui490
    LIBS += -lopencv_core490
    LIBS += -lopencv_imgcodecs490
    LIBS += -lopencv_imgproc490
    LIBS += -lopencv_features2d490
    LIBS += -lopencv_video490
    LIBS += -lopencv_videoio490
} else: unix {
    INCLUDEPATH += $$OPENCV_PATH
    LIBS += -L$$OPENCV_LIBS_PATH
    LIBS += -lopencv_highgui
    LIBS += -lopencv_core
    LIBS += -lopencv_imgcodecs
    LIBS += -lopencv_imgproc
    LIBS += -lopencv_features2d
    LIBS += -lopencv_video
    LIBS += -lopencv_videoio
}

# Uncomment and adjust the following paths if needed for specific configurations
# win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -libopencv_highgui490.dll
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -libopencv_highgui490.dlld
# else:unix: LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -llibopencv_highgui490.dll

# INCLUDEPATH += $$PWD/../../../../../opcv/opencv/release/include
# DEPENDPATH += $$PWD/../../../../../opcv/opencv/release/include
