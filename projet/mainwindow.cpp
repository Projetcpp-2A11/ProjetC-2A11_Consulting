#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "todo.h"
#include <QSerialPort>
#include "connection.h"
#include "consult.h"
#include <QSqlQuery>
#include <QDebug>
#include <QTextDocument>
#include <QDir>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPageSize>
#include <QMarginsF>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialiserOngletToDo();
    initializeChatBot();
    QTimer::singleShot(1000, this, &MainWindow::checkArduinoConnection);
    // Connection des signals avec les slots
    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_ajouter_clicked);
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::on_supp_clicked);
    connect(ui->mod, &QPushButton::clicked, this, &MainWindow::on_modifications_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);
    connect(ui->search_s, &QPushButton::clicked, this, &MainWindow::on_search_s_clicked);
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_tri_currentIndexChanged);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
    connect(ui->reset, &QPushButton::clicked, this, &MainWindow::on_reset_clicked);


    // arduino initialization
    arduino = new QSerialPort(this);
    arduino_is_available = false;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        // Check if the serial port has both a vendor and product ID
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            // Here you should check against your specific Arduino's vendor and product IDs
            // For example, for an Arduino Uno:
            // if(serialPortInfo.vendorIdentifier() == 0x2341 && serialPortInfo.productIdentifier() == 0x0043)
            arduino_is_available = true;
            arduino->setPortName(serialPortInfo.portName());
        }
    }

    if(arduino_is_available) {
        if(arduino->open(QSerialPort::ReadWrite)) {
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
        } else {
            QMessageBox::warning(this, "Port error", "Couldn't open serial port!");
            arduino_is_available = false;
        }
    } else {
        QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
    }
    // fin arduino

    // fin arduino
    setupTable();
    populateTable();
    
    // Initialize chart views on null valeur
    expChartView = nullptr;
    dispChartView = nullptr;
    
    // ta5lik tbadel fi table
    ui->tableau->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
}

MainWindow::~MainWindow()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}

