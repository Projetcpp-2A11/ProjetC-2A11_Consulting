#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "todo.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QMap>
#include <QPair>
#include <QPrinter>
#include <QTextDocument>
#include <QChartView>
#include <QPieSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QValueAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QVBoxLayout>
#include <QWidget>
// Add these missing includes
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Les charts poura la statisticques
    QChartView *expChartView;
    QChartView *dispChartView;

    void on_ajouterTache_clicked();
    void on_supprimerTache_clicked();
    void on_rafraichirListe_clicked();
    void chargerListeTaches();

    // Add initialiserOngletToDo to the declaration
    void initialiserOngletToDo();

    // Add this to private members
    QListWidget *listeTaches;
    QLineEdit *inputIdConsultant;
    QLineEdit *inputTache;
    QPushButton *boutonAjouter;
    QPushButton *boutonSupprimer;
    QPushButton *boutonRafraichir;

    void setupTable();
    void populateTable();
    void initCharts();
    void updateStats();

    // valeur orginal pour la modiacation (tracking system)
    QMap<QPair<int, int>, QString> originalValues;

private slots:
    void on_ajouter_clicked();
    void on_supp_clicked();
    void on_modifications_clicked();
    void on_pdf_clicked();
    void on_search_s_clicked();
    void on_tri_currentIndexChanged(int index);
    void onTabChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
