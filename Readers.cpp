#include "Readers.h"

using namespace std;

int detectFileContent(string filename){
    ifstream file{filename};
    if(!file){
        return -1;
    }
    string s;
    file >> s;
    file.close();
    if (s[0]=='['){
        return 0;
    }
    if (s[0]=='{'){
        return 1;
    }
    return 2;
}

Cart readCart(string filename){
    Cart cart;
    //Automatically checks that file is valid
    if(detectFileContent(filename)){
        cerr << "File does not contain a cart item (not json format or file does not have correct data)" << endl;
        return cart;
    }
    ifstream file{filename};
    string s;
    while (getline(file, s)){
        if(s!="[" && s!="]"){
            //Parse Item from CartItem
            string name = s.substr(s.find("Name")+8,(s.find(",\"Config") - s.find("Name")-9));
            float price = stof(s.substr(s.find("Price")+8,(s.find("\"Options\"") - s.find("Price")-10)));
            Item item = Item(name, price);
            //Isolate and parse attributes
            string configs = s.substr(s.find("Configs\":[")+10, (s.find("],\"Price")-s.find("Configs"))-10);
            while(configs!=""){
                string attrStr = configs.substr(0,configs.find("}")+1);
                auto p = configs.erase(0, configs.find("}")+2);
                name = attrStr.substr(attrStr.find("Name")+8,attrStr.find("Cost")-attrStr.find("Name")-11);
                price = stof(attrStr.substr(attrStr.find("Cost")+7, attrStr.find("}") - attrStr.find("Cost")-7));
                item.setAttr(Attr(name, price));
            }
            cout << item.writeItem() << endl;
        }
    }
    file.close();
    return cart;
}

Item readItem(string filename){
    return Item();
}