#include "CPQ_base.h"
#include <sstream>

using namespace std;

string projectName;

Item::Item(){
    name="";
    price=0;
}

Item::Item(string setName, float setPrice){
	name=setName;
	price=setPrice;
}

bool Item::operator==(const Item &i) {
	if(name == i.name){
        auto at = attr.begin();
        auto iat = i.attr.begin();
        while(!(at == attr.end()) && !(iat == i.attr.end())){
            if(!(*at == *iat)){
                return false;
            }
            ++at;
            ++iat;
        }
        if(!(at == attr.end()) || !(iat == i.attr.end())){
            return false;
        }
        return true;
    }
    return false;
}
 
void Item::setPrice(float newPrice){
	price = newPrice;
}

float Item::getPrice(){
	return price;
}

void Item::setAttr(Item attrib){
	attr.push_back(attrib);
	setPrice(attrib.getPrice() + getPrice());
}

vector<Item> Item::getAttr(){
	return attr;
}

string Item::writeItem(){
    std::ostringstream s;
	s << "{\"Name\": " << name << ",\n\"Options\":[";
    auto attr = getAttr().begin();
    while(!(attr == getAttr().end())){
        s << "{" << attr->writeItem() << "},\n";
    }
    s << "],\n\"Price\": " << price << "}";
    return s.str();
}

int Item::write(){
    std::ostringstream s;
	s << "{\n\"Name\": " << name << ",\n\"Options\":[";
    auto attr = getAttr().begin();
    while(!(attr == getAttr().end())){
        s << "\n{\n" << attr->writeItem() << "},";
    }
    s << "],\n\"Price\": " << price <<"\n}";
    std::ostringstream fname;
    fname << name << "File.json";
    std::ofstream file{ fname.str() };
    if(!file){
        std::cerr << "Failed to open file\n";
        return 1;
    }
    file << s.str();
    file.close();
    return 0;
}