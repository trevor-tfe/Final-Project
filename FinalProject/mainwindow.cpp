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
#include "main.cpp"
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include "mainwindow.h"
#include <QApplication>
using namespace std;

const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Inventory{
private:
    string name;
    int SKU;
    double price;
    int stock;
public:
    //CONSTRUCTORS
    Inventory(){}
    Inventory(string s){this->name = s;}
    Inventory(string s, int k){this->name = s; this->SKU = k;}
    Inventory(string s, int k, double p){this->name = s; this->SKU = k; this->price = p;}
    Inventory(string s, int k, double p, int st){this->name = s; this->SKU = k; this->price = p; this->stock = st;}
    //SETTERS
    void SetName(string s){this->name = s;}
    void SetSKU(int k){this->SKU = k;}
    void SetPrice(double p){this->price = p;}
    void SetStock(int s){this->stock = s;}
    //GETTERS
    string GetName(){return this->name;}
    int GetSKU(){return this->SKU;}
    double GetPrice(){return this->price;}
    int GetStock(){return this->stock;}
    string ToString(){return name + "," + to_string(SKU) + "," + to_string(price) + "," + to_string(stock);}
};

class Delivery{
private:
    string contact;
    string address;
    string phone;
    int schedule = 0;
    string schedString;
    list <Inventory> items;
public:
    //Constructors
    Delivery(){}
    Delivery(string c){this->contact = c;}
    Delivery(string c, string a){this->contact = c; this->address = a;}
    Delivery(string c, string a, string p){this->contact = c; this->address = a; this->phone = p;}
    Delivery(string c, string a, string p, int s, string ss){
        this->contact = c;
        this->address = a;
        this->phone = p;
        this->schedule = s;
        this->schedString = ss;
    }
    //Setters
    void SetContact(string c){this->contact = c;}
    void SetAddress(string a){this->address = a;}
    void SetPhone(string p){this->phone = p;}
    void AddItem(Inventory i){this->items.push_back(i);}
    void AddItemList(string s, list<Inventory> stock){
        stringstream ss(s);
        string word;

        while (ss >> word){
            for (auto it = stock.begin(); it != stock.end(); it++){
                if (it->GetName() == word){AddItem(*it);}
            }
        }
    }
    void SetSchedule(int year, int month, int day){
        schedString = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
        int days = 0;
        days += (year-1900)*365;
        for (int i = 0; i < month-1; i++){
            days += monthDays[i];
        }
        days += day;
        schedule = days;
    }
    void SetSchedString(string ss){schedString = ss;}
    //Getters
    string GetContact(){return contact;}
    string GetAddress(){return address;}
    string GetPhone(){return phone;}
    list<Inventory> GetItems(){return items;}
    int GetSchedule(){return schedule;}
    string GetSchedString(){return schedString;}
};

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
    while (!fInv.eof()){

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
    connect(AddDeliveryButton, SIGNAL(clicked), this, SLOT(docket = createScheduledDelivery(contact, address, phone, schedule, docket)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


