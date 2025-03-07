#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "consult.h"
#include <QSqlQuery>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_ajouter_clicked);
    setupTable();
    populateTable();
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

}
void MainWindow::onTabChanged(int index) {
    if (index == 1) { // Assuming tab_2 is the second tab (index 1)
        populateTable();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_clicked()
{
    // Create a Consultant object and populate it with data from the UI

    Consultant consultant;
    consultant.setNomCon(ui->nom->toPlainText());
    consultant.setPrenomCon(ui->prenom->toPlainText());
    consultant.setEmailCon(ui->email->toPlainText());
    consultant.setTelCon(ui->tele->toPlainText().toInt());
    consultant.setSpecialisation(ui->spec->toPlainText());
    consultant.setExperience(ui->list->currentText());
    consultant.setDisponibilite(ui->oui->isChecked() ? "Oui" : "Non");


    QSqlQuery query;
    if (consultant.insertIntoDatabase(query)) {
        qDebug() << "Data inserted successfully!";
    } else {
        qDebug() << "Failed to insert data.";
    }
}


void MainWindow::populateTable() {

    ui->tableau->setRowCount(0);

    QSqlQuery query;
    QList<Consultant> consultants = Consultant::fetchAllConsultants(query);

    for (const Consultant &consultant : consultants) {
        int row = ui->tableau->rowCount();
        ui->tableau->insertRow(row);

        // Add data to each column
        ui->tableau->setItem(row, 0, new QTableWidgetItem(QString::number(consultant.getIdCon())));
        ui->tableau->setItem(row, 1, new QTableWidgetItem(consultant.getNomCon()));
        ui->tableau->setItem(row, 2, new QTableWidgetItem(consultant.getPrenomCon()));
        ui->tableau->setItem(row, 3, new QTableWidgetItem(consultant.getEmailCon()));
        ui->tableau->setItem(row, 4, new QTableWidgetItem(QString::number(consultant.getTelCon())));
        ui->tableau->setItem(row, 5, new QTableWidgetItem(consultant.getSpecialisation()));
        ui->tableau->setItem(row, 6, new QTableWidgetItem(consultant.getExperience()));
        ui->tableau->setItem(row, 7, new QTableWidgetItem(consultant.getDisponibilite()));
    }
}
void MainWindow::on_tab_2_clicked() {
    populateTable();
}
void MainWindow::setupTable() {

    ui->tableau->setColumnCount(8);


    QStringList headers = {"ID", "Nom", "Prénom", "Email", "Téléphone", "Spécialisation", "Expérience", "Disponible"};
    ui->tableau->setHorizontalHeaderLabels(headers);


    ui->tableau->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

