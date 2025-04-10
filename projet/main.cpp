#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include "consult.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;


    Connection c;
    bool test = c.createconnect();

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
