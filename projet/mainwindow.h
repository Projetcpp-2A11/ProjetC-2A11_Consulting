#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    // Chart views for statistics
    QChartView *expChartView;
    QChartView *dispChartView;

    // UI setup methods
    void setupTable();
    void populateTable();
    void initCharts();
    void updateStats();

    // Original values for tracking modifications
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