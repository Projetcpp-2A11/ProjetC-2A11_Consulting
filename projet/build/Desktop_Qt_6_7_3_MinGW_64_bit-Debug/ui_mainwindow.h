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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QWidget *widget_11;
    QLabel *label_18;
    QLineEdit *nom;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_19;
    QPushButton *ajouter;
    QLabel *label_36;
    QComboBox *list;
    QLabel *label_37;
    QLineEdit *prenom;
    QLineEdit *email;
    QLineEdit *tele;
    QLineEdit *histo;
    QLineEdit *eval;
    QLineEdit *spec;
    QRadioButton *oui;
    QRadioButton *non;
    QWidget *tab;
    QWidget *widget_3;
    QTableWidget *tableau;
    QLabel *label_2;
    QComboBox *tri;
    QLabel *label_35;
    QPushButton *supp;
    QPushButton *pdf;
    QLabel *label_6;
    QLineEdit *search;
    QLineEdit *id_supp;
    QPushButton *mod;
    QPushButton *search_s;
    QWidget *tab_3;
    QWidget *widget_12;
    QLineEdit *lineEdit_id;
    QPushButton *pushButton_charger;
    QWidget *tab_4;
    QWidget *widget_13;
    QLineEdit *lineEdit_id_2;
    QWidget *tab_5;
    QWidget *widget_14;
    QLineEdit *lineEdit_id_3;
    QPushButton *pushButton_charger_2;
    QPushButton *pushButton;
    QLabel *label_5;
    QWidget *widget_5;
    QPushButton *pushButton_5;
    QLabel *client;
    QWidget *widget_6;
    QPushButton *pushButton_6;
    QLabel *rdv;
    QWidget *widget_8;
    QPushButton *pushButton_8;
    QLabel *projet;
    QWidget *widget_9;
    QLabel *label_11;
    QPushButton *pushButton_9;
    QLabel *consultant;
    QWidget *widget_7;
    QPushButton *reclamation;
    QLabel *label_33;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1665, 1246);
        centralwidget = new QWidget(MainWindow);
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
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        widget_11 = new QWidget(tab_2);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(0, 0, 1298, 583));
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        label_18 = new QLabel(widget_11);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(21, 171, 79, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(12);
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        nom = new QLineEdit(widget_11);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(199, 21, 1071, 30));
        nom->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka")});
        font1.setPointSize(10);
        nom->setFont(font1);
        nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"color: black; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        label_17 = new QLabel(widget_11);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(21, 121, 69, 20));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_16 = new QLabel(widget_11);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(21, 71, 121, 20));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_15 = new QLabel(widget_11);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(21, 21, 154, 20));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_21 = new QLabel(widget_11);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(21, 300, 147, 20));
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_22 = new QLabel(widget_11);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(21, 350, 131, 20));
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_19 = new QLabel(widget_11);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 230, 101, 20));
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        ajouter = new QPushButton(widget_11);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(1190, 530, 88, 32));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka")});
        font2.setBold(true);
        ajouter->setFont(font2);
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_36->setFont(font);
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        list = new QComboBox(widget_11);
        list->addItem(QString());
        list->addItem(QString());
        list->addItem(QString());
        list->addItem(QString());
        list->addItem(QString());
        list->addItem(QString());
        list->setObjectName("list");
        list->setGeometry(QRect(200, 230, 1061, 22));
        list->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"color: black; \n"
"}\n"
"\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"	color: black; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"color: black; \n"
"}"));
        label_37 = new QLabel(widget_11);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(30, 450, 120, 20));
        label_37->setFont(font);
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        prenom = new QLineEdit(widget_11);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(200, 70, 1075, 30));
        prenom->setMinimumSize(QSize(0, 30));
        prenom->setFont(font1);
        prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"color: black; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        email = new QLineEdit(widget_11);
        email->setObjectName("email");
        email->setGeometry(QRect(200, 120, 1075, 30));
        email->setMinimumSize(QSize(0, 30));
        email->setFont(font1);
        email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"color: black; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        tele = new QLineEdit(widget_11);
        tele->setObjectName("tele");
        tele->setGeometry(QRect(200, 170, 1075, 30));
        tele->setMinimumSize(QSize(0, 30));
        tele->setFont(font1);
        tele->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"color: black; \n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        histo = new QLineEdit(widget_11);
        histo->setObjectName("histo");
        histo->setGeometry(QRect(200, 340, 1075, 30));
        histo->setMinimumSize(QSize(0, 30));
        histo->setFont(font1);
        histo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"color: black; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        eval = new QLineEdit(widget_11);
        eval->setObjectName("eval");
        eval->setGeometry(QRect(200, 390, 1075, 30));
        eval->setMinimumSize(QSize(0, 30));
        eval->setFont(font1);
        eval->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"color: black; \n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        spec = new QLineEdit(widget_11);
        spec->setObjectName("spec");
        spec->setGeometry(QRect(200, 450, 1075, 30));
        spec->setMinimumSize(QSize(0, 30));
        spec->setFont(font1);
        spec->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"color: black; \n"
