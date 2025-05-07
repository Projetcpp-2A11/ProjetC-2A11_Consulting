#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_lakahni");
    db.setUserName("lakahni");
    db.setPassword("1234");
    //qDebug() << "Pilotes disponibles : " << QSqlDatabase::drivers();


    if (db.open()) {
        test = true;
        qDebug() << "Connexion à la base de données réussie!";
    } else {
        qDebug() << "Erreur de connexion à la base de données: " << db.lastError().text();
    }

    return test;
}
