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

string CartItem::write()
{
    std::ostringstream s;
    s << "{\n\"Item\":\n" << item.writeItem() << ",\n\"Quantity\":" << quantity << "\n}";
    return s.str();
}
