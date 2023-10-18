/*
Name: Jasmine Singleton
Course: SCIS 215
Date: 9/13/23
Purpose: The purpose of this program is to display a report for grades K-12.
It also has the option to add new data to each grade.
The data for each grade is read from a file.

*/



#include <iostream>
#include <vector> //library to use vectors
#include <fstream> //stream to manipulate files
using namespace std;

void report(int, float, float);

void report(int grade, float numofClasses, float numofStudents){
    float average;
    const int ELE = 6;
    string nameOfGrade[ELE] = {"kindergarten", "First grade", "Second grade", "Third grade", "Fourth grade", "Fifth grade"}; //array to switch grades

    average = numofStudents / numofClasses; //calculating th average

    cout << endl << nameOfGrade[grade] << " has " << numofStudents << " kids in " << numofClasses << " classes, and the average students per class is " << average << endl;
    //cout << fixed << setprecision(2) << showpoint << average << endl << endl;
}

int main() {
    const int ROWS = 6;
    vector<int> gradeTracker[ROWS]; //creating an array of vectors
    int count = 0, num, num2, newGrade;
    float totalClasses = 0, sumKids = 0, newStudentNum;
    string numLine, preConversion, answer;
    char x;

    ifstream data;
    data.open("classes.dat"); // Opening data file

    //taking in each line of the file as a string
    while(getline(data, numLine)){
        
        //parsing the string of data
        for (int i = 1; i < numLine.length(); i++){
            //checking each character to see if it is a space
            x = numLine[i];
            if (x != ' '){
                preConversion += x; //getting numbers that are above 9 reading for string to int conversion
            }else{
                 if (!preConversion.empty()) {
                    num = stoi(preConversion); //converting the string to an integer
                    gradeTracker[count].push_back(num); //adding the integer to the array of vectors
                    preConversion.clear(); //clearing the string to allow new conversion for numbers above 9
                    }
                }
            }
            
        num2 = stoi(preConversion); //converting the character to an integer
        gradeTracker[count].push_back(num2); //adding the integer to the array of vectors
    
        count++; //updating the index for the array to correspond to each grade

    }

    data.close(); //closing data file

    for (int j = 1; j < ROWS; j++) {
        gradeTracker[j].erase(gradeTracker[j].begin()); //getting rid of duplicate from beginning of each grade

        }

    //traversing the data for each grade
    for (int y = 0; y < 6; y++ ){
        for (int w = 0; w < gradeTracker[y].size(); w++){
            totalClasses = totalClasses + 1; //getting the total number of classes in each grade
            sumKids = sumKids + gradeTracker[y][w]; // getting the total number of students in each grade
            }
    
        report(y,totalClasses, sumKids); //calling the report function to display the grade data

        //reseting the  sum variables
        totalClasses = 0;
        sumKids = 0;
        }

    cout << endl;

    //asking the user if they want to add anything until they quit
     while (true){
        cout << "Do you want to add another class to a grade? (Y/N) "; 
        cin >> answer;

        if (answer == "Y"){
            //getting grade level
            cout << "Enter the grade level," << endl;
            cout << "[kindergarten - 0, 1st grade - 1, 2nd grade - 2, 3rd grade - 3, 4th grade - 4, 5th grade - 5]" << endl;
            cin >> newGrade;

            //getting number of students
            cout << "Enter the number of students: " << endl;
            cin >> newStudentNum;

            //adding the data to the grade
            gradeTracker[newGrade].push_back(newStudentNum);


            //getting the new data for the users input
            for (int x = 0; x < gradeTracker[newGrade].size(); x++){
                totalClasses = totalClasses + 1;
                sumKids = sumKids + gradeTracker[newGrade][x];

            }
            report(newGrade,totalClasses, sumKids); //calling the report function to display the grade data

            //updating the sum variables
            totalClasses = 0;
            sumKids = 0;
        }else if(answer == "N"){

            //displaying goodbye message and breaking the loop
            cout << endl << "Have a nice day!" << endl;
            break;
        }
    }

    return 0;

}