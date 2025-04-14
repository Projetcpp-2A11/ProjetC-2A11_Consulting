#include "connection.h"
#include "todo.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
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


