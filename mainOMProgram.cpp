/*
Name: Jasmine Singleton
Course: SCIS 215
Date: 11-19-23
Description: Office manager final project

Note: I left the comments of where i added or took away
some things with a reason why
*/

#include <iostream>
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include "Account.h"
#include <vector>
#include <fstream>
//removed arrays because vectors are easier to manipulate
//added array for room occupancy

/*
    TO DO
    - Add some input validation
    - UI Design
    - Update Algorithm
    - Submitttttttt

*/

using namespace std;

class OfficeManager {
    private:
        vector<Doctor> doctors; //vector for  doctors
        vector<Patient> patients; //vector for  patients
        vector<Appointment> appointments; //vector to keep track of appointments
        vector<Account> doctorAccounts; //added vector to keep track of accounts and
        vector<Account> patientAccounts; //added separate vectors for doctors and patients
        vector <string> docStatus; //added vector to keep track of doctor status
        vector<int> rooms; //added a vector to hold rooms
        int roomsArr[5][2]; //added private member array to access it in multiple functions
        int appointmentCount; //added private variable to keep count of appointments
        

    public:
        OfficeManager(){} //default constructor

        void loadOfficeData(string filename){
            ifstream gettingData;
            string line, object;
            appointmentCount = 0;
            //creating vectors to hold raw data before breaking it down
            vector<string> doc;
            vector<string> pat;
            

            gettingData.open(filename);

            while (getline(gettingData, line)) { //reading each line of file
                
                if(line.empty()){ //skipping over spaces
                    continue;
                }
                if (line == "Doctors"){
                    object = "Doctors";
                    continue;
                } else if (line == "Patients"){
                    object = "Patients";
                    continue;
                } else if (line == "Rooms"){
                    object = "Rooms";
                    continue;
                }

                if (object == "Doctors"){ //adding doctor data to raw data vector
                    doc.push_back(line);

                } else if (object == "Patients"){ //adding patient data to raw data vector
                        pat.push_back(line);

                } else if (object == "Rooms"){ //adding room numbers to room vector
                    rooms.push_back(stoi(line));
                }
            }
            for (int x = 0; x < doc.size(); x++){ //iterating doctor vector for raw data
               if (x == 0 || x == 9 || x == 18){ //creating new doctor objects for each doctor from file
                    Doctor doctor(doc[x], doc[x + 1], doc[x + 2], doc[x + 3],
                    doc[x + 4], doc[x + 5], doc[x + 6], doc[x + 7], doc[x + 8]);

                    Account docAccount(doc[x], doc[x + 8], 700, "null"); //creating account for each doctor
                                                                         //with $700 to start
                    doctors.push_back(doctor); //adding object to doctor vector
                    doctorAccounts.push_back(docAccount);
                }else{
                   continue; //skipping over other values of x
                }
            }

            for (int y = 0; y < pat.size(); y++){ //iterating patient vector for raw data
                //cout << pat[y] << endl; error checking
                if (y == 0 || y == 12 || y == 24 || y == 48 || y == 96){ //creating new patient objects for each doctor from file
                    Patient patient(pat[y], pat[y + 1], pat[y + 2], pat[y + 3],
                    pat[y + 4], pat[y + 5], pat[y + 6], pat[y + 7], pat[y + 8], pat[y + 9], pat[y + 10], pat[y + 11]);

                    Account patAccount(pat[y + 1],pat[y + 11], 300, pat[y + 10]);//creating account for each patient
                                                                                 //with $300 to start

                    patients.push_back(patient); //adding object to patient vector
                    patientAccounts.push_back(patAccount);
                }else{
                    continue; //skipping over other values of y
                }
            }
            
            //creating mechanism for room occupancy
            //updated populating array by using loop because I ran into issues with tryin to use the array in another function
            //0 means unoccupied and 1 means occupied
            for (int i = 0; i < 5; ++i) {
                roomsArr[i][0] = rooms[i];
                roomsArr[i][1] = 0;
            }
            for (int i = 0; i < doctors.size(); i++){
                docStatus.push_back("Unoccupied");
            }
            

            /*
            error checking
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 2; ++j) {
                    cout << roomsArr[i][j] << " ";
                }
                cout << endl;
            }
           */

            gettingData.close();

            /*
            error checking
            for (int i = 0; i < patients.size(); i++) {
                patients[i].displayInfo();
                cout << "---------------------------------\n";
                }
            */
            
        }

