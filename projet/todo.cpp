#include "todo.h"
#include <QSqlError>
#include <QDebug>

bool ToDo::ajouterTache(int idConsultant, const QString &tache, QSqlQuery &query) {

    query.prepare("INSERT INTO \"C##NOUR\".\"ToDo\" (ID_CON, TACHE) VALUES (:id, :tache)");
    query.bindValue(":id", idConsultant);
    query.bindValue(":tache", tache);

    if (!query.exec()) {
        qDebug() << "Error adding task:" << query.lastError().text();
        return false;
    }
    return true;
}

bool ToDo::supprimerTache(int idConsultant, const QString &tache, QSqlQuery &query) {

    query.prepare("DELETE FROM \"C##NOUR\".\"ToDo\" WHERE ID_CON = :id AND TACHE = :tache");
    query.bindValue(":id", idConsultant);
    query.bindValue(":tache", tache);

    if (!query.exec()) {
        qDebug() << "Error deleting task:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

QList<QPair<int, QString>> ToDo::recupererTousLesTaches(QSqlQuery &query) {
    QList<QPair<int, QString>> taches;


    if (!query.exec("SELECT ID_CON, TACHE FROM \"C##NOUR\".\"ToDo\" ORDER BY ID_CON")) {
        qDebug() << "Error fetching tasks:" << query.lastError().text();
        return taches;
    }

    while (query.next()) {
        taches.append(qMakePair(query.value(0).toInt(), query.value(1).toString()));
    }

    return taches;
}

bool ToDo::verifierIdExiste(int idConsultant, QSqlQuery &query) {

    query.prepare("SELECT ID_CON FROM \"C##NOUR\".\"CONSULTANT\" WHERE ID_CON = :id");
    query.bindValue(":id", idConsultant);

    if (!query.exec()) {
        qDebug() << "Error checking ID:" << query.lastError().text();
        return false;
    }
    return query.next();
}
