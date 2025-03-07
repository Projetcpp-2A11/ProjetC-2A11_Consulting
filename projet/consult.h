#ifndef CONSULT_H
#define CONSULT_H
#include <QList>
#include <QString>
#include <QSqlQuery>

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

    Consultant();
    Consultant(int id, QString nom, QString prenom, QString email, int tel, QString spec, QString exp, QString disp);



    int getIdCon() const;
    QString getNomCon() const;
    QString getPrenomCon() const;
    QString getEmailCon() const;
    int getTelCon() const;
    QString getSpecialisation() const;
    QString getExperience() const;
    QString getDisponibilite() const;
    static QList<Consultant> fetchAllConsultants(QSqlQuery &query);

    void setIdCon(int id);
    void setNomCon(QString nom);
    void setPrenomCon(QString prenom);
    void setEmailCon(QString email);
    void setTelCon(int tel);
    void setSpecialisation(QString spec);
    void setExperience(QString exp);
    void setDisponibilite(QString disp);

    bool insertIntoDatabase(QSqlQuery &query);
};

#endif // CONSULT_H
