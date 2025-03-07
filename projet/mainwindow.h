#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QMap>
#include <QPair>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void onTabChanged(int index);
    MainWindow(QWidget *parent = nullptr);
    void setupTable() ;
    QMap<QPair<int, int>, QString> originalValues;
    void populateTable();
    void on_tab_2_clicked();
    ~MainWindow();
    void on_ajouter_clicked();
    void on_supp_clicked();
    void on_modifications_clicked();
private:
    Ui::MainWindow *ui;
 // Slot for the Ajouter button
};
#endif // MAINWINDOW_H
