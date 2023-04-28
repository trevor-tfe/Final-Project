/***************************************************************
* Name : Final Project - Inventory and Scheduling
* Author: Trevor Stewart
* Created : 04/01/2023
* Course: CIS 152 - Data Structure
* Version: 1.0
* OS: Windows 10
* IDE: VS Code and MSYS2
* Copyright : This is my own original work
* based onspecifications issued by our instructor
* Description : An app that sorts an array in different ways and returns
* the time it took to use each sort function.
*   Input: Delivery schedule and dates
*   Ouput: Display and print delivery receipts.
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access
* to my program.
***************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inventory.cpp"
#include "delivery.cpp"
#include "mainwindow.h"
#include <QApplication>
using namespace std;

inline
    bool operator<(Delivery lhs, Delivery rhs){
    return lhs.GetSchedule() < rhs.GetSchedule();
}

inline
    bool operator>(Delivery lhs, Delivery rhs){
    return lhs.GetSchedule() > rhs.GetSchedule();
}

//Takes a list and inserts inventory items into it.
void ImportInventory(list<Inventory> &currStock){
    fstream fInv;
    fInv.open("inventory.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    //Checks for end of file and ends while loop
    while (!fInv.eof()){
        //clears row info
        row.clear();

        //Gets row info
        getline(fInv, line);
        //Creates new stringstream from info
        stringstream s(line);

        //Inserts each word into the vector
        while (getline(s, word, ',')){
            row.push_back(word);
        }
        //1. Name, 2. SKU, 3. Price, 4. Stock
        int stk = stoi(row.back());
        row.pop_back();
        double pr = stod(row.back());
        row.pop_back();
        int sku = stoi(row.back());
        row.pop_back();
        string n = row.back();
        row.pop_back();

        currStock.push_back(Inventory(n, sku, pr, stk));
    }
    fInv.close();
}

void UpdateInventory(){

}

void ImportDeliveries(list<Delivery> &unscheduled, priority_queue<Delivery> &docket){
    fstream fInv;
    fInv.open("deliveries.csv", ios::in);
    string row[6] = {"Error", "Incorrect Road", "45012", "04/27/2023", "Chair:50504:24.56:5"};
    string line, inv, word, temp;
    int attempts = 0;
    while (!fInv.eof() && attempts < 10){
        attempts++;
        getline(fInv, line);
        stringstream s(line);
        int it = 0;
        while (getline(s, word, ',')){
            if (it < 6){
                row[it] = word;
            }
            it++;
        }
        //0: Name, 1: Address, 2: Phone, 3: Schedule, 4: Schedule String, 5: Inventory
        if (row[5] == "0"){
            unscheduled.push_back(Delivery(row[0], row[1], row[2], stoi(row[3]), row[4]));
        } else {
            unscheduled.push_back(Delivery(row[0], row[1], row[2], stoi(row[3]), row[4]));
            stringstream sinv(row[5]);
            string invVec[4] = {"Chair","50504","24.56","5"};
            int vit = 0;
            while (getline(sinv, inv, ':')){
                //1. Name, 2. SKU, 3. Price, 4. Stock
                if (vit < 4){
                    invVec[vit] = inv;
                    vit++;
                }
            }
            unscheduled.back().AddItem(Inventory(invVec[0], stoi(invVec[1]), stod(invVec[2]), stoi(invVec[3])));
            docket.emplace(unscheduled.back());
            unscheduled.pop_back();
        }
    }
    fInv.close();
}

void printNextDelivery(priority_queue<string> &docket){
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

priority_queue<Delivery> createScheduledDelivery(string contact, string address, string phone, string schedule, priority_queue<Delivery> docket){
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
    return docket;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    list<Inventory> currentStock;
    list<Delivery> unscheduled;
    priority_queue<Delivery> docket;

//    ImportInventory(currentStock);
    ImportDeliveries(unscheduled, docket);

    ui->stackedWidget->setCurrentIndex(0);

    QPushButton *AddDeliveryButton = new QPushButton;
    QPushButton *GetDeliveryButton = new QPushButton;
    QPushButton *PrintDeliveryButton = new QPushButton;

    connect(AddDeliveryButton, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(GetDeliveryButton, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    string contact = ui->contactText->toPlainText().toStdString();
    string address = ui->addressText->toPlainText().toStdString();
    string phone = ui->phoneText->toPlainText().toStdString();
    string schedule = ui->scheduleInfo->text().toStdString();

    QObject::connect(AddDeliveryButton, SIGNAL(clicked()), this, SLOT(docket = createScheduledDelivery(contact, address, phone, schedule, docket)));
    QObject::connect(PrintDeliveryButton, SIGNAL(clicked()), this, SLOT(printNextDelivery(docket)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


