#ifndef TODO_H
#define TODO_H

#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QPair>

// Forward declaration instead of including mainwindow.h to avoid circular dependency
class MainWindow;

class ToDo {
public:
    static bool ajouterTache(int idConsultant, const QString &tache, QSqlQuery &query);
    static bool supprimerTache(int idConsultant, const QString &tache, QSqlQuery &query);
    static QList<QPair<int, QString>> recupererTousLesTaches(QSqlQuery &query);
    static bool verifierIdExiste(int idConsultant, QSqlQuery &query);
};

#endif // TODO_H
