#include <ctime>

#include "../include/snippets.h"

double Add(double a, double b) {
    return a + b;
}
double Subtract(double a, double b) {
    return a - b;
}
double Multiply(double a, double b) {
    return a * b;
}
double Divide(double a, double b) {
    return a / b;
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
        print("5. Exit");
        int choice = getNum("Enter your choice: ");
        if (choice == 5) {
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
            default: {
                print("Invalid choice");
                break;
            }
        }
    }

    // print(sum);
    return 0;
}
