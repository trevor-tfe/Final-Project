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
#include "delivery.h"
#include <fstream>
#include <sstream>

//Constructors
    Delivery::Delivery(std::string c){this->contact = c;}
    Delivery::Delivery(std::string c, std::string a){this->contact = c; this->address = a;}
    Delivery::Delivery(std::string c, std::string a, std::string p){this->contact = c; this->address = a; this->phone = p;}
    Delivery::Delivery(std::string c, std::string a, std::string p, int s, std::string ss){
        this->contact = c;
        this->address = a;
        this->phone = p;
        this->schedule = s;
        this->schedString = ss;
    }
//Setters
    void Delivery::SetContact(std::string c){this->contact = c;}
    void Delivery::SetAddress(std::string a){this->address = a;}
    void Delivery::SetPhone(std::string p){this->phone = p;}
    void Delivery::AddItem(Inventory i){this->items.push_back(i);}
    void Delivery::AddItemList(std::string s, std::list<Inventory> stock){
        std::stringstream ss(s);
        std::string word;

        while (ss >> word){
            for (auto it = stock.begin(); it != stock.end(); it++){
                if (it->GetName() == word){AddItem(*it);}
            }
        }
    }
    void Delivery::AddItemList(std::list<Inventory> stock){
        items = stock;
    }
    void Delivery::SetSchedule(int year, int month, int day){
        schedString = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
        int days = 0;
        days += (year-1900)*365;
        for (int i = 0; i < month-1; i++){
            days += monthDays[i];
        }
        days += day;
        schedule = days;
    }
    void Delivery::SetSchedString(std::string ss){schedString = ss;}
//Getters
    std::string Delivery::GetContact(){return contact;}
    std::string Delivery::GetAddress(){return address;}
    std::string Delivery::GetPhone(){return phone;}
    std::list<Inventory> Delivery::GetItems(){return items;}
    int Delivery::GetSchedule(){return schedule;}
    std::string Delivery::GetSchedString(){return schedString;}
