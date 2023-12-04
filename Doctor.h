//Jasmine Singleton

#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string>
using namespace std;

class Doctor {

    private:
        string firstName;
        string lastName;
        string address;
        string city;
        string state;
        string zip;
        string phone;
        string email;
        string employeeID;
        
    public:
        Doctor(string fn, string ln, string a, string c, string s,
            string z, string ph, string e, string eID){ //constuctor

            //added variables for first and last name based on file
            firstName = fn;
            lastName = ln;
            address = a;
            city = c;
            state = s;
            zip = z;
            phone = ph;
            email = e;
            employeeID = eID;
            //appointmentID = aID;
        }

    void displayInfo(){ //displaying doctor info
        cout << "Doctor Name: " << getFName() << ", " << getLName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "City: " << getCity() << endl;
        cout << "State: " << getState() << endl;
        cout << "ZIP Code: " << getZip() << endl;
        cout << "Phone: " << getPhone() << endl;
        cout << "Email: " << getEmail() << endl;
        cout << "Employee ID: " << getEmployeeID() << endl;
    }

    //getter funcitons
    string getFName(){return firstName;}
    string getLName(){return lastName;}
    string getAddress(){return address;}
    string getCity(){return city;}
    string getState(){return state;}
    string getZip(){return zip;}
    string getPhone(){return phone;}
    string getEmail(){return email;}
    string getEmployeeID(){return employeeID;}


};

#endif
