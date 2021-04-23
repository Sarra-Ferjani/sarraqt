#include "tarif.h"
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
tarif::tarif()
{

}

tarif::~tarif()
{

}

tarif::tarif(int code,int date , int somme )
{
     CODE_TARIF = code;
     DATE_TARIF = date;
     SOMME_TARIF = somme ;


}

bool tarif::ajoutertarif()
{
    QSqlQuery q;


    q.prepare("INSERT INTO TARIF (CODE_TARIF,DATE_TARIF,SOMME_TARIF) "
                  "VALUES (:CODE_TARIF,:DATE_TARIF,:SOMME_TARIF)");
    q.bindValue(":CODE_TARIF",CODE_TARIF);
    q.bindValue(":DATE_TARIF",DATE_TARIF);
    q.bindValue(":SOMME_TARIF",SOMME_TARIF);

    return q.exec();
}

QSqlQueryModel * tarif::affichertarif()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select *from TARIF");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_TARIF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_TARIF"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME_TARIF"));
    return model;
}

bool tarif::supprimertarif(int CODE)
{
    QSqlQuery q;
    q.prepare("Delete from TARIF where CODE_TARIF = :CODE_TARIF");
    q.bindValue(":CODE_TARIF",CODE);
    return    q.exec();
}

QSqlQueryModel * tarif::afficher_ComboBox()
{
    QSqlQueryModel * C= new QSqlQueryModel();

    C->setQuery("select * from TARIF");
    C->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_TARIF"));

    return C;
}

bool tarif::modifiertarif(int SOMME)
{
    QSqlQuery q;
    q.prepare("UPDATE TARIF SET SOMME= :SOMME_TARIF where CODE_TARIF= :CODE_TARIF ");

    q.bindValue(":SOMME_TARIF", SOMME);

       return    q.exec();
}

/*
bool tarif::rechercheT(int DATE_TARIF)
{
    QSqlQuery q;
             QString idc=QString::number(DATE_TARIF);
             q.prepare("Select * from TARIF where DATE_TARIF= :DATE_TARIF");//verifier avec la base
             q.bindValue(":DATE_TARIF", idc);
             q.exec();
              QSqlQueryModel * model = new QSqlQueryModel();
            model->setQuery(q);
            if(model->rowCount() == 0){ return false;}//comparer avc les colonnes
         return  true;
}

QSqlQueryModel * tarif::trierT()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from TARIF order by SOMME_TARIF  ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_TARIF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_TARIF"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME_TARIF"));
        return model;
}

QSqlQueryModel * tarif::trierCdesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from TARIF order by SOMME_TARIF  DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_TARIF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_TARIF"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME_TARIF"));

        return model;
}

*/








