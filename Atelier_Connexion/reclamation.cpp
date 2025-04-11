#include "reclamation.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// Constructor with ID (useful if you need to populate from DB or for editing)
Reclamation::Reclamation(int id, QString nom, QString sujet, QString description, QString status, QString date) {
    this->idReclamation = id;
    this->nom = nom;
    this->sujet = sujet;
    this->description = description;
    this->status = status;
    this->date = date;
}

// Constructor without ID (auto-increment mode)
Reclamation::Reclamation(QString nom, QString sujet, QString description, QString status, QString date) {
    this->nom = nom;
    this->sujet = sujet;
    this->description = description;
    this->status = status;
    this->date = date;
}

// Default constructor

bool Reclamation::ajouter() {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur: Base de données non ouverte !";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO reclamation (nom, sujet, description, status, date) "
                  "VALUES (:nom, :sujet, :description, :status, :date)");

    query.bindValue(":nom", nom);
    query.bindValue(":sujet", sujet);
    query.bindValue(":description", description);
    query.bindValue(":status", status);
    query.bindValue(":date", date);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de la réclamation:" << query.lastError().text();
        return false;
    }

    qDebug() << "Réclamation ajoutée avec succès.";
    return true;
}

bool Reclamation::supprimer(int idReclamation) {
    QSqlQuery query;
    query.prepare("DELETE FROM reclamation WHERE id_reclamation = :id");
    query.bindValue(":id", idReclamation);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }

    qDebug() << "Réclamation avec ID" << idReclamation << "supprimée.";
    return true;
}
