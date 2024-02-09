#include <string.h>

#include <iostream>

using namespace std;
#define ALPHABET 26
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
// gets a number from the user
double getNum(string prompt = "") {
    string num;
    char* p;
    do {
        cout << prompt;
        cin >> num;
        double convertedNum = strtod(num.c_str(), &p);
        if (*p) {
            cout << "Invalid input" << endl;
        } else {
            cin.ignore();
            return convertedNum;
        }
    } while (true);
    return 0;
}

// gets a string from the user
string getStr(string prompt = "") {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}
// shifts the message by the totalShift value and returns the shifted message
string shift(string message, int totalShift = 1) {
    for (int i = 0; i < message.length(); i++) {
        // checks ascii value of the character via typecasting
        if (message[i] >= 'a' && message[i] <= 'z')
            message[i] = (message[i] - 'a' + totalShift) % ALPHABET + 'a';
        // checks ascii value of the character via typecasting
        else if (message[i] >= 'A' && message[i] <= 'Z')
            message[i] = (message[i] - 'A' + totalShift) % ALPHABET + 'A';
    }
    return message;
}

// unit testing
void test() {
    string message = "abcdefghijklmnopqrstuvwxyz apple 1234";
    string message2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ APPLE 1234";
    printLn("Test case 1: ");
    print("'" + shift(message) + "'");
    printLn("Test case 2: ");
    print("'" + shift(message2) + "'");
    if (strcmp(shift(message).c_str(), "bcdefghijklmnopqrstuvwxyza bqqmf 1234") != 0) {
        print("Test case 1 failed");
    }
    if (strcmp(shift(message2).c_str(), "BCDEFGHIJKLMNOPQRSTUVWXYZA BQQMF 1234") != 0) {
        print("Test case 2 failed");
        return;
    }
    print("All test cases passed");
}
int main() {
    string userInput;
    test();  /// uncomment for unit testing
    // bool isError = false;
    // // check if userInput has a number
    // while (!isError) {
    //     userInput = getStr("Enter a message: ");
    //     try {
    //         int test = stoi(userInput);
    //         // check if successful
    //         print("Invalid input");
    //         isError = false;
    //     } catch (exception e) {
    //         isError = true;
    //     }
    //     if (isError) break;
    // }
    // int shiftValue = (int)getNum("Enter shift value: ");  // getting userInput
    // string result = shift(userInput, shiftValue);         // shifting the message
    // print("");
    // printLn("The decrypted message is: ");  // printing the result
    // print(userInput);
    // printLn("The encrypted message is: ");  // printing the result
    // print(result);
    return 0;
}