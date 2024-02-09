
#include <string.h>

#include <iomanip>

#include "../include/snippets.h"
using namespace std;
struct Students {
    int studentID;
    char firstName[50];
    char lastName[50];
    float GPA;
};
int registeredStudents = 0;
void addStudent(Students student[], int& numStudents) {
    student[numStudents].studentID = numStudents + 1;
    printLn("Enter the first name: ");
    cin.getline(student[numStudents].firstName, 50);
    printLn("Enter the last name: ");
    cin.getline(student[numStudents].lastName, 50);
    while (true) {
        student[numStudents].GPA = (float)getNum("Enter student's GPA:");
        if (student[numStudents].GPA >= 0 && student[numStudents].GPA <= 4) break;
        print("Invalid GPA. Please enter a value between 0 and 4.");
    }
    print("Student added successfully");
    numStudents++;
}
void displayStudents(const Students students[], int numStudents) {
    // linear search. not efficient for large data sets
    for (int i = 0; i < numStudents; i++) {
        printLn("Student ID: " + to_string(students[i].studentID));
        printLn("First Name: " + string(students[i].firstName));
        printLn("Last Name: " + string(students[i].lastName));
        printLn("GPA: " + to_string(students[i].GPA));
    }
}
void findStudentsByLastName(const Students students[], int numStudents, const char lastName[]) {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].lastName, lastName) == 0) {
            found = true;
            printLn("Student ID: " + to_string(students[i].studentID));
            printLn("First Name: " + string(students[i].firstName));
            printLn("Last Name: " + string(students[i].lastName));
            printLn("GPA: " + to_string(students[i].GPA));
        }
    }
    if (!found) {
        print("No student found with the last name: " + string(lastName));
    }
}
float calculateAverageGPA(const Students students[], int numStudents) {
    if (numStudents > 0) {
        return (students[numStudents - 1].GPA + calculateAverageGPA(students, numStudents - 1)) / numStudents;
    } else {
        return 0.0;
    }
}

int main(int argc, char const* argv[]) {
    print("1. Add student");
    print("2. Display All Students");
    print("3. Calculate Average GPA");
    print("4. Find Students by Last Name");
    print("5. Exit");
    bool isRunning = true;
    Students student[100];
    while (isRunning) {
        string response = getStr("Enter your choice: ");
        print("You entered: " + response);
        switch (response[0]) {
            case '1': {
                addStudent(student, registeredStudents);
                break;
            }
            case '2': {
                displayStudents(student, registeredStudents);
                break;
            }
            case '3': {
                printLn("Average GPA: " + to_string(calculateAverageGPA(student, registeredStudents)));
                break;
            }
            case '4': {
                char lastName[50];
                print("Enter the last name: ");
                cin.getline(lastName, 50);
                findStudentsByLastName(student, registeredStudents, lastName);
                break;
            }
            case '5': {
                printLn("Exit");
                isRunning = false;
                break;
            }
            default: {
                printLn("Invalid choice");
                break;
            }
        }
    }
    return 0;
}
