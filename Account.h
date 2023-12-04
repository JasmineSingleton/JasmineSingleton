//Jasmine Singleton

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account {
    private:
        string ownerID;
        string insured;
        string firstNAME;
        double balance;
    public:
        Account( string fName, string oID, double bal, string surance){ //added parameter for first name to make checkout easier
            firstNAME = fName;
            ownerID = oID;
            balance = bal;
            insured = surance;
        }

        void updateBalance(double amount){ //updating balance
            balance += amount;
        }

        string getInsurance(){return insured;}
        string getOwnerID(){return ownerID;}
        string getFirstName(){return firstNAME;}
        double getDocBalance(){return balance;} //added getter for returning balance when office closes

};

#endif
