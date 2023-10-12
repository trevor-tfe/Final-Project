/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *AddDeliveryButton;
    QPushButton *GetDeliveryButton;
    QPushButton *PrintDeliveryButton;
    QPushButton *ExDeliveryButton;
    QStackedWidget *stackedWidget;
    QWidget *NewDelivery;
    QLabel *label;
    QTextEdit *contactText;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *addressText;
    QLabel *label_5;
    QTextEdit *phoneText;
    QLabel *label_6;
    QDateEdit *scheduleInfo;
    QCommandLinkButton *addNewDelivery;
    QWidget *NextDelivery;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *ContactInfo;
    QLabel *AddressInfo;
    QLabel *PhoneInfo;
    QLabel *ScheduleInfo;
    QMenuBar *menubar;
    QMenu *menuFinal_Project;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(690, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        AddDeliveryButton = new QPushButton(centralwidget);
        AddDeliveryButton->setObjectName("AddDeliveryButton");
        AddDeliveryButton->setGeometry(QRect(10, 10, 111, 31));
        GetDeliveryButton = new QPushButton(centralwidget);
        GetDeliveryButton->setObjectName("GetDeliveryButton");
        GetDeliveryButton->setGeometry(QRect(130, 10, 111, 31));
        PrintDeliveryButton = new QPushButton(centralwidget);
        PrintDeliveryButton->setObjectName("PrintDeliveryButton");
        PrintDeliveryButton->setGeometry(QRect(250, 10, 111, 31));
        ExDeliveryButton = new QPushButton(centralwidget);
        ExDeliveryButton->setObjectName("ExDeliveryButton");
        ExDeliveryButton->setGeometry(QRect(370, 10, 111, 31));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 50, 691, 501));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        NewDelivery = new QWidget();
        NewDelivery->setObjectName("NewDelivery");
        NewDelivery->setAcceptDrops(true);
        NewDelivery->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 200, 150);"));
        label = new QLabel(NewDelivery);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 20, 101, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        contactText = new QTextEdit(NewDelivery);
        contactText->setObjectName("contactText");
        contactText->setGeometry(QRect(130, 60, 421, 41));
        contactText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color:rgb(0, 0, 0);"));
        label_3 = new QLabel(NewDelivery);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 70, 71, 21));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_4 = new QLabel(NewDelivery);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 130, 71, 21));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        addressText = new QTextEdit(NewDelivery);
        addressText->setObjectName("addressText");
        addressText->setGeometry(QRect(130, 120, 421, 41));
        addressText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color:rgb(0, 0, 0);"));
        label_5 = new QLabel(NewDelivery);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 190, 71, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        phoneText = new QTextEdit(NewDelivery);
        phoneText->setObjectName("phoneText");
        phoneText->setGeometry(QRect(130, 180, 421, 41));
        phoneText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color:rgb(0, 0, 0);"));
        label_6 = new QLabel(NewDelivery);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 250, 71, 21));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        scheduleInfo = new QDateEdit(NewDelivery);
        scheduleInfo->setObjectName("scheduleInfo");
        scheduleInfo->setGeometry(QRect(130, 240, 421, 41));
        scheduleInfo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        scheduleInfo->setCalendarPopup(true);
        addNewDelivery = new QCommandLinkButton(NewDelivery);
        addNewDelivery->setObjectName("addNewDelivery");
        addNewDelivery->setGeometry(QRect(290, 360, 131, 41));
        addNewDelivery->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"background-color: rgb(0, 85, 0);\n"
"border-color: rgb(0, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(NewDelivery);
        NextDelivery = new QWidget();
        NextDelivery->setObjectName("NextDelivery");
        NextDelivery->setAcceptDrops(true);
        NextDelivery->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 200);"));
        label_2 = new QLabel(NextDelivery);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 20, 101, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7 = new QLabel(NextDelivery);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 70, 71, 21));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_8 = new QLabel(NextDelivery);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 130, 71, 21));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9 = new QLabel(NextDelivery);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 190, 71, 21));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_10 = new QLabel(NextDelivery);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(50, 250, 71, 21));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        ContactInfo = new QLabel(NextDelivery);
        ContactInfo->setObjectName("ContactInfo");
        ContactInfo->setGeometry(QRect(150, 70, 71, 21));
        ContactInfo->setFont(font);
        ContactInfo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        AddressInfo = new QLabel(NextDelivery);
        AddressInfo->setObjectName("AddressInfo");
        AddressInfo->setGeometry(QRect(150, 130, 71, 21));
        AddressInfo->setFont(font);
        AddressInfo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        PhoneInfo = new QLabel(NextDelivery);
        PhoneInfo->setObjectName("PhoneInfo");
        PhoneInfo->setGeometry(QRect(150, 190, 71, 21));
        PhoneInfo->setFont(font);
        PhoneInfo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        ScheduleInfo = new QLabel(NextDelivery);
        ScheduleInfo->setObjectName("ScheduleInfo");
        ScheduleInfo->setGeometry(QRect(150, 250, 71, 21));
        ScheduleInfo->setFont(font);
        ScheduleInfo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(NextDelivery);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 690, 21));
        menuFinal_Project = new QMenu(menubar);
        menuFinal_Project->setObjectName("menuFinal_Project");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFinal_Project->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AddDeliveryButton->setText(QCoreApplication::translate("MainWindow", "Add New Delivery", nullptr));
        GetDeliveryButton->setText(QCoreApplication::translate("MainWindow", "Get Next Delivery", nullptr));
        PrintDeliveryButton->setText(QCoreApplication::translate("MainWindow", "Print Next Delivery", nullptr));
        ExDeliveryButton->setText(QCoreApplication::translate("MainWindow", "Export Deliveries", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "New Delivery", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Contact", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Schedule", nullptr));
        addNewDelivery->setText(QCoreApplication::translate("MainWindow", "Add Delivery", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Next Delivery", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Contact", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Schedule", nullptr));
        ContactInfo->setText(QCoreApplication::translate("MainWindow", "Contact", nullptr));
        AddressInfo->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        PhoneInfo->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        ScheduleInfo->setText(QCoreApplication::translate("MainWindow", "Schedule", nullptr));
        menuFinal_Project->setTitle(QCoreApplication::translate("MainWindow", "Final Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
