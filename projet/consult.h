#ifndef CONSULT_H
#define CONSULT_H
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QList>

class Consultant {
private:
    int idCon;              // ID_CON
    QString nomCon;         // NOM_CON
    QString prenomCon;      // PRENOM_CON
    QString emailCon;       // EMAIL_CON
    int telCon;             // TEL_CON
    QString specialisation; // SPECIALISATION
    QString experience;     // EXPERIENCE
    QString disponibilite;  // DISPONIBILITE

public:
    // Constructors
    Consultant();
    Consultant(QString nom, QString prenom, QString email, int tel, QString spec, QString exp, QString disp, QSqlQuery &query);
    static bool deleteById(int id, QSqlQuery &query);
    // Getters
    int getIdCon() const;
    QString getNomCon() const;
    QString getPrenomCon() const;
    QString getEmailCon() const;
    int getTelCon() const;
    QString getSpecialisation() const;
    QString getExperience() const;
    QString getDisponibilite() const;

    // Setters
    void setIdCon(int id);
    void setNomCon(QString nom);
    void setPrenomCon(QString prenom);
    void setEmailCon(QString email);
    void setTelCon(int tel);
    void setSpecialisation(QString spec);
    void setExperience(QString exp);
    void setDisponibilite(QString disp);

    // Method to insert a Consultant into the database
    bool insertIntoDatabase(QSqlQuery &query);
    static bool validateNomPrenom(const QString &name, QString &error);
    static bool validateEmail(const QString &email, QString &error);
    static bool validateTel(int tel, QString &error);
    static bool validateExperience(const QString &experience, QString &error);
    static bool validateDisponibilite(const QString &disponibilite, QString &error);
    // Method to fetch all consultants from the database
    static QList<Consultant> fetchAllConsultants(QSqlQuery &query);

    // Method to get the maximum ID_CON from the database
    static int getMaxIdCon(QSqlQuery &query);

    static bool updateConsultant(int id, const QString &column, const QString &newValue, QSqlQuery &query);
};

#endif // CONSULT_H
