#ifndef COMMANDE_H
#define COMMANDE_H

#include <QObject>
#include <QWidget>
#include<QSqlQueryModel>

class commande
{
public:
    commande();
    commande(int,int,int,int,QString);
    bool ajouter();
       QSqlQueryModel* afficher();
       bool supprimer (int);
       bool modifier();
       QSqlQueryModel * tri_commande();
       QSqlQueryModel *rechercherCommande(QString adresselivraison);
       QSqlQueryModel * Find_commande();
   private:
       int idCommande,idLivreur,idClient,idStock;
       QString adresseLivraison;
};

#endif // COMMANDE_H
