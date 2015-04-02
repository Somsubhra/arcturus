QT += widgets

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/actioncollection.cpp \
    src/standardactions.cpp \
    src/actionhandlers.cpp

LIBS += -lpoppler-qt5

HEADERS += \
    src/mainwindow.h \
    src/actioncollection.h \
    src/standardactions.h \
    src/actionhandlers.h
