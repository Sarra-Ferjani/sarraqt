#include "jalel.h"
#include "ui_jalel.h"
#include "etudiant.h"
#include "livraison.h"
#include <statistique_clients.h>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QThread>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QTableView>
#include <iostream>
#include <QDebug>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QSound>
jalel::jalel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jalel)
{
    ui->setupUi(this);

    ui->tabetudiant->setModel(tmpclient.afficher());
    ui->tabliv->setModel(tmplivraison.afficher());
    player= new QMediaPlayer(this);
}

jalel::~jalel()
{
    delete ui;
}
void jalel::on_pb_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString nom= ui->le_nom->text();
    QString prenom= ui->le_prenom->text();
    int num=ui->le_num->text().toInt();
    QString email= ui->le_email->text();
    QString adresse=ui->le_adresse->text();
    QString commande=ui->le_commande->text();
 // client c(id,nom,prenom,num,email,adresse,commande)
    bool nomm,prenomm,adressee,numm,emaill,commandee;
    commandee=cl.controlSaisieCharVide(commande,"commande");
    if (commandee==true)
    {
        commandee=cl.controlsaisiechar(commande,"commande");
    }
   if(commandee==true)
   {
     nomm= cl.controlSaisieCharVide(nom,"nom");
      if (nomm==true)
           {nomm= cl.controlsaisiechar(nom,"nom");}
        if (nomm==true){
             prenomm= cl.controlSaisieCharVide(prenom,"prenom");
              if (prenomm==true)
                   {prenomm= cl.controlsaisiechar(prenom,"prenom");}
               if (prenomm==true) {
              adressee= cl.controlSaisieCharVide(adresse,"adresse");
              if(adressee==true){

               numm= cl.controlSaisieNumVide(num,"num");
               if(numm==true){
               emaill= cl.controlsaisieMail(email);

   if(emaill==true)
   {

   client c(id,nom,prenom,num,email,adresse,commande);

   bool test=c.ajouter();
  if(test)

  {
          player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/client ajouter.mp3"));
                      player->play();
                      qDebug()<<player->errorString();
                      QThread::sleep(1);
          ui->tabetudiant->setModel(tmpclient.afficher());

          QMessageBox::information(nullptr,"AJOUT CLIENT","Client Ajouté");
      }


  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
}
}
}
}
}
}


