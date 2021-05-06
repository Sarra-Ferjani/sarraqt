#include "livreur.h"
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
livreur::livreur()
{

}

livreur::~livreur()
{

}

livreur::livreur(int id,QString n,QString p,int tel)
{
  ID_LIVREUR=id;
  NOM_LIVREUR=n;
  PRENOM_LIVREUR=p;
  TEL_LIVREUR=tel;


}

bool livreur::ajouterL()
{
    QSqlQuery q;


    q.prepare("INSERT INTO LIVREUR (ID_LIVREUR,NOM_LIVREUR,PRENOM_LIVREUR,TEL_LIVREUR) "
                  "VALUES (:ID_LIVREUR,:NOM_LIVREUR,:PRENOM_LIVREUR,:TEL_LIVREUR)");
    q.bindValue(":ID_LIVREUR",ID_LIVREUR);
    q.bindValue(":NOM_LIVREUR",NOM_LIVREUR);
    q.bindValue(":PRENOM_LIVREUR",PRENOM_LIVREUR);
    q.bindValue(":TEL_LIVREUR",TEL_LIVREUR);

    return q.exec();
}

QSqlQueryModel * livreur::afficherL()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select *from livreur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIVREUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_LIVREUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_LIVREUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_LIVREUR"));

    return model;
}

bool livreur::supprimerL(int identifiant)
{
    QSqlQuery q;
    q.prepare("Delete from livreur where ID_LIVREUR = :ID_LIVREUR");
    q.bindValue(":ID_LIVREUR",identifiant);
    return    q.exec();
}

QSqlQueryModel * livreur::afficher_ComboBox2()
{
    QSqlQueryModel * m= new QSqlQueryModel();

    m->setQuery("select * from LIVREUR");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIVREUR"));

    return m;
}

bool livreur::modifierL(QString telephone)
{
    QSqlQuery q;
    //QString idc=QString::number(telephone);
    q.prepare("UPDATE livreur SET TEL_LIVREUR= :TEL_LIVREUR where ID_LIVREUR= :ID_LIVREUR ");

    q.bindValue(":TEL_LIVREUR", telephone);

       return    q.exec();
}

bool livreur::rechercheL(int telephone)
{
    QSqlQuery q;
             QString id=QString::number(telephone);
             q.prepare("Select * from livreur where TEL_LIVREUR= :TEL_LIVREUR");//verifier avec la base
             q.bindValue(":TEL_LIVREUR", id);
             q.exec();
              QSqlQueryModel * model = new QSqlQueryModel();
            model->setQuery(q);
            if(model->rowCount() == 0){ return false;}//comparer avc les colonnes
         return  true;
}

QSqlQueryModel * livreur::trierL()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from livreur order by TEL_LIVREUR  ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIVREUR"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_LIVREUR"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_LIVREUR"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_LIVREUR"));


        return model;
}

QSqlQueryModel * livreur::trierLdesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from livreur order by TEL_LIVREUR  DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIVREUR"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_LIVREUR"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_LIVREUR"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_LIVREUR"));


        return model;
}
