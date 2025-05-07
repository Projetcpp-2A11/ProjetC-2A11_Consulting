#ifndef RDV_H
#define RDV_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Rdv
{
public:
    // Constructors
    Rdv() = default; // Default constructor (needed for some Qt models)
    Rdv(QString heure, QString nom_vac, QString nom, QString prenom);

    // CRUD operations
    bool ajouter();
    static QSqlQueryModel *afficher();
    bool supprimer(int id_rdv);

    // Getters
    QString getHeure() const;
    QString getNomVac() const;
    QString getNom() const;
    QString getPrenom() const;

    // Setters
    void setHeure(const QString &heure);
    void setNomVac(const QString &nom_vac);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);

private:
    QString heure, nom_vac, nom, prenom;
};

#endif // RDV_H
