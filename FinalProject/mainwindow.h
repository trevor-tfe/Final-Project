
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "delivery.h"
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void createScheduledDelivery(string contact, string address, string phone, string schedule, priority_queue<Delivery> &docket){
        int month = stoi(schedule.substr(0, 1));
        int day = stoi(schedule.substr(3, 4));
        int year = stoi(schedule.substr(6, 9));
        int days = 0;
        days += (year-1900)*365;
        for (int i = 0; i < month-1; i++){
            days += monthDays[i];
        }
        days += day;
        Delivery nd = Delivery(contact, address, phone, days, schedule);
        docket.emplace(nd);
    }

    void printNextDelivery(std::priority_queue<Delivery> &docket){
        cout << "Delivery Printing" << endl;
        ofstream fout;
        fout.open("delivery.txt");
        Delivery del = docket.top();
        list<Inventory> inv = del.GetItems();
        docket.pop();

        fout << "Contact: " << del.GetContact() << endl;
        fout << "Address: " << del.GetAddress() << endl;
        fout << "Phone: " << del.GetPhone() << endl;
        fout << "_________________________________________" << endl;
        fout << "Items" << endl;
        for (auto it = inv.begin(); it != inv.end(); it++){
            fout << "Item: " << it->GetName();
            fout << " SKU: " << it->GetSKU();
            fout << " Price: " << it->GetPrice();
            fout << " Count: " << it->GetStock() << endl;
        }
    }

public: signals:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
