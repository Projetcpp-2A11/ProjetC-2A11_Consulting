#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include "Reclamation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //afficher()
    Reclamation reclamation;
    ui->tableView_3->setModel(reclamation.afficher());
    // Connect the 'clicked' signal of the 'ajouter' button to the on_ajouter_clicked slot
    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    //connect(ui->pb_supprimer, &QPushButton::clicked, this, &MainWindow::on_pb_supprimer_clicked);


    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur : La base de données n'est pas ouverte !" << db.lastError().text();
    } else {
        qDebug() << "Connexion réussie à la base de données.";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked() {
    // Récupération des informations saisies dans les champs
    QString nom = ui->lineEdit_nom->text();
    QString sujet = ui->lineEdit_sujet->text();
    QString description = ui->lineEdit_description->text();
    QString status = ui->lineEdit_status->text();
    QString date = ui->lineEdit_date->text();

    // Use the constructor with status
    Reclamation R(nom, sujet, description,status,  date);  // Corrected constructor call

    bool test = R.ajouter();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\nClick Cancel to exit."),
                                 QMessageBox::Cancel);
        qDebug() << "Réclamation ajoutée avec succès !";
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        qDebug() << "Erreur lors de l'ajout de la réclamation.";
    }
}

/*void MainWindow::on_pushButton_supprimer_clicked() {
    int id = ui->lineEdit_IDS->text().toInt();

    Reclamation Rtmp;  // temporary object
    bool test = Rtmp.supprimer(id);

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\nClick Cancel to exit."),
                                 QMessageBox::Cancel);
        qDebug() << "Réclamation supprimée.";
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        qDebug() << "Erreur lors de la suppression.";
    }
}
*/
