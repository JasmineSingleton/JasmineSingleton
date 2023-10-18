/*
Name: Jasmine Singleton
Course: SCIS 215
Date: 10/11/23
Purpose: The purpose fo this program is to act as a cash register.
It allows a customer to add items to their cart and check
the current iventory of the retail store.

*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "retailItem.h" //giving access to retailItem class

using namespace std;

//creating CashRegister class
class CashRegister{
    private:
        vector<RetailItem>items; //creating a vector to store objects from RetailItem
    public:
        CashRegister() {}; //creating a constructor

        //defining function to clear items from the vector
        void clear(){
            items.clear();
        }

        //defining function to add items to the vector
        void purchase_item(RetailItem retail_item){
            items.push_back(retail_item);
        }

        //defining function to get the total of the customers cart
        double getTotal(){
            double total;
            for (int i = 0; i < items.size(); i++){
                total += items[i].getPrice();
            }
            return total; //returning the total
        }
        void show_items(){
            if (items.empty()){ //letting customer know theu have nothing in their cart
                cout << "...Your cart is empty." << endl;

            }else{
                //displaying the cart of items
                cout << "Cart:" << endl;
                for (int j = 0; j < items.size(); j++){
                    cout << "Item: " << items[j].getDescription() << endl; //displaying the item
                    cout << "Price: $" << items[j].getPrice() << endl << endl; //displaying the price
                }
                
            }
        }
};

int main(){
    CashRegister cart; //creating CashRegister object
    string selection;
    int howMany;

    //creating RetailItem objects with starting quantities
    RetailItem pants("Pants", 10, 19.99);
    RetailItem shirts("Shirts", 15, 12.50);
    RetailItem dresses("Dresses", 3, 79.00);
    RetailItem socks("Socks", 50, 1.00);
    RetailItem sweaters("Sweaters", 5, 49.95);
    RetailItem jackets("Jackets", 12, 59.95);
    
    //displaying welcome message and menu,
    cout << "\n\nWelcome to JGS Retail!\n" << endl;
    cout << "1. pants (quantity: 10, price: $19.99)" << endl
        << "2. shirts (quantity: 15, price: $12.50)" << endl
        << "3. dresses (quantity: 3, price: $79.00)" << endl
        << "4. socks (quantity: 50, price: $1.00)" << endl
        << "5. sweaters (quantity: 5, price: $49.95)" << endl
        << "6. jackets(quantity: 12, price: $59.95)" << endl
        << "7. See Item Inventory" << endl;

    //getting item to add to cart
    cout << "Please select your item from the menu or enter 'done' to quit: ";
    cin >> selection;

    while (true){

        if (selection == "done"){
            cout << " " << endl;
            cart.show_items(); //displaying the items the customer purchased
            cout << endl << "Total: $" << fixed << setprecision(2) << cart.getTotal() << endl; //dispaying the total the customer pays
            break;
        }else{
            //adding the item selected to the cart and subtracting the item from the inventory
            switch (stoi(selection)){
                case 1:
                    if (pants.getUnitsOnHand() > 0) {
                        cout << "How many do you want to add to your cart? ";
                        cin >> howMany;
                        if (howMany <= (pants.getUnitsOnHand())){//making sure there are enough items in stock
                            for (int i = 0; i < howMany; i++){
                                cart.purchase_item(pants);
                            }
                            pants.setUnitsOnHand(pants.getUnitsOnHand() - (1 * howMany));
                            cout << "\nAdded to cart.\n";
                        }else{
                            cout << "\nSorry, there are not enough items left in stock." << endl;
                        }
                    }
                    else {
                        cout << "\nSorry, the pants are sold out.\n" << endl; //displying that the item is sold out
                    }
                    break;
                case 2:
                    if (shirts.getUnitsOnHand() > 0) {
                        cout << "How many do you want to add to your cart? ";
                        cin >> howMany;
                        if (howMany <= (shirts.getUnitsOnHand())){//making sure there are enough items in stock
                            for (int i = 0; i < howMany; i++){
                                cart.purchase_item(shirts);
                            }
                            shirts.setUnitsOnHand(shirts.getUnitsOnHand() - (1 * howMany));
                            cout << "\nAdded to cart.\n";
                        }else{
                            cout << "\nSorry, there are not enough items left in stock." << endl;
                        }
                    }
                    else {
                        cout << "\nSorry, the shirts are sold out.\n" << endl; //displying that the item is sold out
                    }
                    break;
                case 3:
                    if (dresses.getUnitsOnHand() > 0) {
                        cout << "How many do you want to add to your cart? ";
                        cin >> howMany;

                        if (howMany <= (dresses.getUnitsOnHand())){//making sure there are enough items in stock
                            for (int i = 0; i < howMany; i++){
                                cart.purchase_item(dresses);
                            }
                            dresses.setUnitsOnHand(dresses.getUnitsOnHand() - (1 * howMany));
                            cout << "\nAdded to cart.\n";
                        }else{
                            cout << "\nSorry, there are not enough items left in stock." << endl;
                        }
                    }
                    else {
                        cout << "\nSorry, the dresses are sold out.\n" << endl; //displying that the item is sold out
                    }
                    break;
                case 4:
                    if (socks.getUnitsOnHand() > 0) {
                        cout << "How many do you want to add to your cart? ";
                        cin >> howMany;

                        if (howMany <= (socks.getUnitsOnHand())){//making sure there are enough items in stock
                            for (int i = 0; i < howMany; i++){
                                cart.purchase_item(socks);
                            }
                            socks.setUnitsOnHand(socks.getUnitsOnHand() - (1 * howMany));
                            cout << "\nAdded to cart.\n";
                        }else{
                            cout << "\nSorry, there are not enough items left in stock." << endl;
                        }
                    }
                    else {
                        cout << "\nSorry, the socks are sold out.\n" << endl; //displying that the item is sold out
                    }
                    break;
                case 5:
                    if (sweaters.getUnitsOnHand() > 0) {
                        cout << "How many do you want to add to your cart? ";
                        cin >> howMany;

                        if (howMany <= (sweaters.getUnitsOnHand())){//making sure there are enough items in stock
                            for (int i = 0; i < howMany; i++){
                                cart.purchase_item(sweaters);
                            }
                            sweaters.setUnitsOnHand(sweaters.getUnitsOnHand() - (1 * howMany));
                            cout << "\nAdded to cart.\n";
                        }else{
                            cout << "\nSorry, there are not enough items left in stock." << endl;
                        }
                    }
                    else {
                        cout << "\nSorry, the sweaters are sold out.\n" << endl; //displying that the item is sold out
                    }
                    break;
                case 6:
                    if (jackets.getUnitsOnHand() > 0) {
                        cout << "How many do you want to add to your cart? ";
                        cin >> howMany;

                        if (howMany <= (jackets.getUnitsOnHand())){//making sure there are enough items in stock
                            for (int i = 0; i < howMany; i++){
                                cart.purchase_item(jackets);
                            }
                            jackets.setUnitsOnHand(jackets.getUnitsOnHand() - (1 * howMany));
                            cout << "\nAdded to cart.\n";
                        }else{
                            cout << "\nSorry, there are not enough items left in stock." << endl;
                        }
                    }
                    else {
                        cout << "\nSorry, the jackets are sold out.\n" << endl; //displying that the item is sold out
                    }
                    break;
                case 7:
                    cout << "\nCurrent Inventory:\n";
                    //displaying how many items are currently in stock for each item
                    displayItem(pants);
                    displayItem(shirts);
                    displayItem(dresses);
                    displayItem(socks);
                    displayItem(sweaters);
                    displayItem(jackets);
                    break;
                default:
                //displaying the menu
                    cout << "\nSorry, we do not have that item." << endl;
                    cout << "\n\n1. pants (price: $19.99)" << endl
                        << "2. shirts (price: $12.50)" << endl
                        << "3. dresses (price: $79.00)" << endl
                        << "4. socks (price: $1.00)" << endl
                        << "5. sweaters (price: $49.95)" << endl
                        << "6. jackets(price: $59.95)" << endl
                        << "7. See Item Inventory" << endl;

                    cout << "Please select your item from the menu or enter 'done' to quit: ";
                    cin >> selection;
                    continue;

            };

            //displaying the menu
            cout << "\n\n1. pants (price: $19.99)" << endl
                << "2. shirts (price: $12.50)" << endl
                << "3. dresses (price: $79.00)" << endl
                << "4. socks (price: $1.00)" << endl
                << "5. sweaters (price: $49.95)" << endl
                << "6. jackets(price: $59.95)" << endl
                << "7. See Item Inventory" << endl;

            cout << "Please select your item from the menu or enter 'done' to quit: ";
            cin >> selection;
    
            }
        }
    return 0;
}
