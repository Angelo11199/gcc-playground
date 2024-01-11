#include <iostream>
using namespace std;
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

// gets a number from the user and loop until user enters a valid number
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

double Add(double a = 0, double b = 0) {
    return a + b;
}
double Subtract(double a = 0, double b = 0) {
    return a - b;
}
double Multiply(double a = 0, double b = 0) {
    return a * b;
}
double Divide(double a = 0, double b = 0) {
    return a / b;
}
double Modulo(double a = 0, double b = 0) {
    // typecast to int to get the remainder
    return (int)a % (int)b;
}
int main(int argc, char const* argv[]) {
    while (true) {
        print("========================================");
        print("                  MENU!               ");
        print("========================================");
        print("1. Add two numbers");
        print("2. Subtract two numbers");
        print("3. Multiply two numbers");
        print("4. Divide two numbers");
        print("5. Modulo two numbers");
        print("6. Exit");
        int choice = getNum("Enter your choice: ");
        if (choice == 6) {
            print("Exiting...");
            break;
        }
        double num1 = getNum("Enter first number: ");
        double num2 = getNum("Enter second number: ");
        switch (choice) {
            case 1: {
                printLn("Sum is: ");
                print(Add(num1, num2));

                break;
            }
            case 2: {
                printLn("Difference is: ");
                print(Subtract(num1, num2));

                break;
            }
            case 3: {
                printLn("Product is: ");
                print(Multiply(num1, num2));
                break;
            }
            case 4: {
                printLn("Quotient is: ");
                print(Divide(num1, num2));
                break;
            }
            case 5: {
                printLn("Remainder is: ");
                print(Modulo(num1, num2));
                break;
            }

            default: {
                print("Invalid choice");
                break;
            }
        }
    }

    // print(sum);
    return 0;
}
