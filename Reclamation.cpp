#include "Reclamation.h"
#include "stmpclient.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QMap>
#include <QVBoxLayout>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>





// Method to add a new reclamation
bool Reclamation::ajouter() {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Base de données non ouverte !";
        return false;
    }

    QSqlQuery query;
    QString sql = "INSERT INTO reclamation (nom, sujet, description, datee, status, email) "
                  "VALUES (:nom, :sujet, :description, TO_TIMESTAMP(:datee, 'YYYY-MM-DD HH24:MI:SS'), :status, :email)";
    query.prepare(sql);
    query.bindValue(":nom", nom);
    //query.bindValue(":idclient", idclient);
    query.bindValue(":sujet", sujet);
    query.bindValue(":description", description);
    query.bindValue(":datee", datee); // e.g., "2025-04-09 12:00:00"
    //query.bindValue(":status", status);
    QString categorie = classerParMotCle();
    query.bindValue(":status", categorie);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << " Erreur SQL:" << query.lastError().text();
        qDebug() << " Requête:" << sql;
        return false;
    }

    qDebug() << " Réclamation ajoutée avec succès.";
    return true;
}

// Method to display reclamations
QSqlQueryModel* Reclamation::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_RECLAMATION, NOM, SUJET, DESCRIPTION, STATUS, DATEE, EMAIL FROM RECLAMATION");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Sujet"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Status"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

// Method to delete a reclamation by ID
bool Reclamation::supprimer(int id_reclamation) {
    QSqlQuery query;
    query.prepare("DELETE FROM RECLAMATION WHERE ID_RECLAMATION = :id_reclamation");
    query.bindValue(":id_reclamation", id_reclamation);

    if (!query.exec()) {
        qDebug() << "Error deleting reclamation:" << query.lastError().text();
        return false;
    }

    qDebug() << "Reclamation with ID_RECLAMATION" << id_reclamation << "deleted successfully!";
    return true;
}

// Method to sort reclamations
QSqlQueryModel* Reclamation::trier(QString column, QString order) {
    QSqlQueryModel* model = new QSqlQueryModel;
    QString queryStr;

    // Vérification de l'option du comboBox
    QString ordreTri = (order == "ASC" || order == "DESC") ? order : "ASC";  // Si l'option n'est pas valide, on met par défaut "ASC"

    // Vérification du critère de tri
    if (column == "id" || column == "ID_REC") {
        // Tri par ID_RECLAMATION en fonction de l'ordre choisi
        queryStr = QString("SELECT * FROM RECLAMATION ORDER BY ID_RECLAMATION %1").arg(ordreTri);
    } else {
        qDebug() << "Critère de tri invalide :" << column;
        delete model;
        return nullptr;
    }

    model->setQuery(queryStr);

    // Vérification des erreurs SQL
    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL lors du tri :" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}


// Method to modify a reclamation
bool Reclamation::modifier(int id_reclamation)
{

        QSqlQuery query;
        query.prepare("UPDATE RECLAMATION SET "
                      "NOM = :NOM, "
                      "SUJET = :SUJET, "
                      "DESCRIPTION = :DESCRIPTION, "
                      "DATEE = TO_DATE(:DATEE, 'YYYY-MM-DD HH24:MI:SS'), "
                      "STATUS = :STATUS, "
                      "EMAIL = :EMAIL "
                      "WHERE ID_RECLAMATION = :ID_RECLAMATION");

        query.bindValue(":ID_RECLAMATION", id_reclamation);
        query.bindValue(":NOM", nom);
        query.bindValue(":SUJET", sujet);
        query.bindValue(":DESCRIPTION", description);

        // Formatage correct de la date/heure
        //QString datee = datee.toString("yyyy-MM-dd HH:mm:ss");
        query.bindValue(":DATEE", datee);

        query.bindValue(":STATUS", status);
        query.bindValue(":EMAIL", email);

        if (!query.exec()) {
            qDebug() << "Erreur lors de la modification de la réclamation :" << query.lastError().text();
            return false;
        }

        return true;


}

// Method to load a reclamation by ID
bool Reclamation::loadById(int id_reclamation)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM RECLAMATION WHERE ID_RECLAMATION = :id_reclamation");
    query.bindValue(":id_reclamation", id_reclamation);

    // Execute the query and load the result into the object's properties
    if (query.exec() && query.next()) {
        setNom(query.value("NOM").toString());
        //setIdClient(query.value("IDCLIENT").toString());
        setSujet(query.value("SUJET").toString());
        setDescription(query.value("DESCRIPTION").toString());
        setDatee(query.value("DATEE").toString());  // Ensure the format matches "YYYY-MM-DD HH:mm:ss"
        setStatus(query.value("STATUS").toString());
        setEmail(query.value("EMAIL").toString());
        return true;
    }
    return false;
}

