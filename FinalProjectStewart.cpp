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
#include <bits/stdc++.h>
using namespace std;
time_t now = time(0);

const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30, 
       31, 31, 30, 31, 30, 31 };

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
    //Getters
    string GetContact(){return contact;}
    string GetAddress(){return address;}
    string GetPhone(){return phone;}
    list<Inventory> GetItems(){return items;}
    int GetSchedule(){return schedule;}
    string GetSchedString(){return schedString;}
};


bool operator<(Delivery lhs, Delivery rhs){
    return lhs.GetSchedule() < rhs.GetSchedule();
}

bool operator>(Delivery lhs, Delivery rhs){
    return lhs.GetSchedule() > rhs.GetSchedule();
}

void ImportInventory(list<Inventory> &currStock){
    fstream fInv;
    fInv.open("inventory.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    bool endFile = false;
    while (endFile == false){
        row.clear();

        getline(fInv, line);
        stringstream s(line);

        while (getline(s, word, ',')){
            row.push_back(word);
        }
        currStock.push_back(Inventory(row[0], stoi(row[1]), stod(row[2]), stoi(row[3])));
        if(fInv.eof()){endFile = true;}
    }
    fInv.close();
}

void UpdateInventory(){
    
}

void ImportDeliveries(list<Delivery> &unscheduled, priority_queue<Delivery> &docket){
    fstream fInv;
    fInv.open("deliveries.csv", ios::in);
    vector<string> row;
    string line, name, SKU, price, stock, inv, word, temp;
    bool endFile = false;
    while (endFile == false){
        row.clear();

        getline(fInv, line);
        stringstream s(line);

        while (getline(s, word, ',')){
            row.push_back(word);
        }
        if (row[5] == "0"){
            unscheduled.push_back(Delivery(row[0], row[1], row[2], stoi(row[3]), row[4]));
        } else {
            Delivery *digorno = new Delivery(row[0], row[1], row[2], stoi(row[3]), row[4]);//The pizza reference was the only way for me to keep it straight in my head.
            stringstream sinv(row[5]);
            while (getline(sinv, inv, ':')){
                Inventory *pizza = new Inventory();
                vector<string> invVec;
                invVec.push_back(inv);
                pizza->SetName(invVec[0]);
                pizza->SetSKU(stoi(invVec[1]));
                pizza->SetPrice(stod(invVec[2]));
                pizza->SetStock(stoi(invVec[3]));
                digorno->AddItem(*pizza);
            }
            docket.emplace(digorno);

        }
        if(fInv.eof()){endFile = true;}
    }
    fInv.close();
}

int main(){
    list<Inventory> currentStock;
    list<Delivery> unscheduled;
    priority_queue<Delivery> docket;

    ImportInventory(currentStock);
    ImportDeliveries(unscheduled, docket);

    bool guardian = true;
    while (guardian == true){
        
    }

    return 0;
}