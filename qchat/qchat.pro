QT       += core gui
QT  +=  network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Thread1.cpp \
    chat_box.cpp \
    help_guide.cpp \
    hot_uses.cpp \
    keyboard.cpp \
    login_condition.cpp \
    main.cpp \
    mainwindow.cpp \
    personal_document.cpp \
    qq_main_menu.cpp \
    qqchat_main_window.cpp \
    security.cpp \
    setting1.cpp \
    vip_settings.cpp \
    weather.cpp

HEADERS += \
    Thread1.h \
    chat_box.h \
    help_guide.h \
    hot_uses.h \
    keyboard.h \
    login_condition.h \
    mainwindow.h \
    personal_document.h \
    qq_main_menu.h \
    qqchat_main_window.h \
    security.h \
    setting1.h \
    vip_settings.h \
    weather.h

FORMS += \
    chat_box.ui \
    help_guide.ui \
    hot_uses.ui \
    keyboard.ui \
    login_condition.ui \
    mainwindow.ui \
    personal_document.ui \
    qq_main_menu.ui \
    qqchat_main_window.ui \
    security.ui \
    setting1.ui \
    vip_settings.ui \
    weather.ui

TRANSLATIONS += \
    qchat_zh_CN.ts



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
