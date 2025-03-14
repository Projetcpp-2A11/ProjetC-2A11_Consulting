#include "mainwindow.h"
#include "employe.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRegularExpression>

// Constructor and Destructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Function to add an employee
void MainWindow::on_ajouter_clicked()
{
    QString nom = ui->lineEdit_3->text();
    QString prenom = ui->lineEdit_6->text();
    QString email = ui->lineEdit_7->text();
    QString motDePasse = ui->lineEdit_8->text();
    QString telephone = ui->lineEdit_4->text();
    QString poste = ui->comboBox->currentText();
    QString dateDeNaissance = ui->dateEdit->date().toString();

    // Input validation
    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || motDePasse.isEmpty() || telephone.isEmpty() || poste.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Tous les champs doivent être remplis !"));
        return;
    }

    // Check email format
    QRegularExpression emailRegex("[A-Za-z0-9]+@[A-Za-z0-9]+\\.[A-Za-z]{2,}");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, tr("Erreur"), tr("L'email n'est pas valide !"));
        return;
    }

    // Check telephone format (allowing for basic numeric input and optional spaces, dashes, etc.)
    QRegularExpression phoneRegex("^[0-9\\+\\-\\s]+$");
    if (!phoneRegex.match(telephone).hasMatch()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Le numéro de téléphone n'est pas valide !"));
        return;
    }

    // Create employee object
    Employe E(nom, prenom, telephone, poste, email, motDePasse, dateDeNaissance);

    // Add employee to the database
    if (E.ajouter()) {
        ui->tab_emp->setModel(E.afficher());
        QMessageBox::information(this, tr("Succès"), tr("Ajout réussi !"));

        // Clear the form
        ui->lineEdit_3->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_4->clear();
        ui->comboBox->setCurrentIndex(0);  // Reset to default
        ui->dateEdit->clear();
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout a échoué !"));
    }
}




void MainWindow::on_tabWidget_2_currentChanged(int index)
{

    if(index==0)
        ui->tab_emp->setModel(E.afficher());
}


void MainWindow::on_Supprimer_emp_clicked()
{

        bool test=E.supprimer(ui->tab_emp->currentIndex().model()->index(ui->tab_emp->currentIndex().row(),0,ui->tab_emp->currentIndex().parent()).data().toInt());
        if(test)
        {
            ui->tab_emp->setModel(E.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Suppression non effectuÃ©\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

}


void MainWindow::on_modifier_2_clicked()
{
    ui->tabWidget_2->setCurrentIndex(2);

        E.SetDonnees((ui->tab_emp->currentIndex().model()->index(ui->tab_emp->currentIndex().row(),0,ui->tab_emp->currentIndex().parent()).data().toInt()));


    ui->lineEdit_10->setText(E.getNomEMP());
    ui->lineEdit_11->setText(E.getPrenomEMP());
    ui->comboBox_2->setCurrentText(E.getPoste());  // Correction ici
    ui->lineEdit_14->setText(E.getEmail());
    ui->lineEdit_15->setText(E.getMotDePasse());
    ui->lineEdit_13->setText(E.getTelephone());



}


void MainWindow::on_modifier_clicked()
{


    //int id_emp = ui->tab_emp->selectionModel()->currentIndex().model()->index(ui->tab_emp->selectionModel()->currentIndex().row(), 0 ).data().toInt();
    QString nom = ui->lineEdit_10->text();
    QString prenom = ui->lineEdit_11->text();
    QString poste = ui->comboBox_2->currentText();
    QString email = ui->lineEdit_14->text();
    QString motDePasse = ui->lineEdit_15->text();
    QString telephone = ui->lineEdit_13->text();
    QString dateDeNaissance = ui->dateEdit_2->date().toString("yyyy-MM-dd");

    Employe E(nom, prenom, motDePasse, email, telephone, poste, dateDeNaissance);


        if(E.modifier((ui->tab_emp->currentIndex().model()->index(ui->tab_emp->currentIndex().row(),0,ui->tab_emp->currentIndex().parent()).data().toInt())))
        {
            ui->tab_emp->setModel(E.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}

