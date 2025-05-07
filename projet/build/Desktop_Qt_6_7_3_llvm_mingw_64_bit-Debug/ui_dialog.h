/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_8;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QLabel *label_14;
    QPushButton *pushButton_13;
    QTabWidget *tabWidget;
    QWidget *widget;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLabel *label_21;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QLabel *label_24;
    QCalendarWidget *calendarWidget_3;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QTimeEdit *timeEdit;
    QPushButton *pushButton_25;
    QLabel *label_2;
    QWidget *Modifier;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QLabel *label_12;
    QLabel *label_18;
    QLabel *label_22;
    QCalendarWidget *calendarWidget_2;
    QLabel *label_23;
    QTimeEdit *timeEdit_2;
    QWidget *Statistiques;
    QLabel *label_11;
    QLabel *label_17;
    QWidget *tabWidgetPage4;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QPushButton *pushButton_14;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *pushButton_15;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *pushButton_10;
    QTableWidget *tableWidget;
    QPushButton *pushButton_11;
    QLabel *label_7;
    QPushButton *pushButton_6;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1260, 720);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        pushButton_8 = new QPushButton(Dialog);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(40, 510, 151, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 120, 151, 51));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 220, 151, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        pushButton_7 = new QPushButton(Dialog);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(40, 410, 151, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        pushButton_9 = new QPushButton(Dialog);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 600, 151, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_14 = new QLabel(Dialog);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 20, 161, 91));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_14->setTextFormat(Qt::TextFormat::RichText);
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        label_14->setScaledContents(true);
        pushButton_13 = new QPushButton(Dialog);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(1030, 50, 131, 29));
        pushButton_13->setStyleSheet(QString::fromUtf8("color : black;\n"
"background-color: rgb(81, 182, 182);"));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(260, 130, 951, 641));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(81, 182, 182);"));
        widget = new QWidget();
        widget->setObjectName("widget");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 50, 921, 431));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 241, 240);"));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 110, 121, 31));
        QFont font;
        font.setKerning(true);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 160, 161, 28));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(12, 12, 12);"));
        label_21 = new QLabel(widget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(40, 240, 131, 31));
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(30, 310, 161, 28));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(9, 9, 9);"));
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(330, 20, 291, 41));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_24 = new QLabel(widget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(420, 90, 121, 31));
        label_24->setFont(font);
        label_24->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        calendarWidget_3 = new QCalendarWidget(widget);
        calendarWidget_3->setObjectName("calendarWidget_3");
        calendarWidget_3->setGeometry(QRect(280, 180, 421, 261));
        calendarWidget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(7, 7, 7);"));
        pushButton_23 = new QPushButton(widget);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(760, 260, 121, 41));
        pushButton_23->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        pushButton_24 = new QPushButton(widget);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(770, 370, 121, 41));
        pushButton_24->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        timeEdit = new QTimeEdit(widget);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(420, 140, 118, 29));
        timeEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(13, 13, 13);"));
        pushButton_25 = new QPushButton(widget);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(690, 110, 121, 31));
        pushButton_25->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 150, 171, 551));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 241, 240);"));
        tabWidget->addTab(widget, QString());
        Modifier = new QWidget();
        Modifier->setObjectName("Modifier");
        label_8 = new QLabel(Modifier);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 50, 921, 431));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 241, 240);"));
        lineEdit_7 = new QLineEdit(Modifier);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(20, 160, 161, 28));
        lineEdit_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_8 = new QLineEdit(Modifier);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(20, 330, 161, 31));
        lineEdit_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_21 = new QPushButton(Modifier);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(750, 270, 121, 41));
        pushButton_21->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        pushButton_22 = new QPushButton(Modifier);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(750, 340, 121, 41));
        pushButton_22->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_12 = new QLabel(Modifier);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(300, 30, 291, 41));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_18 = new QLabel(Modifier);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 110, 121, 31));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_22 = new QLabel(Modifier);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(30, 280, 131, 31));
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        calendarWidget_2 = new QCalendarWidget(Modifier);
        calendarWidget_2->setObjectName("calendarWidget_2");
        calendarWidget_2->setGeometry(QRect(270, 180, 421, 261));
        calendarWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(7, 7, 7);"));
        label_23 = new QLabel(Modifier);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(410, 90, 121, 31));
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        timeEdit_2 = new QTimeEdit(Modifier);
        timeEdit_2->setObjectName("timeEdit_2");
        timeEdit_2->setGeometry(QRect(410, 140, 118, 29));
        timeEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(13, 13, 13);"));
        tabWidget->addTab(Modifier, QString());
        Statistiques = new QWidget();
        Statistiques->setObjectName("Statistiques");
        label_11 = new QLabel(Statistiques);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 50, 921, 431));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 241, 240);"));
        label_17 = new QLabel(Statistiques);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(300, 30, 291, 41));
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        tabWidget->addTab(Statistiques, QString());
        tabWidgetPage4 = new QWidget();
        tabWidgetPage4->setObjectName("tabWidgetPage4");
        lineEdit_5 = new QLineEdit(tabWidgetPage4);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(270, 60, 113, 28));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(tabWidgetPage4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 20, 431, 111));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 241, 240);"));
        comboBox_2 = new QComboBox(tabWidgetPage4);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(520, 60, 111, 28));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        comboBox = new QComboBox(tabWidgetPage4);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 60, 111, 28));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_14 = new QPushButton(tabWidgetPage4);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(160, 90, 101, 31));
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_15 = new QLabel(tabWidgetPage4);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(640, 10, 141, 41));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_16 = new QLabel(tabWidgetPage4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(130, 10, 161, 41));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        pushButton_15 = new QPushButton(tabWidgetPage4);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(790, 60, 91, 31));
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label_19 = new QLabel(tabWidgetPage4);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(490, 20, 431, 111));
        label_19->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 241, 240);"));
        label_20 = new QLabel(tabWidgetPage4);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 140, 911, 371));
        label_20->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 241, 240);"));
        pushButton_10 = new QPushButton(tabWidgetPage4);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(560, 470, 131, 29));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        tableWidget = new QTableWidget(tabWidgetPage4);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem9);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(170, 170, 701, 211));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(false);
        pushButton_11 = new QPushButton(tabWidgetPage4);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(210, 470, 131, 29));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        tabWidget->addTab(tabWidgetPage4, QString());
        label_20->raise();
        label_19->raise();
        label_10->raise();
        lineEdit_5->raise();
        comboBox_2->raise();
        comboBox->raise();
        pushButton_14->raise();
        label_15->raise();
        label_16->raise();
        pushButton_15->raise();
        pushButton_10->raise();
        tableWidget->raise();
        pushButton_11->raise();
        label_7 = new QLabel(Dialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 80, 101, 20));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        pushButton_6 = new QPushButton(Dialog);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(40, 320, 151, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(-10, -20, 1211, 131));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 105, 107);"));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Dialog", "Gestion rendez-vous", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">DASHBOARD</span></p></body></html>", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog", "Gestion Patients", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Dialog", "Gestion ressources", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Dialog", "Gestion Vaccins", nullptr));
        label_14->setText(QString());
        pushButton_13->setText(QCoreApplication::translate("Dialog", "D\303\251connexion", nullptr));
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("Dialog", "<html><head/><body><p>ajout</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_4->setText(QString());
        label_6->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\">Nom du Patient</p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:700; font-style:italic;\">Type de vaccin</span></p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Rendez-vous</span></p></body></html>", nullptr));
        label_24->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\">Time</p></body></html>", nullptr));
        pushButton_23->setText(QCoreApplication::translate("Dialog", "Valider", nullptr));
        pushButton_24->setText(QCoreApplication::translate("Dialog", "Retour", nullptr));
        pushButton_25->setText(QCoreApplication::translate("Dialog", "PDF", nullptr));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("Dialog", "Ajouter un rendez-vous", nullptr));
        label_8->setText(QString());
        pushButton_21->setText(QCoreApplication::translate("Dialog", "Valider", nullptr));
        pushButton_22->setText(QCoreApplication::translate("Dialog", "Retour", nullptr));
        label_12->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">MODIFIER RENDEZ-VOUS</span></p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\">Nom du Patient</p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:700; font-style:italic;\">Type de vaccin</span></p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_23->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\">Time</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Modifier), QCoreApplication::translate("Dialog", "modifier rendez-vous", nullptr));
        label_11->setText(QString());
        label_17->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">STATISTIQUES</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Statistiques), QString());
        label_10->setText(QString());
        pushButton_14->setText(QCoreApplication::translate("Dialog", "Rechercher", nullptr));
        label_15->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Tri</span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Recherche</span></p></body></html>", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Dialog", "Trier", nullptr));
        label_19->setText(QString());
        label_20->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("Dialog", "Export PDF", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Dialog", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Dialog", "Nom du patient", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Dialog", "type de vaccinn", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Dialog", "time", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Dialog", "date", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Dialog", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Dialog", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Dialog", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Dialog", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Dialog", "New Row", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Dialog", "Ajouter ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage4), QString());
        label_7->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:700;\">LAKAHNI</span></p></body></html>", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Dialog", "Gestion employ\303\251s", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
