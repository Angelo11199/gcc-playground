#include <iostream>
// include rand
#include <cstdlib>

#include "../include/snippets.h"
using namespace std;
// max limit of factorial : 20. This is a recursive function
size_t getFactorial(size_t n) {
    do {
        if (n == 1 || n == 0) break;
        return n * getFactorial(n - 1);
    } while (true);
    return 1;
}
// reversing using pointers
void Reverse(string result, string* strPtr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        *strPtr += result[i];
    }
}
void multiplication(int n, int max = 10) {
    while (n <= 0) {
        n = getNum("Enter a number: ");
        if (n > 0) {
            multiplication(n);
            break;
        } else
            print("Please enter a positive NON ZERO number");
    }
    for (int i = 1; i <= max; i++)
        print(to_string(n) + " * " + to_string(i) + " = " + to_string(n * i));
}
int main(int argc, char const* argv[]) {
    bool isRunning = true;
    while (isRunning) {
        print("[F] Factorial");
        print("[M] Multiplication");
        print("[R] Reverse");
        print("[Q] Quit");
        char choice = tolower(getStr("Enter a choice: ")[0]);
        // use switch case to call functions
        switch (choice) {
            case 'f': {
                size_t n = getNum("Enter a number: ");
                if (n > 20) {
                    print("Number too large");
                    break;
                }
                print("Factorial of " + to_string(n) + " is " + to_string(getFactorial(n)));
                break;
            }
            case 'm': {
                int n = getNum("Enter a number: ");
                multiplication(n);
                break;
            }
            case 'r': {
                string value = getStr("Enter a string: ");
                string result = "";
                string* resultPtr = &result;
                Reverse(value, resultPtr, value.length());
                cout << "Reversed string: " << result << endl;
                break;
            }
            case 'q': {
                isRunning = false;
                print("Quitting...");
                break;
            }
            default: {
                print("Invalid choice");
                break;
            }
        }
    }
}
