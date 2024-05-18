QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



INCLUDEPATH += C:\opcv\opencv\release\install\include

LIBS += C:\opcv\opencv\release\bin\libopencv_highgui490.dll
LIBS += C:\opcv\opencv\release\bin\libopencv_core490.dll
LIBS += C:\opcv\opencv\release\bin\libopencv_highgui490.dll
LIBS += C:\opcv\opencv\release\bin\libopencv_imgcodecs490.dll
LIBS += C:\opcv\opencv\release\bin\libopencv_imgproc490.dll
LIBS += C:\opcv\opencv\release\bin\libopencv_features2d490.dll
LIBS += C:\opcv\opencv\release\bin\libopencv_video490.dll
LIBS += C:\opcv\opencv\release\bin\libopencv_videoio490.dll





#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -llibopencv_highgui490.dll
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -llibopencv_highgui490.dlld
#else:unix: LIBS += -L$$PWD/../../../../../opcv/opencv/release/lib/ -llibopencv_highgui490.dll

#INCLUDEPATH += $$PWD/../../../../../opcv/opencv/release/include
#DEPENDPATH += $$PWD/../../../../../opcv/opencv/release/include
