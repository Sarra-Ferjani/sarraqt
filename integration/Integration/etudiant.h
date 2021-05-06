#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{public:
    client();
    client(int, QString, QString, int, QString,QString,QString);

    QString get_nom();
    QString get_prenom();
    int get_id();
    int getnum();
    QString getemail();
    QString getadresse();
    QString getcommande();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * tri_client();
    QSqlQueryModel *rechercherClient(QString nom);
    QSqlQueryModel * Find_Client();
    bool modifier();


    bool controlsaisiechar(QString,QString);
    bool controlSaisieNumVide(int num, QString numm);
    bool controlSaisieCharVide (QString,QString);
    bool controlsaisieMail(QString saisi);
private:
    QString nom,prenom,email,adresse,commande;
    int id,num;
};

#endif // ETUDIANT_H
