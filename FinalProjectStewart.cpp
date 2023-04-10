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
};

class Delivery{
    private:
    string contact;
    string address;
    string phone;
    tm *schedule = localtime(&now);
    list <Inventory> items;
    public:
    //Constructors
    Delivery(){}
    Delivery(string c){this->contact = c;}
    Delivery(string c, string a){this->contact = c; this->address = a;}
    Delivery(string c, string a, string p){this->contact = c; this->address = a; this->phone = p;}
    //Setters
    void SetContact(string c){this->contact = c;}
    void SetAddress(string a){this->address = a;}
    void SetPhone(string p){this->phone = p;}
    void AddItem(Inventory i){this->items.push_back(i);}
    void SetSchedule(int year, int month, int day){
        this->schedule->tm_year = year-1900;
        this->schedule->tm_mon = month-1;
        this->schedule->tm_mday = day;
    }
    //Getters
    string GetContact(){return contact;}
    string GetAddress(){return address;}
    string GetPhone(){return phone;}
    list<Inventory> GetItems(){return items;}
    tm GetSchedule(){return *schedule;}
};


bool operator<(Delivery lhs, Delivery rhs){
    return lhs.GetSchedule().tm_yday < rhs.GetSchedule().tm_yday;
}

bool operator>(Delivery lhs, Delivery rhs){
    return lhs.GetSchedule().tm_yday > rhs.GetSchedule().tm_yday;
}

int main(){
    list<Inventory> currentStock;
    list<Delivery> unscheduled;
    priority_queue<Delivery> docket;

    time_t rawtime;
    time(&rawtime);
    struct tm * test;
    test = localtime(&rawtime);
    test->tm_mday = 20;
    test->tm_mon = 2;
    test->tm_year = 2023;
    mktime(test);

    cout << test->tm_yday;
    return 0;
}