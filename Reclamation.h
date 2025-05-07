#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reclamation {
private:
    int id_reclamation;
    QString nom;
    QString sujet;
    QString description;
    QString status;
    QString datee;
    QString email;

public:
    // Constructeur par défaut
    Reclamation()
        : nom(""), sujet(""), description(""), status(""), datee(""), email("") {}

    // Constructeur paramétré
    Reclamation(QString nom, QString sujet, QString description, QString status, QString datee, QString email)
        : nom(nom), sujet(sujet), description(description), status(status), datee(datee), email(email) {}

    // Destructeur
    ~Reclamation() {}

    // Getters
    int getId() const { return id_reclamation; }
    QString getNom() const { return nom; }
    QString getSujet() const { return sujet; }
    QString getDescription() const { return description; }
    QString getStatus() const { return status; }
    QString getDatee() const { return datee; }
    QString getEmail() const { return email; }

    // Setters
    void setId(int id) { id_reclamation = id; }
    void setNom(const QString &n) { nom = n; }
    void setSujet(const QString &s) { sujet = s; }
    void setDescription(const QString &d) { description = d; }
    void setStatus(const QString &s) { status = s; }
    void setDatee(const QString &d) { datee = d; }
    void setEmail(const QString &e) { email = e; }

    // Fonctions de base
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id_reclamation);
    bool modifier(int id_reclamation);
    void SetDonnees(int id_reclamation);
    QSqlQueryModel*trier(QString column, QString order) ;

    QSqlQueryModel* rechercherParMotCle(const QString& motCle);
    QString classerParMotCle();

    bool loadById(int id_reclamation);


    // Email (si utilisé)
    bool envoyerEmailConfirmation(const QString& destinataire);

    // Statistiques (si applicable)
    void afficherStatistiques();
};

#endif // RECLAMATION_H
