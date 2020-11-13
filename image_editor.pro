#========================================================================================

TARGET = ImageEditor

#========================================================================================

QT += widgets
QT += gui

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

#========================================================================================

# For Linux:

unix {
    CONFIG += link_pkgconfig

    PKGCONFIG += opencv4

    INCLUDEPATH += $$OPENCV_DIR/include/opencv4

    LIBS += -L$$OPENCV_DIR/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui \
                               -lopencv_features2d -lopencv_imgproc -lopencv_calib3d
}

#========================================================================================

# For Windows:

win32 {
    INCLUDEPATH += D:\opencv\build\include

    LIBS += D:\opencv-build\bin\libopencv_core320.dll
    LIBS += D:\opencv-build\bin\libopencv_highgui320.dll
    LIBS += D:\opencv-build\bin\libopencv_imgcodecs320.dll
    LIBS += D:\opencv-build\bin\libopencv_imgproc320.dll
    LIBS += D:\opencv-build\bin\libopencv_features2d320.dll
    LIBS += D:\opencv-build\bin\libopencv_calib3d320.dll

# more correct variant, how set includepath and libs for mingw
# add system variable: OPENCV_SDK_DIR=D:/opencv/opencv-build/install
# read http://doc.qt.io/qt-5/qmake-variable-reference.html#libs

#INCLUDEPATH += $$(OPENCV_SDK_DIR)/include

#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
#        -lopencv_core320        \
#        -lopencv_highgui320     \
#        -lopencv_imgcodecs320   \
#        -lopencv_imgproc320     \
#        -lopencv_features2d320  \
#        -lopencv_calib3d320
}

#========================================================================================

MAIN_DIR = $$PWD

include( $$PWD/src/src.pri )

#========================================================================================

INCLUDEPATH += $$PWD

RESOURCES += images/images.qrc

#========================================================================================
