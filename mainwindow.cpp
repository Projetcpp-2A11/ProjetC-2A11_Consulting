#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTableView>
#include <QHeaderView>
#include <QAbstractItemModel>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QVBoxLayout>
#include <QLayoutItem>
#include "Reclamation.h"
#include "connection.h"
#include <QMap>
#include <QDialog>
#include <QPushButton>
#include "stmpclient.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Establish database connection
    //Connection conn;
    //if (!conn.createconnection()) {
      //  qDebug() << "Erreur : La base de données n'est pas ouverte !";
    //} else {
      //  qDebug() << "Connexion réussie à la base de données.";
    //}

    // Display complaints
    Reclamation reclamation;
    ui->tableView_3->setModel(reclamation.afficher());

    // Connect the Add button
    connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    connect(ui->pb_supprimer, &QPushButton::clicked, this, &MainWindow::on_pb_supprimer_clicked);
    connect(ui->pb_trier, &QPushButton::clicked, this, &MainWindow::on_pb_trier_clicked);
    connect(ui->pb_recherche, &QPushButton::clicked, this, &MainWindow::on_pb_recherche_clicked);
    connect(ui->pb_modifier, &QPushButton::clicked, this, &MainWindow::on_pb_modifier_clicked);
    //connect(ui->pb_load, &QPushButton::clicked, this, &MainWindow::on_pb_load_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajouter_clicked() {
    QString nom = ui->lineEdit_nom->text().trimmed();
    //QString idclient = ui->lineEdit_client->text().trimmed();
    QString sujet = ui->lineEdit_sujet->text().trimmed();
    QString description = ui->lineEdit_description->text().trimmed();
    QString status = ui->lineEdit_status->text().trimmed();
    QString datee = ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString email = ui->lineEdit_Email->text().trimmed();
    if (nom.isEmpty()  || sujet.isEmpty() || description.isEmpty() || datee.isEmpty() || email.isEmpty() ) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }
    // Créer l'objet Réclamation
    Reclamation r(nom ,sujet, description, "", datee , email);  // Status vide, sera défini automatiquement
    // Déterminer automatiquement la catégorie basée sur les mots-clés
    QString categorie = r.classerParMotCle();
    // Mettre à jour le champ status avec la catégorie détectée
    r.setStatus(categorie);
    // Ajouter la réclamation avec le statut détecté
    if (r.ajouter()) {
        SmtpClient smtp;
        QString subject = "Bienvenue sur Stratedgge";
        QString generatedUsername = nom + "_user";  // Valeur factice
        QString plainPassword = "MotDePasse123";    // Valeur factice
        QString htmlBody = R"(<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <style>
    body {
      font-family: 'Arial', sans-serif;
      background-color: #f4f4f4;
      padding: 30px;
    }
    .container {
      background-color: #ffffff;
      padding: 40px;
      border-radius: 12px;
      box-shadow: 0 2px 10px rgba(0,0,0,0.1);
      max-width: 600px;
      margin: auto;
    }
    h2 {
      color: #333333;
    }
    p {
      color: #555555;
      font-size: 16px;
    }
    .footer {
      margin-top: 30px;
      font-size: 12px;
      color: #aaaaaa;
    }
  </style>
</head>
<body>
  <div class="container">
    <h2>Bienvenue sur Stratedgge</h2>
    <p>Bonjour <strong>[NAME]</strong>,</p>
    <p>Votre réclamation a été ajoutée avec succès. Nous tenons à vous informer que la procédure de traitement est en cours et vous serez tenu informé des prochaines étapes très prochainement.</p>
    <p>Merci de votre confiance.</p>
    <br>
    <p class="footer">© 2025 Stratedgge. Tous droits réservés.</p>
  </div>
</body>
</html>)";htmlBody.replace("[NAME]", email)
                                                  .replace("[USERNAME]", generatedUsername)
                                                  .replace("[PASSWORD]", plainPassword);

        bool mailSent = smtp.sendMail(
            "Nexovate_noReply@example.com", // From
            email  ,                  // To (ensure getEmail() returns a valid email)
            subject,                          // Subject
            htmlBody,                         // HTML body content
            "smtp.gmail.com",                 // SMTP server address
            465,                              // Port
            "medchah605@gmail.com",           // SMTP username
            "yuuy rlem xfsy cwfj"             // SMTP password
            );

        if (!mailSent) {
            qCritical() << "Erreur lors de l'envoi de l'email via SMTP.";
        } else {
            qDebug() << "Welcome email sent successfully.";
        }
        QMessageBox::information(this, "Succès", "Réclamation ajoutée.");
        // Rafraîchir l'affichage sans double ajout
        // Ne pas appeler `afficher()` ici à moins que cela soit vraiment nécessaire
        QSqlQueryModel *model = r.afficher();
        ui->tableView_3->setModel(model);  // Rafraîchir la table avec le nouveau modèle
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout.");
    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    int id_reclamation = ui->lineEditsup->text().toInt();  // Get the ID from the input field

    if (id_reclamation == 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid reclamation ID.");
        return;
    }

    // Confirmation message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Deletion",
                                  "Are you sure you want to delete this reclamation?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Reclamation r;  // Create Reclamation object
        if (r.supprimer(id_reclamation)) {  // Try to delete the record
            qDebug() << "Deletion successful!";
            ui->statusbar->showMessage("Reclamation deleted successfully", 3000);

            // Refresh the table view after deletion
            QSqlQueryModel *model = r.afficher();  // Get the updated model
            if (model) {
                ui->tableView_3->setModel(model);  // Update the view with fresh data
                qDebug() << "Table refreshed!";
            } else {
                qDebug() << "Error refreshing table.";
            }
        } else {
            qDebug() << "Error deleting reclamation!";
            ui->statusbar->showMessage("Failed to delete reclamation", 3000);
        }
    } else {
        qDebug() << "Deletion canceled!";
    }
}
void MainWindow::on_pb_trier_clicked()
{
    QString column = ui->comboBoxtri->currentText();  // Assurez-vous que comboBoxCritere est un QComboBox dans votre interface
    QString order = ui->comboBoxtri_2->currentText();      // Assurez-vous que comboBoxOrdre est un QComboBox pour choisir ASC ou DESC

    // Appeler la fonction trierPar avec les valeurs récupérées
    QSqlQueryModel* model = R.trier(column, order);

    if (model) {
        // Si le tri est réussi, mettre à jour le modèle du QTableView ou de tout autre composant qui affiche les données
       ui->tableView_3->setModel(model);  // Assurez-vous que tableView est le QTableView qui affiche les réclamations
    } else {
        qDebug() << "Erreur lors du tri.";
    }
}
void MainWindow::on_pb_recherche_clicked()
{
    QString value = ui->lineEdit_rech->text().trimmed(); // Get search value

    if (value.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a search value.");
        return;
    }

    // Create a QSqlQueryModel to display search results
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Modify the query to search based on 'nom' column in the 'reclamation' table
    query.prepare("SELECT * FROM RECLAMATION WHERE nom LIKE :value");
    query.bindValue(":value", "%" + value + "%");

    // Execute the query
    if (!query.exec()) {
        QMessageBox::critical(this, "Search Error", "Failed to execute search.");
        return;
    }

    // Set the query to the model and update the table view
    model->setQuery(query);
    ui->tableView_3->setModel(model); // Update the table view
}
void MainWindow::on_pb_generate_pdf_clicked()
{
    // Open file dialog to select where to save the PDF
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return;
    }

    // Create a QPdfWriter object
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);  // Set page size to A4
    writer.setResolution(300);  // Set resolution for quality
    writer.setPageMargins(QMarginsF(10, 10, 10, 10));

    // Create QPainter object to draw on the PDF
    QPainter painter;
    if (!painter.begin(&writer)) {
        qWarning() << "Failed to open file for writing";
        return;
    }

    // Get the model from the table view
    QAbstractItemModel *model = ui->tableView_3->model();
    if (!model) {
        QMessageBox::warning(this, "Error", "No data available in the table.");
        return;
    }

    // Set up initial drawing variables
    int yOffset = 100;
    int margin = 50;
    int rowHeight = 40;
    int columnCount = model->columnCount();
    int pageWidth = writer.width() - 2 * margin;

    // Set font for the header
    QFont font("Arial", 12, QFont::Bold);
    painter.setFont(font);

    // Calculate the column widths dynamically
    QVector<int> columnWidths(columnCount, pageWidth / columnCount);

    // Draw document title
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(margin, yOffset - 50, "Liste des Reclamations");

    // Draw the table header
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int col = 0; col < columnCount; ++col) {
        QRect rect(margin + col * columnWidths[col], yOffset, columnWidths[col], rowHeight);
        painter.drawRect(rect);  // Draw border
        painter.drawText(rect, Qt::AlignCenter, model->headerData(col, Qt::Horizontal).toString());
    }

    // Draw the table rows
    painter.setFont(QFont("Arial", 10));
    yOffset += rowHeight;
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QRect rect(margin + col * columnWidths[col], yOffset, columnWidths[col], rowHeight);
            painter.drawRect(rect);  // Draw border
            painter.drawText(rect, Qt::AlignCenter, model->data(model->index(row, col)).toString());
        }
        yOffset += rowHeight;

        // Check if we need to create a new page
        if (yOffset + rowHeight > writer.height() - 100) {
            writer.newPage();
            yOffset = 100; // Reset yOffset for new page
        }
    }

    // Draw footer with timestamp
    QString dateTime = QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss");
    painter.setFont(QFont("Arial", 8));
    painter.drawText(margin, writer.height() - 50, "Generated on: " + dateTime);

    // End the painter
    painter.end();

    QMessageBox::information(this, "Success", "PDF exported successfully!");
    qDebug() << "PDF saved to" << fileName;
}
void MainWindow::on_pb_modifier_clicked()
{
QString nom = ui->lineEdit_nom_2->text();
QString sujet = ui->lineEdit_sujet_2->text();
QString description = ui->lineEdit_description_2->text();
QString status = ui->lineEdit_status_3->text();
QString datee = ui->dateTimeEdit_2->date().toString("yyyy-MM-dd");
QString email = ui->lineEdit_Email_3->text();

Reclamation R(nom, sujet, email, description, status, datee);



if(R.modifier((ui->tableView_3->currentIndex().model()->index(ui->tableView_3->currentIndex().row(), 0, ui->tableView_3->currentIndex().parent()).data().toInt())))
{
    ui->tableView_3->setModel(R.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modification effectuée\n""Click Cancel to exit."), QMessageBox::Cancel);
}
else
{
    QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification non effectuée\n""Click Cancel to exit."), QMessageBox::Cancel);
}

}
void MainWindow::on_pb_load_clicked()
{
    int id_reclamation = ui->lineEdit_id->text().toInt();  // Get ID from input
    Reclamation reclamation;

    // Attempt to load the reclamation by its ID
    if (reclamation.loadById(id_reclamation)) {
        ui->lineEdit_nom_2->setText(reclamation.getNom());
        ui->lineEdit_sujet_2->setText(reclamation.getSujet());
        ui->lineEdit_description_2->setText(reclamation.getDescription());
        ui->lineEdit_status_3->setText(reclamation.getStatus());
        ui->dateTimeEdit_2->setDateTime(QDateTime::fromString(reclamation.getDatee(), "yyyy-MM-dd HH:mm:ss"));
        ui->lineEdit_Email_3->setText(reclamation.getEmail());

        QMessageBox::information(this, "Success", "Données chargées avec succès.");
    } else {
        QMessageBox::warning(this, "Error", "Aucune réclamation trouvée avec cet ID.");
    }
}

void MainWindow::on_lineEdit_categorie_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QModelIndex selectedIndex = ui->tableView_3->currentIndex();
    if (!selectedIndex.isValid()) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner une réclamation dans le tableau.");
        return;
    }

    // Récupérer la description de la ligne sélectionnée
    int row = selectedIndex.row();
    QString description = ui->tableView_3->model()->index(row, 3).data().toString(); // Colonne 3 = Description

    if (description.isEmpty()) {
        QMessageBox::warning(this, "Description manquante", "Aucune description trouvée pour cette réclamation.");
        return;
    }

    // Créer un objet temporaire de réclamation pour classifier
    Reclamation tempReclamation;
    tempReclamation.setDescription(description);

    // Obtenir la catégorie en fonction des mots-clés
    QString categorie = tempReclamation.classerParMotCle();

    // Afficher la catégorie dans une boîte de message
    QMessageBox::information(this, "Catégorie", "La réclamation est classée sous la catégorie : " + categorie);
}
void MainWindow::on_pushButton_10_clicked()
{
    Reclamation r;
    r.afficherStatistiques();
}



void MainWindow::on_pushButton_6_clicked()
{
    ui->tabWidget_3->setCurrentIndex(2);
    R.SetDonnees((ui->tableView_3->currentIndex().model()->index(ui->tableView_3->currentIndex().row(), 0, ui->tableView_3->currentIndex().parent()).data().toInt()));

    ui->lineEdit_nom_2->setText(R.getNom());
    ui->lineEdit_sujet_2->setText(R.getSujet());
    ui->lineEdit_description_2->setText(R.getDescription());
    ui->lineEdit_status_3->setText(R.getStatus());
    ui->dateTimeEdit_2->setDate(QDate::fromString(R.getDatee(), "yyyy-MM-dd"));
    ui->lineEdit_Email_3->setText(R.getEmail());


}



