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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MW_projet
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget_3;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_35;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_annuler;
    QWidget *tab_2;
    QWidget *widget_11;
    QComboBox *comboBox_complexite;
    QComboBox *comboBox_statut;
    QLabel *label_18;
    QLineEdit *lineEdit_nom;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_19;
    QComboBox *comboBox_client;
    QDateEdit *dateEdit_debut;
    QDateEdit *dateEdit_fin;
    QDoubleSpinBox *doubleSpinBox_budget;
    QPushButton *pushButton_ajouter;
    QLabel *label_36;
    QComboBox *comboBox_client_4;
    QWidget *tab_3;
    QWidget *widget_12;
    QLineEdit *lineEdit_id;
    QPushButton *pushButton_modifier;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_29;
    QLabel *label_27;
    QComboBox *comboBox_statut_2;
    QComboBox *comboBox_complexite_2;
    QLabel *label_3;
    QLabel *label_14;
    QLabel *label_26;
    QDateEdit *dateEdit_debut_2;
    QDateEdit *dateEdit_fin_2;
    QLabel *label_25;
    QComboBox *comboBox_client_2;
    QDoubleSpinBox *doubleSpinBox_budget_2;
    QLineEdit *lineEdit_nom_2;
    QLabel *label_24;
    QComboBox *comboBox_projet;
    QPushButton *pushButton_charger;
    QComboBox *comboBox_client_3;
    QWidget *tab_4;
    QWidget *widget;
    QGroupBox *groupBox_prediction_form;
    QLabel *label_select_project;
    QComboBox *comboBox_select_project;
    QLabel *label_title;
    QLineEdit *lineEdit_title;
    QLabel *label_complexity;
    QLineEdit *lineEdit_complexity;
    QLabel *label_status;
    QLineEdit *lineEdit_status;
    QPushButton *pushButton_predict;
    QGroupBox *groupBox_prediction_result;
    QLabel *label_predicted_duration;
    QLabel *label_risk;
    QLabel *label_advice;
    QLabel *label_5;
    QWidget *widget_5;
    QPushButton *pushButton_5;
    QLabel *label_9;
    QWidget *widget_6;
    QPushButton *pushButton_6;
    QLabel *label_10;
    QWidget *widget_8;
    QPushButton *pushButton_8;
    QLabel *label_34;
    QWidget *widget_9;
    QLabel *label_11;
    QPushButton *pushButton_9;
    QLabel *label_7;
    QWidget *widget_7;
    QPushButton *pushButton_7;
    QLabel *label_33;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MW_projet)
    {
        if (MW_projet->objectName().isEmpty())
            MW_projet->setObjectName("MW_projet");
        MW_projet->resize(1665, 1246);
        centralwidget = new QWidget(MW_projet);
        centralwidget->setObjectName("centralwidget");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 1771, 1211));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1769, 1209));
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(150, 120, 1331, 661));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 2px solid #2E543F; /* Bordure verte fonc\303\251e */\n"
"    background: #F8F8F8; /* Fond clair */\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #4E6F50; /* Vert fonc\303\251 */\n"
"    color: white;\n"
"    padding: 8px 12px;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    margin: 2px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #6A8A63; /* Vert plus clair */\n"
"    color: #F8F8F8;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #87A88D; /* Vert encore plus clair */\n"
"    color: black;\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        widget_3 = new QWidget(tab);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 1331, 1021));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        tableWidget = new QTableWidget(widget_3);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 6, __qtablewidgetitem13);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(150, 90, 1031, 391));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #f8f9fa; /* Light gray background */\n"
"    border: 2px solid #4D6F50; /* Green border */\n"
"    gridline-color: #cccccc; /* Light gray grid lines */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #4D6F50; /* Green header */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #3B5D40;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #A3D9A5; /* Light green selection */\n"
"    color: black;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #C8E6C9; /* Hover effect */\n"
"}\n"
"\n"
"/* Alternate row colors */\n"
"QTableWidget::item:alternate {\n"
"    background-color: #E8F5E9; /* Light green */\n"
"}\n"
""));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 131, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(14);
        label_2->setFont(font);
        comboBox = new QComboBox(widget_3);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(450, 50, 201, 26));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        comboBox_2 = new QComboBox(widget_3);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(360, 570, 171, 26));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        label_35 = new QLabel(widget_3);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(30, 580, 301, 21));
        label_35->setFont(font);
        pushButton_supprimer = new QPushButton(widget_3);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(560, 560, 121, 41));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(193, 179, 255, 200), \n"
