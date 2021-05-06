#include "sarra.h"
#include "ui_sarra.h"
#include "livreur.h"
#include "tarif.h"
#include <QMessageBox>
#include <QTableView>
#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QSound>
#include<statistique_livreur.h>
#include<statistique_tarif.h>
sarra::sarra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sarra)
{
    ui->setupUi(this);
    int ret= ard.connect_arduino();
    switch(ret)
    {case(0):
        qDebug() << "arduino is available and cooneted to  : "<<ard.getarduino_port_name();
        break;
     case(1):
        qDebug()<< "arduino is available but not conected to : "<< ard.getarduino_port_name();
        break;
     case(-1):
        qDebug()<<"arduino is no available ";
        break;

}


QObject::connect(ard.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()) );
    /* updtae_label thoteha bech tamel mise a jour lel label eli feha heya bech trajja el valeur taa el arduino
      yani el retour taa el arduino */

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this ,SLOT(myfunction()));
    timer->start(1000);

   //livreur int
        ui->lineEditIDL->setValidator(new QIntValidator(100, 9999, this));  // des nombres entre 100 et 9999
    ui->lineEditTelL->setValidator(new QIntValidator(100, 9999, this));  // des nombres entre 100 et 9999

//livreur varchar
        ui-> lineEditNomL ->setMaxLength(20);
        ui->lineEditPrenomL->setMaxLength(20);//controle de saisie je ne peut pas depasser les 20 lettres

         //tarif int
    ui->lineEditCT->setValidator(new QIntValidator(100, 9999, this));
    ui->lineEditSMAjout->setValidator(new QIntValidator(100, 9999, this));

if (tarif::afficher_ComboBox() != nullptr)
    {std:: cout<<"null";}
    ui->comboBox_ModifTarif->setModel(tarif::afficher_ComboBox());
    if (tabT.afficher() != nullptr)
    {std:: cout<<"null";}
    ui->tableView->setModel(tabT.afficher());
    ui->tableView_2->setModel(tabL.afficherL());
    ui->comboBoxModifL->setModel(livreur::afficher_ComboBox2());
    ui->comboBoxRechL->setModel(livreur::afficher_ComboBox2());
}


sarra::~sarra()
{
    delete ui;
}
//BOUTON AJOUTER

void sarra::on_pushButtonValidTarif_clicked()
{


           /*sound*/
                  QMediaPlayer *player = new QMediaPlayer;

                  player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/bruit-pop-up.mp3"));
                  player->setVolume(100);
                  player->play();
                  ui->lineEditCT->text();

   tarif tar(ui->lineEditCT->text().toInt(),ui->dateEdit_2->text(),ui->lineEditSMAjout->text().toInt());
   bool test = tar.ajouter();
    tar.ajouter();
    if (test)
    {
          ui->tableView->setModel(tabT.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajout !"),
                             QObject::tr("Le Tarif a bien été ajouté"),
                             QMessageBox::Ok);}
    else{

    QMessageBox::critical(nullptr,QObject::tr("Erreur d'ajout"),
                            QObject::tr("Le Tarif n'a pas pu etre ajouté"),
                            QMessageBox::Cancel);}

}
void sarra::on_pushButtonValidL_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    livreur liv(ui->lineEditIDL->text().toInt(),ui->lineEditNomL->text(),ui->lineEditPrenomL->text(),ui->lineEditTelL->text().toInt());
   bool test1 = liv.ajouterL();
    liv.ajouterL();
    if (test1)
    {
          ui->tableView_2->setModel(tabL.afficherL());
          // controle de saisi
        QMessageBox::information(nullptr,QObject::tr("Ajout !"),
                             QObject::tr("Le Livreur a bien été ajouté"),
                             QMessageBox::Ok);}
    else{

    QMessageBox::critical(nullptr,QObject::tr("Erreur d'ajout"),
                            QObject::tr("Le livreur n'a pas pu etre ajouté"),
                            QMessageBox::Cancel);}
}

//BOUTON SUPPRIMER


void sarra::on_pushButtonSuppL_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    bool test=tabL.supprimerL( ui->lineEditSuppL->maxLength());
        if (test)
        {
              ui->tableView_2->setModel(tabL.afficherL());
            QMessageBox::information(nullptr,QObject::tr("Supression !"),
                                 QObject::tr("supression effectuée"),
                                 QMessageBox::Ok);}
        else{

        QMessageBox::critical(nullptr,QObject::tr("Erreur de supression"),
                                QObject::tr("supression non effectuée"),
                                QMessageBox::Cancel);}

}

void sarra::on_pushButtonSuppTarif_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    bool test=tabT.supprimer( ui->lineEditSuppTarif->maxLength());
        if (test)
        {
              ui->tableView->setModel(tabT.afficher());
            QMessageBox::information(nullptr,QObject::tr("Supression !"),
                                 QObject::tr("supression effectuée"),
                                 QMessageBox::Ok);}
        else{

        QMessageBox::critical(nullptr,QObject::tr("Erreur de supression"),
                                QObject::tr("supression non effectuée"),
                                QMessageBox::Cancel);}

}
//BOUTON MODIFIER

void sarra::on_comboBox_ModifTarif_currentIndexChanged(int index)
{
    ui->comboBox_ModifTarif->currentText();

}

