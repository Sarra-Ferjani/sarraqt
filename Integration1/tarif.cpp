#include "tarif.h"
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

tarif::tarif()
{

}

tarif::tarif(int c,QString d,int s)
{
   CODE_TARIF= c;
   DATE_TARIF=d;
   SOMME_TARIF=s;

}

tarif::~tarif()
{

}

bool tarif::ajouter() // conrole de saisie sur l'ajout et sur le type(date etc)
{
    QSqlQuery q;


    q.prepare("INSERT INTO TARIF(CODE_TARIF,DATE_TARIF,SOMME_TARIF) "
                  "VALUES (:CODE_TARIF,:DATE_TARIF,:SOMME_TARIF)");
    q.bindValue(":CODE_TARIF",CODE_TARIF);
    q.bindValue(":DATE_TARIF",DATE_TARIF);
    q.bindValue(":SOMME_TARIF",SOMME_TARIF);


    return q.exec();
}

QSqlQueryModel * tarif:: afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from tarif");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_TARIF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_TARIF"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME_TARIF"));


    return model;

}

QSqlQueryModel * tarif::afficher_ComboBox()
{
    QSqlQueryModel * m= new QSqlQueryModel();

    m->setQuery("select * from TARIF");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_TARIF"));

    return m;
}

bool tarif::supprimer(int CODE_TARIF)
{

    QSqlQuery q;
    q.prepare("Delete from tarif where CODE_TARIF = :CODE_TARIF ");
    q.bindValue(":CODE_TARIF",CODE_TARIF);
    return    q.exec();
}

bool tarif::modifier(int CODE_TARIF, QString DATE_TARIF, int SOMME_TARIF)
{

    QSqlQuery q;

    q.prepare("UPDATE tarif SET DATE_TARIF= :DATE_TARIF, SOMME_TARIF= :SOMME_TARIF where CODE_TARIF= :CODE_TARIF ");
    q.bindValue(":CODE_TARIF", CODE_TARIF);
    q.bindValue(":DATE_TARIF", DATE_TARIF);
    q.bindValue(":SOMME_TARIF",SOMME_TARIF);
       return    q.exec();

}

bool tarif::recherche(int CODE_TARIF)
{
    QSqlQuery q;
             q.prepare("Select * from tarif where CODE_TARIF= :CODE_TARIF");//verifier avec la base
             q.bindValue(":CODE_TARIF", CODE_TARIF);
             q.exec();
              QSqlQueryModel * model = new QSqlQueryModel();
            model->setQuery(q);
            if(model->rowCount() == 0){ return false;}//comparer avc les colonnes
         return  true;
}

QSqlQueryModel * tarif::trier()
{

   QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from tarif order by titre  ASC");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_TARIF"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_TARIF"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME_TARIF"));

       return model;
}


QSqlQueryModel * tarif::trierdesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from tarif order by titre  DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_TARIF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_TARIF"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME_TARIF"));

        return model;
}