"                                stop:1 rgba(255, 228, 196, 200));\n"
"    color: #4A4A4A;\n"
"    border-radius: 10px;\n"
"    border: 1px solid rgba(74, 74, 74, 50);\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(170, 153, 255, 200), \n"
"                                stop:1 rgba(255, 204, 153, 200));\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: rgba(193, 179, 255, 180);\n"
"}\n"
""));
        pushButton_annuler = new QPushButton(widget_3);
        pushButton_annuler->setObjectName("pushButton_annuler");
        pushButton_annuler->setGeometry(QRect(660, 47, 131, 32));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka")});
        font1.setBold(true);
        pushButton_annuler->setFont(font1);
        pushButton_annuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(193, 179, 255, 200), \n"
"                                stop:1 rgba(255, 228, 196, 200));\n"
"    color: #4A4A4A;\n"
"    border-radius: 10px;\n"
"    border: 1px solid rgba(74, 74, 74, 50);\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(170, 153, 255, 200), \n"
"                                stop:1 rgba(255, 204, 153, 200));\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: rgba(193, 179, 255, 180);\n"
"}\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        widget_11 = new QWidget(tab_2);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(0, 0, 1331, 1021));
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        comboBox_complexite = new QComboBox(widget_11);
        comboBox_complexite->addItem(QString());
        comboBox_complexite->addItem(QString());
        comboBox_complexite->addItem(QString());
        comboBox_complexite->setObjectName("comboBox_complexite");
        comboBox_complexite->setGeometry(QRect(195, 71, 1075, 30));
        comboBox_complexite->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka")});
        font2.setPointSize(10);
        comboBox_complexite->setFont(font2);
        comboBox_complexite->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        comboBox_statut = new QComboBox(widget_11);
        comboBox_statut->addItem(QString());
        comboBox_statut->addItem(QString());
        comboBox_statut->addItem(QString());
        comboBox_statut->addItem(QString());
        comboBox_statut->setObjectName("comboBox_statut");
        comboBox_statut->setGeometry(QRect(195, 121, 1075, 30));
        comboBox_statut->setMinimumSize(QSize(0, 30));
        comboBox_statut->setFont(font2);
        comboBox_statut->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        label_18 = new QLabel(widget_11);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(21, 171, 79, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka")});
        font3.setPointSize(12);
        label_18->setFont(font3);
        lineEdit_nom = new QLineEdit(widget_11);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(195, 21, 1075, 30));
        lineEdit_nom->setMinimumSize(QSize(0, 30));
        lineEdit_nom->setFont(font2);
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        label_17 = new QLabel(widget_11);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(21, 121, 69, 20));
        label_17->setFont(font3);
        label_16 = new QLabel(widget_11);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(21, 71, 121, 20));
        label_16->setFont(font3);
        label_15 = new QLabel(widget_11);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(21, 21, 154, 20));
        label_15->setFont(font3);
        label_21 = new QLabel(widget_11);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(21, 300, 147, 20));
        label_21->setFont(font3);
        label_22 = new QLabel(widget_11);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(21, 350, 119, 20));
        label_22->setFont(font3);
        label_19 = new QLabel(widget_11);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(21, 221, 67, 20));
        label_19->setFont(font3);
        comboBox_client = new QComboBox(widget_11);
        comboBox_client->setObjectName("comboBox_client");
        comboBox_client->setGeometry(QRect(195, 221, 1075, 30));
        comboBox_client->setMinimumSize(QSize(0, 30));
        comboBox_client->setFont(font2);
        comboBox_client->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        dateEdit_debut = new QDateEdit(widget_11);
        dateEdit_debut->setObjectName("dateEdit_debut");
        dateEdit_debut->setGeometry(QRect(195, 290, 1075, 30));
        dateEdit_debut->setMinimumSize(QSize(0, 30));
        dateEdit_debut->setFont(font2);
        dateEdit_debut->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        dateEdit_debut->setCalendarPopup(true);
        dateEdit_fin = new QDateEdit(widget_11);
        dateEdit_fin->setObjectName("dateEdit_fin");
        dateEdit_fin->setGeometry(QRect(195, 350, 1075, 30));
        dateEdit_fin->setMinimumSize(QSize(0, 30));
        dateEdit_fin->setFont(font2);
        dateEdit_fin->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        dateEdit_fin->setCalendarPopup(true);
        doubleSpinBox_budget = new QDoubleSpinBox(widget_11);
        doubleSpinBox_budget->setObjectName("doubleSpinBox_budget");
        doubleSpinBox_budget->setGeometry(QRect(195, 171, 163, 30));
        doubleSpinBox_budget->setMinimumSize(QSize(0, 30));
        doubleSpinBox_budget->setFont(font2);
        doubleSpinBox_budget->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button, QDoubleSpinBox::down-button {\n"
"    width: 16px;\n"
"    border-width: 1px;\n"
"}\n"
"\n"
"QDoubleSpinBox:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        doubleSpinBox_budget->setMaximum(1000000.000000000000000);
        pushButton_ajouter = new QPushButton(widget_11);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(1180, 470, 88, 32));
        pushButton_ajouter->setFont(font1);
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(193, 179, 255, 200), \n"
"                                stop:1 rgba(255, 228, 196, 200));\n"
"    color: #4A4A4A;\n"
"    border-radius: 10px;\n"
"    border: 1px solid rgba(74, 74, 74, 50);\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(170, 153, 255, 200), \n"
"                                stop:1 rgba(255, 204, 153, 200));\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: rgba(193, 179, 255, 180);\n"
"}\n"
""));
        label_36 = new QLabel(widget_11);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(30, 400, 120, 20));
        label_36->setFont(font3);
        comboBox_client_4 = new QComboBox(widget_11);
        comboBox_client_4->setObjectName("comboBox_client_4");
        comboBox_client_4->setGeometry(QRect(200, 400, 1075, 30));
        comboBox_client_4->setMinimumSize(QSize(0, 30));
        comboBox_client_4->setFont(font2);
        comboBox_client_4->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        widget_12 = new QWidget(tab_3);
        widget_12->setObjectName("widget_12");
        widget_12->setGeometry(QRect(0, 0, 1331, 1021));
        widget_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        lineEdit_id = new QLineEdit(widget_12);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(20, 550, 113, 22));
        lineEdit_id->setVisible(false);
        pushButton_modifier = new QPushButton(widget_12);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(1160, 550, 96, 32));
        pushButton_modifier->setFont(font1);
        pushButton_modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(193, 179, 255, 200), \n"
