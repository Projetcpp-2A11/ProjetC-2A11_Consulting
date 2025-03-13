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
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::on_supp_clicked);

    ui->tableau->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    connect(ui->mod, &QPushButton::clicked, this, &MainWindow::on_modifications_clicked);
}
void MainWindow::onTabChanged(int index) {
    if (index == 1) {
        populateTable();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_clicked() {
    QSqlQuery query;


    Consultant consultant(
        ui->nom->toPlainText(),
        ui->prenom->toPlainText(),
        ui->email->toPlainText(),
        ui->tele->toPlainText().toInt(),
        ui->spec->toPlainText(),
        ui->list->currentText(),
        ui->oui->isChecked() ? "Oui" : "Non",
        query
        );


    if (consultant.insertIntoDatabase(query)) {
        QMessageBox::information(this, "Succès", "Consultant ajouté avec succès!");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout du consultant.");
    }
}
void MainWindow::populateTable() {

    ui->tableau->setRowCount(0);
    originalValues.clear();


    QSqlQuery query;
    QList<Consultant> consultants = Consultant::fetchAllConsultants(query);

    for (const Consultant &consultant : consultants) {
        int row = ui->tableau->rowCount();
        ui->tableau->insertRow(row);


        ui->tableau->setItem(row, 0, new QTableWidgetItem(QString::number(consultant.getIdCon())));
        ui->tableau->setItem(row, 1, new QTableWidgetItem(consultant.getNomCon()));
        ui->tableau->setItem(row, 2, new QTableWidgetItem(consultant.getPrenomCon()));
        ui->tableau->setItem(row, 3, new QTableWidgetItem(consultant.getEmailCon()));
        ui->tableau->setItem(row, 4, new QTableWidgetItem(QString::number(consultant.getTelCon())));
        ui->tableau->setItem(row, 5, new QTableWidgetItem(consultant.getSpecialisation()));
        ui->tableau->setItem(row, 6, new QTableWidgetItem(consultant.getExperience()));
        ui->tableau->setItem(row, 7, new QTableWidgetItem(consultant.getDisponibilite()));


        for (int col = 0; col < ui->tableau->columnCount(); ++col) {
            originalValues.insert({row, col}, ui->tableau->item(row, col)->text());
        }
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

void MainWindow::on_supp_clicked() {

    int id = ui->id_supp->toPlainText().toInt();


    if (id < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }


    QSqlQuery query;
    if (Consultant::deleteById(id, query)) {
        QMessageBox::information(this, "Succès", "Consultant supprimé avec succès!");
    } else {
        QMessageBox::warning(this, "Erreur", "Ce Consultant n'éxiste pas!");
    }
}
void MainWindow::on_modifications_clicked() {

    int selectedRow = ui->tableau->currentRow();


    if (selectedRow < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à modifier.");
        return;
    }


    int id = ui->tableau->item(selectedRow, 0)->text().toInt();
    bool updateSuccess = false;


    for (int col = 1; col < ui->tableau->columnCount(); ++col) {
        QTableWidgetItem *item = ui->tableau->item(selectedRow, col);
        if (item) {
            QString currentValue = item->text();
            QString originalValue = originalValues.value({selectedRow, col});

            if (currentValue != originalValue) {
                QString columnName;
                switch (col) {
                case 1: columnName = "NOM_CON"; break;
                case 2: columnName = "PRENOM_CON"; break;
                case 3: columnName = "EMAIL_CON"; break;
                case 4: columnName = "TEL_CON"; break;
                case 5: columnName = "SPECIALISATION"; break;
                case 6: columnName = "EXPERIENCE"; break;
                case 7: columnName = "DISPONIBILITE"; break;
                default: continue;
                }


                QSqlQuery query;
                if (Consultant::updateConsultant(id, columnName, currentValue, query)) {
                    updateSuccess = true;

                    originalValues[{selectedRow, col}] = currentValue;
                } else {
                    QMessageBox::warning(this, "Erreur", QString("Erreur lors de la mise à jour de la colonne %1.").arg(columnName));
                }
            }
        }
    }


    if (updateSuccess) {
        QMessageBox::information(this, "<Succès", "Modification réussite!");
    } else {
        QMessageBox::warning(this, "Erreur", "Aucune Modification détectée.");
    }
}
