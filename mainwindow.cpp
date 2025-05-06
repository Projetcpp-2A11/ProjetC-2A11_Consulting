#include "mainwindow.h"
#include "employe.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "modelphotoemploye.h"
#include "arduino.h"
#include <QMessageBox>
#include <QSqlError>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRegularExpression>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QFile>
#include <QDir>
#include <QInputDialog>
#include <QBuffer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

QByteArray photoBuffer;
QString photoPath;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget_2->setCurrentIndex(0);
    activerOngletsSelonPoste("");

    int ret = A.connect_arduino(); // Lancer la connexion à l'Arduino
    switch (ret) {
    case 0:
        qDebug() << "Arduino is available and connected to :" << A.getarduino_port_name();
        break;
    case 1:
        qDebug() << "Arduino is available but not connected to :" << A.getarduino_port_name();
        break;
    case -1:
        qDebug() << "Arduino is not available";
        break;
    }

    // Connecter le signal "readyRead" du port série au slot "update_label"
    QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));
}

MainWindow::~MainWindow()
{

    delete ui;
}


// Function to add an employee
void MainWindow::on_ajouter_5_clicked()
{
    QString nom = ui->lineEdit_12->text();
    QString prenom = ui->lineEdit_17->text();
    QString email = ui->lineEdit_18->text();
    QString motDePasse = ui->lineEdit_19->text();
    QString telephone = ui->lineEdit_16->text();
    QString poste = ui->comboBox_3->currentText();
    QString dateDeNaissance = ui->dateEdit_3->date().toString("yyyy-MM-dd");


    QString imagePath = QFileDialog::getOpenFileName(this, tr("Choisir une photo"),
                                                     "", tr("Images (*.png *.jpg *.jpeg *.bmp)"));
    QByteArray photo;
    if (!imagePath.isEmpty()) {
        QFile file(imagePath);
        if (file.open(QIODevice::ReadOnly)) {
            photo = file.readAll();
            file.close();
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible de lire le fichier image !");
            return;
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Aucune image sélectionnée !");
        return;
    }

    // ✅ Vérification des champs
    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || motDePasse.isEmpty() || telephone.isEmpty() || poste.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Tous les champs doivent être remplis !"));
        return;
    }

    QRegularExpression emailRegex("[A-Za-z0-9]+@[A-Za-z0-9]+\\.[A-Za-z]{2,}");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, tr("Erreur"), tr("L'email n'est pas valide !"));
        return;
    }

    QRegularExpression phoneRegex("^[0-9\\+\\-\\s]+$");
    if (!phoneRegex.match(telephone).hasMatch()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Le numéro de téléphone n'est pas valide !"));
        return;
    }


    Employe E(nom, prenom, telephone, poste, email, motDePasse, dateDeNaissance, photo); // constructeur avec photo

    if (E.ajouter()) {
        ui->tab_emp_2->setModel(E.afficher());
        QMessageBox::information(this, tr("Succès"), tr("Ajout réussi !"));

        // Afficher la photo ajoutée
        QPixmap pixmap;
        pixmap.loadFromData(photo);
        ui->label_pic_2->setPixmap(pixmap.scaled(ui->label_pic_2->size(), Qt::KeepAspectRatio));

        // Nettoyer le formulaire
        ui->lineEdit_12->clear();
        ui->lineEdit_17->clear();
        ui->lineEdit_18->clear();
        ui->lineEdit_19->clear();
        ui->lineEdit_16->clear();
        ui->comboBox_3->setCurrentIndex(0);
        ui->dateEdit_3->clear();
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout a échoué !"));
    }
}


