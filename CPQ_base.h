#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Item{
public:
	Item(string setName, float setPrice);
    bool operator==(const Item &i);
    string name;
    vector<Item*> attr;
	float getPrice();
	void setPrice(float newPrice);
	vector<Item*> getAttr();
	void setAttr(Item* attrib);
private:
	float price;
};


class CartItem{
public:
    CartItem(const Item& itemAdd, int quantityAdd);
    bool operator==(const CartItem &c);
	string printCartItem();
    Item item;
    float getPrice();
	int getQuantity();
	void setQuantity(int q);
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
};