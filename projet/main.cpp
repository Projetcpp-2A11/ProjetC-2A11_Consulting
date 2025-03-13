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
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection Avec Succées.\n"
                                             "Click OK to continue."), QMessageBox::Ok);
    } else {

        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Connection failed.\n"
                                          "Click OK to exit."), QMessageBox::Ok);
        return -1;
    }

    return a.exec();
}