"                                stop:1 rgba(255, 228, 196, 200));\n"
"    color: #4A4A4A;\n"
"    border-radius: 10px;\n"
"    border: 1px solid rgba(74, 74, 74, 50);\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(170, 153, 255, 200), \n"
"                                stop:1 rgba(255, 204, 153, 200));\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: rgba(193, 179, 255, 180);\n"
"}\n"
""));
        label_30 = new QLabel(widget_12);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(21, 400, 119, 20));
        label_30->setFont(font3);
        label_31 = new QLabel(widget_12);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(21, 460, 120, 20));
        label_31->setFont(font3);
        label_29 = new QLabel(widget_12);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(21, 350, 147, 20));
        label_29->setFont(font3);
        label_27 = new QLabel(widget_12);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(21, 291, 67, 20));
        label_27->setFont(font3);
        comboBox_statut_2 = new QComboBox(widget_12);
        comboBox_statut_2->addItem(QString());
        comboBox_statut_2->addItem(QString());
        comboBox_statut_2->addItem(QString());
        comboBox_statut_2->addItem(QString());
        comboBox_statut_2->setObjectName("comboBox_statut_2");
        comboBox_statut_2->setGeometry(QRect(195, 191, 1075, 30));
        comboBox_statut_2->setMinimumSize(QSize(0, 30));
        comboBox_statut_2->setFont(font2);
        comboBox_statut_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        comboBox_complexite_2 = new QComboBox(widget_12);
        comboBox_complexite_2->addItem(QString());
        comboBox_complexite_2->addItem(QString());
        comboBox_complexite_2->addItem(QString());
        comboBox_complexite_2->setObjectName("comboBox_complexite_2");
        comboBox_complexite_2->setGeometry(QRect(195, 141, 1075, 30));
        comboBox_complexite_2->setMinimumSize(QSize(0, 30));
        comboBox_complexite_2->setFont(font2);
        comboBox_complexite_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        label_3 = new QLabel(widget_12);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(21, 91, 154, 20));
        label_3->setFont(font3);
        label_14 = new QLabel(widget_12);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(21, 141, 121, 20));
        label_14->setFont(font3);
        label_26 = new QLabel(widget_12);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(21, 241, 79, 20));
        label_26->setFont(font3);
        dateEdit_debut_2 = new QDateEdit(widget_12);
        dateEdit_debut_2->setObjectName("dateEdit_debut_2");
        dateEdit_debut_2->setGeometry(QRect(195, 340, 1075, 30));
        dateEdit_debut_2->setMinimumSize(QSize(0, 30));
        dateEdit_debut_2->setFont(font2);
        dateEdit_debut_2->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        dateEdit_debut_2->setCalendarPopup(true);
        dateEdit_fin_2 = new QDateEdit(widget_12);
        dateEdit_fin_2->setObjectName("dateEdit_fin_2");
        dateEdit_fin_2->setGeometry(QRect(195, 400, 1075, 30));
        dateEdit_fin_2->setMinimumSize(QSize(0, 30));
        dateEdit_fin_2->setFont(font2);
        dateEdit_fin_2->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        dateEdit_fin_2->setCalendarPopup(true);
        label_25 = new QLabel(widget_12);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(21, 191, 69, 20));
        label_25->setFont(font3);
        comboBox_client_2 = new QComboBox(widget_12);
        comboBox_client_2->setObjectName("comboBox_client_2");
        comboBox_client_2->setGeometry(QRect(195, 291, 1075, 30));
        comboBox_client_2->setMinimumSize(QSize(0, 30));
        comboBox_client_2->setFont(font2);
        comboBox_client_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        doubleSpinBox_budget_2 = new QDoubleSpinBox(widget_12);
        doubleSpinBox_budget_2->setObjectName("doubleSpinBox_budget_2");
        doubleSpinBox_budget_2->setGeometry(QRect(195, 241, 181, 30));
        doubleSpinBox_budget_2->setMinimumSize(QSize(0, 30));
        doubleSpinBox_budget_2->setFont(font2);
        doubleSpinBox_budget_2->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button, QDoubleSpinBox::down-button {\n"
"    width: 16px;\n"
"    border-width: 1px;\n"
"}\n"
"\n"
"QDoubleSpinBox:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        doubleSpinBox_budget_2->setMaximum(1000000.000000000000000);
        lineEdit_nom_2 = new QLineEdit(widget_12);
        lineEdit_nom_2->setObjectName("lineEdit_nom_2");
        lineEdit_nom_2->setGeometry(QRect(195, 91, 1075, 30));
        lineEdit_nom_2->setMinimumSize(QSize(0, 30));
        lineEdit_nom_2->setFont(font2);
        lineEdit_nom_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        label_24 = new QLabel(widget_12);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(21, 21, 232, 20));
        label_24->setFont(font3);
        comboBox_projet = new QComboBox(widget_12);
        comboBox_projet->setObjectName("comboBox_projet");
        comboBox_projet->setGeometry(QRect(440, 34, 401, 33));
        comboBox_projet->setMinimumSize(QSize(0, 30));
        comboBox_projet->setFont(font2);
        comboBox_projet->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        pushButton_charger = new QPushButton(widget_12);
        pushButton_charger->setObjectName("pushButton_charger");
        pushButton_charger->setGeometry(QRect(858, 34, 92, 32));
        pushButton_charger->setFont(font1);
        pushButton_charger->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(193, 179, 255, 200), \n"
