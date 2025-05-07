#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rdv.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tableView_3->setModel(Rdv.afficher());

    // Connect the 'clicked' signal of the 'ajouter' button to the on_ajouter_clicked slot
    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_pb_ajouter_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
    qDebug() << "✅ Button Clicked: on_pb_ajouter_clicked() triggered!";

    QString heure = ui->timeEdit->time().toString("HH:mm");
    QString nom_vac = ui->lineEdit_nom_vac->text();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();

    if (heure.isEmpty() || nom_vac.isEmpty() || nom.isEmpty() || prenom.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields before submitting.");
        return;
    }

    Rdv rdv(heure, nom_vac, nom, prenom);

    if (rdv.ajouter()) {
        QMessageBox::information(nullptr, "OK", "Rendez-vous ajouté avec succès.");
        qDebug() << "✅ Appointment added successfully!";

        // Refresh Table
        QSqlQueryModel *model = rdv.afficher();
        if (model) {
            ui->tableView_3->setModel(model);
            qDebug() << "🔄 Table refreshed!";
        } else {
            qDebug() << "❌ Error refreshing table.";
        }
    } else {
        QMessageBox::critical(nullptr, "Not OK", "Échec de l'ajout du rendez-vous.");
        qDebug() << "❌ ERROR: Failed to add appointment!";
    }
}