void jalel::on_pb_supprimer_clicked()
{
int id = ui->le_id->text().toInt();
bool test=tmpclient.supprimer(id);

    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/client supprimer.mp3"));
                    player->play();
                    qDebug()<<player->errorString();
                    QThread::sleep(1);
        ui->tabetudiant->setModel(tmpclient.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER CLIENT","Client Supprimé !");


    }


else
    {
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void jalel::on_modifier_clicked()
{
    int id=ui->le_id2->text().toInt();
    QString nom=ui->le_nom2->text();
    QString prenom=ui->le_prenom2->text();
    int num=ui->le_num2->text().toInt();
    QString email=ui->le_email2->text();
    QString adresse=ui->le_adresse2->text();
    QString commande=ui->le_commande2->text();




client C1(id,nom,prenom,num,email,adresse,commande);
bool test=C1.modifier();
QMessageBox msgBox;

if (test)
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/client modifier.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    ui->tabetudiant->setModel(tmpclient.afficher());

    QMessageBox::information(nullptr,"MODIFIER CLIENT","Client Modifié !");


}


else
{
QMessageBox::critical(nullptr, QObject::tr("Modifier un Client"),
            QObject::tr("Erreur !.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void jalel::on_trieID_clicked()
{

        ui->tabetudiant->setModel(tmpclient.tri_client());
        player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/tri.mp3"));
                        player->play();
                        qDebug()<<player->errorString();
                        QThread::sleep(1);

}








void jalel::on_rechercherclient_textChanged(const QString &arg1)
{
    ui->tabetudiant->setModel(tmpclient.rechercherClient(arg1));
   // ui->tabetudiant->setModel(tmpclient.afficher());

}

void jalel::on_Excel_clicked()
{

        client E;
                  QSqlQueryModel * model=new QSqlQueryModel();
                  model=E.Find_Client();
                  QString textData= "id ; nom ; prenom ; num ; email ; adresse ; commande \n";
                  int rows=model->rowCount();
                  int columns=model->columnCount();
                  for (int i = 0; i < rows; i++)
                  {
                      for (int j = 0; j < columns; j++)
                      {
                          textData += model->data(model->index(i,j)).toString();
                          textData +=" ; ";
                      }
                      textData += "\n";
                  }
                  QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
                  if (!fileName.isEmpty())
                      if (QFileInfo(fileName).suffix().isEmpty())
                          fileName.append(".csv");
                  QFile csvfile(fileName);
                  if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
                  {
                     QTextStream out (&csvfile);
                      out<<textData;
                  }
                  csvfile.close();
    }



void jalel::on_pb_ajouter_L_clicked()
{
    int prix=ui->le_prix->text().toInt();
    int id = ui->le_idL->text().toInt();
    QDate datelivraison= ui->le_dateL->date();
    QString adresselivraison= ui->le_adresseL->text();
    bool prixx,adresselivraisonn;
    adresselivraisonn=lv.controlSaisieCharVide(adresselivraison,"adresselivraison");
    if (adresselivraisonn==true)
    {
        adresselivraisonn=lv.controlsaisiechar(adresselivraison,"adresselivraison");
    }
   if(adresselivraisonn==true)
   {
     prixx=lv.controlSaisieNumVide(prix,"prix");
      if (prixx==true)
   {

  livraison l(prix,id,adresselivraison,datelivraison);
  bool test=l.ajouter();
  if (test)
     {
         player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/livraison ajouter.mp3"));
                     player->play();
                     qDebug()<<player->errorString();
                     QThread::sleep(1);
         ui->tabliv->setModel(tmplivraison.afficher());

         QMessageBox::information(nullptr,"AJOUTER LIVRAISON","Livraison Ajouté !");


     }
  else
     {
     QMessageBox::critical(nullptr, QObject::tr("Ajouter une Livraison"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
     }



}
   }
}

void jalel::on_pb_supprimer_L_clicked()
{
    int id = ui->le_idL->text().toInt();
    bool test=tmplivraison.supprimer(id);
 if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/livraison supprimer.mp3"));
                    player->play();
                    qDebug()<<player->errorString();
                    QThread::sleep(1);
        ui->tabliv->setModel(tmplivraison.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER CLIENT","Client Supprimé !");


    }
 else
    {
    QMessageBox::critical(nullptr, QObject::tr("Modifier un Client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void jalel::on_modifier_L_clicked()
{
    int id=ui->le_idL2->text().toInt();
     int prix=ui->le_prix2->text().toInt();
    QString adresselivraison=ui->le_adresseL2->text();
    QDate datelivraison=ui->le_dateL2->date();
livraison L1(prix,id,adresselivraison,datelivraison);
bool test=L1.modifier();
QMessageBox msgBox;

if(test)
       {
           player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/livraison modifier.mp3"));
                       player->play();
                       qDebug()<<player->errorString();
                       QThread::sleep(1);
           ui->tabliv->setModel(tmplivraison.afficher());

           QMessageBox::information(nullptr,"MODIFIER LIVRAISON","Livraison Modifié !");


       }
    else
       {
       QMessageBox::critical(nullptr, QObject::tr("Modifier une Livraison"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void jalel::on_trieID_L_clicked()
{

    ui->tabliv->setModel(tmplivraison.tri_liv());

    player->setMedia(QUrl::fromLocalFile("C:/Users/Sarra/Downloads/Integration/tri.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);

}

void jalel::on_rechercherliv_textChanged(const QString &arg1)
{
    ui->tabliv->setModel(tmplivraison.rechercherLiv(arg1));
}



void jalel::on_statsC_clicked()
{
    /*sound*/
         /*  QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:\\Users\\LENEVO\\Desktop\\2A13\\Projet C++\\Interface_Clients_Films\\button-8.mp3"));
           player->setVolume(100);
           player->play();*/

    stat_clients=new statistique_clients(this);
    stat_clients->show();
}

void jalel::on_Excel_L_clicked()
{
    livraison L;
              QSqlQueryModel * model=new QSqlQueryModel();
              model=L.Find_Liv();
              QString textData= "prix ; id ; datelivraison ; adresselivraison \n";
              int rows=model->rowCount();
              int columns=model->columnCount();
              for (int i = 0; i < rows; i++)
              {
                  for (int j = 0; j < columns; j++)
                  {
                      textData += model->data(model->index(i,j)).toString();
                      textData +=" ; ";
                  }
                  textData += "\n";
              }
              QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
              if (!fileName.isEmpty())
                  if (QFileInfo(fileName).suffix().isEmpty())
                      fileName.append(".csv");
              QFile csvfile(fileName);
              if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
              {
                 QTextStream out (&csvfile);
                  out<<textData;
              }
              csvfile.close();
}
