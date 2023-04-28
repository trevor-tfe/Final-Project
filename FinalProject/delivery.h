
#ifndef DELIVERY_H
#define DELIVERY_H
#include <string>
#include <list>
#include <inventory.h>

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

inline
    bool operator<(Delivery lhs, Delivery rhs){
        return lhs.GetSchedule() < rhs.GetSchedule();
}

inline
    bool operator>(Delivery lhs, Delivery rhs){
        return lhs.GetSchedule() > rhs.GetSchedule();
}

#endif // DELIVERY_H
