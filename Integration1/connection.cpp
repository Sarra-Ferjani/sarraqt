#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projetqt");//inserer le nom de la source de données ODBC
db.setUserName("sarra123");//inserer nom de l'utilisateur
db.setPassword("sarra1");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
