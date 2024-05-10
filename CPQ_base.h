#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class Attr{
public:
    Attr();
    Attr(string setName, float setPrice);
    bool operator==(const Attr & i);
    string name;
    float getPrice();
    void setPrice(float newPrice);
    string writeAttr();
protected: 
    float price;
};

class Item{
public:
    Item();
    Item(string setName, float setPrice);
    bool operator==(const Item &i);
    string name;
	vector<Attr> getAttr();
    void setPrice(float newPrice);
    float getPrice();
    void setAttr(Attr attrib);
    int write();
    string writeItem();
protected:
    vector<Attr> attr;
    float price;
};


class CartItem{
public:
    CartItem();
    CartItem(const Item &itemAdd, int quantityAdd);
    bool operator==(const CartItem &c);
    Item item;
	vector<Attr> getOptions();
	int setOption(Attr attrib);
    int removeOption(Attr attrib);
    float getPrice();
	int getQuantity();
	void setQuantity(int q);
    string write();
protected:
    vector<Attr> options;
private:
    int quantity;
};


class Cart{
public:
	vector<CartItem> cart;
    string viewCart();
    void setItem(CartItem item);
    CartItem newItem(Item item, int quant);
    float getTotal();
    int numItems();
    CartItem removeItem(CartItem item);
    void write(string cartName);
};

void read(string fileName);