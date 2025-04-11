/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_sujet;
    QLineEdit *lineEdit_status;
    QLabel *label_4;
    QLineEdit *lineEdit_date;
    QLabel *label_5;
    QLineEdit *lineEdit_description;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 30, 311, 161));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 47, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 91, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 110, 47, 13));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(60, 30, 113, 20));
        lineEdit_sujet = new QLineEdit(groupBox);
        lineEdit_sujet->setObjectName("lineEdit_sujet");
        lineEdit_sujet->setGeometry(QRect(60, 60, 113, 20));
        lineEdit_status = new QLineEdit(groupBox);
        lineEdit_status->setObjectName("lineEdit_status");
        lineEdit_status->setGeometry(QRect(60, 110, 113, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 140, 47, 13));
        lineEdit_date = new QLineEdit(groupBox);
        lineEdit_date->setObjectName("lineEdit_date");
        lineEdit_date->setGeometry(QRect(60, 140, 113, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 60, 91, 16));
        lineEdit_description = new QLineEdit(groupBox);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setGeometry(QRect(90, 90, 113, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(190, 10, 47, 13));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 30, 113, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 210, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter R\303\251clamation", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Sujet", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