void MainWindow::on_tabWidget_5_currentChanged(int index)
{

        // 1. Charger le modèle de données
        QSqlQueryModel *model = E.afficher();
        if (!model) {
            qDebug() << "Erreur: Impossible de créer le modèle";
            return;
        }

        // 2. Appliquer le modèle à la table
        ui->tab_emp_2->setModel(model);

        // 3. Debug: Vérifier la structure des données
        qDebug() << "Nombre de colonnes:" << model->columnCount();
        for (int i = 0; i < model->columnCount(); ++i) {
            qDebug() << "Colonne" << i << ":" << model->headerData(i, Qt::Horizontal).toString();
        }

        // 4. Configurer l'affichage des photos
        const int photoColumn = 8;

        if (model->columnCount() > photoColumn) {
            // Nettoyer l'ancien delegate
            QAbstractItemDelegate *oldDelegate = ui->tab_emp_2->itemDelegateForColumn(photoColumn);
            if (oldDelegate) {
                oldDelegate->deleteLater();
            }

            // Appliquer le nouveau delegate
            ModelPhotoEmploye *photoDelegate = new ModelPhotoEmploye(this);
            ui->tab_emp_2->setItemDelegateForColumn(photoColumn, photoDelegate);

            // Configuration des dimensions
            ui->tab_emp_2->setColumnWidth(photoColumn, 150); // Largeur
            ui->tab_emp_2->verticalHeader()->setDefaultSectionSize(150); // Hauteur




            // Forcer le redessin de la table
            ui->tab_emp_2->viewport()->update();
        } else {
            qWarning() << "Avertissement: La colonne photo (index" << photoColumn << ") n'existe pas dans le modèle";
        }

        // 5. Optimisations supplémentaires
        ui->tab_emp_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tab_emp_2->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tab_emp_2->setAlternatingRowColors(true);
        ui->tab_emp_2->horizontalHeader()->setStretchLastSection(true);
        ui->tab_emp_2->setSortingEnabled(true);

}

