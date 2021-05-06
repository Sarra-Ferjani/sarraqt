#include "commande.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QString>
commande::commande()
{
    idCommande=0;
    idLivreur=0;
    idClient=0;
    idStock=0;
    adresseLivraison="";

}
commande::commande(int idCommande,int idLivreur,int idClient,int idStock,QString adresseLivraison)
{

    this->idCommande=idCommande;
    this->idLivreur=idLivreur;
    this->idClient=idClient;
    this->idStock=idStock;
    this->adresseLivraison=adresseLivraison;

}

bool commande::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO commande (idCommande,idLivreur,idClient,idStock,adresseLivraison) VALUES (:idCommande,:idLivreur,:idClient,:idStock,:adresseLivraison)");
    query.bindValue(":idCommande",idCommande);
    query.bindValue(":idLivreur",idLivreur);
    query.bindValue(":idClient",idClient);
    query.bindValue(":idStock",idStock);
    query.bindValue(":adresseLivraison",adresseLivraison);

    return query.exec();
}
bool commande::supprimer(int idCommande )
{
    QSqlQuery query;
    query.prepare("delete from commande where idCommande = :idCommande") ;

    query.bindValue(":idCommande",idCommande);

    return query.exec();
}

QSqlQueryModel* commande::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM commande");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("idCommande"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("idLivreur"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("idClient"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("idStock"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresseLivraison"));

    return model;

}

bool commande::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE commande SET idCommande =:idCommande,idLivreur =:idLivreur,idClient =:idClient,idStock =:idStock,adresseLivraison =:adresseLivraison WHERE idCommande =:idCommande ");
    query.bindValue(":idCommande",idCommande);
    query.bindValue(":idLivreur",idLivreur);
    query.bindValue(":idClient",idClient);
    query.bindValue(":idStock",idStock);
    query.bindValue(":adresseLivraison",adresseLivraison);

    return query.exec();
}

QSqlQueryModel * commande ::rechercherCommande(QString adresseLivraison)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from commande where adresseLivraison like ?");
    q.addBindValue("%"+ adresseLivraison +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

QSqlQueryModel * commande::Find_commande()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT idcommande,idlivreur,idclient,idstock,adresselivraison FROM commande");

    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel * commande::tri_commande()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM commande ORDER BY idcommande");
    return model;

}
