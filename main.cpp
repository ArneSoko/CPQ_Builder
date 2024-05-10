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
    //std::cout << cart.viewCart();
    CartItem removed = cart.removeItem(*c);
    //cart.write("testCart");
    Attr i = Attr("test", 3.52f);
    std::cout << i.writeAttr() << endl;
    removed.item.setAttr(i);
    std::cout << removed.item.writeItem() << endl;
    //removed.setOption(i);
    //std::cout << removed.write() << endl;
    return 0;
}