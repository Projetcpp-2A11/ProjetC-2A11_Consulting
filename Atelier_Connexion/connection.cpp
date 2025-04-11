#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnection() {
    bool test = false;

    // Vérifier si le pilote QODBC est disponible
    if (!QSqlDatabase::isDriverAvailable("QODBC")) {
        qDebug() << "Erreur : Le pilote ODBC n'est pas disponible.";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("STRATEDGGE");  // Nom de la source de données (DSN)
    db.setUserName("STRATEDGGE");      // Nom d'utilisateur
    db.setPassword("consulting");      // Mot de passe

    if (db.open()) {
        test = true;
        qDebug() << "Connexion réussie à la base de données.";
    } else {
        qDebug() << "Erreur de connexion :" << db.lastError().text();
    }

    return test;
}
void Connection::closeConnection(){
    db.close();
}
/*void Connection::closeConnection() {
    QSqlDatabase db = QSqlDatabase::database();
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connexion fermée.";
    }
}
*/
