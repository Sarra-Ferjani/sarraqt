#include "livreur.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

livreur::livreur()
{

}
livreur::livreur(int id,QString prenom,QString nom,QString tel)
{
  this->id=id;
  this->prenom=prenom;
  this->nom=nom;
    this->tel=tel;
   



}
int livreur::get_id(){return  id;}
QString livreur::get_nom(){return nom;}
QString livreur::get_prenom(){return prenom;}
QString livreur::get_tel(){return tel;}

void livreur::set_identifiant(int identifiant){id=identifiant;}
void livreur::chercher(){
    QSqlQuery query;
    query.prepare("SELECT nom,prenom,tel FROM livreur WHERE id=:id");
    query.bindValue(":id",id);
    query.exec();
    while(query.next())
    {
        nom=query.value(1).toString();
        prenom=query.value(2).toString();
        tel=query.value(3).toString();
        
}
}
bool livreur::ajouter(int id,QString prenom,QString nom,QString tel)
{
QSqlQuery query;
query.prepare("INSERT INTO livreur (ID, NOM, PRENOM,TEL) "
                    "VALUES (:id,:nom,:prenom,:tel)");
query.bindValue(":id",id);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":tel",tel);

return    query.exec();
}

QSqlQueryModel * livreur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * "
                "from livreur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));

return model;
}

bool livreur::supprimer(int id)
{
QSqlQuery query;

query.prepare("Delete from livreur where ID=:id ");
query.bindValue(":id", id);
return    query.exec();
}

 QSqlQueryModel * livreur::  afficher_liste()
 {
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id from livreur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    return  model;
 }

bool livreur::modifier(int id,QString prenom,QString nom,QString tel)
{QSqlQuery edit;
    edit.prepare("Update livreur set nom=:nom,prenom=:prenom,tel=:tel where ID =:id");
    edit.bindValue(":id",id);
    edit.bindValue(":nom",nom);
    edit.bindValue(":prenom",prenom);
    edit.bindValue(":tel",tel);


    return       edit.exec()  ;
}
QSqlQueryModel * livreur::afficher2(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';
    query.prepare("SELECT * from livreur where nom like :nom or prenom like :nom or  tel like :nom order by id");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("tel"));
  
    return model;
}
QSqlQueryModel * livreur:: recherche_livreur(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;


    query.prepare("SELECT * FROM livreur WHERE NOM LIKE :valeur order by NOM");


    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
  
    return model;

}
QSqlQueryModel * livreur :: recherche_livreurtd(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
  query.prepare("SELECT * FROM livreur WHERE NOM LIKE :valeur order by NOM desc");
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
  
    return model;

}
QSqlQueryModel * livreur::recherche_e(int valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM livreur WHERE id== LIKE :valeur order by nom ");
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
   
    return model;
}
QSqlQueryModel * livreur::tri(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
        if(index == 0)
        {
            model->setQuery("select *FROM livreur ORDER BY ref ASC");
        }
        else
        {
            model->setQuery("select *FROM  livreur ORDER BY ref DESC ");
        }


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
        
        return model;
}











