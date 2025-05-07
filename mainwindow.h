#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Reclamation.h"

#include <QMainWindow>
#include <QSqlQueryModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();  // Slot for adding a new reclamation
    void on_pb_supprimer_clicked();        // Slot for deleting a reclamation
    void on_pb_trier_clicked();        // Slot for sorting reclamations
    void on_pb_recherche_clicked();
    void on_pb_generate_pdf_clicked();
    void on_pb_modifier_clicked();
    void on_pb_load_clicked();
    void on_lineEdit_categorie_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Reclamation R;
};

#endif // MAINWINDOW_H
