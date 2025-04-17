#include "login.h"
#include <QDebug>


bool Login::verifierIdentifiants()
{
    QSqlQuery query;

    query.prepare("SELECT * FROM EMPLOYE WHERE EMAIL = :email AND MDPS = :mdps");
    query.bindValue(":email", email);
    query.bindValue(":mdps", motDePasse);

    if (query.exec()) {
        if (query.next()) {
            poste = query.value("POSTE").toString(); // ✅ C’est ici qu’on récupère le rôle
            return true;
        }
    } else {
        qDebug() << "Erreur SQL dans Login::verifierIdentifiants :" << query.lastError().text();
    }

    return false;
}

