#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class livraison
{
public:
    livraison();
    livraison(int, int, QString, QDate);

    int get_prix();
    int get_id();
    QString get_adresselivraison();
    QDate get_datelivraison();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * tri_liv();
    QSqlQueryModel *rechercherLiv(QString adresselivraison);
    QSqlQueryModel * Find_Liv();
    bool modifier();


    bool controlsaisiechar(QString,QString);
    bool controlSaisieNumVide(int prix, QString prixx);
    bool controlSaisieCharVide (QString,QString);

private:
    QString adresselivraison;
    int id,prix;
    QDate datelivraison;
};

#endif // LIVRAISON_H
