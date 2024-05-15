#include "Readers.h"
#include <stdio.h>

using namespace std;

int main(int argc, char **argv){
    //Generate some items and add to cart
    /*Cart cart;
    CartItem *c = new CartItem;
    Attr test = Attr("test", 3.52f);
    for(int i = 1; i <= 26; i++){
        CartItem ci = cart.newItem(Item(std::to_string(i), i/10.f),i);
        if(i==13){
            *c = ci;
        }
        if(i==14){
            ci.item.setAttr(test);
            ci.setOption(test);
            cart.setItem(ci);
        }
    }
    std::cout << cart.viewCart();
    CartItem removed = cart.removeItem(*c);
    cart.write("testCart");
    removed.item.setAttr(test);
    int w = removed.setOption(test);
    std::cout << removed.write() << endl;*/
    readCart("testCart.json");
    return 0;
}