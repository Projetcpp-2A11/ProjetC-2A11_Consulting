#ifndef LOGIN_H
#define LOGIN_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

class Login
{
private:
    QString email;
    QString motDePasse;
    QString poste; // ✅ Add this line

public:
    // Constructeur par défaut
    Login() : email(""), motDePasse(""), poste("") {} // ✅ Init poste

    // Constructeur paramétré
    Login(QString email, QString motDePasse) : email(email), motDePasse(motDePasse), poste("") {} // ✅ Init poste

    ~Login() {} // Destructeur

    // Getters
    QString getEmail() const { return email; }
    QString getMotDePasse() const { return motDePasse; }
    QString getPoste() const { return poste; } // ✅ Add this getter

    // Setters
    void setEmail(const QString &e) { email = e; }
    void setMotDePasse(const QString &m) { motDePasse = m; }

    // Fonction de login
    bool verifierIdentifiants();
};

#endif // LOGIN_H