        void newPatient(){ //took away parameter because it was unnecessary
            string arrival, firstName, lastName, address, city, state, zip, phone, email, dateOfBirth, insuranceCompany, patientID, appointmentID;

            //getting information for new patient
            cout << "Please enter Patient Information:\n\n";

            cout << "Arrival Time (hour:minute:seconds am/pm): ";
            getline(cin, arrival);

            cout << "First Name: ";
            getline(cin, firstName);

            cout << "Last Name: ";
            getline(cin, lastName);


            cout << "Address: ";
            getline(cin, address);

            cout << "City: ";
            getline(cin, city);

            cout << "State: ";
            getline(cin, state);

            cout << "Zip Code: ";
            getline(cin, zip);

            cout << "Phone Number: ";
            getline(cin, phone);

            cout << "Email: ";
            getline(cin, email);

            cout << "Date of Birth: ";
            getline(cin, dateOfBirth);

            cout << "Insurance Company: ";
            getline(cin, insuranceCompany);

            cout << "Patient ID: ";
            getline(cin, patientID);

            Patient patient(arrival, firstName, lastName, address, city, state, zip, phone, email, dateOfBirth, insuranceCompany, patientID); //adding new patient
            patients.push_back(patient);
            Account newPatientAccount(firstName, patientID, 300, insuranceCompany); //starting every patient off with $300
            patientAccounts.push_back(newPatientAccount); //adding the new account to vector

            //displaying information for new patient
            cout << "\nSummary of New Patient Information:\n";
            patient.displayInfo();
            
        }

        void newDoctor(){//took away parameter because it was unnecessary
            string firstName, lastName, address, city, state, zip, phone, email, employeeID;

            //getting information for new doctor
            cout << "Please enter Doctor Information:\n\n";
            
            cout << "First Name: ";
            getline(cin, firstName);

            cout << "Last Name: ";
            getline(cin, lastName);

            cout << "Address: ";
            getline(cin, address);

            cout << "City: ";
            getline(cin, city);

            cout << "State: ";
            getline(cin, state);

            cout << "Zip Code: ";
            getline(cin, zip);

            cout << "Phone Number: ";
            getline(cin, phone);

            cout << "Email: ";
            getline(cin, email);

            cout << "Appointment ID: ";
            getline(cin, employeeID);

            Doctor doctor(firstName, lastName, address, city, state, zip, phone, email, employeeID);
            doctors.push_back(doctor);

            Account newDoctorAccount(firstName, employeeID, 700, "Null"); //starting every doctor with a balance of $700
            doctorAccounts.push_back(newDoctorAccount); //adding new doctor account
            docStatus.push_back("Unoccupied"); //adding doctor status

            //displaying information for new doctor
            cout << "\nSummary of New Doctor Information:\n";
            doctor.displayInfo();

            
        }

        void patientsSummary(){
            string assignApp, pName;
            if (patients.empty()) { //checking for the patients vector being empty
                cout << "No patients to report." << endl;
            }else{
                //displaying the patient summary
                cout << endl << "Patient Summary:\n";
                cout << "---------------------------------\n";

                for (int i = 0; i < patients.size(); i++) {
                    cout << "Patient: " << patients[i].getFName() << " " << patients[i].getLName() << endl;
                    cout << "Arrival Time: " << patients[i].getArrival() << endl << endl;
                }
                cout << "---------------------------------\n";

                cout << "Do you want to assign a patient? [Y/N]" << endl;
                cin >> assignApp;

                if (assignApp == "Y"){
                    cout << "\nEnter the patients first name: " << endl; //getting patients name
                    cin >> pName;
                    newAppointment(pName); //calling function to make the appointment
                }
            }



        }

        void doctorSummary(){
            if (doctors.empty()) { //checking for the patients vector being empty
                cout << "No doctors to report." << endl;
            }else{
                //displaying the doctor summary
                cout << endl << "Doctor Summary:\n";
                cout << "---------------------------------\n";

                for (int i = 0; i < doctors.size(); i++) {
                    cout << "Doctor: " << doctors[i].getFName() << " " << doctors[i].getLName() << endl;
                    cout << "Status " << docStatus[i] << endl << endl;
                }
                cout << "---------------------------------\n";
            }
        }

