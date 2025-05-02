#include "todo.h"


bool ToDo::ajouterTache(int idConsultant, const QString &tache, QSqlQuery &query) {
    query.prepare("INSERT INTO \"C##NOUR\".\"ToDo\" (ID_CON, TACHE, STATUS) VALUES (:id, :tache, 'TODO')");
    query.bindValue(":id", idConsultant);
    query.bindValue(":tache", tache);

    if (!query.exec()) {
        qDebug() << "Erreur d'ajout de tache:" << query.lastError().text();
        return false;
    }
    return true;
}

bool ToDo::supprimerTache(int idConsultant, const QString &tache, QSqlQuery &query) {
    query.prepare("DELETE FROM \"C##NOUR\".\"ToDo\" WHERE ID_CON = :id AND TACHE = :tache");
    query.bindValue(":id", idConsultant);
    query.bindValue(":tache", tache);

    if (!query.exec()) {
        qDebug() << "Erreur Suppresion de tache:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool ToDo::updateTacheStatus(int idConsultant, const QString &tache, const QString &status, QSqlQuery &query) {
    query.prepare("UPDATE \"C##NOUR\".\"ToDo\" SET STATUS = :status WHERE ID_CON = :id AND TACHE = :tache");
    query.bindValue(":id", idConsultant);
    query.bindValue(":tache", tache);
    query.bindValue(":status", status);

    if (!query.exec()) {
        qDebug() << "Erreur de mise à jour du statut:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

QList<QPair<int, QString>> ToDo::recupererTousLesTaches(QSqlQuery &query) {
    QList<QPair<int, QString>> taches;

    if (!query.exec("SELECT ID_CON, TACHE FROM \"C##NOUR\".\"ToDo\" ORDER BY ID_CON")) {
        qDebug() << "Erreur de fetching Les Taches:" << query.lastError().text();
        return taches;
    }

    while (query.next()) {
        taches.append(qMakePair(query.value(0).toInt(), query.value(1).toString()));
    }

    return taches;
}

QList<QPair<QPair<int, QString>, QString>> ToDo::recupererTachesAvecStatus(QSqlQuery &query) {
    QList<QPair<QPair<int, QString>, QString>> taches;

    if (!query.exec("SELECT ID_CON, TACHE, STATUS FROM \"C##NOUR\".\"ToDo\" ORDER BY ID_CON")) {
        qDebug() << "Erreur de fetching Les Taches avec statut:" << query.lastError().text();
        return taches;
    }

    while (query.next()) {
        taches.append(qMakePair(
            qMakePair(query.value(0).toInt(), query.value(1).toString()),
            query.value(2).toString()
            ));
    }

    return taches;
}

bool ToDo::verifierIdExiste(int idConsultant, QSqlQuery &query) {
    query.prepare("SELECT ID_CON FROM \"C##NOUR\".\"CONSULTANT\" WHERE ID_CON = :id");
    query.bindValue(":id", idConsultant);

    if (!query.exec()) {
        qDebug() << "Erreur verification d'ID:" << query.lastError().text();
        return false;
    }
    return query.next();
}
