#include "mainwindow.h"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Connect signals to slots
    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_ajouter_clicked);
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::on_supp_clicked);
    connect(ui->mod, &QPushButton::clicked, this, &MainWindow::on_modifications_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);
    connect(ui->search_s, &QPushButton::clicked, this, &MainWindow::on_search_s_clicked);
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_tri_currentIndexChanged);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    // Initialize table and charts
    setupTable();
    populateTable();
    
    // Initialize chart views as null pointers
    expChartView = nullptr;
    dispChartView = nullptr;
    
    // Enable editing in table
    ui->tableau->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
}

MainWindow::~MainWindow()
{
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

    // Create a container widget for charts
    QWidget *chartsContainer = new QWidget(ui->tab_3);
    QVBoxLayout *chartsLayout = new QVBoxLayout(chartsContainer);

    // Experience Pie Chart
    expChartView = new QChartView();
    expChartView->setRenderHint(QPainter::Antialiasing);
    chartsLayout->addWidget(expChartView);

    // Availability Bar Chart
    dispChartView = new QChartView();
    dispChartView->setRenderHint(QPainter::Antialiasing);
    chartsLayout->addWidget(dispChartView);

    // Set layout for the statistics tab
    ui->tab_3->setLayout(new QVBoxLayout());
    ui->tab_3->layout()->addWidget(chartsContainer);
}

void MainWindow::updateStats()
{
    QSqlQuery query;

    // Experience Pie Chart
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

    // Availability Bar Chart
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
        // Clear fields after successful addition
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

    // Create document
    QTextDocument document;
    document.setHtml(html);

    // Ensure directory exists
    QDir().mkpath("Documents_consultant");

    // Set up printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("Documents_consultant/Doc.pdf");
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    // Generate PDF
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
