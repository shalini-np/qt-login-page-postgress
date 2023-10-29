QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

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

# Adding postgress ref
#LIBS += -LC:/Program Files/PostgreSQL/10/lib -llibpq
# C:\Program Files\PostgreSQL\10\lib

# Add PostgreSQL library and include path
#LIBS += -LC:/Program Files/PostgreSQL/10/lib -lpq
#INCLUDEPATH += -LC:/Program Files/PostgreSQL/10/lib/include

INCLUDEPATH += $$quote(C:\Program Files\PostgreSQL\10\include)
LIBS += $$quote(C:\Program Files\PostgreSQL\10\lib\libpq.lib)
