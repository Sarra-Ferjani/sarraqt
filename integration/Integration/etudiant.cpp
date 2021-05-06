#include "etudiant.h"
#include <QDebug>
#include <QMessageBox>
client::client()
{
id=0;
nom="";
prenom="";
}
client::client(int id, QString nom, QString prenom, int num, QString email, QString adresse,QString commande)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->num=num;
  this->email=email;
  this->adresse=adresse;
  this->commande=commande;
}
QString client::get_nom(){return  nom;}
QString client::get_prenom(){return prenom;}
int client::get_id(){return  id;}
int client::getnum(){return num;}
QString client::getemail(){return email;}
QString client::getadresse(){return adresse;}
QString client::getcommande(){return commande;}

bool client::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString ress= QString::number(num);

query.prepare("INSERT INTO etudiant (ID, NOM, PRENOM,num,email,adresse,commande) "
                    "VALUES (:id, :nom, :prenom, :num, :email, :adresse, :commande)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":num", num);
query.bindValue(":email", email);
query.bindValue(":adresse", adresse);
query.bindValue(":commande", commande);

return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etudiant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numéro"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("E-Mail"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Commande"));

    return model;
}

bool client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiant where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool client::modifier()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE etudiant SET id =:id,nom =:nom,prenom =:prenom,num =:num,email =:email,adresse =:adresse,commande =:commande WHERE id =:id ");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num",num);
    query.bindValue(":email",email);
    query.bindValue(":adresse",adresse);
    query.bindValue(":commande",commande);

    return query.exec();
}

QSqlQueryModel * client::tri_client()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM etudiant ORDER BY id");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("E-Mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Commande"));
    return model;

}

QSqlQueryModel * client::rechercherClient(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from etudiant where nom like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

QSqlQueryModel * client::Find_Client()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id,nom,prenom,num,email,adresse,commande FROM etudiant");

    query.exec();
    model->setQuery(query);
    return model;
}

bool client::controlsaisieMail(QString saisi){
    int i,test1=0,test2=0;


            for (i=0;i<saisi.length();i++)
            {
     if( saisi[i]=="@")
          test1=1;
     if( saisi[i]==".")
         test2=1;
            }
    if((test1==1)&&(test2==1)){
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Email"),
                    QObject::tr("L'adresse Mail non valid.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }


}
bool client::controlsaisiechar(QString saisi,QString type){
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
bool client::controlSaisieNumVide(int num,QString numm){

       if(std::to_string(num).length()==8)
               {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Numéro"),
                    QObject::tr("Le %1 doit avoir 8 chiffre .\n"
                                "Click Cancel to exit.").arg(numm), QMessageBox::Cancel);
        return false;
    }

}

bool client::controlSaisieCharVide(QString prenom,QString prenomm){

 if(prenom.length()!=0)
 {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ID"),
                    QObject::tr("Le champs de %1 est vide.\n"
                                "Click Cancel to exit.").arg(prenomm), QMessageBox::Cancel);
        return false;
    }

}

