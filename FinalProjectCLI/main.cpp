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
#include "delivery.cpp"
#include "inventory.cpp"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DUE TO TIME CONSTRAINTS: I'M ABANDONING INVENTORY LOOKUP
// INSTEAD, INVENTORY IS GOING TO BE A VARIABLE STORED WITHIN DELIVERIES 
// void ImportInventory(list<Inventory> &currStock){
//     fstream fInv;
//     fInv.open("inventory.csv", ios::in);
//     vector<string> row;
//     string line, word, temp;
//     //Checks for end of file and ends while loop
//     while (!fInv.eof()){
//         //clears row info
//         row.clear();

//         //Gets row info
//         getline(fInv, line);
//         //Creates new stringstream from info
//         stringstream s(line);

//         //Inserts each word into the vector
//         while (getline(s, word, ',')){
//             row.push_back(word);
//         }
//         //1. Name, 2. SKU, 3. Price, 4. Stock
//         int stk = stoi(row.back());
//         row.pop_back();
//         double pr = stod(row.back());
//         row.pop_back();
//         int sku = stoi(row.back());
//         row.pop_back();
//         string n = row.back();
//         row.pop_back();

//         currStock.push_back(Inventory(n, sku, pr, stk));
//     }
//     fInv.close();
// }

void ImportDeliveries(list<Delivery> &unscheduled, priority_queue<Delivery> &docket){
    fstream fInv;
    fInv.open("deliveries.csv", ios::in);
    string line, inv, word, temp;
    int attempts = 0;
    while (!fInv.eof() && attempts < 10){
        string row[6] = {"Error", "Incorrect Road", "45012", "04/27/2023", "Chair:50504:24.56:5"};
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

char mainMenu(){
    char input = ' ';
    cout << "To exit the program, enter 'Q' at any time." << endl;
    cout << "Enter Delivery -> Enter '1'. " << endl;
    cout << "To view next delivery -> Enter '2'. " << endl;
    cout << "To print next delivery - Enter '3'. " << endl;
    cin >> input;
    return input;
}

//Walks user through entering new delivery
char addNewDelivery(priority_queue<Delivery> &docket){
    char input = ' ';
    Delivery *newDel = new Delivery();
    cout << "Do you want to enter a delivery? y/n: ";
    while (input != 'n' && input != 'N' && input != 'q' && input != 'Q'){
        cin >> input;
        //Kicks user out to main menu.
        if (input == 'n' || input == 'N'){break;}
        string info = "";
        int day;
        int month;
        int year;
        cout << "Enter Contact Name: ";
        cin >> info;
        newDel->SetContact(info);
        cout << "Enter Address: ";
        cin >> info;
        newDel->SetPhone(info);
        cout << "Enter Phone Number: ";
        cin >> info;
        newDel->SetPhone(info);
        cout << "Would you like to add inventory items now? y/n: ";
        cin >> input;
        //Begin adding items to delivery
        while (input != 'n' && input != 'N'){
            Inventory *newInv = new Inventory();
            //get item name
            cout << "Enter the item Name: ";
            cin >> info;
            newInv->SetName(info);

            //get item SKU
            cout << "Enter item SKU (5 digits): ";
            cin >> info;
            newInv->SetSKU(stoi(info));

            //get item price
            cout << "Enter item price: ";
            cin >> info;
            newInv->SetPrice(stod(info));

            //get number shipped
            cout << "Enter amount shipped: ";
            cin >> info;
            newInv->SetStock(stoi(info));

            //add item to delivery list
            newDel->AddItem(*newInv);
            cout << "Would you like to add another item to the delivered items? y/n: ";
            cin >> input;
        }
        //add delivery to the docket
        cout << "would you like to add another delivery? y/n: ";
        cin >> input;
        docket.emplace(*newDel);
    }
    return input;
}

char DisplayNextDelivery(priority_queue<Delivery> docket){
    char input = 'n';
    Delivery temp = docket.top();
    list<Inventory> tempList = temp.GetItems();
    int total = 0;
    cout << "Contact:  " << temp.GetContact() << endl;
    cout << "Address:  " << temp.GetAddress() << endl;
    cout << "Phone #:  " << temp.GetPhone() << endl;
    cout << "Schedule: " << temp.GetSchedString() << endl;
    cout << "_____Item List_____" << endl;
    for (auto it = tempList.begin(); it != tempList.end(); it++){
        cout << it->GetName() << ", SKU: " << it->GetSKU() << ", Price: $" << it->GetPrice() << ", Quantity: " << it->GetStock() << endl;
        total += it->GetPrice();
    }
    cout << "Total: $" << total << endl;
    return input;
}

char PrintDeliverySlip(priority_queue<Delivery> &docket){
    char input = 'N';

    return input;
}


int main(int argc, char *argv[])
{
    list<Delivery> unscheduled;
    priority_queue<Delivery> docket;

    try {
        ImportDeliveries(unscheduled, docket);

        Delivery bigDelivery = Delivery("DMACC", "2006 S Ankeny Blvd, Ankeny, IA 50023", "(515) 964-6200", 45019, "5/4/2023");
        bigDelivery.AddItem(Inventory("Desk", 40154, 56.62, 500));
        bigDelivery.AddItem(Inventory("Chair", 40155, 32.16, 1000));
        char input = ' ';
        cout << "Deliveries Program Initializing" << endl;
        while (input != 'q' && input != 'Q'){
            input = mainMenu();
            while (input != 'n' && input != 'N' && input != 'q' && input != 'Q'){
                if (input == '1'){input = addNewDelivery(docket);}
                if (input == '2'){}
                if (input == '3'){}
            }
        }

    } catch (exception x){
        cout << x.what();
    }



    return 0;
}
