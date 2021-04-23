#ifndef LIVREUR_H
#define LIVREUR_H
#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
class livreur
{public:
  livreur();
    livreur(int id,QString prenom,QString nom,QString tel);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_tel();
    
    void set_identifiant(int identifiant);
    void set_nom(QString nom1 ){nom=nom1;}
    void set_prenom(QString prenom1){prenom=prenom1;}
    void set_tel(QString tel1){tel=tel1;}
    
    void chercher();
    bool ajouter(int id, QString nom, QString prenom,QString tel);
    bool supprimer(int id_ch);
    bool modifier(int id,QString prenom,QString nom,QString tel);
    QSqlQueryModel * afficher_liste();
    QSqlQueryModel * afficher2(QString nom);
    QSqlQueryModel *  recherche_livreur(QString valeur);
    QSqlQueryModel * recherche_livreurtd(QString valeur);
    QSqlQueryModel * recherche_e(int valeur);
    QSqlQueryModel *tri(int index);
    QSqlQueryModel * afficher();





private:
    QString nom,prenom,tel;
  
    int id;

};


#endif // AGENT_H
