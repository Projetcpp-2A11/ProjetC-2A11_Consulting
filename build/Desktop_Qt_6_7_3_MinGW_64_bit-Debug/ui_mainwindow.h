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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *acceuil;
    QPushButton *login;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTableView *tab_emp;
    QPushButton *Supprimer_emp;
    QPushButton *modifier_2;
    QWidget *tab;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QPushButton *ajouter;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QWidget *tab_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *modifier;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QComboBox *comboBox_2;
    QDateEdit *dateEdit_2;
    QWidget *tab_6;
    QWidget *tab_5;
    QWidget *tab_7;
    QWidget *tab_11;
    QWidget *tab_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1239, 742);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(70, 30, 1131, 601));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(1131, 601));
        tabWidget->setMaximumSize(QSize(1131, 16777215));
        tabWidget->setTabletTracking(false);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 2px solid #D3D3D3;\n"
"    background: #F8F9FA;\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"QTabBar {\n"
"    alignment: left;\n"
"    min-width: 100px; /* Make sidebar thinner */\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #E0E7F0;\n"
"    color: #000;\n"
"    border: 1px solid #D3D3D3;\n"
"    border-radius: 10px;\n"
"    padding: 5px 10px;  /* Adjust padding for smaller size */\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    width: 40px;  /* Reduce width */\n"
"    height: 73px;  /* Reduce height */\n"
"    text-align: center;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #0078D7; /* Color for selected tab */\n"
"    color: white;\n"
"    border-left: 3px solid #FFD700;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #A9A9A9;\n"
"    color: white;\n"
"}\n"
""));
        tabWidget->setTabPosition(QTabWidget::TabPosition::West);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setIconSize(QSize(173, 38));
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        acceuil = new QWidget();
        acceuil->setObjectName("acceuil");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(acceuil->sizePolicy().hasHeightForWidth());
        acceuil->setSizePolicy(sizePolicy1);
        acceuil->setMinimumSize(QSize(80, 35));
        login = new QPushButton(acceuil);
        login->setObjectName("login");
        login->setGeometry(QRect(740, 420, 151, 29));
        lineEdit = new QLineEdit(acceuil);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(720, 290, 201, 28));
        lineEdit_2 = new QLineEdit(acceuil);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(720, 360, 201, 28));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        label = new QLabel(acceuil);
        label->setObjectName("label");
        label->setGeometry(QRect(720, 250, 63, 20));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_2 = new QLabel(acceuil);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(720, 330, 101, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_3 = new QLabel(acceuil);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 30, 681, 531));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/img/476340197_494486546746576_7566987837383606640_n.png")));
        tabWidget->addTab(acceuil, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        sizePolicy1.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy1);
        tab_2->setMinimumSize(QSize(80, 35));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(60, 10, 921, 561));
        tabWidget_2->setStyleSheet(QString::fromUtf8("QTabBar {\n"
"    min-height: 40px; /* Adjust height to make tabs longer */\n"
"    background-color: #FFFFFF; /* Background color */\n"
"}\n"
"QTabBar::tab {\n"
"    min-width: 100px; /* Adjust width to make tabs thinner */\n"
"    padding: 10px; /* Add padding for better appearance */\n"
"    margin: 0; /* Remove margin for compactness */\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background-color: #0078D7; /* Color for selected tab */\n"
"}\n"
"QTabBar::tab {\n"
"    background: #E0E7F0;\n"
"    color: #000;\n"
"    border: 1px solid #D3D3D3;\n"
"    border-radius: 10px;\n"
"    padding: 5px 10px;  /* Adjust padding for smaller size */\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    width: 285px;  /* Reduce width */\n"
"    height: 40px;  /* Reduce height */\n"
"    text-align: center;\n"
"}"));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tab_emp = new QTableView(tab_3);
        tab_emp->setObjectName("tab_emp");
        tab_emp->setGeometry(QRect(50, 40, 831, 421));
        Supprimer_emp = new QPushButton(tab_3);
        Supprimer_emp->setObjectName("Supprimer_emp");
        Supprimer_emp->setGeometry(QRect(742, 470, 131, 29));
        modifier_2 = new QPushButton(tab_3);
        modifier_2->setObjectName("modifier_2");
        modifier_2->setGeometry(QRect(570, 470, 151, 29));
        tabWidget_2->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 80, 63, 20));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 250, 131, 20));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 350, 111, 20));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 170, 63, 20));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(470, 80, 63, 20));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(470, 170, 63, 20));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(470, 250, 63, 20));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: #000000; "));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(220, 80, 113, 28));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(220, 340, 113, 28));
        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(220, 170, 113, 28));
        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(600, 80, 113, 28));
        lineEdit_8 = new QLineEdit(tab);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(600, 170, 113, 28));
        ajouter = new QPushButton(tab);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(510, 350, 151, 29));
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(600, 250, 121, 28));
        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(220, 250, 110, 29));
        tabWidget_2->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_11 = new QLabel(tab_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 60, 63, 20));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_12 = new QLabel(tab_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 150, 63, 20));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 240, 131, 20));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_14 = new QLabel(tab_4);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(40, 350, 111, 20));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(490, 60, 63, 20));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_16 = new QLabel(tab_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(490, 150, 63, 20));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("color: #000000; "));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(490, 240, 63, 20));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("color: #000000; "));
        modifier = new QPushButton(tab_4);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(570, 350, 151, 29));
        lineEdit_10 = new QLineEdit(tab_4);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(200, 60, 113, 28));
        lineEdit_11 = new QLineEdit(tab_4);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(200, 150, 113, 28));
        lineEdit_13 = new QLineEdit(tab_4);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(200, 340, 113, 28));
        lineEdit_14 = new QLineEdit(tab_4);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(620, 60, 113, 28));
        lineEdit_15 = new QLineEdit(tab_4);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(620, 150, 113, 28));
        comboBox_2 = new QComboBox(tab_4);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(620, 240, 121, 28));
        dateEdit_2 = new QDateEdit(tab_4);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(200, 240, 110, 29));
        tabWidget_2->addTab(tab_4, QString());
        tabWidget->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        sizePolicy1.setHeightForWidth(tab_6->sizePolicy().hasHeightForWidth());
        tab_6->setSizePolicy(sizePolicy1);
        tab_6->setMinimumSize(QSize(80, 35));
        tabWidget->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        sizePolicy1.setHeightForWidth(tab_5->sizePolicy().hasHeightForWidth());
        tab_5->setSizePolicy(sizePolicy1);
        tab_5->setMinimumSize(QSize(80, 35));
        tabWidget->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        sizePolicy1.setHeightForWidth(tab_7->sizePolicy().hasHeightForWidth());
        tab_7->setSizePolicy(sizePolicy1);
        tab_7->setMinimumSize(QSize(80, 35));
        tabWidget->addTab(tab_7, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        sizePolicy1.setHeightForWidth(tab_11->sizePolicy().hasHeightForWidth());
        tab_11->setSizePolicy(sizePolicy1);
        tab_11->setMinimumSize(QSize(80, 35));
        tabWidget->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName("tab_12");
        sizePolicy1.setHeightForWidth(tab_12->sizePolicy().hasHeightForWidth());
        tab_12->setSizePolicy(sizePolicy1);
        tab_12->setMinimumSize(QSize(80, 35));
        tabWidget->addTab(tab_12, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1239, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "se connecter", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer votre email", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer votre mot de passe", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        label_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(acceuil), QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        Supprimer_emp->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        modifier_2->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Date de naissance", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Mdp", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        lineEdit_4->setText(QString());
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Directeur", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Rh", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Consultant ", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Date de naissance", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Mdp", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Directeur", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Rh", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Consultant ", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Employ\303\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Client", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Consultant", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Projet", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QCoreApplication::translate("MainWindow", "RDV", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_12), QCoreApplication::translate("MainWindow", "R\303\251clamation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
