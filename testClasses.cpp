/*
Name: Jasmine Singleton
Course: SCIS 215
Date: 9/18/23
Purpose: the purpose of this program is to format a date based on the format choice  of the user.

Algorithm-

submitted as a pdf doc

*/

#include <iostream>
using namespace std;


//creating date class
class Date {
public:
//setting public functions
    void menu();
    void getDate();
    void setDate();
    void dateOne();
    void dateTwoThree();
    void dateFour();
    int option;

private:
//setting private funcitons
    int month, day;
    string year;
};

//defining menu function to show the formats
void Date::menu() {
    cout << "1) 04/11/81" << endl;
    cout << "2) April 11, 1881" << endl;
    cout << "3) 11 April, 1881" << endl;
    cout << "4) 1881/04/11" << endl;
}

void Date::getDate() {

    //getting valid date from the user
    while (true) {
        cout << "Enter the month (1 - 12): ";
        cin >> month;

        if (month > 12 || month < 1) { //only accepting a valid month from the user
            cout << "Invalid entry for month. Please try again." << endl;
            continue;
        }

        cout << "Enter the day (1-31): ";
        cin >> day;

        if (day > 31 || day < 1) { //only accepting a valid day from the user
            cout << "Invalid entry for day. Please try again." << endl; 
            continue;
        }

        cout << "Enter the year (XXXX): ";
        cin >> year;

        if (year.length() != 4 || stoi(year) < 1) { //only accepting a valid year from the user
            cout << "Invalid entry for year. Please try again." << endl;
            continue;
        }

        break;
    }
    setDate(); //calling setter function to set the date based on user choice

}

void Date::setDate(){

    //calling function based on the users choice for formating
    switch (option){
        case 1:
            dateOne();
            break;
        case 2:
            dateTwoThree();
            break;
        case 3:
            dateTwoThree();
            break;
        case 4:
            dateFour();
            break;
    };

}

void Date::dateOne() {
    string finalYear = year.substr(2); //removing the first two numbers in the year for format one
    if (month < 10) { //checking for if "0" should be added
        cout << "0" << month << "/" << day << "/" << finalYear << endl;
    } else {
        cout << month << "/" << day << "/" << finalYear << endl;
    }
}

void Date::dateTwoThree() {
    
    //making array for the months as words
    string monthTYPE[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 

    
    switch (option){
        case 2:
            cout << monthTYPE[month - 1] << " " << day << ", " << year << endl; //displaying th correcty format with the month as a word for option 2
            break;

        case 3:
            cout << day << " " << monthTYPE[month-1] << ", " << year << endl; //displaying th correcty format with the month as a word for option 3
    };


}

void Date::dateFour() {
    if (month < 10) { //checking for if "0" should be added
        cout << year << "/" << "0" << month << "/" << day << endl;
    } else {
        cout << year << "/" << month << "/" << day << endl;
    }
}

int main() {
    Date info; //creating instance of Date class
    string answer;

    while (true) {
        cout << "Hello! Would you like to format your date? (Y/N): "; //checking to see if user wants to input a date to format
        cin >> answer;
        if (answer == "N") {
            cout << "Have a nice day!" << endl;
            break;
        } else if (answer == "Y") {
            cout << "Make your date format selection" << endl;
            info.menu(); //calling menu function from Date class
            cin >> info.option;
            info.getDate(); //calling getter function from Date class to get the date from the user
        } else {
            cout << "INVALID INPUT... TRY AGAIN" << endl; //catching invalid input
        }
    }

    return 0;
}



