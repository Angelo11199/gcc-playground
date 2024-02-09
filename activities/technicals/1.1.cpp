//! Notice: The following does not work on dev c++ due to compiler issues. but it does work on online compilers. I use G++ or clang++ on linux
#include <math.h>

#include <iostream>
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
int Add(int a = 0, int b = 0) {
    return a + b;
}
int Subtract(int a = 0, int b = 0) {
    return a - b;
}
int Multiply(int a = 0, int b = 0) {
    return a * b;
}
int Divide(int a = 0, int b = 0) {
    // check if divisor is 0
    if (b == 0) {
        print("Cannot divide by 0");
        return 0;
    }
    return a / b;
}
int Modulo(int a = 0, int b = 0) {
    return a % b;
}
int main(int argc, char const* argv[]) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);  // sets the precision of the output to 2 decimal places
    while (true) {
        print("========================================");
        print("                  MENU!               ");
        print("========================================");
        print("1. Add two numbers");
        print("2. Subtract two numbers");
        print("3. Multiply two numbers");
        print("4. Divide two numbers");
        print("5. Modulo of two numbers");
        print("6. Power of two numbers");
        print("7. Exit");
        int choice = getNum("Enter your choice: ");
        if (choice == 7) {
            print("Exiting...");
            break;
        }
        clearScreen();
        int a = getNum("Enter two numbers: ");
        int b = getNum();
        int c;
        switch (choice) {
            case 1: {
                printLn("Sum is: ");
                c = Add(a, b);
                break;
            }
            case 2: {
                printLn("Difference is: ");
                c = Subtract(a, b);
                break;
            }
            case 3: {
                printLn("Product is: ");
                c = Multiply(a, b);
                break;
            }
            case 4: {
                printLn("Quotient is: ");
                c = Divide(a, b);
                break;
            }
            case 5: {
                printLn("Remainder is: ");
                c = Modulo(a, b);
                break;
            }
            case 6: {
                print(to_string(a) + " to the power of " + to_string(b) + " is: ");
                if (b < 0) {
                    c = 1 / pow(a, abs(b));
                } else
                    c = pow(a, b);
                break;
            }
            default: {
                print("Invalid choice");
                break;
            }
        }
        print(c);
        clearAndPuase();
    }
    print("Bye!");
    return 0;
}
