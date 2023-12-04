//Jasmine Singleton

#ifndef PATIENT_H
#define PATIENT_H
#include "Account.h" //added account header file to update account...
#include <iostream>
#include <string>
using namespace std;

class Patient {

    private:
        string arrival;
        string firstName;
        string lastName;
        string address;
        string city;
        string state;
        string zip;
        string phone;
        string email;
        string dateOfBirth;
        string insuranceCompany;
        string patientID;
        
    public:
        Patient( string arr, string fn, string ln, string a,  string c,  string s,
            string z, string ph, string e, string DOB,
            string iC, string pID){ //constuctor

                arrival = arr;
                firstName = fn;
                lastName = ln;
                address = a;
                city = c;
                state = s;
                zip = z;
                phone = ph;
                email = e;
                dateOfBirth = DOB;
                insuranceCompany = iC;
                patientID = pID;
            }

        void displayInfo(){ //displaying doctor info
            cout << "Arrival Time: " << getArrival() << endl;
            cout << "Patient Name: " << getFName() << ", " << getLName() << endl;
            cout << "Address: " << getAddress() << endl;
            cout << "City: " << getCity() << endl;
            cout << "State: " << getState() << endl;
            cout << "ZIP Code: " << getZip() << endl;
            cout << "Phone: " << getPhone() << endl;
            cout << "Email: " << getEmail() << endl;
            cout << "Date of Birth: " << getDOB() << endl;
            cout << "Insurance Company: " << getIC() << endl;
            cout << "Patient ID: " << getPatientID() << endl;
        }


        //defining getter funcitons
        string getArrival(){return arrival;}
        string getFName(){return firstName;}
        string getLName(){return lastName;}
        string getAddress(){return address;}
        string getCity(){return city;}
        string getState(){return state;}
        string getZip(){return zip;}
        string getPhone(){return phone;}
        string getEmail(){return email;}
        string getDOB(){return dateOfBirth;}
        string getIC(){return insuranceCompany;}
        string getPatientID(){return patientID;}
};

#endif
