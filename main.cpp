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
    std::cout << cart.viewCart() << "\n";
    Item removed = cart.removeItem(*c);
    std::cout << cart.viewCart() << "\n";
    std::cout << removed.name << "\n";
    return 0;
}