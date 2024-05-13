#include "CPQ_base.h"
#include <sstream>

using namespace std;

Attr::Attr(){
    name="";
    price=0;
}

bool Attr::operator==(const Attr &i){
    return ((name == i.name) && (price == i.price));
}

Attr::Attr(string setName, float setPrice){
    name=setName;
    price=setPrice;
}

void Attr::setPrice(float newPrice){
	price = newPrice;
}

float Attr::getPrice(){
	return price;
}

string Attr::writeAttr(){
    std::ostringstream s;
	s << "{\"Name\": " << name << ",\n\"Price\": " << price << "}";
    return s.str();
}