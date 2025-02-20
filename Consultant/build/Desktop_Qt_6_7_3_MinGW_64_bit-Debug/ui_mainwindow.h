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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *Consultant;
    QLabel *Neo;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_5;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_6;
    QTextEdit *textEdit_5;
    QLabel *label_7;
    QTextEdit *textEdit_6;
    QPushButton *Reset;
    QPushButton *Submit;
    QLabel *Background;
    QMenuBar *menubar;
    QMenu *menuGestion_de_Consultant;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(523, 389);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-10, -11, 531, 91));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 51, 102);"));
        Consultant = new QLabel(widget);
        Consultant->setObjectName("Consultant");
        Consultant->setGeometry(QRect(410, 60, 101, 16));
        Consultant->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        Neo = new QLabel(widget);
        Neo->setObjectName("Neo");
        Neo->setGeometry(QRect(30, 50, 101, 31));
        Neo->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe Fluent Icons\";\n"
"text-decoration: underline;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 71, 16));
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 150, 37, 12));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 200, 51, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 120, 111, 21));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white; /* Background color */\n"
"    color: black; /* Text color */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 5px; /* Optional: Slightly rounded corners */\n"
"    padding: 5px; /* Ensures text isn't too close to the edges */\n"
"}\n"
""));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(20, 170, 111, 21));
        textEdit_2->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white; /* Background color */\n"
"    color: black; /* Text color */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 5px; /* Optional: Slightly rounded corners */\n"
"    padding: 5px; /* Ensures text isn't too close to the edges */\n"
"}\n"
""));
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(20, 220, 111, 21));
        textEdit_3->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white; /* Background color */\n"
"    color: black; /* Text color */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 5px; /* Optional: Slightly rounded corners */\n"
"    padding: 5px; /* Ensures text isn't too close to the edges */\n"
"}\n"
""));
        textEdit_4 = new QTextEdit(centralwidget);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(20, 270, 111, 21));
        textEdit_4->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white; /* Background color */\n"
"    color: black; /* Text color */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 5px; /* Optional: Slightly rounded corners */\n"
"    padding: 5px; /* Ensures text isn't too close to the edges */\n"
"}\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 250, 71, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 310, 111, 22));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white; /* Background color */\n"
"    color: black; /* Text color */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 5px; /* Rounded border */\n"
"    padding: 5px; /* Space inside */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: rgb(240, 240, 240); /* Slightly lighter background on hover */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none; /* Remove the default dropdown border */\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/down-arrow.png); /* Optional: Custom dropdown arrow */\n"
"    width: 14px;\n"
"    height: 14px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white; /* Dropdown list background */\n"
"    color: black; /* Dropdown text color */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border for dropdown list */\n"
"    selection-background-color: rgb(0, 51, 102); /* Background when an item is selected */\n"
"    selection-color: white; /* Tex"
                        "t color when selected */\n"
"}\n"
""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 100, 71, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(380, 130, 58, 18));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    color: white; /* Text color */\n"
"    spacing: 5px; /* Space between checkbox and text */\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 3px; /* Slightly rounded edges */\n"
"    background-color: white; /* Checkbox background */\n"
"}\n"
"\n"
"QCheckBox::indicator:hover {\n"
"    background-color: rgb(240, 240, 240); /* Light background on hover */\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: rgb(0, 51, 102); /* Background when checked */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border stays the same */\n"
"    image: url(:/checkmark.png); /* Optional: Custom checkmark */\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white; /* Unchecked background */\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover {\n"
"    background-color: rgb(0, 61, 122); /* Slightly lighter blue when checked & hovered */\n"
"}\n"
""));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(440, 130, 58, 18));
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    color: white; /* Text color */\n"
"    spacing: 5px; /* Space between checkbox and text */\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 3px; /* Slightly rounded edges */\n"
"    background-color: white; /* Checkbox background */\n"
"}\n"
"\n"
"QCheckBox::indicator:hover {\n"
"    background-color: rgb(240, 240, 240); /* Light background on hover */\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: rgb(0, 51, 102); /* Background when checked */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border stays the same */\n"
"    image: url(:/checkmark.png); /* Optional: Custom checkmark */\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white; /* Unchecked background */\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover {\n"
"    background-color: rgb(0, 61, 122); /* Slightly lighter blue when checked & hovered */\n"
"}\n"
""));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 160, 111, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        textEdit_5 = new QTextEdit(centralwidget);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(380, 190, 104, 21));
        textEdit_5->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white; /* Background color */\n"
"    color: black; /* Text color */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 5px; /* Optional: Slightly rounded corners */\n"
"    padding: 5px; /* Ensures text isn't too close to the edges */\n"
"}\n"
""));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(380, 230, 91, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        textEdit_6 = new QTextEdit(centralwidget);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(380, 250, 104, 21));
        textEdit_6->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white; /* Background color */\n"
"    color: black; /* Text color */\n"
"    border: 2px solid rgb(0, 51, 102); /* Border color */\n"
"    border-radius: 5px; /* Optional: Slightly rounded corners */\n"
"    padding: 5px; /* Ensures text isn't too close to the edges */\n"
"}\n"
""));
        Reset = new QPushButton(centralwidget);
        Reset->setObjectName("Reset");
        Reset->setGeometry(QRect(299, 310, 91, 31));
        Reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Text color */\n"
"    background-color: rgb(0, 51, 102); /* Background color */\n"
"    border: 2px solid rgb(173, 216, 230); /* Lime blue border */\n"
"    border-radius: 5px; /* Short rounded border */\n"
"    padding: 5px 10px; /* Small padding */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 61, 122); /* Slightly lighter blue on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 41, 82); /* Darker blue when clicked */\n"
"}\n"
""));
        Submit = new QPushButton(centralwidget);
        Submit->setObjectName("Submit");
        Submit->setGeometry(QRect(410, 310, 91, 31));
        Submit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Text color */\n"
"    background-color: rgb(0, 51, 102); /* Background color */\n"
"    border: 2px solid rgb(173, 216, 230); /* Lime blue border */\n"
"    border-radius: 5px; /* Short rounded border */\n"
"    padding: 5px 10px; /* Small padding */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 61, 122); /* Slightly lighter blue on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 41, 82); /* Darker blue when clicked */\n"
"}\n"
""));
        Background = new QLabel(centralwidget);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 80, 521, 271));
        Background->setPixmap(QPixmap(QString::fromUtf8("bg.jpg")));
        Background->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        Background->raise();
        widget->raise();
        label->raise();
        label_3->raise();
        label_4->raise();
        textEdit->raise();
        textEdit_2->raise();
        textEdit_3->raise();
        textEdit_4->raise();
        label_2->raise();
        comboBox->raise();
        label_5->raise();
        checkBox->raise();
        checkBox_2->raise();
        label_6->raise();
        textEdit_5->raise();
        label_7->raise();
        textEdit_6->raise();
        Reset->raise();
        Submit->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 523, 17));
        menuGestion_de_Consultant = new QMenu(menubar);
        menuGestion_de_Consultant->setObjectName("menuGestion_de_Consultant");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGestion_de_Consultant->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Consultant->setText(QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        Neo->setText(QCoreApplication::translate("MainWindow", "NeoConseil", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom et pr\303\251nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialisation ", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Exp\303\251rience", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "+1", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "+2", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "+3", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "+4", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "+5", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "+..", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251 ", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Oui", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Non", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Historique missions", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\303\211valuation", nullptr));
        Reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        Submit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        Background->setText(QString());
        menuGestion_de_Consultant->setTitle(QCoreApplication::translate("MainWindow", "Gestion de Consultant", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
