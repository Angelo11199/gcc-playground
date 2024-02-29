#include <string.h>
#include <algorithm>
#include <string>

#include <iomanip>
#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

void getConsoleSize(int &rows, int &cols) {
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    #else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        rows = w.ws_row;
        cols = w.ws_col;
    #endif
}
#define MAX 100
// #include "../include/snippets.h" //boilerplate code only
using namespace std;
struct Students {
    int studentID;
    char firstName[50];
    char lastName[50];
    float GPA;
};
// prints in a new line
template <typename T>
void print(T Value) {
    cout << Value << endl;
}
// Prints in the same line
template <typename U>
void printLn(U s) {
    cout << s;
};
// gets a string from the user
void getStr(string prompt = "", char inputValue[] = nullptr, int numMax = 20) {
    if (inputValue == nullptr) {
        inputValue = new char[numMax];
    }
    cout << prompt;
    cin.getline(inputValue, numMax);
}
// gets a number from the user
float getNum(string prompt = "") {
    string num;
    char* p;
    do {
        cout << prompt;
        cin >> num;
        float convertedNum = strtof(num.c_str(), &p);
        if (*p) {
            cout << "Invalid input" << endl;
        } else {
            cin.ignore();
            return convertedNum;
        }
    } while (true);
    return 0;
}
// check if an array is full
bool arrayFull(Students student[], int numStudents) {
    if (numStudents > MAX) {
        print("Array is full");
        return true;
    }
    return false;
}
void getLongestLength(const Students student[], int numStudents, int& longestFirst, int& longestLast, int& longestId, int index = 0) {
    if (index == numStudents) {
        return;
    }

    longestFirst = max(longestFirst, static_cast<int>(strlen(student[index].firstName)));
    longestLast = max(longestLast, static_cast<int>(strlen(student[index].lastName)));
    longestId = max(longestId, static_cast<int>(to_string(student[index].studentID).length()));
    getLongestLength(student, numStudents, longestFirst, longestLast, longestId, index + 1);
}

// adds a student to the array
void addStudent(Students student[], int& numStudents) {
    if (arrayFull(student, numStudents)) return;
    student[numStudents].studentID = numStudents + 1;
    getStr("Enter student's first name:", student[numStudents].firstName, 50);
    getStr("Enter student's last name:", student[numStudents].lastName, 50);
    student[numStudents].GPA = getNum("Enter student's GPA:");
    while (true) {
        student[numStudents].GPA = getNum("Enter student's GPA:");
        if (student[numStudents].GPA >= 0 && student[numStudents].GPA <= 4) break;
        print("Invalid GPA. Please enter a value between 0 and 4.");
    }
    print("Student added successfully");
    numStudents++;
}
void displayStudents(const Students students[], int numStudents, int offset = 0, int limit = 10) {
    // linear search. not efficient for large data sets TODO: implement a binary tree search algorithm
    if (numStudents == 0) {
        print("No students found");
        return;
    }
    if (limit > numStudents) limit = numStudents;
    if (offset < 0) offset = 0;
    //get the longest length on each column
    int longestID = 0, longestFirstName = 0, longestLastName = 0, longestGPA = 0;
    getLongestLength(students, numStudents, longestFirstName, longestLastName, longestID);
    //print the header
    //get window size
    int rows, cols;
    getConsoleSize(rows, cols);
    if(longestID + longestFirstName + longestLastName + longestGPA > cols){
        print("Window size too small. Please resize the window to at least " + to_string(longestID + longestFirstName + longestLastName + longestGPA) + " columns");
        return;
    }
    cout << left << setw(longestID + 5) << "ID" << setw(longestFirstName + 5) << "First Name" << setw(longestLastName + 5) << "Last Name" << setw(longestGPA + 5) << "GPA" << endl;
    for (int i = offset; i < limit; i++) {
        cout << left << setw(longestID + 5) << students[i].studentID << setw(longestFirstName + 5) << students[i].firstName << setw(longestLastName + 5) << students[i].lastName << setw(longestGPA + 5) << students[i].GPA << endl;
       
    }
    print("Press N for next page, P for previous page, Q to quit");
    char response[1];
    getStr("Enter your choice: ",response, 1);
    response[0] = toupper(response[0]);
    if (response[0] == 'N' && limit < numStudents) {
        displayStudents(students, numStudents, offset + 10, limit + 10);
    } else if (response[0] == 'P' && offset > 0) {
        displayStudents(students, numStudents, offset - 10, limit - 10);
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
    if (numStudents > 0)
        return (students[numStudents - 1].GPA + calculateAverageGPA(students, numStudents - 1)) / numStudents;
    else
        return 0.0;
}
void printMenu() {
    print( "                                                                                                                     ");
    print( "   _______________________________          _______________________________          _______________________________ ");
    print( "  |                               |        |                               |        |                               |");
    print( "  |       Add Student [1]         |        |    Display All Students [2]   |        | Find Students by Last Name[3] |");
    print( "  |_______________________________|        |_______________________________|        |_______________________________|");
    print( "   _______________________________          _______________________________          _______________________________");
    print( "  |                               |        |                               |        |                               |");
    print( "  |  Compute Average GPA [4]      |        |             Exit [0]          |        |                               |");
    print( "  |_______________________________|        |_______________________________|        |_______________________________|");

}
void pauseAndContinue() {
#ifdef _WIN32
    system("pause");
    system("cls");
#endif
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("read -p 'Press enter to continue...' var");
    system("clear");
#endif
}
int main(int argc, char const* argv[]) {
    int rows, cols;
    getConsoleSize(rows, cols);
    print("Welcome to the student management system");
    pauseAndContinue();
    int registeredStudents = 0;
    char temp[50];
    bool isRunning = true;
    Students student[MAX];
    while (isRunning) {
        printMenu();
        printLn("Enter your choice: ");
        string response;
        getline(cin, response);
        switch (response[0]) {
            case '1': {
                if (arrayFull(student, registeredStudents)) break;
                addStudent(student, registeredStudents);
                pauseAndContinue();
                break;
            }
            case '2': {
                displayStudents(student, registeredStudents);
                pauseAndContinue();
                break;
            }
            case '3': {
                print("Average GPA: " + to_string(calculateAverageGPA(student, registeredStudents)));
                pauseAndContinue();

                break;
            }
            case '4': {
                getStr("Enter the last name: ", temp, 50);
                findStudentsByLastName(student, registeredStudents, temp);
                pauseAndContinue();

                break;
            }
            case '5': {
                print("Goodbye!");
                isRunning = false;
                break;
            }
            default: {
                print("Invalid choice");
                pauseAndContinue();
                break;
            }
        }
    }
    return 0;
}
