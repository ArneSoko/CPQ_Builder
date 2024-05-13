# CPQ_Builder

As the name suggests, this is a program designed to build a CPQ configurator system.  

### How to use?

1. Run `$ cmake ./` to compile build files.  
2. Run `$ make` to build project.  
3. Run `./MyProject` to run main.cpp code.  

### What's inside?

You're using this to configure **Items** for purchase. An item has a set of possible **Attributes** which can be selected. Each item and attribute comes with an associated cost.  

The item and any selected attribute is combined into a **CartItem** object. This object holds an item, the quantity selected, and a list of all the selected attributes added to the item. These are the cartitem's **Options**.  

The top-level object is the **Cart**. The cart is the full list of all cartitems. The total cost of all cartitems ((the item + all the selected options) * quantity) is computed at the cart level.  

The objects all print in json format. The cart and item objects both contain methods for writing to a json file for disk storage.

#### Future additions

- GUI interface
- Read from json file
- Generate CPQ Program