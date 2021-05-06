#ifndef LIVREUR_H
#define LIVREUR_H
#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>


class livreur
    {
        int ID_LIVREUR;
        QString NOM_LIVREUR;
        QString PRENOM_LIVREUR;
        int TEL_LIVREUR;

public:
    livreur();
    livreur(int,QString,QString,int);
    ~livreur();
    int getID_LIVREUR() {return ID_LIVREUR;}
    QString getNOM_LIVREUR(){return NOM_LIVREUR;}
    QString getPRENOM_LIVREUR() {return PRENOM_LIVREUR;}
    int getTEL_LIVREUR() {return TEL_LIVREUR;}

    void setID_LIVREUR(int id){ID_LIVREUR=id;}
    void setNOM_LIVREUR(QString n){NOM_LIVREUR=n;}
    void setPRENOM_LIVREUR(QString p){PRENOM_LIVREUR=p;}
    void setTEL_LIVREUR(int tel){TEL_LIVREUR=tel;}


    bool ajouterL();
    QSqlQueryModel * afficherL();
    bool supprimerL(int identifiant) ;
    bool modifierL(QString telephone);

    static QSqlQueryModel * afficher_ComboBox2();
    bool rechercheL(int identifiant);
    QSqlQueryModel *trierL();
    QSqlQueryModel *trierLdesc();
};

#endif // LIVREUR_H
