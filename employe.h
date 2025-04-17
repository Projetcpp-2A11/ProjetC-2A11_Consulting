#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QPixmap>
#include <QByteArray>

class Employe {
private:
    int id_emp;
    QString nom;
    QString prenom;
    QString telephone;
    QString poste;
    QString email;
    QString motDePasse;
    QString dateDeNaissance;
    QByteArray photo;


public:
    // Default constructor
    Employe() :  nom(""), prenom(""), telephone(""), poste(""), email(""), motDePasse(""), dateDeNaissance(QString()), photo(""){}

    // Parametrized constructor
    Employe( QString nom, QString prenom, QString telephone, QString poste, QString email, QString motDePasse, QString dateDeNaissance,QByteArray photo = QByteArray())
        :  nom(nom), prenom(prenom), telephone(telephone), poste(poste), email(email), motDePasse(motDePasse), dateDeNaissance(dateDeNaissance),photo(photo)  {}

    ~Employe() {} // Destructor

    // Getters (marked as const)
    int getIdEMP() const { return id_emp; }
    QString getNomEMP() const { return nom; }
    QString getPrenomEMP() const { return prenom; }
    QString getTelephone() const { return telephone; }
    QString getPoste() const { return poste; }
    QString getEmail() const { return email; }
    QString getMotDePasse() const { return motDePasse; }
    QString getDateDeNaissance() const { return dateDeNaissance; }
    QByteArray getPhoto() const { return photo; }


    // Setters
    void setIdEMP(int id_emp) { this->id_emp = id_emp; }
    void setNomEMP(const QString &n) { nom = n; }
    void setPrenomEMP(const QString &p) { prenom = p; }
    void setTelephone(const QString &t) { telephone = t; }
    void setPoste(const QString &p) { poste = p; }
    void setEmail(const QString &e) { email = e; }
    void setMotDePasse(const QString &m) { motDePasse = m; }
    void setDateDeNaissance(const QString &d) { dateDeNaissance = d; }
    void setPhoto(const QByteArray &p) { photo = p; }


    // Base functionalities
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(int );
    bool supprimer(int);
    void SetDonnees(int id_emp);
    QSqlQueryModel*trierPar(const QString& critere);
    QSqlQueryModel* rechercherParNom(const QString& nom);
    void loadPhotoFromFile(const QString& filePath);

};
#endif // EMPLOYE_H
