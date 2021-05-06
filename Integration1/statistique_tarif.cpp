#include "statistique_tarif.h"
#include "ui_statistique_tarif.h"
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

statistique_tarif::statistique_tarif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique_tarif)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

        QList<qreal> list= stat_tarifs();
        QList<QString> list2= stat_tarifs_nom();

        for(int i=0 ;i<list.size();i++)
                    {
                         series->append(list2[i],list[i]);

                    }

         //   series->append("Action",list[0]);
           // series->append("Comedie",list[1]);
           // series->append("Romance",list[2]);




            QChart *chart =new QChart;
            chart->addSeries(series);
            chart->setTitle("STATS des tarifs");
             QChartView *chartview= new QChartView(chart);
             chartview->setParent(ui->horizontalFrame);

}

statistique_tarif::~statistique_tarif()
{
    delete ui;
}

QList<qreal> statistique_tarif::stat_tarifs()
{
    QList<qreal> list ;
        QSqlQuery query;
        query.prepare("SELECT SOMME_TARIF, count(*) AS counter FROM tarif GROUP BY SOMME_TARIF ORDER BY SOMME_TARIF");
        query.exec();
        while(query.next())
        {list.append(query.value(1).toInt());}
        return list ;
}
QList<QString> statistique_tarif::stat_tarifs_nom()
{
    QList<QString>  list ;
        QSqlQuery query;
        query.prepare("SELECT SOMME_TARIF, count(*) AS counter FROM tarif GROUP BY SOMME_TARIF ORDER BY SOMME_TARIF");
        query.exec();
        while(query.next())
        {list.append(query.value(0).toString());}
        return list ;

}
