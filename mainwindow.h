#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"employe.h"

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

private slots:
    void on_ajouter_clicked();


    void on_tabWidget_2_currentChanged(int index);

    void on_Supprimer_emp_clicked();

    void on_modifier_2_clicked();

    void on_modifier_clicked();

private:
    Employe E;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
