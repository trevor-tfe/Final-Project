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
#include "inventory.h"

//CONSTRUCTORS
Inventory::Inventory(std::string s){this->name = s;}
Inventory::Inventory(std::string s, int k){this->name = s; this->SKU = k;}
Inventory::Inventory(std::string s, int k, double p){this->name = s; this->SKU = k; this->price = p;}
Inventory::Inventory(std::string s, int k, double p, int st){this->name = s; this->SKU = k; this->price = p; this->stock = st;}
//SETTERS
void Inventory::SetName(std::string s){this->name = s;}
void Inventory::SetSKU(int k){this->SKU = k;}
void Inventory::SetPrice(double p){this->price = p;}
void Inventory::SetStock(int s){this->stock = s;}
//GETTERS
std::string Inventory::GetName(){return this->name;}
int Inventory::GetSKU(){return this->SKU;}
double Inventory::GetPrice(){return this->price;}
int Inventory::GetStock(){return this->stock;}
std::string Inventory::ToString(){return name + "," + std::to_string(SKU) + "," + std::to_string(price) + "," + std::to_string(stock);}

