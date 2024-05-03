#include "CPQ_base.h"
#include <sstream>

using namespace std;

Item::Item(string setName, float setPrice){
	name=setName;
	price=setPrice;
}

bool Item::operator ==(const Item &i) {
	return (name == i.name) && (attr == i.attr);
}
 
void Item::setPrice(float newPrice){
	price = newPrice;
}

float Item::getPrice(){
	return price;
}

void Item::setAttr(Item* attrib){
	attr.push_back(attrib);
	setPrice(attrib->getPrice() + getPrice());
}

vector<Item*> Item::getAttr(){
	return attr;
}

CartItem::CartItem(const Item& itemAdd, int quantityAdd) : item(itemAdd){
    item = itemAdd;
    quantity = quantityAdd;
}

bool CartItem::operator ==(const CartItem &c){
	return (item == c.item) && (quantity == c.quantity);
}

string CartItem::printCartItem()
{
	std::ostringstream s;
	s << item.name << ", " << quantity;
    return s.str();
}

float CartItem::getPrice(){
	return (item.getPrice() * quantity);
}

int CartItem::getQuantity()
{
    return quantity;
}

void CartItem::setQuantity(int q){
	quantity = q;
}

string Cart::viewCart(){
	std::ostringstream s;
	for(auto i = cart.begin(); (i!=cart.end()); ++i){
		s << i->printCartItem() << ", " << i->getPrice() << "\n";
	}
	s << "Total, " << numItems() << ", " << getTotal() << "\n";
	return s.str();
}

void Cart::setItem(CartItem item){
    cart.push_back(item);
}

CartItem Cart::newItem(Item item, int quant){
	CartItem x = CartItem(item, quant);
	setItem(x);
	return x;
}

float Cart::getTotal(){
	float sum = 0.f;
	for(auto i = cart.begin(); (i!=cart.end()); ++i){
		sum = sum + (i->getQuantity() * i->item.getPrice());
	}
	return sum;
}

int Cart::numItems(){
	int sum = 0;
	for(auto i = cart.begin(); (i!=cart.end()); ++i){
		sum = sum + i->getQuantity();
	}
	return sum;
}

Item Cart::removeItem(CartItem item){
	auto i = cart.begin();
	for(i; !(*i == item) && (i!=cart.end()); ++i){
		continue;
	}
	if ((i==cart.end()) && !(*i == item)){
		return Item("NULL", 0.f);
	}
	Item iItem = i->item;
	std::cout << iItem.name;
	cart.erase(i);
	return iItem;
}