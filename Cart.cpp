#include "CPQ_base.h"
#include <sstream>

using namespace std;

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
	for(i; !(i->item.name == item.item.name) && (i!=cart.end()); ++i){
		continue;
	}
	std::cout << "\n";
	if ((i==cart.end()) && !(i->item.name == item.item.name)){
		return Item();
	}
	Item iItem = i->item;
	cart.erase(i);
	return iItem;
}