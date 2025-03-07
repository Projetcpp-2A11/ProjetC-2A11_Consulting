#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include "consult.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the main window
    MainWindow w;

    // Attempt to establish a database connection
    Connection c;
    bool test = c.createconnect();

    if (test) {
        // If the connection is successful, show the main window
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful.\n"
                                             "Click OK to continue."), QMessageBox::Ok);
    } else {
        // If the connection fails, show an error message and exit
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Connection failed.\n"
                                          "Click OK to exit."), QMessageBox::Ok);
        return -1; // Exit the application with an error code
    }

    return a.exec();
}
