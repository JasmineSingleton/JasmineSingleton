
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Class declaration
class RetailItem{
    private:
        string description; // Item description
        int unitsOnHand; // Units on hand
        double price; // Item price
    public:
        // Constructor
        RetailItem(string d, int u, double p)
            { description = d; unitsOnHand = u; price = p; }
        // Mutators
        void setDescription(string d)
            { description = d; }
        void setUnitsOnHand(int u)
            { unitsOnHand = u; }
        void setPrice(double p)
            { price = p; }
        // Accessors
        string getDescription()
            { return description; }
        int getUnitsOnHand()
            { return unitsOnHand; }
        double getPrice()
            { return price; }
        };
// Function prototype
void displayItem(RetailItem);



int notTheMain(){
    // Example RetailItem object.
    RetailItem pants("Pants", 10, 19.99);
    RetailItem shirts("Shirts", 15, 12.50);
    RetailItem dresses("Dresses", 3, 79.00);
    RetailItem socks("Socks", 50, 1.00);
    RetailItem sweaters("Sweaters", 5, 49.95);
    RetailItem jackets("Jackets", 12, 59.95);
    return 0;
}
//**************************************************
// The displayItem function displays the data *
// in a RetailItem object. *
//**************************************************
void displayItem(RetailItem item){
    cout << setprecision(2) << fixed << showpoint;
    cout << "Description: " << item.getDescription() << endl;
    cout << "Units on hand: " << item.getUnitsOnHand() << endl;
    cout << "Price: $" << item.getPrice() << endl << endl;
}