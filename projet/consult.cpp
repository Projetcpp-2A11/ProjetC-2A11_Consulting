#include "consult.h"
#include <QSqlQuery>
#include <QDebug>
#include <QRegularExpression>

//Constructor par defaut
Consultant::Consultant() : idCon(0), nomCon(""), prenomCon(""), emailCon(""), telCon(0), specialisation(""), experience(""), disponibilite("") {}

// Constructor avec paramtére
Consultant::Consultant(QString nom, QString prenom, QString email, int tel, QString spec, QString exp, QString disp, QSqlQuery &query)
    : idCon(getMaxIdCon(query) + 1),
      nomCon(nom),
      prenomCon(prenom),
      emailCon(email),
      telCon(tel),
      specialisation(spec),
      experience(exp),
      disponibilite(disp) {}

//Les Getters
int Consultant::getIdCon() const {
    return idCon;
}

QString Consultant::getNomCon() const {
    return nomCon;
}

QString Consultant::getPrenomCon() const {
    return prenomCon;
}

QString Consultant::getEmailCon() const {
    return emailCon;
}

int Consultant::getTelCon() const {
    return telCon;
}

QString Consultant::getSpecialisation() const {
    return specialisation;
}

QString Consultant::getExperience() const {
    return experience;
}

QString Consultant::getDisponibilite() const {
    return disponibilite;
}

// Les Setters
void Consultant::setIdCon(int id) {
    idCon = id;
}

void Consultant::setNomCon(QString nom) {
    nomCon = nom;
}

void Consultant::setPrenomCon(QString prenom) {
    prenomCon = prenom;
}

void Consultant::setEmailCon(QString email) {
    emailCon = email;
}

void Consultant::setTelCon(int tel) {
    telCon = tel;
}

void Consultant::setSpecialisation(QString spec) {
    specialisation = spec;
}

void Consultant::setExperience(QString exp) {
    experience = exp;
}

void Consultant::setDisponibilite(QString disp) {
    disponibilite = disp;
}


//Les Validations
bool Consultant::validateNomPrenom(const QString &name, QString &error) {
    if (name.length() < 3 || name.length() > 15) {
        error = "Le nom et le prénom doivent contenir entre 3 et 15 caractères.";
        return false;
    }
    return true;
}

bool Consultant::validateEmail(const QString &email, QString &error) {
    QRegularExpression regex(R"((.+@.+\..+))");
    if (!regex.match(email).hasMatch()) {
        error = "L'email doit contenir un '@' et un '.'.";
        return false;
    }
    return true;
}

bool Consultant::validateTel(int tel, QString &error) {
    if (tel <= 0) {
        error = "Le numéro de téléphone doit être un nombre positif.";
        return false;
    }
    return true;
}

bool Consultant::validateExperience(const QString &experience, QString &error) {
    if (experience == "Donner Votre expérience") {
        error = "Veuillez entrer une expérience valide.";
        return false;
    }
    if (experience.split(" ").size() > 20) {
        error = "L'expérience ne doit pas dépasser 20 mots.";
        return false;
    }
    return true;
}

bool Consultant::validateDisponibilite(const QString &disponibilite, QString &error) {
    if (disponibilite.isEmpty()) {
        error = "Veuillez sélectionner une disponibilité.";
        return false;
    }
    return true;
}


bool Consultant::insertIntoDatabase(QSqlQuery &query) {
    QString error;
    if (!validateNomPrenom(nomCon, error)) {
        QMessageBox::warning(nullptr, "Erreur", error);
        return false;
    }
    if (!validateNomPrenom(prenomCon, error)) {
        QMessageBox::warning(nullptr, "Erreur", error);
        return false;
    }
    if (!validateEmail(emailCon, error)) {
        QMessageBox::warning(nullptr, "Erreur", error);
        return false;
    }
    if (!validateTel(telCon, error)) {
        QMessageBox::warning(nullptr, "Erreur", error);
        return false;
    }
    if (!validateExperience(experience, error)) {
        QMessageBox::warning(nullptr, "Erreur", error);
        return false;
    }
    if (!validateDisponibilite(disponibilite, error)) {
        QMessageBox::warning(nullptr, "Erreur", error);
        return false;
    }

    query.prepare("INSERT INTO CONSULTANT (ID_CON, NOM_CON, PRENOM_CON, EMAIL_CON, TEL_CON, SPECIALISATION, EXPERIENCE, DISPONIBILITE) "
                  "VALUES (:id, :nom, :prenom, :email, :tel, :spec, :exp, :disp)");
    query.bindValue(":id", idCon);
    query.bindValue(":nom", nomCon);
    query.bindValue(":prenom", prenomCon);
    query.bindValue(":email", emailCon);
    query.bindValue(":tel", telCon);
    query.bindValue(":spec", specialisation);
    query.bindValue(":exp", experience);
    query.bindValue(":disp", disponibilite);

    if (query.exec()) {
        qDebug() << "Consultant Ajouter au Base de données!";
        return true;
    } else {
        qDebug() << "Erreur d'insertion consultant!";
        return false;
    }
}

QList<Consultant> Consultant::fetchAllConsultants(QSqlQuery &query) {
    QList<Consultant> consultants;

    if (query.exec("SELECT * FROM CONSULTANT")) {
        while (query.next()) {
            Consultant consultant;
            consultant.setIdCon(query.value("ID_CON").toInt());
            consultant.setNomCon(query.value("NOM_CON").toString());
            consultant.setPrenomCon(query.value("PRENOM_CON").toString());
            consultant.setEmailCon(query.value("EMAIL_CON").toString());
            consultant.setTelCon(query.value("TEL_CON").toInt());
            consultant.setSpecialisation(query.value("SPECIALISATION").toString());
            consultant.setExperience(query.value("EXPERIENCE").toString());
            consultant.setDisponibilite(query.value("DISPONIBILITE").toString());

            consultants.append(consultant);
        }
    } else {
        qDebug() << "Erreur fetching des consultants!" ;
    }

    return consultants;
}

int Consultant::getMaxIdCon(QSqlQuery &query) {
    int maxId = 0;
    if (query.exec("SELECT MAX(ID_CON) FROM CONSULTANT")) {
        if (query.next()) {
            maxId = query.value(0).toInt();
        }
    } else {
        qDebug() << "Error fetching le maximum ID_CON:";
    }
    return maxId;
}


bool Consultant::deleteById(int id, QSqlQuery &query) {
    query.prepare("DELETE FROM CONSULTANT WHERE ID_CON = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            qDebug() << "Consultant Supprimer avec succéss!";
            return true;
        } else {
            qDebug() << "Aucun consultants trouvé avec cette ID:" << id;
            return false;
        }
    } else {
        qDebug() << "Erreur de Supprision de consultant!" ;
        return false;
    }
}


bool Consultant::updateConsultant(int id, const QString &column, const QString &newValue, QSqlQuery &query) {
    query.prepare(QString("UPDATE CONSULTANT SET %1 = :newValue WHERE ID_CON = :id").arg(column));
    query.bindValue(":newValue", newValue);
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            qDebug() << "Consultant Modifié avec succéss!";
            return true;
        } else {
            qDebug() << "Aucun consultants trouvée avec cette  ID:" << id;
            return false;
        }
    } else {
        qDebug() << "Error de Modification de consultant!" ;
        return false;
    }
}
