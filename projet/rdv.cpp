#include "rdv.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QDebug>
#include <QSqlError>

// Constructor
Rdv::Rdv(QString heure, QString nom_vac, QString nom, QString prenom)
{
    this->heure = heure;
    this->nom_vac = nom_vac;
    this->nom = nom;
    this->prenom = prenom;
}

// Getters
QString Rdv::getHeure() const { return heure; }
QString Rdv::getNomVac() const { return nom_vac; }
QString Rdv::getNom() const { return nom; }
QString Rdv::getPrenom() const { return prenom; }

// Setters
void Rdv::setHeure(const QString &heure) { this->heure = heure; }
void Rdv::setNomVac(const QString &nom_vac) { this->nom_vac = nom_vac; }
void Rdv::setNom(const QString &nom) { this->nom = nom; }
void Rdv::setPrenom(const QString &prenom) { this->prenom = prenom; }

// ✅ Ajouter function with debugging
bool Rdv::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO RDV (HEURE, NOM_VAC, NOM, PRENOM) VALUES (:heure, :nom_vac, :nom, :prenom)");

    query.bindValue(":heure", getHeure());
    query.bindValue(":nom_vac", getNomVac());
    query.bindValue(":nom", getNom());
    query.bindValue(":prenom", getPrenom());

    qDebug() << "📝 Executing Query: " << query.executedQuery();
    qDebug() << "HEURE:" << getHeure();
    qDebug() << "NOM_VAC:" << getNomVac();
    qDebug() << "NOM:" << getNom();
    qDebug() << "PRENOM:" << getPrenom();

    if (!query.exec()) {
        qDebug() << " SQL Insert Error:" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Appointment added successfully!";
    return true;
}

// ✅ Afficher function
QSqlQueryModel *Rdv::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM rdv");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RDV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("HEURE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_VAC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOM"));
    return model;
}

bool Rdv::supprimer(int id_rdv)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RDV WHERE ID_RDV = :id_rdv");
    query.bindValue(":id_rdv", id_rdv);

    return query.exec();
}
