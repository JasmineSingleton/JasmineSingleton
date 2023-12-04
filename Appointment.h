//Jasmine Singleton

#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include <string>
using namespace std;

class Appointment {

    private:
        string patientName;
        string doctorName;
        string date;
        string time;
        int visitType;
        string appointmentID; //added this to update correct account
        int roomNumber;
    public:
        Appointment(string pName, string dName, string d, string t, int vType,string appID, int rNumber){
            patientName = pName;
            doctorName = dName;
            date = d;
            time = t;
            visitType = vType;
            appointmentID = appID;
            roomNumber = rNumber;
        }


    string getPatientName(){return patientName;}
    string getDocName(){return doctorName;}
    string getDATE(){return date;}
    string getTIME(){return time;}
    int getVisitType(){return visitType;}
    string getAppointmentID(){return appointmentID;}
    int getRoomNum(){return roomNumber;}

};

#endif
