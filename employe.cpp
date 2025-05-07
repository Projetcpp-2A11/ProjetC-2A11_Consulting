#include "employe.h"
#include "modelphotoemploye.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QFile>

// Ajouter un employé dans la base de données
bool Employe::ajouter()
{
    QSqlQuery query;

    // Préparer la requête SQL (ID_EMP est auto-incrémenté via une SEQUENCE + TRIGGER côté Oracle)
    query.prepare("INSERT INTO EMPLOYE (NOM_EMP, PRENOM_EMP, MDPS, EMAIL, TELEPHONE, POSTE, DATE_NAISSANCE, PHOTO) "
                  "VALUES (:NOM_EMP, :PRENOM_EMP, :MDPS, :EMAIL, :TELEPHONE, :POSTE, TO_DATE(:DATE_NAISSANCE, 'YYYY-MM-DD'), :PHOTO)");

    // Lier les valeurs
    query.bindValue(":NOM_EMP", nom);
    query.bindValue(":PRENOM_EMP", prenom);
    query.bindValue(":MDPS", motDePasse);
    query.bindValue(":EMAIL", email);
    query.bindValue(":TELEPHONE", telephone);
    query.bindValue(":POSTE", poste);
    query.bindValue(":DATE_NAISSANCE", dateDeNaissance);
    query.bindValue(":PHOTO", photo);

    // Vérification taille de la photo
    if (photo.isEmpty()) {
        qDebug() << "[AVERTISSEMENT] La photo est vide. Insertion d'une valeur NULL.";
        query.bindValue(":PHOTO", photo);
          // Oracle accepte NULL ici
    } else {
        qDebug() << "Photo size before insertion:" << photo.size();
        query.bindValue(":PHOTO", photo);  // Insertion en tant que BLOB
    }

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'employé :";
        qDebug() << "Message SQL :" << query.lastError().text();
        qDebug() << "Requête SQL utilisée :" << query.lastQuery();
        return false;
    }

    return true;
}

// Afficher tous les employés dans un modèle
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EMP,NOM_EMP,PRENOM_EMP,POSTE,TELEPHONE,DATE_NAISSANCE,MDPS,EMAIL,PHOTO FROM EMPLOYE");

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
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("PHOTO"));


    return model;
}
// Supprimer un employé de la base de données
bool Employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE ID_EMP = :ID_EMP");
    query.bindValue(":ID_EMP", id);

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
    query.prepare("UPDATE EMPLOYE SET "
                  "NOM_EMP = :NOM_EMP, "
                  "PRENOM_EMP = :PRENOM_EMP, "
                  "MDPS = :MDPS, "
                  "EMAIL = :EMAIL, "
                  "TELEPHONE = :TELEPHONE, "
                  "POSTE = :POSTE, "
                  "DATE_NAISSANCE = TO_DATE(:DATE_NAISSANCE, 'YYYY-MM-DD'), "
                  "PHOTO = :PHOTO "
                  "WHERE ID_EMP = :ID_EMP");

    query.bindValue(":ID_EMP", id_emp);
    query.bindValue(":NOM_EMP", nom);
    query.bindValue(":PRENOM_EMP", prenom);
    query.bindValue(":POSTE", poste);
    query.bindValue(":TELEPHONE", telephone);
    query.bindValue(":DATE_NAISSANCE", dateDeNaissance);
    query.bindValue(":MDPS", motDePasse);
    query.bindValue(":EMAIL", email);

    if (photo.isEmpty()) {
        query.bindValue(":PHOTO", QVariant(QMetaType(QMetaType::QByteArray)));

    } else {
        query.bindValue(":PHOTO", photo);
    }

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de l'employé :" << query.lastError().text();
        return false;
    }
    return true;
}

// Remplir les données d'un employé depuis la BDD
void Employe::SetDonnees(int id_emp)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE ID_EMP = :id_emp");
    query.bindValue(":id_emp", id_emp);
    query.exec();
    if (query.next()) {
        this->id_emp = query.value("ID_EMP").toInt();
        this->nom = query.value("NOM_EMP").toString();
        this->prenom = query.value("PRENOM_EMP").toString();
        this->poste = query.value("POSTE").toString();
        this->telephone = query.value("TELEPHONE").toString();
        this->dateDeNaissance = query.value("DATE_NAISSANCE").toDate().toString("yyyy-MM-dd");
        this->motDePasse = query.value("MDPS").toString();
        this->email = query.value("EMAIL").toString();
        this->photo = query.value("PHOTO").toByteArray();
    }
}

// Trier les employés par un critère
QSqlQueryModel* Employe::trierPar(const QString& critere)
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QString queryStr;

    if (critere == "nom") {
        queryStr = "SELECT * FROM EMPLOYE ORDER BY NOM_EMP ASC";
    } else if (critere == "prenom") {
        queryStr = "SELECT * FROM EMPLOYE ORDER BY PRENOM_EMP ASC";
    } else {
        qDebug() << "Critère de tri invalide :" << critere;
        delete model;
        return nullptr;
    }

    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL lors du tri :" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}

// Rechercher un employé par nom
QSqlQueryModel* Employe::rechercherParNom(const QString& nom)
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    query.prepare("SELECT * FROM EMPLOYE WHERE NOM_EMP LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la recherche :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(std::move(query));

    if (model->lastError().isValid()) {
        qDebug() << "Erreur modèle SQL :" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}

// Conversion de la photo en cv::Mat (OpenCV)
