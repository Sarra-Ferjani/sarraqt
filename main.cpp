#include "mainwindow.h"
#include "login.h"
#include <QMessageBox>
#include <QtDebug>
#include <QApplication>
#include "connecion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    connecion c;
    a.setStyle("fusion");

    bool test = c.ouvrirconnexion();
    if(test){
    //qDebug()<<"connexion etablie";
    QMessageBox::information(nullptr,QObject::tr("database is open"),
                             QObject::tr("connexion etablie"),
                             QMessageBox::Ok);}
    else{
    //qDebug()<<"connexion echouer";
    QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                            QObject::tr("non connecter"),
                            QMessageBox::Cancel);}
     //qDebug()<<"connexion echouer";
  //MainWindow M;
   // M.show();
    return a.exec();
}



