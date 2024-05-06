#include "CPQ_base.h"

using namespace std;

Item::Item(){
    name="";
    price=0;
}

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