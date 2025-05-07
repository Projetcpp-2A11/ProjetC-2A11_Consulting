#include "acceuil.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>



bool Acceuil::verifierConnexion(const QString &email, const QString &mdp)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM USER WHERE EMAIL = :email AND MDPS = :mdp");
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);

    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Problème avec la base de données.");
        return false;
    }

    if (query.next() && query.value(0).toInt() > 0) {
        return true;  // Connexion réussie
    } else {
        return false;  // Connexion échouée
    }
}


