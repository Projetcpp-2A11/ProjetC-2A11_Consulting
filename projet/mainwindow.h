#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "todo.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QMap>
#include <QPair>
#include <QSerialPortInfo>
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
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QSerialPort>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSerialPort>
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


    QChartView *expChartView;
    QChartView *dispChartView;

    void on_ajouterTache_clicked();
    void on_supprimerTache_clicked();
    void on_rafraichirListe_clicked();
    void chargerListeTaches();
    void initialiserOngletToDo();
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
    void on_reset_clicked();
    void on_modifications_clicked();
    QMap<QPair<int, int>, QString> originalValues;
    void on_reset_table_clicked();
    QListWidget *chatHistory;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    void initializeChatBot();
    void onSendMessage();
    void handleBotResponse(QNetworkReply* reply);
    QMap<QString, QString> getFirstConsultant();
    QMap<QString, QString> getLastConsultant();
    int getTotalConsultants();
    QPair<int, int> getAvailabilityStats();
    QMap<QString, int> getExperienceStats();
    int getTotalTasks();

    //ardunio
    void on_connectButton_clicked();
    void checkArduinoConnection();

    QSerialPort *arduino;
    bool arduino_is_available;
    void showConnectionStatus(bool connected);
    QNetworkAccessManager* networkManager;

private slots:
    void on_ajouter_clicked();
    void on_supp_clicked();
    void on_pdf_clicked();
    void on_search_s_clicked();
    void on_tri_currentIndexChanged(int index);
    void onTabChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
