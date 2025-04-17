#include "mainwindow.h"
#include "employe.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "modelphotoemploye.h"
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

// Attribut global pour stocker la photo temporairement
QByteArray photoBuffer;

// Constructor and Destructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
    activerOngletsSelonPoste("");
    //connect(ui->login_3, &QPushButton::clicked, this, &MainWindow::on_login_3_clicked);


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
    QString dateDeNaissance = ui->dateEdit->date().toString("yyyy-MM-dd");

    // 📷 Choix de la photo
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

    // 👨‍💼 Création de l'objet Employe avec photo
    Employe E(nom, prenom, telephone, poste, email, motDePasse, dateDeNaissance, photo); // constructeur avec photo

    if (E.ajouter()) {
        ui->tab_emp->setModel(E.afficher());
        QMessageBox::information(this, tr("Succès"), tr("Ajout réussi !"));

        // Afficher la photo ajoutée
        QPixmap pixmap;
        pixmap.loadFromData(photo);
        ui->label_pic->setPixmap(pixmap.scaled(ui->label_pic->size(), Qt::KeepAspectRatio));

        // Nettoyer le formulaire
        ui->lineEdit_3->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_4->clear();
        ui->comboBox->setCurrentIndex(0);
        ui->dateEdit->clear();
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout a échoué !"));
    }
}


void MainWindow::on_tabWidget_2_currentChanged(int index)
{

        // 1. Charger le modèle de données
        QSqlQueryModel *model = E.afficher();
        if (!model) {
            qDebug() << "Erreur: Impossible de créer le modèle";
            return;
        }

        // 2. Appliquer le modèle à la table
        ui->tab_emp->setModel(model);

        // 3. Debug: Vérifier la structure des données
        qDebug() << "Nombre de colonnes:" << model->columnCount();
        for (int i = 0; i < model->columnCount(); ++i) {
            qDebug() << "Colonne" << i << ":" << model->headerData(i, Qt::Horizontal).toString();
        }

        // 4. Configurer l'affichage des photos
        const int photoColumn = 8; // Ajustez selon votre structure de données

        if (model->columnCount() > photoColumn) {
            // Nettoyer l'ancien delegate
            QAbstractItemDelegate *oldDelegate = ui->tab_emp->itemDelegateForColumn(photoColumn);
            if (oldDelegate) {
                oldDelegate->deleteLater();
            }

            // Appliquer le nouveau delegate
            ModelPhotoEmploye *photoDelegate = new ModelPhotoEmploye(this);
            ui->tab_emp->setItemDelegateForColumn(photoColumn, photoDelegate);

            // Configuration des dimensions
            ui->tab_emp->setColumnWidth(photoColumn, 150); // Largeur
            ui->tab_emp->verticalHeader()->setDefaultSectionSize(150); // Hauteur




            // Forcer le redessin de la table
            ui->tab_emp->viewport()->update();
        } else {
            qWarning() << "Avertissement: La colonne photo (index" << photoColumn << ") n'existe pas dans le modèle";
        }

        // 5. Optimisations supplémentaires
        ui->tab_emp->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tab_emp->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tab_emp->setAlternatingRowColors(true);
        ui->tab_emp->horizontalHeader()->setStretchLastSection(true);
        ui->tab_emp->setSortingEnabled(true);

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
                              QObject::tr("Suppression non effectuée\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_modifier_2_clicked()
{
    ui->tabWidget_2->setCurrentIndex(2);
    E.SetDonnees((ui->tab_emp->currentIndex().model()->index(ui->tab_emp->currentIndex().row(),0,ui->tab_emp->currentIndex().parent()).data().toInt()));

    ui->lineEdit_10->setText(E.getNomEMP());
    ui->lineEdit_11->setText(E.getPrenomEMP());
    ui->lineEdit_14->setText(E.getEmail());
    ui->lineEdit_15->setText(E.getMotDePasse());
    ui->lineEdit_13->setText(E.getTelephone());
    ui->comboBox_2->setCurrentText(E.getPoste());
    ui->dateEdit->setDate(QDate::fromString(E.getDateDeNaissance(), "yyyy-MM-dd"));
    photoBuffer = E.getPhoto(); // ✅ récupération de l'image
}

void MainWindow::on_modifier_clicked()
{
    QString nom = ui->lineEdit_10->text();
    QString prenom = ui->lineEdit_11->text();
    QString email = ui->lineEdit_14->text();
    QString motDePasse = ui->lineEdit_15->text();
    QString telephone = ui->lineEdit_13->text();
    QString poste = ui->comboBox_2->currentText();
    QString dateDeNaissance = ui->dateEdit_2->date().toString("yyyy-MM-dd");

    Employe E(nom, prenom, telephone, poste, email, motDePasse, dateDeNaissance);
    E.setPhoto(photoBuffer); // ✅ mise à jour photo

    if(E.modifier((ui->tab_emp->currentIndex().model()->index(ui->tab_emp->currentIndex().row(),0,ui->tab_emp->currentIndex().parent()).data().toInt())))
    {
        ui->tab_emp->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_modifier_3_clicked()
{
    Employe e;
    QSqlQueryModel* model = E.trierPar("nom");
    if (model) {
        ui->tab_emp->setModel(model);
    }
}

void MainWindow::on_modifier_4_clicked()
{
    Employe e;
    QSqlQueryModel* model = E.trierPar("prenom");
    if (model) {
        ui->tab_emp->setModel(model);
    }
}

void MainWindow::on_modifier_5_clicked()
{
    QString nomRecherche = ui->lineEdit_5->text();
    Employe emp;
    QSqlQueryModel* model = E.rechercherParNom(nomRecherche);

    if (model) {
        ui->tab_emp->setModel(model);
    } else {
        QMessageBox::warning(this, "Recherche", "Aucun résultat trouvé ou erreur de recherche.");
    }
}

void MainWindow::on_login_clicked()
{
    QString email = ui->lineEdit->text();
    QString motdepasse = ui->lineEdit_2->text();

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
                on_login_2_clicked();
            }

            failedLoginAttempts = 0;
        }
    }
}

void MainWindow::activerOngletsSelonPoste(const QString &poste)
{
    int totalTabs = ui->tabWidget->count();
    for (int i = 1; i < totalTabs; ++i) {
        ui->tabWidget->setTabEnabled(i, false);
    }

    if (poste == "Admin") {
        for (int i = 1; i < totalTabs; ++i) {
            ui->tabWidget->setTabEnabled(i, true);
        }
    }
    else if (poste == "Directeur") {
        ui->tabWidget->setTabEnabled(1, true);
        ui->tabWidget->setTabEnabled(2, true);
    }
    else if (poste == "RH") {
        ui->tabWidget->setTabEnabled(3, true);
        ui->tabWidget->setTabEnabled(5, true);
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

void MainWindow::on_login_2_clicked()
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



void MainWindow::on_pushButton_clicked()
{

        photoPath = QFileDialog::getOpenFileName(this, "Sélectionner une photo",
                                                 QDir::homePath(),
                                                 "Images (*.png *.jpg *.jpeg *.bmp)");

        if (!photoPath.isEmpty()) {
            QPixmap pixmap(photoPath);
            if (!pixmap.isNull()) {
                ui->label_pic->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
            } else {
                QMessageBox::warning(this, "Erreur", "Impossible de charger l'image");
            }
        }

}





