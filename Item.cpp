#include "CPQ_base.h"
#include <sstream>

using namespace std;


Item::Item(){
    name="";
    price=0;
}

Item::Item(string setName, float setPrice){
	name=setName;
	price=setPrice;
}

bool Item::operator==(const Item &i) {
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
    return ((name == i.name) && price == i.price);
}

void Item::setPrice(float newPrice){
	price = newPrice;
}

float Item::getPrice(){
	return price;
}

void Item::setAttr(Attr attrib){
	attr.push_back(attrib);
}

vector<Attr> Item::getAttr(){
	return attr;
}

string Item::writeItem(){
    std::ostringstream s;
	s << "{\"Name\": " << name << ",\n\"Options\":[";
    auto i = getAttr().begin();
    while(!(i == getAttr().end())){
        std::cout << i->writeAttr() << endl;
        //This is just for json formatting
        if(!(++i == getAttr().end())){s << ",\n";}
    }
    s << "],\n\"Price\": " << price << "}";
    return s.str();
}

int Item::write(){
    string s = writeItem();
    std::ostringstream fname;
    fname << name << "File.json";
    std::ofstream file{ fname.str() };
    if(!file){
        std::cerr << "Failed to open file\n";
        return 1;
    }
    file << s;
    file.close();
    return 0;
}