#ifndef STATISTIQUE_LIVREUR_H
#define STATISTIQUE_LIVREUR_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QWidget>
#include <QList>


namespace Ui {
class statistique_livreur;
}

class statistique_livreur : public QDialog
{
    Q_OBJECT

public:
    explicit statistique_livreur(QWidget *parent = nullptr);
    ~statistique_livreur();


private:
    Ui::statistique_livreur *ui;
   // QList<qreal> stat_tarif();
    QList<qreal> stat_livreurs();
   QList<QString> stat_livreurs_nom();
};

#endif // STATISTIQUE_LIVREUR_H