void MainWindow::setupTable()
{
    ui->tableau->setColumnCount(8);
    
    QStringList headers = {"ID", "Nom", "Prénom", "Email", "Téléphone", "Spécialisation", "Expérience", "Disponible"};
    ui->tableau->setHorizontalHeaderLabels(headers);
    
    ui->tableau->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::populateTable()
{
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

void MainWindow::initCharts()
{
    if (expChartView && dispChartView) {
        return;
    }


    QWidget *chartsContainer = new QWidget(ui->tab_3);
    QVBoxLayout *chartsLayout = new QVBoxLayout(chartsContainer);


    expChartView = new QChartView();
    expChartView->setRenderHint(QPainter::Antialiasing);
    chartsLayout->addWidget(expChartView);


    dispChartView = new QChartView();
    dispChartView->setRenderHint(QPainter::Antialiasing);
    chartsLayout->addWidget(dispChartView);

    ui->tab_3->setLayout(new QVBoxLayout());
    ui->tab_3->layout()->addWidget(chartsContainer);
}

void MainWindow::updateStats()
{
    QSqlQuery query;


    QPieSeries *expSeries = new QPieSeries();
    query.exec("SELECT EXPERIENCE, COUNT(*) FROM CONSULTANT GROUP BY EXPERIENCE");
    while (query.next()) {
        expSeries->append(query.value(0).toString(), query.value(1).toInt());
    }

    QChart *expChart = new QChart();
    expChart->addSeries(expSeries);
    expChart->setTitle("Répartition par Expérience");
    expChart->legend()->setVisible(true);
    expChart->legend()->setAlignment(Qt::AlignBottom);
    expSeries->setLabelsVisible();
    expChartView->setChart(expChart);


    QBarSeries *dispSeries = new QBarSeries();
    QBarSet *set = new QBarSet("Disponibilité");

    int ouiCount = 0, nonCount = 0;
    query.exec("SELECT DISPONIBILITE, COUNT(*) FROM CONSULTANT GROUP BY DISPONIBILITE");
    while (query.next()) {
        if (query.value(0).toString() == "Oui") ouiCount = query.value(1).toInt();
        else nonCount = query.value(1).toInt();
    }

    *set << ouiCount << nonCount;
    dispSeries->append(set);

    QChart *dispChart = new QChart();
    dispChart->addSeries(dispSeries);
    dispChart->setTitle("Disponibilité");
    dispChart->legend()->setVisible(true);
    dispChart->legend()->setAlignment(Qt::AlignBottom);

    // X-axis
    QStringList categories {"Oui", "Non"};
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    dispChart->addAxis(axisX, Qt::AlignBottom);
    dispSeries->attachAxis(axisX);

    // Y-axis
    QValueAxis *axisY = new QValueAxis();
    dispChart->addAxis(axisY, Qt::AlignLeft);
    dispSeries->attachAxis(axisY);

    dispChartView->setChart(dispChart);
}

void MainWindow::onTabChanged(int index)
{
    if (index == 1) { // "Liste Des Consultants" tab
        populateTable();
    }
    else if (index == 2) { // "Les Statistiques" tab
        initCharts();
        updateStats();
    }
}

void MainWindow::on_ajouter_clicked()
{
    QSqlQuery query;

    Consultant consultant(
        ui->nom->text(),
        ui->prenom->text(),
        ui->email->text(),
        ui->tele->text().toInt(),
        ui->spec->text(),
        ui->list->currentText(),
        ui->oui->isChecked() ? "Oui" : "Non",
        query
        );


    if (consultant.insertIntoDatabase(query)) {
        QMessageBox::information(this, "Succès", "Consultant ajouté avec succès!");

        // tfasa5 les fileds b3d addition
        ui->nom->clear();
        ui->prenom->clear();
        ui->email->clear();
        ui->tele->clear();
        ui->spec->clear();
        ui->list->setCurrentIndex(0);
        ui->oui->setChecked(false);
        ui->non->setChecked(false);
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout du consultant.");
    }
}

void MainWindow::on_supp_clicked()
{
    int id = ui->id_supp->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    QSqlQuery query;
    if (Consultant::deleteById(id, query)) {
        QMessageBox::information(this, "Succès", "Consultant supprimé avec succès!");
        ui->id_supp->clear();
        populateTable(); // Refresh the table
    } else {
        QMessageBox::warning(this, "Erreur", "Ce Consultant n'existe pas!");
    }
}

void MainWindow::on_modifications_clicked()
{
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
        QMessageBox::information(this, "Succès", "Modification réussite!");
    } else {
        QMessageBox::warning(this, "Erreur", "Aucune Modification détectée.");
    }
}

void MainWindow::on_pdf_clicked()
{
    // Fetch data
    QSqlQuery query;
    QList<Consultant> consultants = Consultant::fetchAllConsultants(query);

    // Create HTML content
    QString html;
    html += "<h1 style='text-align:center'>Liste de tous les Consultants :</h1>";
    html += "<table border='1' style='width:100%; border-collapse:collapse'>"
            "<tr>"
            "<th>ID</th><th>Nom</th><th>Prénom</th><th>Email</th>"
            "<th>Téléphone</th><th>Spécialisation</th><th>Expérience</th><th>Disponibilité</th>"
            "</tr>";

    foreach (const Consultant &c, consultants) {
        html += QString("<tr>"
                        "<td>%1</td><td>%2</td><td>%3</td><td>%4</td>"
                        "<td>%5</td><td>%6</td><td>%7</td><td>%8</td>"
                        "</tr>")
                    .arg(c.getIdCon())
                    .arg(c.getNomCon())
                    .arg(c.getPrenomCon())
                    .arg(c.getEmailCon())
                    .arg(c.getTelCon())
                    .arg(c.getSpecialisation())
                    .arg(c.getExperience())
                    .arg(c.getDisponibilite());
    }
    html += "</table>";

    // creation d' un Doc
    QTextDocument document;
    document.setHtml(html);

    // Verifer le directoire existe
    QDir().mkpath("Documents_consultant");
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("Documents_consultant/Doc.pdf");
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    // Generatopn de PDF
    document.print(&printer);
    QMessageBox::information(this, "Succès", "PDF généré dans Documents_consultant/Doc.pdf");
}

void MainWindow::on_search_s_clicked()
{
    QString searchTerm = ui->search->text().trimmed();

    if (searchTerm.isEmpty()) {
        populateTable();
        return;
    }

    // Clear the table
    ui->tableau->setRowCount(0);
    originalValues.clear();

    QSqlQuery query;
    QList<Consultant> consultants = Consultant::fetchAllConsultants(query);

    for (const Consultant &consultant : consultants) {
        if (consultant.getNomCon().contains(searchTerm, Qt::CaseInsensitive)) {
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

    if (ui->tableau->rowCount() == 0) {
        QMessageBox::information(this, "Recherche", "Aucun consultant trouvé avec ce nom.");
    }
}

void MainWindow::on_tri_currentIndexChanged(int index)
{
    int columnToSort = -1;
    Qt::SortOrder order = Qt::AscendingOrder;

    switch(index) {
    case 1: // "Nom"
        columnToSort = 1;
        break;
    case 2: // "Spécialisation"
        columnToSort = 5;
        break;
    default:
        return;
    }

    ui->tableau->sortItems(columnToSort, order);
}

void MainWindow::on_reset_clicked()
{

    ui->nom->clear();
    ui->prenom->clear();
    ui->email->clear();
    ui->tele->clear();
    ui->spec->clear();
    ui->histo->clear();
    ui->eval->clear();

    ui->list->setCurrentIndex(0);


    ui->oui->setAutoExclusive(false);
    ui->non->setAutoExclusive(false);
    ui->oui->setChecked(false);
    ui->non->setChecked(false);
    ui->oui->setAutoExclusive(true);
    ui->non->setAutoExclusive(true);
}


void MainWindow::initialiserOngletToDo() {
    QWidget *widgetToDo = ui->tab_4;
    QVBoxLayout *layoutPrincipal = new QVBoxLayout(widgetToDo);

    // Title
    QLabel *titre = new QLabel("Liste des Tâches à Faire");
    titre->setStyleSheet("QLabel { color: #4D6F50; font-size: 20px; font-weight: bold; }");
    titre->setAlignment(Qt::AlignCenter);
    layoutPrincipal->addWidget(titre);

    // Input area
    QWidget *zoneSaisie = new QWidget();
    QHBoxLayout *layoutSaisie = new QHBoxLayout(zoneSaisie);

    QLabel *labelId = new QLabel("ID Consultant:");
    labelId->setStyleSheet("color: #4D6F50; font-weight: bold;");
    inputIdConsultant = new QLineEdit();
    inputIdConsultant->setPlaceholderText("Entrez l'ID du consultant");
    inputIdConsultant->setStyleSheet("QLineEdit { border: 2px solid #4D6F50; border-radius: 5px; padding: 5px; }");

    QLabel *labelTache = new QLabel("Tâche:");
    labelTache->setStyleSheet("color: #4D6F50; font-weight: bold;");
    inputTache = new QLineEdit();
    inputTache->setPlaceholderText("Entrez la tâche à ajouter");
    inputTache->setStyleSheet("QLineEdit { border: 2px solid #4D6F50; border-radius: 5px; padding: 5px; }");

    layoutSaisie->addWidget(labelId);
    layoutSaisie->addWidget(inputIdConsultant);
    layoutSaisie->addWidget(labelTache);
    layoutSaisie->addWidget(inputTache);
    layoutSaisie->setStretch(1, 2);
    layoutSaisie->setStretch(3, 3);

    // Buttons area
    QWidget *zoneBoutons = new QWidget();
    QHBoxLayout *layoutBoutons = new QHBoxLayout(zoneBoutons);

    boutonAjouter = new QPushButton("Ajouter Tâche");
    boutonSupprimer = new QPushButton("Supprimer Tâche");
    boutonRafraichir = new QPushButton("Rafraîchir Liste");

    // Style buttons to match your existing design
    QString styleBouton = "QPushButton {"
                          "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,"
                          "stop:0 rgba(193, 179, 255, 200), stop:1 rgba(255, 228, 196, 200));"
                          "color: #4A4A4A; border-radius: 10px; border: 1px solid rgba(74, 74, 74, 50);"
                          "padding: 8px 15px; font-size: 14px; font-weight: bold; }"
                          "QPushButton:hover {"
                          "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,"
                          "stop:0 rgba(170, 153, 255, 200), stop:1 rgba(255, 204, 153, 200));"
                          "color: black; }"
                          "QPushButton:pressed { background: rgba(193, 179, 255, 180); }";

    boutonAjouter->setStyleSheet(styleBouton);
    boutonSupprimer->setStyleSheet(styleBouton);
    boutonRafraichir->setStyleSheet(styleBouton);

    layoutBoutons->addWidget(boutonAjouter);
    layoutBoutons->addWidget(boutonSupprimer);
    layoutBoutons->addWidget(boutonRafraichir);

    // Task list
    listeTaches = new QListWidget();
    listeTaches->setStyleSheet("QListWidget { border: 2px solid #4D6F50; border-radius: 5px; }"
                               "QListWidget::item { padding: 5px; border-bottom: 1px solid #E0E0E0; }"
                               "QListWidget::item:hover { background-color: #E8F5E9; }");

    // Add widgets to main layout
    layoutPrincipal->addWidget(zoneSaisie);
    layoutPrincipal->addWidget(zoneBoutons);
    layoutPrincipal->addWidget(listeTaches);

    // Connect signals
    connect(boutonAjouter, &QPushButton::clicked, this, &MainWindow::on_ajouterTache_clicked);
    connect(boutonSupprimer, &QPushButton::clicked, this, &MainWindow::on_supprimerTache_clicked);
    connect(boutonRafraichir, &QPushButton::clicked, this, &MainWindow::on_rafraichirListe_clicked);

    // Load initial tasks
    chargerListeTaches();
}




void MainWindow::chargerListeTaches() {
    listeTaches->clear();

    QSqlQuery query;
    QList<QPair<int, QString>> taches = ToDo::recupererTousLesTaches(query);

    for (const auto &tache : taches) {
        QString itemText = QString("Consultant ID: %1 - Tâche: %2").arg(tache.first).arg(tache.second);
        QListWidgetItem *item = new QListWidgetItem(itemText, listeTaches);
        item->setData(Qt::UserRole, QVariant::fromValue(tache));
    }
}

void MainWindow::on_ajouterTache_clicked() {
    QString tache = inputTache->text().trimmed();
    bool ok;
    int idConsultant = inputIdConsultant->text().toInt(&ok);

    if (!ok || idConsultant <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    if (tache.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une tâche.");
        return;
    }

    QSqlQuery query;
    if (!ToDo::verifierIdExiste(idConsultant, query)) {
        QMessageBox::warning(this, "Erreur", "Identifiant n'existe pas");
        return;
    }

    if (ToDo::ajouterTache(idConsultant, tache, query)) {
        QMessageBox::information(this, "Succès", "Tâche ajoutée avec succès!");
        inputTache->clear();
        chargerListeTaches();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout de la tâche.");
    }
}

void MainWindow::on_supprimerTache_clicked() {
    QListWidgetItem *itemSelectionne = listeTaches->currentItem();

    if (!itemSelectionne) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une tâche à supprimer.");
        return;
    }

    QPair<int, QString> tache = itemSelectionne->data(Qt::UserRole).value<QPair<int, QString>>();

    QSqlQuery query;
    if (ToDo::supprimerTache(tache.first, tache.second, query)) {
        QMessageBox::information(this, "Succès", "Tâche supprimée avec succès!");
        chargerListeTaches();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression de la tâche.");
    }
}

void MainWindow::on_rafraichirListe_clicked() {
    chargerListeTaches();
}
void MainWindow::initializeChatBot()
{
    QWidget *chatWidget = ui->tab_5;
    QVBoxLayout *mainLayout = new QVBoxLayout(chatWidget);

    // Chat History
    chatHistory = new QListWidget();
    chatHistory->setStyleSheet(
        "QListWidget {"
        "   background-color: #f0f4f8;"
        "   border-radius: 15px;"
        "   padding: 10px;"
        "}"
        "QListWidget::item {"
        "   background-color: #ffffff;"
        "   border-radius: 10px;"
        "   margin: 5px;"
        "   padding: 10px;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: #e3f2fd;"
        "}"
        );
    chatHistory->setWordWrap(true);
    chatHistory->setSpacing(5);

    // Input Area
    QWidget *inputWidget = new QWidget();
    QHBoxLayout *inputLayout = new QHBoxLayout(inputWidget);

    messageInput = new QLineEdit();
    messageInput->setPlaceholderText("taper ton message ici...");
    messageInput->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid #4D6F50;"
        "   border-radius: 15px;"
        "   padding: 10px 15px;"
        "   font-size: 14px;"
        "}"
        "QLineEdit:focus {"
        "   border-color: #6A9E70;"
        "}"
        );

    sendButton = new QPushButton("Envoyer!");
    sendButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #4D6F50;"
        "   color: white;"
        "   border-radius: 15px;"
        "   padding: 10px 20px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #6A8A63;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #3B5D40;"
        "}"
        );
    sendButton->setCursor(Qt::PointingHandCursor);

    inputLayout->addWidget(messageInput);
    inputLayout->addWidget(sendButton);
    inputLayout->setStretch(0, 5);
    inputLayout->setStretch(1, 1);

    // Add welcome message
    QListWidgetItem *welcomeItem = new QListWidgetItem("🤖 Bienvenue dans le ConsultantBot! comment je peux aider ?");
    welcomeItem->setTextAlignment(Qt::AlignLeft);
    chatHistory->addItem(welcomeItem);

    mainLayout->addWidget(chatHistory);
    mainLayout->addWidget(inputWidget);

    // Connect signals
    connect(sendButton, &QPushButton::clicked, this, &MainWindow::onSendMessage);
    connect(messageInput, &QLineEdit::returnPressed, this, &MainWindow::onSendMessage);
}

void MainWindow::onSendMessage()
{
    QString message = messageInput->text().trimmed();
    if(message.isEmpty()) return;

    // Add user message
    QListWidgetItem *userItem = new QListWidgetItem("👤 " + message);
    userItem->setTextAlignment(Qt::AlignRight);
    userItem->setForeground(QColor("#2c3e50"));
    chatHistory->addItem(userItem);

    // Clear input
    messageInput->clear();

    // Simulate bot response
    QTimer::singleShot(500, this, [this, message]() {
        handleBotResponse(message);
    });
}






void MainWindow::handleBotResponse(const QString &userMessage)
{
    QString response = "🤖 Je suis un chatbot basique. Voici les commandes que je comprends :\n"
                       "- 'help' - Afficher l'aide\n"
                       "- 'about' - À propos du logiciel\n"
                       "- 'contact' - Informations de contact\n"
                       "- 'commands' - Lister les commandes disponibles";

    QString lowerMsg = userMessage.toLower();

    if(lowerMsg == "help") {
        response = "🤖 Vous pouvez me demander :\n- Gestion des consultants\n- Suivi des tâches\n- Génération de rapports\n- Informations système";
    }
    else if(lowerMsg == "about") {
        response = "🤖 Système de Gestion de Consultants v1.0\nDéveloppé avec Qt/C++\n© 2024 STRATEDGE";
    }
    else if(lowerMsg == "contact") {
        response = "🤖 Contactez-nous :\nsupport@STRATEDDGE.com\n+216 70-567-890";
    }
    else if(lowerMsg == "commands") {
        response = "🤖 Commandes disponibles :\n- help\n- about\n- contact\n- commands\n- clear";
    }
    else if(lowerMsg == "clear") {
        chatHistory->clear();
        QListWidgetItem *welcomeItem = new QListWidgetItem("🤖 Historique effacé !");
        chatHistory->addItem(welcomeItem);
        return;
    }

    QListWidgetItem *botItem = new QListWidgetItem(response);
    botItem->setForeground(QColor("#4D6F50"));
    chatHistory->addItem(botItem);
    chatHistory->scrollToBottom();
}



            // arduinoooo


void MainWindow::on_connectButton_clicked()
{
    checkArduinoConnection();
}



void MainWindow::showConnectionStatus(bool connected)
{
    if(connected) {
        QMessageBox::information(this, "Connection Status",
                                 "Arduino is connected and responding!");
    } else {
        QMessageBox::critical(this, "Connection Status",
                              "Arduino is not connected or not responding!");
    }
}

void MainWindow::checkArduinoConnection()
{
    if(arduino_is_available && arduino->isOpen()) {
        arduino->write("C"); // Send test command

        if(arduino->waitForReadyRead(1000)) { // Wait 1 second for response
            QByteArray response = arduino->readAll();
            while(arduino->waitForReadyRead(10)) {
                response += arduino->readAll();
            }

            if(response.contains('A')) {
                qDebug() << "SUCCESS: Arduino is connected and responding!";
                showConnectionStatus(true);
                return;
            }
        }
    }

    qDebug() << "ERROR: Arduino not connected or not responding!";
    showConnectionStatus(false);
}