QString Reclamation::classerParMotCle() {
    QMap<QStringList, QString> motsClesAvances;
    motsClesAvances[{"retard", "en retard", "délai"}] = "Délai de traitement";
    motsClesAvances[{"facture", "facturation", "montant"}] = "Problème de facturation";
    motsClesAvances[{"panne", "hors service", "ne marche pas"}] = "Problème technique";
    motsClesAvances[{"erreur", "bug", "anomalie"}] = "Erreur système";
    motsClesAvances[{"remboursement", "rembourser", "crédit"}] = "Problème de remboursement";
    motsClesAvances[{"annulation", "annuler"}] = "Demande d'annulation";

    QMap<QString, int> scoreParCategorie;

    for (auto it = motsClesAvances.begin(); it != motsClesAvances.end(); ++it) {
        for (const QString& mot : it.key()) {
            if (description.contains(mot, Qt::CaseInsensitive)) {
                scoreParCategorie[it.value()]++;
            }
        }
    }

    if (!scoreParCategorie.isEmpty()) {
        auto it = std::max_element(scoreParCategorie.begin(), scoreParCategorie.end(),
                                   [](const int& a, const int& b) { return a < b; });
        return it.key(); // catégorie avec le score le plus élevé
    }

    return "Autre";
}

// Méthode pour envoyer un email de confirmation
bool Reclamation::envoyerEmailConfirmation(const QString &destinataire) {
    // Crée une instance de SmtpClient
    SmtpClient *smtp = new SmtpClient();

    // Configuration du serveur SMTP (à adapter selon votre fournisseur email)
    QString smtpServer = "smtp.gmail.com";  // Exemple avec Gmail
    int port = 465;  // Port SSL standard pour Gmail
    QString username = "votre_email@gmail.com";  // À remplacer par votre email
    QString password = "votre_mot_de_passe";     // À remplacer par votre mot de passe d'application

    // Création du contenu de l'email
    QString from = username;  // Généralement, le même que l'adresse d'authentification
    QString to = destinataire;
    QString subject = "Confirmation de votre réclamation";

    // Construction du corps HTML de l'email
    QString body = "<html><body>";


    // Envoi de l'email
    bool sent = smtp->sendMail(from, to, subject, body, smtpServer, port, username, password);

    // Journalisation du résultat
    if (sent) {
        qDebug() << "Email de confirmation envoyé avec succès à" << destinataire;
    } else {
        qDebug() << "Échec de l'envoi de l'email à" << destinataire;
    }

    // Nettoyage
    delete smtp;

    return sent;
}
void Reclamation::afficherStatistiques()
{
    QMap<QString, int> stats;

    QSqlQuery query("SELECT status FROM Reclamation");
    while (query.next()) {
        QString status = query.value(0).toString();
        stats[status]++;
    }

    if (stats.isEmpty()) {
        QMessageBox::information(nullptr, "Statistiques", "Aucune donnée à afficher.");
        return;
    }

    QPieSeries* series = new QPieSeries();
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        series->append(it.key(), it.value());
    }

    QPieSlice* biggest = nullptr;
    int maxVal = 0;
    for (QPieSlice* slice : series->slices()) {
        if (slice->value() > maxVal) {
            maxVal = slice->value();
            biggest = slice;
        }
        slice->setLabel(QString("%1 (%2)").arg(slice->label()).arg((int)slice->value()));
        slice->setLabelVisible(true);
    }

    if (biggest) {
        biggest->setExploded(true);
        biggest->setPen(QPen(Qt::black, 2));
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des réclamations par statut");
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setBackgroundBrush(QBrush(QColor(213, 241, 240)));

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog* dialog = new QDialog();
    dialog->setWindowTitle("Statistiques");
    dialog->resize(600, 400);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->exec();

}

void Reclamation::SetDonnees(int id_reclamation)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM RECLAMATION WHERE ID_RECLAMATION = :id_reclamation");
    query.bindValue(":id_reclamation", id_reclamation);

    if (query.exec() && query.next()) {
       // this->id_reclamation = query.value("ID_RECLAMATION").toInt();
        this->nom = query.value("NOM").toString();
        this->sujet = query.value("SUJET").toString();
        this->description = query.value("DESCRIPTION").toString();
        this->datee = query.value("DATEE").toDateTime().toString("yyyy-MM-dd HH:mm:ss"); // ou toString() selon ton format
        this->status = query.value("STATUS").toString();
        this->email = query.value("EMAIL").toString();
    } else {
        qDebug() << "Erreur lors du chargement de la réclamation : " << query.lastError().text();
    }
}

