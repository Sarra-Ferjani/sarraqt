#ifndef SARRA_H
#define SARRA_H

#include <QDialog>
#include "livreur.h"
#include "tarif.h"
#include "statistique_livreur.h"
#include "statistique_tarif.h"
#include <QWidget>
#include <QTimer>
#include "arduino.h"
#include "widget.h"
namespace Ui {
class sarra;
}

class sarra : public QDialog
{
    Q_OBJECT

public:
    explicit sarra(QWidget *parent = nullptr);
    ~sarra();
private slots:




    void on_pushButtonValidTarif_clicked();
    void on_pushButtonValidL_clicked();
    void on_pushButtonSuppL_clicked();
    void on_pushButtonSuppTarif_clicked();
    void on_comboBox_ModifTarif_currentIndexChanged(int index);
    void on_pushButtonModifTarif_clicked();
    void on_comboBoxModifL_currentIndexChanged(int index);
    void on_pushButtonModifL_clicked();
    void on_pushButtonRechL_clicked();
    void on_pushButtonRechTarif_clicked();
    void on_pushButtonAscL_clicked();
    void on_pushButtonTriAscTarif_clicked();
    void on_pushButtonTriDescTarif_clicked();
    void on_pushButtonTriDescL_clicked();
    void on_pushButtonStatL_clicked();
    void on_pushButtonStattarif_clicked();
    void on_comboBoxRechL_currentIndexChanged(int index);
    void on_lineEditRechL_textChanged(const QString &arg1);
    void on_comboBoxRechTarif_currentIndexChanged(int index);
    void on_lineEditRechTarif_textChanged(const QString &arg1);
    void myfunction();
    void on_pushButtonCamL_clicked();
    void on_pushButtonCamTarif_clicked();




    void on_lineEditSuppTarif_cursorPositionChanged(int arg1, int arg2);



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);
private:
    Ui::sarra *ui;
    livreur tabL;
    tarif tabT;
    statistique_livreur *stat_liv;
    statistique_tarif *stat_tar;
    QTimer *timer;
    Widget *camera;
    arduino  ard;
};

#endif // SARRA_H
