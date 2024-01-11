#include <ctime>

#include "../include/snippets.h"
double* getNums() {
    double* nums = new double[2];
    nums[0] = getNum("Enter first number: ");
    nums[1] = getNum("Enter second number: ");
    return nums;
}
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
            break;
        }
        double* nums = getNums();
        switch (choice) {
            case 1: {
                printLn("Sum is: ");
                print(Add(nums[0], nums[1]));

                break;
            }
            case 2: {
                print(Subtract(nums[0], nums[1]));

                break;
            }
            case 3: {
                print(Multiply(nums[0], nums[1]));
                break;
            }
            case 4: {
                print(Divide(nums[0], nums[1]));
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