void MainWindow::on_Supprimer_emp_2_clicked()
{
    bool test=E.supprimer(ui->tab_emp_2->currentIndex().model()->index(ui->tab_emp_2->currentIndex().row(),0,ui->tab_emp_2->currentIndex().parent()).data().toInt());
    if(test)
    {
        ui->tab_emp_2->setModel(E.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_modifier_6_clicked()
{
    ui->tabWidget_2->setCurrentIndex(2);
    E.SetDonnees((ui->tab_emp_2->currentIndex().model()->index(ui->tab_emp_2->currentIndex().row(),0,ui->tab_emp_2->currentIndex().parent()).data().toInt()));

    ui->lineEdit_20->setText(E.getNomEMP());
    ui->lineEdit_21->setText(E.getPrenomEMP());
    ui->lineEdit_24->setText(E.getEmail());
    ui->lineEdit_23->setText(E.getMotDePasse());
    ui->lineEdit_22->setText(E.getTelephone());
    ui->comboBox_4->setCurrentText(E.getPoste());
    ui->dateEdit_4->setDate(QDate::fromString(E.getDateDeNaissance(), "yyyy-MM-dd"));
    photoBuffer = E.getPhoto(); // ✅ récupération de l'image
}

void MainWindow::on_modifier_10_clicked()
{
    QString nom = ui->lineEdit_20->text();
    QString prenom = ui->lineEdit_21->text();
    QString email = ui->lineEdit_24->text();
    QString motDePasse = ui->lineEdit_23->text();
    QString telephone = ui->lineEdit_22->text();
    QString poste = ui->comboBox_4->currentText();
    QString dateDeNaissance = ui->dateEdit_4->date().toString("yyyy-MM-dd");

    Employe E(nom, prenom, telephone, poste, email, motDePasse, dateDeNaissance);
    E.setPhoto(photoBuffer); // ✅ mise à jour photo

    if(E.modifier((ui->tab_emp_2->currentIndex().model()->index(ui->tab_emp_2->currentIndex().row(),0,ui->tab_emp_2->currentIndex().parent()).data().toInt())))
    {
        ui->tab_emp_2->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_modifier_7_clicked()
{
    Employe e;
    QSqlQueryModel* model = E.trierPar("nom");
    if (model) {
        ui->tab_emp_2->setModel(model);
    }
}

void MainWindow::on_modifier_8_clicked()
{
    Employe e;
    QSqlQueryModel* model = E.trierPar("prenom");
    if (model) {
        ui->tab_emp_2->setModel(model);
    }
}

void MainWindow::on_modifier_9_clicked()
{
    QString nomRecherche = ui->lineEdit_9->text();
    Employe emp;
    QSqlQueryModel* model = E.rechercherParNom(nomRecherche);

    if (model) {
        ui->tab_emp_2->setModel(model);
    } else {
        QMessageBox::warning(this, "Recherche", "Aucun résultat trouvé ou erreur de recherche.");
    }
}

void MainWindow::on_login_3_clicked()
{
    QString email = ui->lineEdit_25->text();
    QString motdepasse = ui->lineEdit_26->text();

    if (email.isEmpty() || motdepasse.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
        return;
    }

    Login login(email, motdepasse);

    if (login.verifierIdentifiants()) {
        failedLoginAttempts = 0;
        QString poste = login.getPoste();
        activerOngletsSelonPoste(poste);
        QMessageBox::information(this, "Connexion réussie", "Bienvenue " + poste + " !");
    } else {
        failedLoginAttempts++;
        QMessageBox::critical(this, "Erreur", "Email ou mot de passe incorrect.");

        if (failedLoginAttempts >= 3) {
            int response = QMessageBox::question(
                this,
                tr("Mot de passe oublié ?"),
                tr("Vous avez échoué 3 fois.\nSouhaitez-vous réinitialiser votre mot de passe ?"),
                QMessageBox::Yes | QMessageBox::No
                );

            if (response == QMessageBox::Yes) {
                on_login_3_clicked();
            }

            failedLoginAttempts = 0;
        }
    }
}

void MainWindow::activerOngletsSelonPoste(const QString &poste)
{
    int totalTabs = ui->tabWidget_2->count();
    for (int i = 1; i < totalTabs; ++i) {
        ui->tabWidget_2->setTabEnabled(i, false);
    }

    if (poste == "Admin") {
        for (int i = 1; i < totalTabs; ++i) {
            ui->tabWidget_2->setTabEnabled(i, true);
        }
    }
    else if (poste == "Directeur") {
        ui->tabWidget_2->setTabEnabled(1, true);
        ui->tabWidget_2->setTabEnabled(2, true);
    }
    else if (poste == "RH") {
        ui->tabWidget_2->setTabEnabled(3, true);
        ui->tabWidget_2->setTabEnabled(5, true);
    }
}

bool MainWindow::isValidEmailAndTelephone(const QString& email, const QString& telephone)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE email = :email AND telephone = :telephone");
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);

    if (!query.exec()) {
        QMessageBox::critical(this, tr("Error"), tr("Database query failed!"));
        return false;
    }

    return query.next();
}

bool MainWindow::updatePasswordInDB(const QString& email, const QString& telephone, const QString& newmotDePasse)
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET MDPS = :motDePasse WHERE EMAIL = :email AND TELEPHONE = :telephone");
    query.bindValue(":motDePasse", newmotDePasse);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);

    if (!query.exec()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to update password in the database: %1").arg(query.lastError().text()));
        return false;
    }

    return true;
}

void MainWindow::on_login_4_clicked()
{
    bool ok;
    QString email = QInputDialog::getText(this, tr("Forgot Password"), tr("Enter your email:"), QLineEdit::Normal, "", &ok);
    if (ok && !email.isEmpty()) {
        QString telephone = QInputDialog::getText(this, tr("Forgot Password"), tr("Enter your telephone number:"), QLineEdit::Normal, "", &ok);

        if (ok && !telephone.isEmpty()) {
            if (isValidEmailAndTelephone(email, telephone)) {
                bool newPassOk;
                QString newmotDePasse = QInputDialog::getText(this, tr("Forgot Password"), tr("Enter new password:"), QLineEdit::Password, "", &newPassOk);

                if (newPassOk && !newmotDePasse.isEmpty()) {
                    if (updatePasswordInDB(email, telephone, newmotDePasse)) {
                        QMessageBox::information(this, tr("Success"), tr("Mot de passe mis à jour avec succès !"));
                    } else {
                        QMessageBox::critical(this, tr("Error"), tr("Échec de la mise à jour du mot de passe."));
                    }
                }
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Email ou numéro de téléphone invalide."));
            }
        }
    }
}



void MainWindow::on_pushButton_5_clicked()
{

        photoPath = QFileDialog::getOpenFileName(this, "Sélectionner une photo",
                                                 QDir::homePath(),
                                                 "Images (*.png *.jpg *.jpeg *.bmp)");

        if (!photoPath.isEmpty()) {
            QPixmap pixmap(photoPath);
            if (!pixmap.isNull()) {
                ui->label_pic_2->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
            } else {
                QMessageBox::warning(this, "Erreur", "Impossible de charger l'image");
            }
        }

}
void MainWindow::on_movementDetected() {
    // Demander l'email à l'utilisateur
    bool ok;
    QString email = QInputDialog::getText(this, "Demande d'email", "Veuillez entrer votre email:", QLineEdit::Normal, "", &ok);
    if (ok && !email.isEmpty()) {
        // Validation basique de l'email
        if (email.contains("@") && email.contains(".")) {
            // Envoie de l'email à Arduino
            arduino->write(email.toUtf8());
            // Attente de la réponse d'Arduino
            connect(arduino, &QSerialPort::readyRead, this, &MainWindow::readFromArduino);
        } else {
            QMessageBox::warning(this, "Email invalide", "L'email entré n'est pas valide.");
        }
    }
}

void MainWindow::readFromArduino() {
    QByteArray data = arduino->readAll();
    QString message = QString::fromUtf8(data);

    if (message.contains("MOTION_DETECTED")) {
        // Demander l'email lorsque le mouvement est détecté
        on_movementDetected();
    } else if (message.contains("ERROR:INVALID_EMAIL")) {
        QMessageBox::warning(this, "Erreur", "Email invalide.");
    } else if (message.contains("STATUS:OPENED")) {
        QMessageBox::information(this, "Porte ouverte", "La porte a été ouverte avec succès.");
    }
}
void MainWindow::update_label() {
    QByteArray data = A.read_from_arduino();
    QString message = QString::fromStdString(data.toStdString()).trimmed();

    qDebug() << "Message from Arduino:" << message;

    if (message.contains("EVENT:MOTION")) {
        qDebug() << "Mouvement détecté";
        askForEmailAndVerify();
    } else if (message.contains("STATUS:OPENED")) {
        QMessageBox::information(this, "Succès", "Porte ouverte avec succès!");
    } else if (message.contains("ERROR")) {
        QMessageBox::warning(this, "Erreur", message);
    }
}

void MainWindow::askForEmailAndVerify() {
    bool ok;
    QString email = QInputDialog::getText(this, "Vérification d'accès",
                                          "Mouvement détecté! Entrez votre email:",
                                          QLineEdit::Normal, "", &ok);

    if (ok && !email.isEmpty()) {
        // Vérifier si l'email existe dans la base de données
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE EMAIL = :email");
        query.bindValue(":email", email);

        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            if (count > 0) {
                // Email valide - envoyer à Arduino
                A.write_to_arduino(email.toUtf8() + '\n');
                QMessageBox::information(this, "Succès", "Email vérifié. Accès accordé.");
            } else {
                QMessageBox::warning(this, "Erreur", "Email non reconnu. Accès refusé.");
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur de base de données: " + query.lastError().text());
        }
    }
}




