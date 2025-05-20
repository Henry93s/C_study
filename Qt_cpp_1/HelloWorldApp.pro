QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    #class_1_helloQT.cpp \
    #class_2_widget_size.cpp \
    #class_3_pushbutton.cpp \
    #class_4_QObject_connect.cpp \
    #class_5_Qlabel_and_Qpushbutton.cpp \
    #class_6_userDefinedWidget.cpp \
    #class_7_QLCDNumberWidget.cpp \
    #class_8_QProgressBarWidget.cpp \
    #class_9_QTextBrowserWidget.cpp \
    #class_10_QPushButtonWidget.cpp \
    #class_11_QRadioButtonWidget.cpp \
    #class_12_QCheckBoxWidget.cpp \
    #class_13_QSliderWidget.cpp \
    #class_14_QScrollBarWidget.cpp \
    #class_15_QDialWidget.cpp \
    #class_16_QSpinBoxWidget.cpp \
    #class_17_QTimeEditAndQdateEdit.cpp \
    #class_18_QLineEditWidget.cpp \
    #class_19_QComboBoxWidget.cpp \
    class_20_QValidatorClass.cpp \
    widget.cpp

HEADERS += \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
