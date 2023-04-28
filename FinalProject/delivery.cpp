
#include "delivery.h"
#include <fstream>
#include <sstream>

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
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
