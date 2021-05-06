#ifndef JALEL_H
#define JALEL_H
#include "etudiant.h"
#include "livraison.h"
#include <statistique_clients.h>
#include <QDialog>
#include <QMediaPlayer>
namespace Ui {
class jalel;
}

class jalel : public QDialog
{
    Q_OBJECT

public:
    explicit jalel(QWidget *parent = nullptr);
    ~jalel();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_modifier_clicked();

    void on_trieID_clicked();



    //void on_rechercher_clicked();



    void on_rechercherclient_textChanged(const QString &arg1);

    void on_Excel_clicked();

    void on_pb_ajouter_L_clicked();

    void on_pb_supprimer_L_clicked();

    void on_modifier_L_clicked();

    void on_trieID_L_clicked();

    void on_rechercherliv_textChanged(const QString &arg1);


    void on_statsC_clicked();

    void on_Excel_L_clicked();

private:
    Ui::jalel *ui;
    client tmpclient;
    livraison tmplivraison;

    int id=0;
    client cl;
    QMediaPlayer* player;
    statistique_clients *stat_clients;
    livraison lv;


};

#endif // JALEL_H
