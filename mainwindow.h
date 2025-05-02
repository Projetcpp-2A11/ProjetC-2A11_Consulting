#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"employe.h"
#include "arduino.h"

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

    void on_modifier_3_clicked();

    void on_modifier_4_clicked();

    void on_modifier_5_clicked();

  //void on_modifier_6_clicked();

    void on_login_clicked();

    void activerOngletsSelonPoste(const QString &poste);

    void on_login_2_clicked();

    bool isValidEmailAndTelephone(const QString& email, const QString& phone);

    bool updatePasswordInDB(const QString& email, const QString& phone, const QString& newmotDePasse);

    void on_pushButton_clicked();
    void on_movementDetected();  // Slot pour demander l'email à l'utilisateur
    void readFromArduino();
    void update_label();
    void askForEmailAndVerify();






private:
    Employe E;
    Ui::MainWindow *ui;
    int failedLoginAttempts = 0;
    QString photoPath;
    QByteArray data;
    Arduino A;
QSerialPort *arduino;
};
#endif // MAINWINDOW_H
