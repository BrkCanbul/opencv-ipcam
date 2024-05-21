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





#INCLUDEPATH += C:\opcv\opencv\release\install\include

#LIBS += C:\opcv\opencv\release\bin\libopencv_highgui490.dll
#LIBS += C:\opcv\opencv\release\bin\libopencv_core490.dll
#LIBS += C:\opcv\opencv\release\bin\libopencv_highgui490.dll
#LIBS += C:\opcv\opencv\release\bin\libopencv_imgcodecs490.dll
#LIBS += C:\opcv\opencv\release\bin\libopencv_imgproc490.dll
#LIBS += C:\opcv\opencv\release\bin\libopencv_features2d490.dll
#LIBS += C:\opcv\opencv\release\bin\libopencv_video490.dll
#LIBS += C:\opcv\opencv\release\bin\libopencv_videoio490.dll


INCLUDEPATH += $$OPENCV_PATH
LIBS += -L$$OPENCV_LIBS_PATH
LIBS += -lopencv_highgui
LIBS += -lopencv_core
LIBS += -lopencv_highgui
LIBS += -lopencv_imgcodecs
LIBS += -lopencv_imgproc
LIBS += -lopencv_features2d
LIBS += -lopencv_video
LIBS += -lopencv_videoio


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -llibopencv_highgui490.dll
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -llibopencv_highgui490.dlld
#else:unix: LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -llibopencv_highgui490.dll

#INCLUDEPATH += $$PWD/../../../../../opcv/opencv/release/include
#DEPENDPATH += $$PWD/../../../../../opcv/opencv/release/include