        void orderingAppointments(){
            swap(patients[0], patients[1]); //ordering patients by arrival time
            swap(patientAccounts[0], patientAccounts[1]); //ordering accounts by arrival time
        }

        void newAppointment(string thePatient){ //added parameter to assign correct patient
            int roomNum, visitT, index, indexTwo;
            

            if (patients.empty()) {
                cout << "No patients available for appointments." << endl;
            }else if(docStatus[0] == "Occupied" && docStatus[1] == "Occupied" && docStatus[2] == "Occupied"){

                cout << "\nAll doctors are currently seeing a patient." << endl; //not allowing new appointments if all doctors are busy

            }else{

                //showing rooms that are available
                cout << "List of available rooms:\n";

                for (int i = 0; i < 5; i++) {
                    //0 means unoccupied
                    if (roomsArr[i][1] == 0) {
                        cout << "Room: " << roomsArr[i][0] << endl;
                    }
                }


                cout << "Enter the room number for the new appointment: ";
                cin >> roomNum;

                cout << "Enter 1 for preventative or 2 for sick" << endl;
                cin >> visitT;

                for (int i = 0; i < patients.size(); i++){ //getting the correct patient
                    if (patients[i].getFName() == thePatient){
                        index = i;
                    }
                }

                for (int i = 0; i < docStatus.size(); i++){
                    if (docStatus[i] == "Unoccupied"){ //getting the first unoccupied doctor
                        indexTwo = i;
                        docStatus[i] = "Occupied";
                        break;
                    }
                }
                //creating an appointment
                Appointment newAppoint(patients[index].getFName(), doctors[indexTwo].getFName(), "04/24/24", patients[index].getArrival(), visitT, patients[index].getPatientID(), roomNum);
                appointments.push_back(newAppoint);

                //updating the room as being occupied
                for (int i = 0; i < 5; i++) {
                    //1 means occupied
                    if (roomsArr[i][0] == roomNum) {
                        roomsArr[i][1] = 1;
                    }
                }

                cout << "\nNew Appointment for " << patients[index].getFName() << " " << patients[index].getLName() << " in room " << roomNum << endl;
                }
                patients.erase(patients.begin() + index); //deleting patient from vector
                appointmentCount++; //updating appointment count
            }
        

        void checkout() { //removed parameter because it was unnecessary
            int index, indexTwo, indexThree;
            string appointmentNum;
            double x;

            if (appointments.empty()){
                cout << "\nThere are no patients to check out.\n";
            }else{
                cout << "---------------------------------\n";

                //displaying current appointments
                for (int i = 0; i < appointments.size(); i++) {
                        cout << "Patient: " << appointments[i].getPatientName() << endl << "Doctor: " << appointments[i].getDocName() << endl;
                        cout << "Appointment ID:  " << appointments[i].getAppointmentID() << endl << endl; //add mechanism for if doctor seeing patient
                    }
                cout << "---------------------------------\n";

                cout << "Enter the appointment ID for checkout: " << endl; //getting specific appointment
                cin >> appointmentNum;

                for (int i = 0; i < appointments.size(); i++){ //getting the correct appointment
                    if (appointmentNum == appointments[i].getAppointmentID()){
                        index = i;
                        for (int j = 0; j < doctorAccounts.size(); j++){ //getting the correct doctor account
                            if (appointments[index].getDocName() == doctorAccounts[j].getFirstName()){
                                indexThree = j;
                                break;
                            }
                        }
                        break;
                    }
                }

                for (int i = 0; i < patientAccounts.size(); i++){
                    if (appointmentNum == patientAccounts[i].getOwnerID()){
                        indexTwo = i;
                    }
                }
                //calculating the fee based on the visit type
                if (appointments[index].getVisitType() == 1){
                    if (patientAccounts[indexTwo].getInsurance() != "NA"){
                        x = 0.0;
                    }else if (patientAccounts[indexTwo].getInsurance() == "NA"){
                        x = 29.95;
                    }
                    
                }else if (appointments[index].getVisitType() == 2){
                    if (patientAccounts[indexTwo].getInsurance() != "NA"){
                        x = 50.95;
                    }else if (patientAccounts[indexTwo].getInsurance() == "NA"){
                        x = 150.95;
                    }
                }



                //getting the doctors account and updating their balance
                for (int i = 0; i < doctors.size(); i++) {
                    if (doctors[i].getFName() == doctorAccounts[indexThree].getFirstName()) {

                        doctorAccounts[i].updateBalance(x);
                        break;
                    }
                }

                //getting the patients account and updating their balance
                for (int i = 0; i < patients.size(); i++) {
                    if (patients[i].getPatientID() == appointments[index].getAppointmentID()) {
                        patientAccounts[i].updateBalance(-x);
                        patients.erase(patients.begin() + i); //deleting patient from system
                        break;
                    }
                }
                
                //adding descriptive message
                cout << endl << appointments[index].getPatientName() << " has checked out successfully.\n" << "The total for their visit was $" << x << endl;

                rooms[appointments[index].getRoomNum()] = 0; //making the room unoccupied
                appointments.erase(appointments.begin() + index); //deleting appointment from vector
                docStatus[indexThree] = "Unoccupied"; //making the doctors status unoccupied
            }
        }


