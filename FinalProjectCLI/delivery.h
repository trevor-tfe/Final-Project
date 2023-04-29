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
#ifndef DELIVERY_H
#define DELIVERY_H
#include <string>
#include <list>
#include "inventory.h"

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Delivery
{
    private:
        std::string contact;
        std::string address;
        std::string phone;
        int schedule = 0;
        std::string schedString;
        std::list <Inventory> items;
    public:
        //Constructors
        Delivery(){}
        Delivery(std::string c);
        Delivery(std::string c, std::string a);
        Delivery(std::string c, std::string a, std::string p);
        Delivery(std::string c, std::string a, std::string p, int s, std::string ss);
        //Setters
        void SetContact(std::string c);
        void SetAddress(std::string a);
        void SetPhone(std::string p);
        void AddItem(Inventory i);
        void AddItemList(std::string s, std::list<Inventory> stock);
        void AddItemList(std::list<Inventory> stock);
        void SetSchedule(int year, int month, int day);
        void SetSchedString(std::string ss);
        //Getters
        std::string GetContact();
        std::string GetAddress();
        std::string GetPhone();
        std::list<Inventory> GetItems();
        int GetSchedule();
        std::string GetSchedString();
};

#endif // DELIVERY_H
