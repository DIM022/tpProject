QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buscar_libros.cpp \
    buscar_socios.cpp \
    cargar_libros.cpp \
    cargar_socios.cpp \
    funcionesLibro.cpp \
    funcionesMain.cpp \
    funcionesPrestamo.cpp \
    gestionVectorLibro.cpp \
    gestionVectorSocio.cpp \
    lectura.cpp \
    libro.cpp \
    main.cpp \
    mainwindow.cpp \
    prestamoFormato.cpp \
    socio.cpp

HEADERS += \
    buscar_libros.h \
    buscar_socios.h \
    cargar_libros.h \
    cargar_socios.h \
    funcionesLibro.h \
    funcionesMain.h \
    funcionesPrestamo.h \
    gestionVectorLibro.h \
    gestionVectorSocio.h \
    lectura.h \
    libroH.h \
    mainwindow.h \
    prestamoFormato.h \
    socioH.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
