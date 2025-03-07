#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    // Use the DSN name
    db.setDatabaseName("STRATEDGGE");
    db.setUserName("C##nour");
    db.setPassword("esp12");

    if (db.open()) {
        test = true;
    } else {
        qDebug() << "Error:" << db.lastError().text();
    }

    return test;
}
