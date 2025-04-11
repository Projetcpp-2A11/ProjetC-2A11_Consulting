#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    Reclamation Rtmp;
};

#endif // MAINWINDOW_H
