

#include "livraison.h"
#include <QMessageBox>
#include <QDebug>
livraison::livraison()
{
id=0;
prix=0;
adresselivraison="";
}
livraison::livraison(int prix, int id, QString adresselivraison, QDate datelivraison)
{
  this->id=id;
  this->prix=prix;
  this->adresselivraison=adresselivraison;
  this->datelivraison=datelivraison;

}
QString livraison::get_adresselivraison(){return  adresselivraison;}
QDate livraison::get_datelivraison(){return datelivraison;}
int livraison::get_id(){return  id;}
int livraison::get_prix(){return prix;}


bool livraison::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
//QString ress= QString::number(prix);

query.prepare("INSERT INTO livraisons (prix, id, datelivraison,adresselivraison) "
                    "VALUES (:prix, :id, :datelivraison, :adresselivraison)");
query.bindValue(":prix", prix);
query.bindValue(":id", res);
query.bindValue(":datelivraison", datelivraison);
query.bindValue(":adresselivraison", adresselivraison);

return    query.exec();
}

QSqlQueryModel * livraison::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from livraisons");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse Livraison"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Livraison"));


    return model;
}

bool livraison::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from livraisons where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool livraison::modifier()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE livraisons SET prix =:prix,id =:id,datelivraison =:datelivraison,adresselivraison =:adresselivraison WHERE id =:id ");
    query.bindValue(":prix",prix);
    query.bindValue(":id",res);
    query.bindValue(":datelivraison",datelivraison);
    query.bindValue(":adresselivraison",adresselivraison);


    return query.exec();
}

QSqlQueryModel * livraison::tri_liv()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM livraisons ORDER BY id");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Livraison"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse Livraison"));

    return model;

}

QSqlQueryModel * livraison::rechercherLiv(QString adresselivraison)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from livraisons where adresselivraison like ?");
    q.addBindValue("%"+ adresselivraison +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

QSqlQueryModel * livraison::Find_Liv()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT prix,id,datelivraison,adresselivraison FROM livraisons");

    query.exec();
    model->setQuery(query);
    return model;
}


bool livraison::controlsaisiechar(QString saisi,QString type){
    if(saisi.contains(QRegExp("^[A-Za-z ]+$")))
    {
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ID"),
                    QObject::tr("Le %1 contient un Caractére non valid.\n"
                                "Click Cancel to exit.").arg(type), QMessageBox::Cancel);
        return false;
    }


}
bool livraison::controlSaisieNumVide(int prix,QString prixx)
{

       if(std::to_string(prix).length()>=2)
               {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Prix"),
                    QObject::tr("Le %1 doit avoir au moins 2  Chiffre .\n"
                                "Click Cancel to exit.").arg(prixx), QMessageBox::Cancel);
        return false;
    }

}

bool livraison::controlSaisieCharVide(QString adresselivraison,QString adresselivraisonn)
{

 if(adresselivraison.length()!=0)
 {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ID"),
                    QObject::tr("Le champs de %1 est vide.\n"
                                "Click Cancel to exit.").arg(adresselivraisonn), QMessageBox::Cancel);
        return false;
    }

}

