#include "employe.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>

// Ajouter un employé dans la base de données
bool Employe::ajouter()
{
    QSqlQuery query;

    // Préparer la requête SQL (ID_EMP ne doit pas être ajouté, c'est auto-incrémenté)
    query.prepare("INSERT INTO EMPLOYE (ID_EMP,NOM_EMP, PRENOM_EMP, MDPS, EMAIL, TELEPHONE, POSTE, DATE_NAISSANCE) "
                  "VALUES (0,:NOM_EMP, :PRENOM_EMP, :MDPS, :EMAIL, :TELEPHONE, :POSTE, :DATE_NAISSANCE)");

    query.bindValue(":NOM_EMP", nom);
    query.bindValue(":PRENOM_EMP", prenom);
    query.bindValue(":MDPS", motDePasse);
    query.bindValue(":EMAIL", email);
    query.bindValue(":TELEPHONE", telephone);  // Assurez-vous que telephone est un QString
    query.bindValue(":POSTE", poste);
    query.bindValue(":DATE_NAISSANCE", dateDeNaissance);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'employé:" << query.lastError().text();
        return false;
    }
    return true;
}

// Afficher tous les employés dans un modèle
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EMP,NOM_EMP,PRENOM_EMP,POSTE,TELEPHONE,DATE_NAISSANCE,MDPS,EMAIL FROM EMPLOYE");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des employés :" << model->lastError().text();
    }

    // Définir les en-têtes pour le modèle
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EMP"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_EMP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("POSTE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MDPS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}

// Supprimer un employé de la base de données
bool Employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE ID_EMP = :ID_EMP");
    query.bindValue(":ID_EMP", id);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'employé:" << query.lastError().text();
        return false;
    }
    return true;
}

// Modifier les informations d'un employé
bool Employe::modifier(int id_emp)
{
    QSqlQuery query;


    // Préparer la requête de mise à jour
    query.prepare("UPDATE EMPLOYE SET "
                  "NOM_EMP = :NOM_EMP, "
                  "PRENOM_EMP = :PRENOM_EMP, "
                  "MDPS = :MDPS, "
                  "EMAIL = :EMAIL, "
                  "TELEPHONE = :TELEPHONE, "
                  "POSTE = :POSTE, "
                  "DATE_NAISSANCE = :DATE_NAISSANCE "
                  "WHERE ID_EMP = :ID_EMP");

    query.bindValue(":ID_EMP", id_emp);  // ID_EMP est toujours nécessaire pour identifier l'employé
    query.bindValue(":NOM_EMP", nom);
    query.bindValue(":PRENOM_EMP", prenom);
    query.bindValue(":MDPS", motDePasse);
    query.bindValue(":EMAIL", email);
    query.bindValue(":TELEPHONE", telephone);  // Assurez-vous que telephone est un QString
    query.bindValue(":POSTE", poste);
    query.bindValue(":DATE_NAISSANCE", dateDeNaissance);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de l'employé :" << query.lastError().text();
        return false;
    }
    return true;
}
void Employe::SetDonnees(int id_emp)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE ID_EMP = :id_emp");
    query.bindValue(":id_emp", id_emp);
    query.exec();
    query.next();
    this->id_emp = query.value(0).toInt();
    this->nom = query.value(1).toString();
    this->prenom = query.value(2).toString();
    this->motDePasse = query.value(3).toString();
    this->email = query.value(4).toString();
    this->telephone = query.value(5).toString();
    this->poste = query.value(6).toString();
    this->dateDeNaissance = query.value(7).toString();

}
