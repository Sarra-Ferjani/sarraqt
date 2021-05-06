#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QObject>
#include <QWidget>
#include<QSqlQueryModel>


class reclamation
{
public:
    reclamation();
     reclamation(int,int,QString);
    bool ajouter();
       QSqlQueryModel* afficher();
       bool supprimer (int);
       bool modifier();
       QSqlQueryModel * tri_reclamation();
       QSqlQueryModel *rechercherReclamation(QString text_reclamation);



   private:
       int id_commande,id_client;
       QString text_reclamation;
};

#endif // RECLAMATION_H
