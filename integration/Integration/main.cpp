#include "mainwindow.h"
#include "connection.h"
#include "jalel.h"
#include "motez.h"
#include "sarra.h"
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   Connection c;
    bool test=c.createconnect();
    MainWindow w;
    sarra s;
      if(test)
        qDebug()<<test<<"connection ok";
      s.show();
    w.show();





    return a.exec();


}
