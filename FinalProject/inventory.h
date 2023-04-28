
#ifndef INVENTORY_H
#define INVENTORY_H
#include<string>



class Inventory
{
private:
    std::string name;
    int SKU;
    double price;
    int stock;
public:
    Inventory();
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
