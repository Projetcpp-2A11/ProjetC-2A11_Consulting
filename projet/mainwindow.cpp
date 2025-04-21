#include "consult.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "todo.h"
#include "connection.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialiserOngletToDo();
    initializeChatBot();
    QTimer::singleShot(1000, this, &MainWindow::checkArduinoConnection);
    ollamaProcess = new QProcess(this);
    startOllamaServer();
    networkManager = new QNetworkAccessManager(this);
    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_ajouter_clicked);
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::on_supp_clicked);
    connect(ui->mod, &QPushButton::clicked, this, &MainWindow::on_modifications_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);
    connect(ui->search_s, &QPushButton::clicked, this, &MainWindow::on_search_s_clicked);
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_tri_currentIndexChanged);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
    connect(ui->reset, &QPushButton::clicked, this, &MainWindow::on_reset_clicked);
    connect(ui->reset_table, &QPushButton::clicked, this, &MainWindow::on_reset_table_clicked);

    // arduino initialization
    arduino = new QSerialPort(this);
    arduino_is_available = false;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {

        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
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
        //QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
    }

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
    stopOllamaServer();
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


void MainWindow::startOllamaServer()
{
    // For Windows, we need to run this through cmd.exe
    ollamaProcess->start("cmd.exe", QStringList() << "/C" << "ollama serve");

    if (!ollamaProcess->waitForStarted(3000)) {
        qDebug() << "Failed to start Ollama server";
        QMessageBox::warning(this, "Warning", "Could not start Ollama server automatically. Please start it manually.");
    } else {
        qDebug() << "Ollama server started successfully";


        connect(ollamaProcess, &QProcess::readyReadStandardOutput, [this](){
            qDebug() << "Ollama:" << ollamaProcess->readAllStandardOutput();
        });
        connect(ollamaProcess, &QProcess::readyReadStandardError, [this](){
            qDebug() << "Ollama Error:" << ollamaProcess->readAllStandardError();
        });
    }
}

void MainWindow::stopOllamaServer()
{
    if (ollamaProcess && ollamaProcess->state() == QProcess::Running) {

        ollamaProcess->terminate();

        if (!ollamaProcess->waitForFinished(3000)) {

            ollamaProcess->kill();
            qDebug() << "Ollama server was force stopped";
        } else {
            qDebug() << "Ollama server stopped gracefully";
        }
    }
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


    QListWidgetItem *welcomeItem = new QListWidgetItem("🤖 Bienvenue dans le ConsultantBot! comment je peux aider ?");
    welcomeItem->setTextAlignment(Qt::AlignLeft);
    chatHistory->addItem(welcomeItem);

    mainLayout->addWidget(chatHistory);
    mainLayout->addWidget(inputWidget);


    connect(sendButton, &QPushButton::clicked, this, &MainWindow::onSendMessage);
    connect(messageInput, &QLineEdit::returnPressed, this, &MainWindow::onSendMessage);
}




void MainWindow::on_pdf_clicked()
{

    QSqlQuery query;
    QList<Consultant> consultants = Consultant::fetchAllConsultants(query);

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

    QTextDocument document;
    document.setHtml(html);


    QDir().mkpath("Documents_consultant");
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("Documents_consultant/Doc.pdf");
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    // Generatopn de PDF
    document.print(&printer);
    QMessageBox::information(this, "Succès", "PDF généré avec Succés dans Documents_consultant/Doc.pdf");
}


void MainWindow::on_reset_table_clicked()
{

    ui->search->clear();


    ui->tri->setCurrentIndex(0);

    populateTable();

    //QMessageBox::information(this, "Réinitialisation", "La table a été réinitialisée à son ordre original.");
}







QMap<QString, QString> MainWindow::getFirstConsultant() {
    QSqlQuery query;
    QMap<QString, QString> consultant;

    query.exec("SELECT NOM_CON, PRENOM_CON, DISPONIBILITE FROM CONSULTANT ORDER BY ID_CON ASC LIMIT 1");
    if (query.next()) {
        consultant["nom"] = query.value(0).toString();
        consultant["prenom"] = query.value(1).toString();
        consultant["disponibilite"] = query.value(2).toString();
    }

    return consultant;
}

