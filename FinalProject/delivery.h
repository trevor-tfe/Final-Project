
#ifndef DELIVERY_H
#define DELIVERY_H
#include <string>
#include <list>
#include <inventory.h>




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