"                                stop:1 rgba(255, 228, 196, 200));\n"
"    color: #4A4A4A;\n"
"    border-radius: 10px;\n"
"    border: 1px solid rgba(74, 74, 74, 50);\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(170, 153, 255, 200), \n"
"                                stop:1 rgba(255, 204, 153, 200));\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: rgba(193, 179, 255, 180);\n"
"}\n"
""));
        comboBox_client_3 = new QComboBox(widget_12);
        comboBox_client_3->setObjectName("comboBox_client_3");
        comboBox_client_3->setGeometry(QRect(200, 450, 1075, 30));
        comboBox_client_3->setMinimumSize(QSize(0, 30));
        comboBox_client_3->setFont(font2);
        comboBox_client_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        widget = new QWidget(tab_4);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1401, 681));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        groupBox_prediction_form = new QGroupBox(widget);
        groupBox_prediction_form->setObjectName("groupBox_prediction_form");
        groupBox_prediction_form->setGeometry(QRect(9, 9, 741, 411));
        label_select_project = new QLabel(groupBox_prediction_form);
        label_select_project->setObjectName("label_select_project");
        label_select_project->setGeometry(QRect(20, 30, 120, 25));
        comboBox_select_project = new QComboBox(groupBox_prediction_form);
        comboBox_select_project->setObjectName("comboBox_select_project");
        comboBox_select_project->setGeometry(QRect(160, 30, 350, 25));
        comboBox_select_project->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}"));
        label_title = new QLabel(groupBox_prediction_form);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(20, 70, 120, 25));
        lineEdit_title = new QLineEdit(groupBox_prediction_form);
        lineEdit_title->setObjectName("lineEdit_title");
        lineEdit_title->setGeometry(QRect(160, 70, 350, 25));
        lineEdit_title->setReadOnly(true);
        label_complexity = new QLabel(groupBox_prediction_form);
        label_complexity->setObjectName("label_complexity");
        label_complexity->setGeometry(QRect(20, 110, 120, 25));
        lineEdit_complexity = new QLineEdit(groupBox_prediction_form);
        lineEdit_complexity->setObjectName("lineEdit_complexity");
        lineEdit_complexity->setGeometry(QRect(160, 110, 150, 25));
        lineEdit_complexity->setReadOnly(true);
        label_status = new QLabel(groupBox_prediction_form);
        label_status->setObjectName("label_status");
        label_status->setGeometry(QRect(20, 150, 120, 25));
        lineEdit_status = new QLineEdit(groupBox_prediction_form);
        lineEdit_status->setObjectName("lineEdit_status");
        lineEdit_status->setGeometry(QRect(160, 150, 150, 25));
        lineEdit_status->setReadOnly(true);
        pushButton_predict = new QPushButton(groupBox_prediction_form);
        pushButton_predict->setObjectName("pushButton_predict");
        pushButton_predict->setGeometry(QRect(440, 150, 100, 30));
        pushButton_predict->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(193, 179, 255, 200), \n"
