#ifndef TODO_H
#define TODO_H
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QPair>


class MainWindow;

class ToDo {
public:
    static bool ajouterTache(int idConsultant, const QString &tache, QSqlQuery &query);
    static bool supprimerTache(int idConsultant, const QString &tache, QSqlQuery &query);
    static bool updateTacheStatus(int idConsultant, const QString &tache, const QString &status, QSqlQuery &query);
    static QList<QPair<int, QString>> recupererTousLesTaches(QSqlQuery &query);
    static QList<QPair<QPair<int, QString>, QString>> recupererTachesAvecStatus(QSqlQuery &query);
    static bool verifierIdExiste(int idConsultant, QSqlQuery &query);
};

#endif // TODO_H
