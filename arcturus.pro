QT += widgets

LIBS += -lpoppler-qt5

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/actioncollection.cpp \
    src/standardactions.cpp \
    src/actionhandlers.cpp \
    src/documentloader.cpp \
    src/viewport.cpp

HEADERS += \
    src/mainwindow.h \
    src/actioncollection.h \
    src/standardactions.h \
    src/actionhandlers.h \
    src/documentloader.h \
    src/viewport.h
