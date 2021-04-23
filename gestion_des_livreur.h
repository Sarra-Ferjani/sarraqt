#ifndef GESTION_DES_LIVREUR_H
#define GESTION_DES_LIVREUR_H

#include <QDialog>
#include"smtp.h"

#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>

class gestion_des_livreur
{
    int ID_LIVREUR ;
    QString NOM_LIVREUR;
    QString PRENOM_LIVREUR;
    int TEL_LIVREUR;


public:
    gestion_des_livreur();
    gestion_des_livreur(int,QString,QString,int);
    ~gestion_des_livreur();

    int getID_LIVREUR(){return ID_LIVREUR;}
    QString getNom_LIVREUR(){return NOM_LIVREUR;}
    QString getPrenom_LIVREUR() {return PRENOM_LIVREUR;}
    int getTEL_LIVREUR() {return TEL_LIVREUR;}

    void setID_LIVREUR(int idL){ID_LIVREUR=idL;}
    void setNom_LIVREUR(QString n){NOM_LIVREUR=n;}
    void setPrenom_LIVREUR(QString p){PRENOM_LIVREUR=p;}
    void setTEL_LIVREUR(int tel){TEL_LIVREUR=tel;}

    bool ajouterLIVREUR();
    QSqlQueryModel * afficherLIVREUR();
    bool supprimerLIVREUR(int ID_LIVREUR) ;
    bool modifierLIVREUR(QString NOM_LIVREUR);

    static QSqlQueryModel * afficher_ComboBox2();
   /* bool rechercheC(int carte);
    QSqlQueryModel *trierC();
    QSqlQueryModel *trierCdesc();*/
};





/*
private:
    Ui::gestion_des_livreur *ui;
    livreur tmplivreur;
    tarif tmptarif;

};
*/
#endif // GESTION_DES_LIVREUR_H
