#include "connecion.h"
#include <QSqlError>
connecion::connecion(){}
bool connecion::ouvrirconnexion(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetqt");
    db.setUserName("sarra123");
    db.setPassword("sarra1");
    if(db.open())
    test=true;
    else test=false;
    return test;}

void connecion::fermerconnexion(){
    db.close();
}
