#ifndef TARIF_H
#define TARIF_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class tarif
{
    int CODE_TARIF;
    QString DATE_TARIF;
    int SOMME_TARIF;

public:
    tarif();
    tarif(int,QString,int);
    ~tarif();

    int getCODE_TARIF(){return CODE_TARIF;}
    QString getDATE_TARIF() {return DATE_TARIF;}
    int getSOMME_TARIF() {return  SOMME_TARIF;}


    void setCODE_TARIF(int c){CODE_TARIF=c;}
    void setDATE_TARIF(QString d){DATE_TARIF=d;}
    void setSOMME_TARIF(int s){SOMME_TARIF=s;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int CODE_TARIF) ;
    bool modifier(int CODE_TARIF, QString DATE_TARIF, int SOMME_TARIF);

    bool recherche(int CODE_TARIF);
    static QSqlQueryModel * afficher_ComboBox();
    QSqlQueryModel *trier(); //ascendant
    QSqlQueryModel *trierdesc();

};

#endif // TARIF_H