        void closeOffice(string file) {
            //opening file
            ofstream closingFile;
            closingFile.open(file);

            for (int i = 0; i < doctors.size(); i++){ //writing the doctors and their balances to the file
                closingFile << "Doctor: " << doctors[i].getFName() << " " << doctors[i].getLName() << endl;
                closingFile << "Balance: $" << doctorAccounts[i].getDocBalance() << endl << endl;
            }

            closingFile << "Number of patients seen today: " << appointmentCount << endl; //writing the number of patients seen to the file
            closingFile.close(); //closing file
        }
        
};

int main() {
    OfficeManager todo;
    int count = 0; //added count variable so manager can only load office data once
    //ofstream closing("closeOffice.txt"); moved to closeOffice function
    ofstream log("officeHistory.txt");
    
    while (true){
        
        int choice;
        string file;
        cout << "\n\nOffice Manager Menu\n";
        cout << "------------------------\n";
        cout << "1. Load Office Data\n2. Add New Patient\n3. Add New Doctor\n4. Patient Queue Summary\n5. Doctor Summary\n6. Checkout Patient\n7. Close Office\n";
        cout << "\nHello, Jasmine! What task would you like to do? ";
        cin >> choice;
        cin.ignore(); //ignoring newline to make getline work correctly
        if (choice == 7){
            cout << "\nThe office is being closed. Goodbye :)" << endl;
            log << "\nTransaction: closed office \n";
            log.close();
            //call close office function
            todo.closeOffice("closeOffice.txt");
            break;
        }
    
        switch (choice){
            case 1:
                if (count == 0) {
                    cout << "Enter the file name ('officeMgr.txt'): " << endl;
                    cin >> file;
                    if (file == "officeMgr.txt") {
                        todo.loadOfficeData(file);
                        todo.orderingAppointments(); //ordering appointments in file by arrival time
                        log << "\nTransaction: loaded office data \n";
                        cout << "\nOffice data loaded successfully!\n";
                        count = 1;
                        
                    } else {
                        cout << "Invalid file name..." << endl;
                    }
                } else {
                    cout << "Office data already loaded.\n";
                }
                break;

            case 2:
                //call new patient function
                todo.newPatient();
                log << "Transaction: added new patient \n";
                break;
            case 3:
                //call new doctor function
                todo.newDoctor();
                log << "Transaction: added new doctor \n";
                break;
            case 4:
                //call patient summary
                todo.patientsSummary();
                log << "Transaction: patient queue summary request \n";
                break;
            case 5:
                //call doctor summary
                todo.doctorSummary();
                log << "Transaction: doctor summary request \n";
                break;
            case 6:
                //call checkout function
                todo.checkout();
                log << "Transaction: checked out a patient \n";
                break;
            default:
                cout << "\nINVALID SELECTION\n";
                break;
        };

    }
    
    return 0;
}

