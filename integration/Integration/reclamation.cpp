#include "reclamation.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QString>
reclamation::reclamation()
{

    id_commande=0;

    id_client=0;

    text_reclamation="";

}
reclamation::reclamation(int id_commande,int id_client,QString text_reclamation)
{

    this->id_commande=id_commande;

    this->id_client=id_client;

    this->text_reclamation=text_reclamation;

}

bool reclamation::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO reclamation (id_commande,id_client,text_reclamation) VALUES (:id_commande,:id_client,:text_reclamation)");
    query.bindValue(":id_commande",id_commande);

    query.bindValue(":id_client",id_client);

    query.bindValue(":text_reclamation",text_reclamation);

    return query.exec();
}
bool reclamation::supprimer(int id_commande )
{
    QSqlQuery query;
    query.prepare("delete from reclamation where id_commande = :id_commande") ;

    query.bindValue(":id_commande",id_commande);

    return query.exec();
}

QSqlQueryModel* reclamation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM reclamation");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_commande"));

          model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));

          model->setHeaderData(1, Qt::Horizontal, QObject::tr("text_reclamation"));

    return model;

}

bool reclamation::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE reclamation SET id_commande =:id_commande,id_client =:id_client,text_reclamation =:text_reclamation WHERE id_commande =:id_commande ");
    query.bindValue(":id_commande",id_commande);

    query.bindValue(":id_client",id_client);

    query.bindValue(":text_reclamation",text_reclamation);

    return query.exec();
}

QSqlQueryModel * reclamation::tri_reclamation()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM RECLAMATION ORDER BY id_client");
    return model;

}

QSqlQueryModel * reclamation ::rechercherReclamation(QString text_reclamation)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from reclamation where id_client like ?");
    q.addBindValue("%"+ text_reclamation +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

