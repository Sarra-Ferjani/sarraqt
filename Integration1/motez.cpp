#include "motez.h"
#include "ui_motez.h"
#include "commande.h"
#include "reclamation.h"
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
motez::motez(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::motez)
{
    ui->setupUi(this);
}

motez::~motez()
{
    delete ui;
}
void motez::on_ajouter_commande_clicked()
{

    int idCommande=ui->lineEdit_idCommande->text().toInt();
    int idLivreur=ui->lineEdit_idLivreur->text().toInt();
    int idClient=ui->lineEdit_idClient->text().toInt();
    int idStock=ui->lineEdit_idStock->text().toInt();
    QString adresseLivraison=ui->lineEdit_adresseLivraison->text();

  commande C1(idCommande,idLivreur,idClient,idStock,adresseLivraison);
  bool test=C1.ajouter();
  QMessageBox msgBox;

  if(test)
     { msgBox.setText("Ajout avec succes.");

       ui->afficher_commande->setModel(tmpcommande.afficher());
       update();
  }
  else
      msgBox.setText("Echec d'ajout");
  msgBox.exec();

}

void motez::on_supprimer_clicked()
{
    bool test=tmpcommande.supprimer(id_commande);
        if(test){
             ui->afficher_commande->setModel(tmpcommande.afficher());
             update();
            QMessageBox::information(nullptr,"suppression commande","commande supprimer avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","commande non supprimeé");

}


void motez::on_afficher_commande_activated(const QModelIndex &index)
{
    QString val=ui->afficher_commande->model()->data(index).toString();
             QSqlQuery qry;
             qry.prepare("select * from commande where"
                         " idCommande='"+val+"' or idLivreur='"+val+"' or idClient='"+val+"'or idStock='"+val+"' or adresseLivraison='"+val+"' ");
             if(qry.exec())
               {while (qry.next())
              { ui->lineEdit_idCommande_2->setText(qry.value(0).toString());
                ui->lineEdit_idLivreur_2->setText(qry.value(1).toString());
                ui->lineEdit_idClient_2->setText(qry.value(2).toString());
                ui->lineEdit_idStock_2->setText(qry.value(3).toString());
                ui->lineEdit_adresseLivraison_2->setText(qry.value(4).toString());


                 }
}
}

void motez::on_afficher_commande_clicked(const QModelIndex &index)
{
    id_commande=ui->afficher_commande->model()->data(index).toInt();
}

void motez::on_modifier_clicked()
{
           int idCommande=ui->lineEdit_idCommande_2->text().toInt();
           int idLivreur=ui->lineEdit_idLivreur_2->text().toInt();
           int idClient=ui->lineEdit_idClient_2->text().toInt();
           int idStock=ui->lineEdit_idStock_2->text().toInt();
          QString adresseLivraison=ui->lineEdit_adresseLivraison_2->text();

      commande C1(idCommande,idLivreur,idClient,idStock,adresseLivraison);
      bool test=C1.modifier();
      QMessageBox msgBox;

      if(test)
         { msgBox.setText(" Modification avec succes.");

           ui->afficher_commande->setModel(tmpcommande.afficher());
      }
      else
          msgBox.setText("Echec de modifier");
      msgBox.exec();
}



void motez::on_rechercher_idCommande_textChanged(const QString &arg1)
{
    ui->afficher_commande->setModel(tmpcommande.rechercherCommande(arg1));
}



void motez::update()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT adresselivraison FROM commande");
            querry->exec();
            m->setQuery(*querry);


           // ui->comboBox->setModel(m);

}


void motez::on_ajouter_reclamation_clicked()
{
    int id_commande=ui->lineEdit_idcom->text().toInt();

    int id_client=ui->lineEdit_idcli->text().toInt();

    QString text_reclamation=ui->lineEdit_textreclamation->text();

  reclamation R1(id_commande,id_client,text_reclamation);
  bool test=R1.ajouter();
  QMessageBox msgBox;

  if(test)
     { msgBox.setText("Ajout avec succes.");

       ui->afficher_reclamation->setModel(tmpreclamation.afficher());
       update();
  }
  else
      msgBox.setText("Echec d'ajout");
  msgBox.exec();
}


