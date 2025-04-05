#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
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
//QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QChartView *expChartView;
    QChartView *dispChartView;
    void onTabChanged(int index);
    void initCharts();
    void updateStats();

    void on_search_s_clicked();
    MainWindow(QWidget *parent = nullptr);
    void setupTable() ;
    QMap<QPair<int, int>, QString> originalValues;
    void populateTable();
    void on_tab_2_clicked();
    ~MainWindow();
    void on_ajouter_clicked();
    void on_supp_clicked();
    void on_modifications_clicked();
    void on_pdf_clicked();
    void on_tri_currentIndexChanged(int index);
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
