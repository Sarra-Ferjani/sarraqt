QT       += core gui
QT       += core gui printsupport
QT       += core gui sql charts multimedia multimediawidgets printsupport charts serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commande.cpp \
    connection.cpp \
    etudiant.cpp \
    jalel.cpp \
    livraison.cpp \
    main.cpp \
    mainwindow.cpp \
    motez.cpp \
    reclamation.cpp \
    statistique_clients.cpp \
    arduino.cpp \
    widget.cpp \
    livreur.cpp \
    statistique_livreur.cpp \
    statistique_tarif.cpp \
    tarif.cpp \
    sarra.cpp \
    login.cpp

HEADERS += \
    commande.h \
    connection.h \
    etudiant.h \
    jalel.h \
    livraison.h \
    mainwindow.h \
    motez.h \
    reclamation.h \
    statistique_clients.h \
    arduino.h \
    widget.h \
    livreur.h \
    statistique_livreur.h \
    statistique_tarif.h \
    tarif.h \
    sarra.h \
    login.h

FORMS += \
    jalel.ui \
    mainwindow.ui \
    motez.ui \
    statistique_clients.ui \
    widget.ui \
    statistique_livreur.ui \
    statistique_tarif.ui \
    sarra.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
