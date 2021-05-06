#ifndef STATISTIQUE_TARIF_H
#define STATISTIQUE_TARIF_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QWidget>
#include <QList>


namespace Ui {
class statistique_tarif;
}

class statistique_tarif : public QDialog
{
    Q_OBJECT

public:
    explicit statistique_tarif(QWidget *parent = nullptr);
    ~statistique_tarif();


private:
    Ui::statistique_tarif *ui;
   // QList<qreal> stat_tarif();
    QList<qreal> stat_tarifs();
   QList<QString> stat_tarifs_nom();
};

#endif // STATISTIQUE_FILM_H
