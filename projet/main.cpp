#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "todo.h"
#include "connection.h"
#include "consult.h"
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

// goblin scanner 
    MainWindow w;
    Connection c;

    bool test = c.createconnect();
     a.setWindowIcon(QIcon("C:/Users/nourii/Desktop/Project QT/projet/outils/Logo_Stradedgge.png"));
    if (test) {

        w.show();
    } else {

        QMessageBox::critical(nullptr, QObject::tr("Connection de Base de données"),
                              QObject::tr("échec de Connection .\n"
                                          "Clicker OK pour fermer l'application"), QMessageBox::Ok);
        return -1;
    }

    return a.exec();
}
