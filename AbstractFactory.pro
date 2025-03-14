QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        classunit.cpp \
        cppcodefactory.cpp \
        csharpcodefactory.cpp \
        javacodefactory.cpp \
        main.cpp \
        methodunit.cpp \
        printoperatorunit.cpp \
        unit.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AbstractCodeFactory.h \
    classunit.h \
    cppcodefactory.h \
    csharpcodefactory.h \
    javacodefactory.h \
    methodunit.h \
    printoperatorunit.h \
    unit.h
