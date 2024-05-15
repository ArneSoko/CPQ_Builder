#include "CPQ_base.h"
#include <sstream>

using namespace std;

CartItem::CartItem(){
    item = Item();
    quantity=0;
}

CartItem::CartItem(const Item& itemAdd, int quantityAdd) : item(itemAdd){
    item = itemAdd;
    quantity = quantityAdd;
}

bool CartItem::operator ==(const CartItem &c){
    auto i = options.begin();
    auto ci = c.options.begin();
    for(i; !(i==options.end()); ++i){
        if(!(*i==*ci)){
            return false;
        }
        ++ci;
    }
	return ((item == c.item) && (quantity == c.quantity));
}

vector<Attr> CartItem::getOptions(){
    return options;
}

int CartItem::setOption(Attr attrib){
    int i = 0;
    for(i; !(i==item.getAttr().size()); ++i){
        if(item.getAttr().at(i) == attrib){
            options.push_back(attrib);
            return 0;
        }
    }
    return 1;
}

int CartItem::removeOption(Attr attrib){
    auto i = options.begin();
    for(i; !(i==options.end()); ++i){
        if(*i == attrib){
            options.erase(i);
            return 0;
        }
    }
    return 1;
}

float CartItem::getPrice(){
    float sum = item.getPrice();
    auto i = options.begin();
    for(i; !(i==options.end()); ++i){
        sum = sum+i->getPrice();
    }
    return (sum * quantity);
}

int CartItem::getQuantity(){
    return quantity;
}

void CartItem::setQuantity(int q){
	quantity = q;
}

string CartItem::write()
{
    std::ostringstream s;
    s << "{\"Item\":" << item.writeItem() << ",\"Options\":[";
    int i = 0;
    while(!(i==options.size())){
        s << options.at(i).writeAttr(); 
        //Json formatting
        if(++i!=options.size()){
            s << ",";
        }
    }
    s << "],\"Quantity\":" << quantity << ",\"Total\":" << getPrice() << "}";
    return s.str();
}