void sarra::on_pushButtonModifTarif_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    bool  test = tabT.modifier(ui->comboBox_ModifTarif->currentText().toInt(), ui->lineEditNvCodeT->text(),ui->lineEditNvSommeT->text().toInt()) ;
           if (test)
           {
                 ui->tableView->setModel(tabT.afficher());
               QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("modification effectuée"),
                                    QMessageBox::Ok);}
           else{
           QMessageBox::critical(nullptr,QObject::tr("Erreur de modification"),
                                   QObject::tr("modification non effectuée"),
                                   QMessageBox::Cancel);}
}


void sarra::on_comboBoxModifL_currentIndexChanged(int index)
{
    ui->comboBoxModifL->currentText();
}

void sarra::on_pushButtonModifL_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    bool  test = tabL.modifierL(ui->pushButtonModifL->text()) ;
           if (test)
           {
                 ui->tableView_2->setModel(tabL.afficherL());
               QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("modification effectuée"),
                                    QMessageBox::Ok);}
           else{
           QMessageBox::critical(nullptr,QObject::tr("Erreur de modification"),
                                   QObject::tr("modification non effectuée"),
                                   QMessageBox::Cancel);}
}

//BOUTON RECHERCHE


void sarra::on_pushButtonRechL_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    bool test=tabL.rechercheL(ui->lineEditRechL->maxLength());
     if( test == true)
     {
         QMessageBox::information(nullptr,QObject::tr("Recherche"),
                              QObject::tr("Livreur trouvé"),
                              QMessageBox::Ok);
     }

     else
     {
         QMessageBox::information(nullptr,QObject::tr("Recherche"),
                              QObject::tr("Le Livreur n'existe pas"),
                              QMessageBox::Ok);
     }
}


void sarra::on_pushButtonRechTarif_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

bool test= tabT.recherche(ui->lineEditRechTarif->maxLength());
     if( test == true)
     {
         QMessageBox::information(nullptr,QObject::tr("Recherche"),
                              QObject::tr("Tarif trouvé"),
                              QMessageBox::Ok);
     }

     else
     {
         QMessageBox::information(nullptr,QObject::tr("Recherche"),
                              QObject::tr("Le Tarif n'existe pas"),
                              QMessageBox::Ok);
     }
}

//BOUTON TRIE ASC



void sarra::on_pushButtonAscL_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    ui->tableView_2->setModel(tabL.trierL());
}



void sarra::on_pushButtonTriAscTarif_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    ui->tableView->setModel(tabT.trier());
}


// BOUTON TRIE DESC

void sarra::on_pushButtonTriDescTarif_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    ui->tableView->setModel(tabT.trierdesc());
}

void sarra::on_pushButtonTriDescL_clicked()
{
    ui->tableView_2->setModel(tabL.trierLdesc());

    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();


}

//BOUTON STAT


void sarra::on_pushButtonStatL_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    stat_liv=new statistique_livreur(this);
    stat_liv->show();
}

void sarra::on_pushButtonStattarif_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sarra\\Downloads\\Integration\\bruit-pop-up.mp3"));
           player->setVolume(100);
           player->play();

    stat_tar=new statistique_tarif(this);
    stat_tar->show();
}

// BOUTON RECHERCHE

void sarra::on_comboBoxRechL_currentIndexChanged(int index)
{
    ui->comboBoxRechL->currentText();
}


void sarra::on_lineEditRechL_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
               QSqlQuery   *query= new QSqlQuery();
       if(ui->comboBoxRechL->currentText()=="nom")
               {
           query->prepare("SELECT * FROM livreur WHERE ID LIKE'"+arg1+"%'");//+tri
   query->exec();
       model->setQuery(*query);
   ui->tableView_2->setModel(model);


       }
       else {
           if(ui->comboBoxRechL->currentText()=="nom"){
               query->prepare("SELECT * FROM livreur WHERE nom LIKE'"+arg1+"%'");//+tri
       query->exec();
           model->setQuery(*query);
       ui->tableView_2->setModel(model);
           }
           else {
               if(ui->comboBoxRechL->currentText()=="prenom"){
               query->prepare("SELECT * FROM livreur WHERE prenom LIKE'"+arg1+"%'");//+tri
       query->exec();
           model->setQuery(*query);
       ui->tableView_2->setModel(model);
               }

           }

       }}


void sarra::on_comboBoxRechTarif_currentIndexChanged(int index)
{
    ui->comboBoxRechTarif->currentText();
}

void sarra::on_lineEditRechTarif_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
               QSqlQuery   *query= new QSqlQuery();
       if(ui->comboBoxRechTarif->currentText()=="code")
               {
           query->prepare("SELECT * FROM tarif WHERE code LIKE'"+arg1+"%'");//+tri
   query->exec();
       model->setQuery(*query);
   ui->tableView->setModel(model);

              }
       else {
           if(ui->comboBoxRechTarif->currentText()=="somme")
    {
               query->prepare("SELECT * FROM tarif WHERE somme LIKE'"+arg1+"%'");//+tri
               query->exec();
               model->setQuery(*query);
               ui->tableView->setModel(model);
        }


          }

   }

//BOUTON TIME

void sarra::myfunction()
{
   /* qDebug() << "update..";*/

    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if ((time.second() % 2)==  0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ' ;
    }
    ui->label_TimeTarif->setText(time_text);
    ui->label_TimeLivreur_->setText(time_text);
}


// BOUTON CAMERA

void sarra::on_pushButtonCamL_clicked()
{
    camera= new Widget(this);
    camera->show();
}

void sarra::on_pushButtonCamTarif_clicked()
{
    camera= new Widget(this);
    camera->show();
}

