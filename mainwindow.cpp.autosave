#include "mainwindow.h"
#include"ui_mainwindow.h"
#include "tarif.h"
#include "gestion_des_livreur.h"
#include <QMessageBox>
#include <QTableView>
#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QSound>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)

{

   ui->setupUi(this);
    int ret= A.connect_arduino();
    switch(ret)
    {case(0):
        qDebug() << "arduino is available and cooneted to  : "<<A.getarduino_port_name();
        break;
     case(1):
        qDebug()<< "arduino is available but not conected to : "<< A.getarduino_port_name();
        break;
     case(-1):
        qDebug()<<"arduino is no available ";
        break;
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()) );
}

void MainWindow::update_label()
{
   data=A.read_from_arduino();
   if(data=="1")
       ui->label_3->setText("ON");
   else if (data=="0")
       ui->label_3->setText("OFF");
}
void MainWindow::on_pushButton_clicked()
{
    A.write_to_arduino("1");
}
void MainWindow::on_pushButton_2_clicked()
{
    A.write_to_arduino("0");
}
void MainWindow::on_pushButton_3_clicked()
{
    A.write_to_arduino("2");
}
void MainWindow::on_pushButton_4_clicked()
{
    A.write_to_arduino("3");
}





 /*   timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this ,SLOT(myfunction()));
    timer->start(1000);

    */

    //client int
/*        ui->lineEditPrenomC->setValidator(new QIntValidator(100, 9999, this));  // des nombres entre 100 et 9999

        //client varchar
        ui->lineEditNomC->setMaxLength(20);
        ui->lineEditRedu->setMaxLength(3);//controle de saisie je ne peut pas depasser les 3 lettres
        ui->lineEditPrenomC->setMaxLength(20);

         //film varchar
          ui->lineEditTitre->setMaxLength(20);
          ui->lineEditCatAjout->setMaxLength(20);
          ui->lineEditNomRea->setMaxLength(20);
          ui->lineEditDuree->setMaxLength(5);*/


/*

    if (tarif::afficher_ComboBox() != nullptr)
    {std:: cout<<"null";}
    ui->comboBox_Modiftarif->setModel(tarif::afficher_ComboBox());
    if (tabt.afficher() != nullptr)
    {std:: cout<<"null";}
    ui->tableView->setModel(tabT.afficher());
    ui->tableView_2->setModel(tabL.afficherC());
    ui->comboBoxModiflivreur->setModel(livreur::afficher_ComboBox2());*/
//}

MainWindow::~MainWindow()
{
    delete ui;
}
