#include "statistique_livreur.h"
#include "ui_statistique_livreur.h"
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

statistique_livreur::statistique_livreur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique_livreur)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

        QList<qreal> list= stat_livreur();
      //  QList<QString> list2= stat_livreur_nom();

            series->append("oui",list[0]);
            series->append("non",list[1]);
        /*for(int i=0 ;i<list.size();i++)
            {
                 series->append(list2[i],list[i]);

            }

*/



            QChart *chart =new QChart;
            chart->addSeries(series);
            chart->setTitle("STATS des livreur");
             QChartView *chartview= new QChartView(chart);
             chartview->setParent(ui->horizontalFrame);

}

statistique_livreur::~statistique_livreur()
{
    delete ui;
}

QList<qreal> statistique_livreur::stat_livreur()
{
    QList<qreal> list ;
        QSqlQuery query;
        query.prepare("SELECT telephone, count(*) AS counter FROM livreur GROUP BY telephone ORDER BY telephone");
        query.exec();
        while(query.next())
        {list.append(query.value(1).toInt());}
        return list ;
}

