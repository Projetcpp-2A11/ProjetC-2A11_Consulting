#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reclamation
{
private:
    QString nom, sujet, description, status, date;
    int idReclamation;

public:
    // Constructors
    Reclamation();  // Default constructor for cases like 'supprimer'
    Reclamation(QString nom, QString sujet, QString description,QString status, QString date);  // Constructor for auto-increment (without idReclamation)
    Reclamation(int id, QString nom, QString sujet, QString description,QString status, QString date);  // Constructor with idReclamation (for update)

    // Getters
 QString getNom() const { return nom; }
    QString getSujet() const { return sujet; }
    QString getDescription() const { return description; }
    QString getStatus() const { return status; }
    QString getDate() const { return date; }
    int getIdReclamation() const { return idReclamation; }

    // Setters
    void setNom(const QString& n) { nom = n; }
    void setSujet(const QString& s) { sujet = s; }
    void setDescription(const QString& d) { description = d; }
    void setStatus(const QString& e) { description = e; }
    void setDate(const QString& dt) { date = dt; }
    void setIdReclamation(int id) { idReclamation = id; }

    // Database functionalities
    bool ajouter();  // Function to add a new reclamation
    bool supprimer(int id);  // Function to delete a reclamation based on its id
    QSqlQueryModel* afficher();  // Optional: For displaying reclamations, if needed
};

#endif // RECLAMATION_H
