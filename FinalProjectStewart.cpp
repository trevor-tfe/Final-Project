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
*   Input: None
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
    public:
    //CONSTRUCTORS
    Inventory(){}
    Inventory(string s){this->name = s;}
    Inventory(string s, int k){this->name = s; this->SKU = k;}
    Inventory(string s, int k, double p){this->name = s; this->SKU = k; this->price = p;}
    //SETTERS
    void SetName(string s){this->name = s;}
    void SetSKU(int k){this->SKU = k;}
    void SetPrice(double p){this->price = p;}
    //GETTERS
    string GetName(){return this->name;}
    int GetSKU(){return this->SKU;}
    double GetPrice(){return this->price;}
};

class Delivery{
    private:
    string contact;
    string address;
    string phone;
    tm *schedule = localtime(&now);
    list <Inventory> items;
    public:
    Delivery(){}
    Delivery(string c){this->contact = c;}
    Delivery(string c, string a){this->contact = c; this->address = a;}
    Delivery(string c, string a, string p){this->contact = c; this->address = a; this->phone = p;}
    tm GetSchedule(){return *schedule;}
};

bool operator<(Delivery lhs, Delivery rhs){
    return lhs.GetSchedule().tm_yday < rhs.GetSchedule().tm_yday;
}

bool operator>(Delivery lhs, Delivery rhs){
    return lhs.GetSchedule().tm_yday > rhs.GetSchedule().tm_yday;
}

int main(){
    return 0;
}