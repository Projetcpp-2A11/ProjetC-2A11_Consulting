#include "consult.h"
#include <QSqlQuery>
#include <QDebug>

// Default Constructor
Consultant::Consultant() : idCon(0), nomCon(""), prenomCon(""), emailCon(""), telCon(0), specialisation(""), experience(""), disponibilite("") {}

// Parameterized Constructor
Consultant::Consultant(int id, QString nom, QString prenom, QString email, int tel, QString spec, QString exp, QString disp)
    : idCon(id), nomCon(nom), prenomCon(prenom), emailCon(email), telCon(tel), specialisation(spec), experience(exp), disponibilite(disp) {}

// Getters
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

// Setters
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

// Method to insert a Consultant into the database
bool Consultant::insertIntoDatabase(QSqlQuery &query) {
    query.prepare("INSERT INTO CONSULTANT (ID_CON, NOM_CON, PRENOM_CON, EMAIL_CON, TEL_CON, SPECIALISATION, EXPERIENCE, DISPONIBILITE) "
                  "VALUES (:id, :nom, :prenom, :email, :tel, :spec, :exp, :disp)");
    query.bindValue(":nom", nomCon);
    query.bindValue(":prenom", prenomCon);
    query.bindValue(":email", emailCon);
    query.bindValue(":tel", telCon);
    query.bindValue(":spec", specialisation);
    query.bindValue(":exp", experience);
    query.bindValue(":disp", disponibilite);

    if (query.exec()) {
        qDebug() << "Consultant added to database!";
        return true;
    } else {
        qDebug() << "Error inserting consultant:"  ;
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
        qDebug() << "Error fetching consultants:";
    }

    return consultants;
}
