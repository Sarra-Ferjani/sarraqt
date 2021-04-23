#ifndef tarif_H
#define tarif_H
#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>

class tarif
{

    int CODE_TARIF ;
    int DATE_TARIF;
    int SOMME_TARIF;

public:
    tarif();
    tarif(int,int,int);
    ~tarif();


    int getCode() {return CODE_TARIF;}
    int getDate() {return DATE_TARIF;}
    int getSomme() {return SOMME_TARIF;}

    void setCode(int code){CODE_TARIF=code;}
    void setDate(int date){DATE_TARIF=date;}
    void setSomme(int somme){SOMME_TARIF=somme;}

    bool ajoutertarif();
    QSqlQueryModel * affichertarif();
    bool supprimertarif(int CODE) ;
    bool modifiertarif(int SOMME);

   static QSqlQueryModel * afficher_ComboBox();
    /*bool rechercheC(int carte);
    QSqlQueryModel *trierC();
    QSqlQueryModel *trierCdesc();*/
};



#endif // tarif_H
