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
#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

class Inventory
{
private:
    std::string name;
    int SKU;
    double price;
    int stock;
public:
    Inventory(){};
    Inventory(std::string s);
    Inventory(std::string s, int k);
    Inventory(std::string s, int k, double p);
    Inventory(std::string s, int k, double p, int st);
    void SetName(std::string s);
    void SetSKU(int k);
    void SetPrice(double p);
    void SetStock(int s);
    //GETTERS
    std::string GetName();
    int GetSKU();
    double GetPrice();
    int GetStock();
    std::string ToString();
};

#endif // INVENTORY_H
