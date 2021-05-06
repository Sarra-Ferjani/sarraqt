#ifndef MOTEZ_H
#define MOTEZ_H
#include"commande.h"
#include "reclamation.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QPrinter>
#include <QPrintDialog>
#include <QPlainTextEdit>
#include <QDialog>

namespace Ui {
class motez;
}

class motez : public QDialog
{
    Q_OBJECT

public:
    explicit motez(QWidget *parent = nullptr);
    ~motez();
    void update();
private slots:

    void on_ajouter_commande_clicked();

    void on_supprimer_clicked();

    void on_afficher_commande_activated(const QModelIndex &index);

    void on_afficher_commande_clicked(const QModelIndex &index);

    void on_modifier_clicked();



    void on_rechercher_idCommande_textChanged(const QString &arg1);

    void on_ajouter_reclamation_clicked();

    void on_modifier_reclamation_clicked();

    void on_supprimer_reclamation_clicked();



    void on_afficher_reclamation_activated(const QModelIndex &index);

    void on_afficher_reclamation_clicked(const QModelIndex &index);

    void on_Excel_clicked();

    void on_triNom_clicked();

    //void on_trireclamation_clicked();

    void on_triClient_clicked();

    void on_recherche_reclamation_textChanged(const QString &arg1);

    void on_pushButton_print_clicked();

private:
    Ui::motez *ui;
    commande tmpcommande;
    reclamation tmpreclamation;
    int id_commande=0;
    int id_reclamation=0;
};

#endif // MOTEZ_H