"                                stop:1 rgba(255, 228, 196, 200));\n"
"    color: #4A4A4A;\n"
"    border-radius: 10px;\n"
"    border: 1px solid rgba(74, 74, 74, 50);\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 rgba(170, 153, 255, 200), \n"
"                                stop:1 rgba(255, 204, 153, 200));\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: rgba(193, 179, 255, 180);\n"
"}\n"
""));
        groupBox_prediction_result = new QGroupBox(groupBox_prediction_form);
        groupBox_prediction_result->setObjectName("groupBox_prediction_result");
        groupBox_prediction_result->setGeometry(QRect(0, 190, 861, 281));
        label_predicted_duration = new QLabel(groupBox_prediction_result);
        label_predicted_duration->setObjectName("label_predicted_duration");
        label_predicted_duration->setGeometry(QRect(20, 70, 221, 25));
        label_risk = new QLabel(groupBox_prediction_result);
        label_risk->setObjectName("label_risk");
        label_risk->setGeometry(QRect(20, 160, 250, 25));
        label_advice = new QLabel(groupBox_prediction_result);
        label_advice->setObjectName("label_advice");
        label_advice->setGeometry(QRect(450, 60, 270, 55));
        label_select_project->raise();
        comboBox_select_project->raise();
        label_title->raise();
        label_complexity->raise();
        lineEdit_complexity->raise();
        label_status->raise();
        lineEdit_status->raise();
        groupBox_prediction_result->raise();
        pushButton_predict->raise();
        lineEdit_title->raise();
        tabWidget->addTab(tab_4, QString());
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-380, -1580, 3360, 2391));
        QFont font4;
        font4.setPointSize(10);
        label_5->setFont(font4);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/background.png")));
        label_5->setScaledContents(true);
        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(20, 130, 120, 121));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(15, 90, 93, 29));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Sitka")});
        font5.setPointSize(11);
        pushButton_5->setFont(font5);
        label_9 = new QLabel(widget_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 20, 63, 61));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/hands-holding-child-solid.svg")));
        label_9->setScaledContents(true);
        widget_6 = new QWidget(scrollAreaWidgetContents);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(20, 260, 120, 121));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        pushButton_6 = new QPushButton(widget_6);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(15, 90, 93, 29));
        pushButton_6->setFont(font5);
        label_10 = new QLabel(widget_6);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 20, 63, 61));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/calendar-days-solid.svg")));
        label_10->setScaledContents(true);
        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(20, 390, 120, 121));
        widget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        pushButton_8 = new QPushButton(widget_8);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(15, 90, 93, 29));
        pushButton_8->setFont(font5);
        label_34 = new QLabel(widget_8);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(20, 20, 81, 71));
        label_34->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/briefcase-solid.svg")));
        label_34->setScaledContents(true);
        widget_9 = new QWidget(scrollAreaWidgetContents);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(20, 520, 120, 121));
        widget_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        label_11 = new QLabel(widget_9);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 20, 63, 61));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/user-tie-solid (1).svg")));
        label_11->setScaledContents(true);
        pushButton_9 = new QPushButton(widget_9);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(15, 90, 91, 29));
        pushButton_9->setFont(font2);
        label_7 = new QLabel(widget_9);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 10, 81, 71));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/user-tie-solid.svg")));
        label_7->setScaledContents(true);
        widget_7 = new QWidget(scrollAreaWidgetContents);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(20, 650, 121, 121));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        pushButton_7 = new QPushButton(widget_7);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 80, 121, 29));
        pushButton_7->setFont(font5);
        label_33 = new QLabel(widget_7);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(20, 10, 81, 71));
        label_33->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/message-solid.svg")));
        label_33->setScaledContents(true);
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, -40, 211, 221));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/mon_icone.png")));
        label_6->setScaledContents(true);
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_5->raise();
        tabWidget->raise();
        widget_5->raise();
        widget_6->raise();
        widget_8->raise();
        widget_9->raise();
        widget_7->raise();
        label_6->raise();
        MW_projet->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MW_projet);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1665, 26));
        MW_projet->setMenuBar(menubar);
        statusbar = new QStatusBar(MW_projet);
        statusbar->setObjectName("statusbar");
        MW_projet->setStatusBar(statusbar);

        retranslateUi(MW_projet);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MW_projet);
    } // setupUi

    void retranslateUi(QMainWindow *MW_projet)
    {
        MW_projet->setWindowTitle(QCoreApplication::translate("MW_projet", "MW_projet", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MW_projet", "Nom-Projet", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MW_projet", "Complexit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MW_projet", "Statue", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MW_projet", "Budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MW_projet", "Nom-Client", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MW_projet", "Date-D\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MW_projet", "Date-Fin", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_2->setText(QCoreApplication::translate("MW_projet", "Les Projets", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MW_projet", "Trier Par", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MW_projet", "Nom", nullptr));

        label_35->setText(QCoreApplication::translate("MW_projet", "Choisir Le Nom de Projet", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MW_projet", "Supprimer", nullptr));
        pushButton_annuler->setText(QCoreApplication::translate("MW_projet", "Exporter PDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MW_projet", "Liste Des Projets", nullptr));
        comboBox_complexite->setItemText(0, QCoreApplication::translate("MW_projet", "Faible", nullptr));
        comboBox_complexite->setItemText(1, QCoreApplication::translate("MW_projet", "Moyenne", nullptr));
        comboBox_complexite->setItemText(2, QCoreApplication::translate("MW_projet", "\303\211lev\303\251e", nullptr));

        comboBox_statut->setItemText(0, QCoreApplication::translate("MW_projet", "En attente", nullptr));
        comboBox_statut->setItemText(1, QCoreApplication::translate("MW_projet", "En cours", nullptr));
        comboBox_statut->setItemText(2, QCoreApplication::translate("MW_projet", "Termin\303\251", nullptr));
        comboBox_statut->setItemText(3, QCoreApplication::translate("MW_projet", "Annul\303\251", nullptr));

        label_18->setText(QCoreApplication::translate("MW_projet", "Budget:", nullptr));
        label_17->setText(QCoreApplication::translate("MW_projet", "Statut:", nullptr));
        label_16->setText(QCoreApplication::translate("MW_projet", "Complexit\303\251:", nullptr));
        label_15->setText(QCoreApplication::translate("MW_projet", "Nom du projet:", nullptr));
        label_21->setText(QCoreApplication::translate("MW_projet", "Date de d\303\251but:", nullptr));
        label_22->setText(QCoreApplication::translate("MW_projet", "Date de fin:", nullptr));
        label_19->setText(QCoreApplication::translate("MW_projet", "Client:", nullptr));
        doubleSpinBox_budget->setSuffix(QCoreApplication::translate("MW_projet", " DT", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MW_projet", "Ajouter", nullptr));
        label_36->setText(QCoreApplication::translate("MW_projet", "Employ\303\251e", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MW_projet", "Ajouter Un Projet", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MW_projet", "Modifier", nullptr));
        label_30->setText(QCoreApplication::translate("MW_projet", "Date de fin:", nullptr));
        label_31->setText(QCoreApplication::translate("MW_projet", "Employ\303\251e", nullptr));
        label_29->setText(QCoreApplication::translate("MW_projet", "Date de d\303\251but:", nullptr));
        label_27->setText(QCoreApplication::translate("MW_projet", "Client:", nullptr));
        comboBox_statut_2->setItemText(0, QCoreApplication::translate("MW_projet", "En attente", nullptr));
        comboBox_statut_2->setItemText(1, QCoreApplication::translate("MW_projet", "En cours", nullptr));
        comboBox_statut_2->setItemText(2, QCoreApplication::translate("MW_projet", "Termin\303\251", nullptr));
        comboBox_statut_2->setItemText(3, QCoreApplication::translate("MW_projet", "Annul\303\251", nullptr));

        comboBox_complexite_2->setItemText(0, QCoreApplication::translate("MW_projet", "Faible", nullptr));
        comboBox_complexite_2->setItemText(1, QCoreApplication::translate("MW_projet", "Moyenne", nullptr));
        comboBox_complexite_2->setItemText(2, QCoreApplication::translate("MW_projet", "\303\211lev\303\251e", nullptr));

        label_3->setText(QCoreApplication::translate("MW_projet", "Nom du projet:", nullptr));
        label_14->setText(QCoreApplication::translate("MW_projet", "Complexit\303\251:", nullptr));
        label_26->setText(QCoreApplication::translate("MW_projet", "Budget:", nullptr));
        label_25->setText(QCoreApplication::translate("MW_projet", "Statut:", nullptr));
        doubleSpinBox_budget_2->setSuffix(QCoreApplication::translate("MW_projet", " DT", nullptr));
        label_24->setText(QCoreApplication::translate("MW_projet", "S\303\251lectionner un projet:", nullptr));
        pushButton_charger->setText(QCoreApplication::translate("MW_projet", "Charger", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MW_projet", "Modifier Un Projet ", nullptr));
        groupBox_prediction_form->setTitle(QCoreApplication::translate("MW_projet", "S\303\251lection du Projet", nullptr));
        label_select_project->setText(QCoreApplication::translate("MW_projet", "Projet :", nullptr));
        label_title->setText(QCoreApplication::translate("MW_projet", "Titre du projet :", nullptr));
        label_complexity->setText(QCoreApplication::translate("MW_projet", "Complexit\303\251 :", nullptr));
        label_status->setText(QCoreApplication::translate("MW_projet", "Statut :", nullptr));
        pushButton_predict->setText(QCoreApplication::translate("MW_projet", "Pr\303\251dire", nullptr));
        groupBox_prediction_result->setTitle(QCoreApplication::translate("MW_projet", "R\303\251sultat de la Pr\303\251diction", nullptr));
        label_predicted_duration->setText(QCoreApplication::translate("MW_projet", "Dur\303\251e Pr\303\251dite : ", nullptr));
        label_risk->setText(QCoreApplication::translate("MW_projet", "Risque de Retard : ", nullptr));
        label_advice->setText(QCoreApplication::translate("MW_projet", "Conseil : ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MW_projet", "Planification Pr\303\251dictive", nullptr));
        label_5->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MW_projet", "Client", nullptr));
        label_9->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MW_projet", "RDV", nullptr));
        label_10->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MW_projet", "Projet", nullptr));
        label_34->setText(QString());
        label_11->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MW_projet", "Consultant", nullptr));
        label_7->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MW_projet", "R\303\251clamation", nullptr));
        label_33->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MW_projet: public Ui_MW_projet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