void motez::on_modifier_reclamation_clicked()
{

    int id_commande=ui->lineEdit_idcom_2->text().toInt();

    int id_client=ui->lineEdit_idcli_2->text().toInt();

   QString text_reclamation=ui->lineEdit_reclamation_2->text();

reclamation R1(id_commande,id_client,text_reclamation);
bool test=R1.modifier();
QMessageBox msgBox;

if(test)
  { msgBox.setText(" Modification avec succes.");

    ui->afficher_reclamation->setModel(tmpreclamation.afficher());
}
else
   msgBox.setText("Echec de modifier");
msgBox.exec();

}

void motez::on_supprimer_reclamation_clicked()
{

    bool test=tmpreclamation.supprimer(id_reclamation);
        if(test){
             ui->afficher_reclamation->setModel(tmpreclamation.afficher());
             update();
            QMessageBox::information(nullptr,"suppression reclamation","reclamation supprimer avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","reclamation non supprimeé");

}

void motez::on_afficher_reclamation_activated(const QModelIndex &index)
{

    QString val=ui->afficher_reclamation->model()->data(index).toString();
             QSqlQuery qry;
             qry.prepare("select * from reclamation where"
                         " id_commande='"+val+"' or id_client='"+val+"'or text_reclamation='"+val+"' ");
             if(qry.exec())
               {while (qry.next())
              { ui->lineEdit_idcom_2->setText(qry.value(0).toString());
                ui->lineEdit_idcli_2->setText(qry.value(1).toString());
                ui->lineEdit_reclamation_2->setText(qry.value(2).toString());



                 }
             }
}

void motez::on_afficher_reclamation_clicked(const QModelIndex &index)
{

      id_reclamation=ui->afficher_reclamation->model()->data(index).toInt();
}

void motez::on_Excel_clicked()
{
    commande E;
              QSqlQueryModel * model=new QSqlQueryModel();
              model=E.Find_commande();
              QString textData= "idcommande ; idlivreur ; idclient ; idstock ; adresselivraison \n";
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
                  QTextStream out(&csvfile);
                  out<<textData;
              }
              csvfile.close();
}

void motez::on_triNom_clicked()
{
    ui->afficher_commande->setModel(tmpcommande.tri_commande());
}


void motez::on_triClient_clicked()
{
    ui->afficher_reclamation->setModel(tmpreclamation.tri_reclamation());
}

void motez::on_recherche_reclamation_textChanged(const QString &arg1)
{
    ui->afficher_reclamation->setModel(tmpreclamation.rechercherReclamation(arg1));

}

void motez::on_pushButton_print_clicked()
{
    QStringList list;
        QAbstractItemModel *model = ui->afficher_reclamation->model();
        QModelIndex index0 = model->index(0,0);
        QModelIndex index1 = model->index(0,1);
        QModelIndex index2 = model->index(0,2);





        QPlainTextEdit text;

            QTextDocument *doc = text.document();
            QFont font = doc->defaultFont();

            font.setBold(true);
            font.setFamily("Arial");
            font.setPixelSize(20);
            doc->setDefaultFont(font);
            text.appendPlainText("                            Fiche de reclamation                         ");
            text.appendPlainText("");
            text.appendPlainText("");
            font.setPixelSize(14);
            text.appendPlainText("");
            text.appendPlainText("");
            text.appendPlainText("ID commande: "+index0.data().toString()+"");
            text.appendPlainText("ID client: "+index1.data().toString()+"");
            text.appendPlainText("Reclamation: "+index2.data().toString()+"");


            text.appendPlainText("");
            text.appendPlainText("");
            text.appendPlainText("");
            text.appendPlainText("                                                signature de directeur");

            QPrinter printer;
                printer.setPrinterName("Print");

                QPrintDialog dlg(&printer,this);
                if (dlg.exec() == QDialog::Rejected)
                {
                    return;
                }
                text.print(&printer);
}
