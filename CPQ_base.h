#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class Item{
public:
    Item();
    Item(string setName, float setPrice);
    bool operator==(const Item &i);
    string name;
    vector<Item> attr;
	float getPrice();
	void setPrice(float newPrice);
	vector<Item> getAttr();
	void setAttr(Item attrib);
    int write();
    string writeItem();
private:
	float price;
};


class CartItem{
public:
    CartItem();
    CartItem(const Item &itemAdd, int quantityAdd);
    bool operator==(const CartItem &c);
	string printCartItem();
    Item item;
    float getPrice();
	int getQuantity();
	void setQuantity(int q);
    string write();
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
    Item removeItem(CartItem item);
    void write(string cartName);
};

void read(string fileName);