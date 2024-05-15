#include "CPQ_base.h"
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

string Cart::viewCart(){
	std::ostringstream s;
	for(auto i = cart.begin(); (i!=cart.end()); ++i){
		s << i->write() << ", " << i->getPrice() << "\n";
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
		sum = sum + (i->getPrice());
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

CartItem Cart::removeItem(CartItem item){
	auto i = cart.begin();
	for(i; !(i->item.name == item.item.name) && (i!=cart.end()); ++i){
		continue;
	}
	if ((i==cart.end()) && !(i->item.name == item.item.name)){
		return CartItem();
	}
	CartItem iItem = *i;
	cart.erase(i);
	return iItem;
}

void Cart::write(string cartName){
	std::ostringstream fileName;
	//Default name
	if(cartName == ""){
		time_t t = time(nullptr);
		struct tm* timeStruct = localtime(&t);
		fileName << put_time(timeStruct, "%d_%m_%Y_%H:%M");
	}
	else{
		fileName << cartName;
	}
	fileName << ".json";
	std::ostringstream s;
	s << "[\n";
	auto i = cart.begin();
	while(i!=cart.end()){
		s << i->write();
		//Json readability
		if(++i != cart.end()){
			s << ",\n";
		}
	}
	s << "\n]";
	std::cout << s.str();
	std::ofstream file { fileName.str() };
	if(!file){
        std::cerr << "Failed to open file\n";
        return;
    }
	file << s.str();
	file.close();
}