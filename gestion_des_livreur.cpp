
#include "gestion_des_livreur.h"
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
gestion_des_livreur::gestion_des_livreur()
{

}

gestion_des_livreur::~gestion_des_livreur()
{

}

gestion_des_livreur::gestion_des_livreur(int idl,QString n,QString p,int tel)
{
    ID_LIVREUR = idl;
    NOM_LIVREUR = n;
    PRENOM_LIVREUR = p ;
    TEL_LIVREUR =tel;

}

bool gestion_des_livreur::ajouterLIVREUR()
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

QSqlQueryModel * gestion_des_livreur::afficherLIVREUR()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select *from LIVREUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIVREUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_LIVREUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_LIVREUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_LIVREUR"));

    return model;
}

bool gestion_des_livreur::supprimerLIVREUR(int ID_LIVREUR)
{
    QSqlQuery q;
    q.prepare("Delete from LIVREUR where ID_LIVREUR = :ID_LIVREUR");
    q.bindValue(":ID_LIVREUR",ID_LIVREUR);
    return    q.exec();
}

QSqlQueryModel * gestion_des_livreur::afficher_ComboBox2()
{
    QSqlQueryModel * m= new QSqlQueryModel();

    m->setQuery("select * from LIVREUR");
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIVREUR"));

    return m;
}

bool gestion_des_livreur::modifierLIVREUR(QString NOM_LIVREUR)
{
    QSqlQuery q;
    //QString idc=QString::number(NOM_LIVREUR);
    q.prepare("UPDATE LIVREUR SET NOM_LIVREUR= :NOM_LIVREUR where ID_LIVREUR= :ID_LIVREUR ");

    q.bindValue(":NOM_LIVREUR", NOM_LIVREUR);

       return    q.exec();
}
/*
bool gestion_des_livreur::rechercheLIVREUR(int carte)
{
    QSqlQuery q;
             QString idc=QString::number(carte);
             q.prepare("Select * from client where carte_fidelite= :carte_fidelite");//verifier avec la base
             q.bindValue(":carte_fidelite", idc);
             q.exec();
              QSqlQueryModel * model = new QSqlQueryModel();
            model->setQuery(q);
            if(model->rowCount() == 0){ return false;}//comparer avc les colonnes
         return  true;
}

QSqlQueryModel * Clients::trierC()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from client order by carte_fidelite  ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_de_naisssance"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("carte_fidelite"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("reduction"));

        return model;
}

QSqlQueryModel * Clients::trierCdesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from client order by carte_fidelite  DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_de_naisssance"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("carte_fidelite"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("reduction"));

        return model;
}



*/


