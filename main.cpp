#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

#include <QTimer>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;

    bool test = c.createconnect();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Base de données ouverte"),
                                 QObject::tr("Connexion réussie.\nCliquez sur Annuler pour fermer."), QMessageBox::Cancel);

        w.show();

        // === Appel de la webcam OpenCV dans un thread séparé (optionnel) ===
        // Tu peux aussi appeler directement afficherWebcam(); ici si tu veux
      //  QTimer::singleShot(0, []() {
        //    afficherWebcam();
        //});

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Base de données non ouverte"),
                              QObject::tr("Connexion échouée.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }

    return a.exec();
}
