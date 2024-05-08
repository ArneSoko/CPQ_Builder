#include "CPQ_base.h"
#include <stdio.h>

using namespace std;

int main(int argc, char **argv){
    //Generate some items and add to cart
    Cart cart;
    CartItem *c = new CartItem;
    for(int i = 1; i <= 26; i++){
        CartItem ci = cart.newItem(Item(std::to_string(i), i/10.f),i);
        if(i==13){
            *c = ci;
        }
    }
    std::cout << c->item.name << "\n";
    std::cout << cart.viewCart();
    Item removed = cart.removeItem(*c);
    cart.write("testCart");
    //Item i = Item("test", 3.f); 
    //removed.setAttr(i);
    //std::cout << removed.getAttr().at(0).name << endl;
    removed.write();
    return 0;
}