#include "consult.h"
#include <QString>

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

// Utility method to display consultant details
QString Consultant::toString() const {
    return QString("ID: %1, Name: %2 %3, Email: %4, Tel: %5, Specialisation: %6, Experience: %7, Disponibilite: %8")
    .arg(idCon)
        .arg(nomCon)
        .arg(prenomCon)
        .arg(emailCon)
        .arg(telCon)
        .arg(specialisation)
        .arg(experience)
        .arg(disponibilite);
}

