//! Notice: The following does not work on dev c++ due to compiler issues. but it does work on online compilers. I use G++ or clang++ on linux
#include <iostream>
#define ARRAY_SIZE 10
using namespace std;
void clearAndPuase() {
#ifdef _WIN32
    system("pause");
    system("cls");
#else
    system("read -p 'Press Enter to continue...' var");
    system("clear");
#endif
}
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// prints in a new line
template <typename any>
void print(any Value) {
    cout << Value << endl;
}
// Prints in the same line
template <typename any>
void printLn(any Value) {
    cout << Value;
};

std::string getStr(std::string prompt = "") {
    std::string s;
    std::cout << prompt;
    getline(std::cin, s);
    return s;
}

// gets a number from the user and loop until user enters a valid number
int getNum(string prompt = "") {
    string num;
    char* p;
    do {
        cout << prompt;
        cin >> num;
        int convertedNum = strtol(num.c_str(), &p, 10);
        if (*p) {
            cout << "Invalid input" << endl;
        } else {
            cin.ignore();
            return convertedNum;
        }
    } while (true);
    return 0;
}
int main(int argc, char const* argv[]) {
    int userInput[ARRAY_SIZE], i;
    bool indexes[ARRAY_SIZE];
    while (true) {
        printLn("Enter 10 numbers: ");
        string userInputStr = getStr("");
        // check if user input is less than 10 numbers
        if (userInputStr.length() < 10) {
            print("numbers too few");
        }
        // split the string by space and only gets the first ten
        for (i = 0; i < ARRAY_SIZE; i++) {
            int pos = userInputStr.find(" ");
            if (pos == string::npos) {
                userInput[i] = stoi(userInputStr);
                break;
            }
            string num = userInputStr.substr(0, pos);
            userInput[i] = stoi(num);
            userInputStr.erase(0, pos + 1);
        }
    }

    clearScreen();
    int selectedNumber = getNum("Enter a number to search: ");
    int count = 0;
    printLn("The numbers you entered are: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (userInput[i] == selectedNumber) {
            count++;
            indexes[i] = true;
        } else {
            indexes[i] = false;
        }
        printLn(to_string(userInput[i]));
        if (i != ARRAY_SIZE - 1) printLn(", ");
    }
    // get the index of the duplicated num
    print("");
    print("The number " + to_string(selectedNumber) + " appeared " + to_string(count) + " times");
    print("The indexes of the number " + to_string(selectedNumber) + " are: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (!indexes[i]) continue;
        printLn(to_string(i));
        if (i == ARRAY_SIZE - 1)
            printLn("");
        else
            printLn(", ");
    }

    return 0;
}