"\n"
"    padding: 5px;\n"
"}\n"
"\n"
"\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        oui = new QRadioButton(widget_11);
        oui->setObjectName("oui");
        oui->setGeometry(QRect(200, 300, 61, 18));
        oui->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 12pt \"Segoe UI\";"));
        non = new QRadioButton(widget_11);
        non->setObjectName("non");
        non->setGeometry(QRect(1170, 290, 61, 18));
        non->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 12pt \"Segoe UI\";"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        widget_3 = new QWidget(tab);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 1331, 1021));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        tableau = new QTableWidget(widget_3);
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
        if (tableau->rowCount() < 1)
            tableau->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableau->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableau->setItem(0, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableau->setItem(0, 2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableau->setItem(0, 3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableau->setItem(0, 4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableau->setItem(0, 5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableau->setItem(0, 6, __qtablewidgetitem14);
        tableau->setObjectName("tableau");
        tableau->setGeometry(QRect(150, 90, 621, 391));
        tableau->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #f8f9fa; /* Light gray background */\n"
"    border: 2px solid #4D6F50; /* Green border */\n"
"    gridline-color: #cccccc; /* Light gray grid lines */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #4D6F50; /* Green header */\n"
"    color: black;\n"
"    padding: 5px;\n"
"    border: 1px solid #3B5D40;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"    color: black; /* Add this line */\n"
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
        label_2->setGeometry(QRect(150, 50, 131, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka")});
        font3.setPointSize(14);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tri = new QComboBox(widget_3);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(250, 50, 201, 26));
        tri->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"	color : black;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #4D6F50;\n"
"    border-left-style: solid;\n"
"	color : black;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"	color: black; \n"
"}"));
        label_35 = new QLabel(widget_3);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(130, 570, 151, 21));
        label_35->setFont(font3);
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        supp = new QPushButton(widget_3);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(350, 560, 101, 31));
        supp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pdf = new QPushButton(widget_3);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(810, 180, 141, 61));
        pdf->setFont(font2);
        pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_6 = new QLabel(widget_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(490, 60, 131, 21));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        search = new QLineEdit(widget_3);
        search->setObjectName("search");
        search->setGeometry(QRect(590, 50, 171, 30));
        search->setMinimumSize(QSize(0, 30));
        search->setFont(font1);
        search->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"	color: black; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        id_supp = new QLineEdit(widget_3);
        id_supp->setObjectName("id_supp");
        id_supp->setGeometry(QRect(240, 560, 81, 30));
        id_supp->setMinimumSize(QSize(0, 30));
        id_supp->setFont(font1);
        id_supp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #4D6F50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"color: black; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6A9E70;\n"
"}"));
        mod = new QPushButton(widget_3);
        mod->setObjectName("mod");
        mod->setGeometry(QRect(810, 410, 141, 61));
        mod->setFont(font2);
        mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        search_s = new QPushButton(widget_3);
        search_s->setObjectName("search_s");
        search_s->setGeometry(QRect(790, 50, 91, 31));
        search_s->setFont(font2);
        search_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_charger = new QPushButton(widget_12);
        pushButton_charger->setObjectName("pushButton_charger");
        pushButton_charger->setGeometry(QRect(858, 34, 92, 32));
        pushButton_charger->setFont(font2);
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
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        widget_13 = new QWidget(tab_4);
        widget_13->setObjectName("widget_13");
        widget_13->setGeometry(QRect(0, 0, 1331, 1021));
        widget_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        lineEdit_id_2 = new QLineEdit(widget_13);
        lineEdit_id_2->setObjectName("lineEdit_id_2");
        lineEdit_id_2->setGeometry(QRect(20, 550, 113, 22));
        lineEdit_id_2->setVisible(false);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        widget_14 = new QWidget(tab_5);
        widget_14->setObjectName("widget_14");
        widget_14->setGeometry(QRect(-90, -70, 1331, 1021));
        widget_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        lineEdit_id_3 = new QLineEdit(widget_14);
        lineEdit_id_3->setObjectName("lineEdit_id_3");
        lineEdit_id_3->setGeometry(QRect(20, 550, 113, 22));
        lineEdit_id_3->setVisible(false);
        pushButton_charger_2 = new QPushButton(widget_14);
        pushButton_charger_2->setObjectName("pushButton_charger_2");
        pushButton_charger_2->setGeometry(QRect(858, 34, 92, 32));
        pushButton_charger_2->setFont(font2);
        pushButton_charger_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton = new QPushButton(widget_14);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 270, 80, 18));
        tabWidget->addTab(tab_5, QString());
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
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        client = new QLabel(widget_5);
        client->setObjectName("client");
        client->setGeometry(QRect(30, 30, 63, 61));
        client->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(:/Tools Interface/circle-user-solid.svg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-color: transparent; /* Optional: keep background clear */\n"
"}\n"
""));
        client->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/circle-user-solid.svg")));
        client->setScaledContents(true);
        widget_6 = new QWidget(scrollAreaWidgetContents);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(20, 260, 120, 121));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        pushButton_6 = new QPushButton(widget_6);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(15, 90, 93, 29));
        pushButton_6->setFont(font5);
        pushButton_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        rdv = new QLabel(widget_6);
        rdv->setObjectName("rdv");
        rdv->setGeometry(QRect(30, 20, 63, 61));
        rdv->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/calendar-days-solid.svg")));
        rdv->setScaledContents(true);
        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(20, 390, 120, 121));
        widget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        pushButton_8 = new QPushButton(widget_8);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(15, 90, 93, 29));
        pushButton_8->setFont(font5);
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        projet = new QLabel(widget_8);
        projet->setObjectName("projet");
        projet->setGeometry(QRect(20, 20, 81, 71));
        projet->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(:/Tools Interface/briefcase-solid.svg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-color: transparent; /* Optional: keep background clear */\n"
"}\n"
""));
        projet->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/briefcase-solid.svg")));
        projet->setScaledContents(true);
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
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        consultant = new QLabel(widget_9);
        consultant->setObjectName("consultant");
        consultant->setGeometry(QRect(20, 10, 81, 71));
        consultant->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/hands-holding-child-solid.svg")));
        consultant->setScaledContents(true);
        widget_7 = new QWidget(scrollAreaWidgetContents);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(20, 650, 121, 121));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:9px;"));
        reclamation = new QPushButton(widget_7);
        reclamation->setObjectName("reclamation");
        reclamation->setGeometry(QRect(0, 80, 121, 29));
        reclamation->setFont(font5);
        reclamation->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_33 = new QLabel(widget_7);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(20, 10, 81, 71));
        label_33->setPixmap(QPixmap(QString::fromUtf8(":/Tools Interface/message-solid.svg")));
        label_33->setScaledContents(true);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setGeometry(QRect(376, -9, 231, 91));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_5->raise();
        tabWidget->raise();
        widget_5->raise();
        widget_6->raise();
        widget_8->raise();
        widget_9->raise();
        widget_7->raise();
        label->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1665, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MW_projet", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Historique Missions:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Experience:", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Evaluation:", nullptr));
        list->setItemText(0, QCoreApplication::translate("MainWindow", "Donner Votre Exp\303\251rience", nullptr));
        list->setItemText(1, QCoreApplication::translate("MainWindow", "1 an", nullptr));
        list->setItemText(2, QCoreApplication::translate("MainWindow", "2 ans", nullptr));
        list->setItemText(3, QCoreApplication::translate("MainWindow", "3 ans", nullptr));
        list->setItemText(4, QCoreApplication::translate("MainWindow", "4 ans", nullptr));
        list->setItemText(5, QCoreApplication::translate("MainWindow", "5 ans", nullptr));

        label_37->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialisation:", nullptr));
        oui->setText(QCoreApplication::translate("MainWindow", "Oui", nullptr));
        non->setText(QCoreApplication::translate("MainWindow", "Non", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Ajouter Un Consultant", nullptr));
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

        const bool __sortingEnabled = tableau->isSortingEnabled();
        tableau->setSortingEnabled(false);
        tableau->setSortingEnabled(__sortingEnabled);

        label_2->setText(QCoreApplication::translate("MainWindow", "Trier Par :", nullptr));
        tri->setItemText(0, QCoreApplication::translate("MainWindow", "Votre Choix:", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        tri->setItemText(2, QCoreApplication::translate("MainWindow", "Sp\303\251cialisation", nullptr));

        label_35->setText(QCoreApplication::translate("MainWindow", "Choisir L'ID :", nullptr));
        supp->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Recherche :", nullptr));
        mod->setText(QCoreApplication::translate("MainWindow", "Modification", nullptr));
        search_s->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Liste Des Consultants", nullptr));
        pushButton_charger->setText(QCoreApplication::translate("MainWindow", "Charger", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Les Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "TO DO LIST", nullptr));
        pushButton_charger_2->setText(QCoreApplication::translate("MainWindow", "Charger", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Chatbot", nullptr));
        label_5->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        client->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "RDV", nullptr));
        rdv->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        projet->setText(QString());
        label_11->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Consultant", nullptr));
        consultant->setText(QString());
        reclamation->setText(QCoreApplication::translate("MainWindow", "R\303\251clamation", nullptr));
        label_33->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