QMap<QString, QString> MainWindow::getLastConsultant() {
    QSqlQuery query;
    QMap<QString, QString> consultant;

    query.exec("SELECT NOM_CON, PRENOM_CON, DISPONIBILITE FROM CONSULTANT ORDER BY ID_CON DESC LIMIT 1");
    if (query.next()) {
        consultant["nom"] = query.value(0).toString();
        consultant["prenom"] = query.value(1).toString();
        consultant["disponibilite"] = query.value(2).toString();
    }

    return consultant;
}



void MainWindow::on_search_s_clicked()
{
    QString searchTerm = ui->search->text().trimmed();

    if (searchTerm.isEmpty()) {
        populateTable();
        return;
    }


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



//debut to do list



void MainWindow::initialiserOngletToDo() {
    QWidget *widgetToDo = ui->tab_4;
    QVBoxLayout *layoutPrincipal = new QVBoxLayout(widgetToDo);

    QLabel *titre = new QLabel("Liste des Tâches à Faire");
    titre->setStyleSheet("QLabel { color: #4D6F50; font-size: 20px; font-weight: bold; }");
    titre->setAlignment(Qt::AlignCenter);
    layoutPrincipal->addWidget(titre);

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

    QWidget *zoneBoutons = new QWidget();
    QHBoxLayout *layoutBoutons = new QHBoxLayout(zoneBoutons);

    boutonAjouter = new QPushButton("Ajouter Tâche");
    boutonSupprimer = new QPushButton("Supprimer Tâche");
    boutonRafraichir = new QPushButton("Rafraîchir Liste");

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

    // Change QListWidget to QTableWidget
    listeTaches = new QTableWidget();
    listeTaches->setColumnCount(3); // ID, Task, Status
    listeTaches->setHorizontalHeaderLabels(QStringList() << "ID Consultant" << "Tâche" << "Statut");
    listeTaches->setStyleSheet("QTableWidget { border: 2px solid #4D6F50; border-radius: 5px; }"
                               "QTableWidget::item { padding: 5px; border-bottom: 1px solid #E0E0E0; }"
                               "QTableWidget::item:hover { background-color: #E8F5E9; }");
    listeTaches->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    listeTaches->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Connect buttons
    connect(boutonAjouter, &QPushButton::clicked, this, &MainWindow::on_ajouterTache_clicked);
    connect(boutonSupprimer, &QPushButton::clicked, this, &MainWindow::on_supprimerTache_clicked);
    connect(boutonRafraichir, &QPushButton::clicked, this, &MainWindow::on_rafraichirListe_clicked);

    // Add context menu for status change
    listeTaches->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(listeTaches, &QTableWidget::customContextMenuRequested, this, [this](const QPoint &pos) {
        QTableWidgetItem *item = listeTaches->itemAt(pos);
        if (!item) return;

        int row = item->row();
        QMenu menu(this);

        QAction *setTodo = menu.addAction("Marquer comme À faire");
        QAction *setDoing = menu.addAction("Marquer comme En cours");
        QAction *setDone = menu.addAction("Marquer comme Terminée");

        QAction *selected = menu.exec(listeTaches->viewport()->mapToGlobal(pos));
        if (selected == setTodo) {
            updateTaskStatusInRow(row, "TODO");
        } else if (selected == setDoing) {
            updateTaskStatusInRow(row, "DOING");
        } else if (selected == setDone) {
            updateTaskStatusInRow(row, "DONE");
        }
    });

    layoutPrincipal->addWidget(zoneSaisie);
    layoutPrincipal->addWidget(zoneBoutons);
    layoutPrincipal->addWidget(listeTaches);

    // Load initial tasks
    chargerListeTaches();
}








void MainWindow::updateTaskStatusInRow(int row, const QString &status) {
    QTableWidgetItem *idItem = listeTaches->item(row, 0);
    QTableWidgetItem *taskItem = listeTaches->item(row, 1);

    if (idItem && taskItem) {
        int id = idItem->text().toInt();
        QString task = taskItem->text();

        QSqlQuery query;
        if (ToDo::updateTacheStatus(id, task, status, query)) {
            // Update the status in the table
            QTableWidgetItem *statusItem = new QTableWidgetItem(status);
            listeTaches->setItem(row, 2, statusItem);
            QMessageBox::information(this, "Succès", "Statut de la tâche mis à jour!");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du statut.");
        }
    }
}








void MainWindow::chargerListeTaches() {
    listeTaches->setRowCount(0);

    QSqlQuery query;
    QList<QPair<QPair<int, QString>, QString>> taches = ToDo::recupererTachesAvecStatus(query);

    for (const auto &tache : taches) {
        int row = listeTaches->rowCount();
        listeTaches->insertRow(row);

        listeTaches->setItem(row, 0, new QTableWidgetItem(QString::number(tache.first.first)));
        listeTaches->setItem(row, 1, new QTableWidgetItem(tache.first.second));
        listeTaches->setItem(row, 2, new QTableWidgetItem(tache.second));
    }
}

//fin to do list




void MainWindow::on_rafraichirListe_clicked() {
    chargerListeTaches();
}


void MainWindow::on_supprimerTache_clicked() {
    int currentRow = listeTaches->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une tâche à supprimer.");
        return;
    }

    QTableWidgetItem *idItem = listeTaches->item(currentRow, 0);
    QTableWidgetItem *taskItem = listeTaches->item(currentRow, 1);

    if (idItem && taskItem) {
        int id = idItem->text().toInt();
        QString task = taskItem->text();

        QSqlQuery query;
        if (ToDo::supprimerTache(id, task, query)) {
            QMessageBox::information(this, "Succès", "Tâche supprimée avec succès!");
            chargerListeTaches();
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la suppression de la tâche.");
        }
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








//debut chatbot



void MainWindow::handleBotResponse(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonResponse.object();

        QString answer = jsonObject["response"].toString();


        QListWidgetItem *botItem = new QListWidgetItem("🤖 " + answer);
        botItem->setTextAlignment(Qt::AlignLeft);
        botItem->setForeground(QColor("#4D6F50"));
        chatHistory->addItem(botItem);


        chatHistory->scrollToBottom();
    } else {
        QString errorMsg = "Erreur: " + reply->errorString();
        QListWidgetItem *errorItem = new QListWidgetItem("⚠ " + errorMsg);
        errorItem->setTextAlignment(Qt::AlignLeft);
        errorItem->setForeground(Qt::red);
        chatHistory->addItem(errorItem);
    }
}


void MainWindow::onSendMessage()
{
    QString question = messageInput->text().trimmed();

    if (question.isEmpty()) return;


    QListWidgetItem *userItem = new QListWidgetItem("👤 " + question);
    userItem->setTextAlignment(Qt::AlignRight);
    userItem->setForeground(QColor("#2c3e50"));
    chatHistory->addItem(userItem);


    messageInput->clear();

    // n7ot commande executi ollma serv
    QUrl url("http://localhost:11434/api/generate");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject payload;
    payload["model"] = "deepseek-r1:1.5b";
    payload["prompt"] = question + " (Réponds en français)";
    payload["stream"] = false;

    QJsonDocument doc(payload);
    QNetworkReply* reply = networkManager->post(request, doc.toJson());


    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        this->handleBotResponse(reply);
        reply->deleteLater();
    });
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
        //    QMessageBox::critical(this, "Connection Status","Arduino is not connected or not responding!");
    }
}

void MainWindow::checkArduinoConnection()
{
    if(arduino_is_available && arduino->isOpen()) {
        arduino->write("C");

        if(arduino->waitForReadyRead(1000)) {
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
