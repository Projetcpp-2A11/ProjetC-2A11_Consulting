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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QTextEdit *nom;
    QTextEdit *prenom;
    QTextEdit *email;
    QTextEdit *tele;
    QComboBox *list;
    QRadioButton *oui;
    QRadioButton *non;
    QTextEdit *spec;
    QTextEdit *histo;
    QTextEdit *eval;
    QPushButton *ajouter;
    QWidget *tab_2;
    QTableWidget *tableau;
    QPushButton *mod;
    QPushButton *pdf;
    QLabel *label_18;
    QLabel *label_19;
    QTextEdit *recherche;
    QTextEdit *id_supp;
    QLabel *label_20;
    QPushButton *supp;
    QComboBox *tri;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuSTRATEDGGE;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 568);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(140, 100, 651, 421));
        tabWidget->setStyleSheet(QString::fromUtf8("color:rgb(180, 120, 180);\n"
"border-top-color: rgb(85, 85, 255);\n"
"background-color: rgb(193, 193, 193);\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 37, 12));
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 110, 61, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 170, 37, 12));
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 230, 71, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(410, 280, 101, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(410, 40, 111, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(410, 110, 141, 16));
        label_8->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(410, 220, 111, 16));
        label_9->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        nom = new QTextEdit(tab);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(20, 70, 141, 21));
        prenom = new QTextEdit(tab);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(20, 130, 141, 21));
        email = new QTextEdit(tab);
        email->setObjectName("email");
        email->setGeometry(QRect(20, 190, 141, 21));
        tele = new QTextEdit(tab);
        tele->setObjectName("tele");
        tele->setGeometry(QRect(20, 260, 141, 21));
        list = new QComboBox(tab);
        list->addItem(QString());
        list->addItem(QString());
        list->addItem(QString());
        list->addItem(QString());
        list->addItem(QString());
        list->addItem(QString());
        list->setObjectName("list");
        list->setGeometry(QRect(20, 320, 191, 22));
        list->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color:rgb(170, 85, 255);\n"
"background-color: rgb(255, 170, 255);"));
        oui = new QRadioButton(tab);
        oui->setObjectName("oui");
        oui->setGeometry(QRect(390, 80, 69, 18));
        oui->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 10px ;\n"
"color: rgb(0, 0, 0);"));
        non = new QRadioButton(tab);
        non->setObjectName("non");
        non->setGeometry(QRect(500, 80, 69, 18));
        non->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 10px ;\n"
"color: rgb(0, 0, 0);"));
        spec = new QTextEdit(tab);
        spec->setObjectName("spec");
        spec->setGeometry(QRect(410, 310, 141, 21));
        histo = new QTextEdit(tab);
        histo->setObjectName("histo");
        histo->setGeometry(QRect(410, 130, 201, 81));
        eval = new QTextEdit(tab);
        eval->setObjectName("eval");
        eval->setGeometry(QRect(410, 250, 141, 21));
        ajouter = new QPushButton(tab);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(530, 350, 101, 31));
        ajouter->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color:rgb(170, 85, 255);\n"
"background-color: rgb(255, 170, 255);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableau = new QTableWidget(tab_2);
        if (tableau->columnCount() < 8)
            tableau->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableau->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableau->setObjectName("tableau");
        tableau->setGeometry(QRect(20, 70, 601, 241));
        tableau->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color:rgb(170, 85, 255);\n"
"background-color: rgb(255, 170, 255);"));
        mod = new QPushButton(tab_2);
        mod->setObjectName("mod");
        mod->setGeometry(QRect(40, 320, 211, 31));
        mod->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color:rgb(170, 85, 255);\n"
"background-color: rgb(255, 170, 255);"));
        pdf = new QPushButton(tab_2);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(390, 320, 211, 31));
        pdf->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color:rgb(170, 85, 255);\n"
"background-color: rgb(255, 170, 255);"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(30, 40, 91, 21));
        label_18->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(370, 40, 81, 16));
        label_19->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        recherche = new QTextEdit(tab_2);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(450, 40, 161, 21));
        recherche->setStyleSheet(QString::fromUtf8(""));
        id_supp = new QTextEdit(tab_2);
        id_supp->setObjectName("id_supp");
        id_supp->setGeometry(QRect(250, 370, 151, 21));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(40, 370, 191, 20));
        label_20->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color: rgb(0, 0, 0);"));
        supp = new QPushButton(tab_2);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(440, 370, 131, 21));
        supp->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color:rgb(170, 85, 255);\n"
"background-color: rgb(255, 170, 255);"));
        tri = new QComboBox(tab_2);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(110, 40, 111, 22));
        tri->setStyleSheet(QString::fromUtf8("font: 9pt \"Times New Roman\";\n"
"font-size: 16px ;\n"
"color:rgb(170, 85, 255);\n"
"background-color: rgb(255, 170, 255);"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget->addTab(tab_5, QString());
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-14, -49, 821, 671));
        label->setPixmap(QPixmap(QString::fromUtf8("../Screenshot 2025-03-07 002543.png")));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        tabWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuSTRATEDGGE = new QMenu(menubar);
        menuSTRATEDGGE->setObjectName("menuSTRATEDGGE");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSTRATEDGGE->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialisation", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Historique Missions", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\303\211valuation", nullptr));
        list->setItemText(0, QCoreApplication::translate("MainWindow", "Donner Votre Exp\303\251rience", nullptr));
        list->setItemText(1, QCoreApplication::translate("MainWindow", "1 ans", nullptr));
        list->setItemText(2, QCoreApplication::translate("MainWindow", "2 ans", nullptr));
        list->setItemText(3, QCoreApplication::translate("MainWindow", "3 ans", nullptr));
        list->setItemText(4, QCoreApplication::translate("MainWindow", "4 ans", nullptr));
        list->setItemText(5, QCoreApplication::translate("MainWindow", "5 ans ++", nullptr));

        oui->setText(QCoreApplication::translate("MainWindow", "Oui", nullptr));
        non->setText(QCoreApplication::translate("MainWindow", "Non", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajouter Consultant", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableau->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableau->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableau->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableau->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableau->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableau->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialisation", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableau->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Experience", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableau->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Disponible", nullptr));
        mod->setText(QCoreApplication::translate("MainWindow", "MODIFICATIONS", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "EXPORT EN PDF", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Trier Par :", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Donner L'ID pour suppresion", nullptr));
        supp->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tri->setItemText(0, QCoreApplication::translate("MainWindow", "Votre Choix :", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        tri->setItemText(2, QCoreApplication::translate("MainWindow", "Nom", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Afficher Consultant", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Les Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "TO DO LIST", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "ChatBot", nullptr));
        label->setText(QString());
        menuSTRATEDGGE->setTitle(QCoreApplication::translate("MainWindow", "STRATEDGGE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
