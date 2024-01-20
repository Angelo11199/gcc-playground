#include <math.h>

#include <iostream>
using namespace std;
// prints in a new line
template <typename T>
void print(T Value) {
    cout << Value << endl;
}
// Prints in the same line
template <typename userInput>
void printLn(userInput value) {
    cout << value;
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
double areaSquare(double side) {
    return side * side;
}
double areaRectangle(double length, double width) {
    return length * width;
}
double areaTriangle(double base, double height) {
    return 0.5 * base * height;
}
double areaCircle(double radius) {
    return M_PI * radius * radius;
}
int main(int argc, char const* argv[]) {
    // loop until user exits
    while (true) {
        print("========================================");
        print("                  MENU!               ");
        print("========================================");
        print("1. Area of a square");
        print("2. Area of a rectangle");
        print("3. Area of a triangle");
        print("4. Area of a circle");
        print("5. Exit");
        int choice = getNum("Enter your choice: ");
        if (choice == 5) {
            print("Exiting...");
            break;
        }
        switch (choice) {
            case 1: {
                double side = getNum("Enter side: ");
                printLn("Area is: ");
                print(areaSquare(side));
                break;
            }
            case 2: {
                double length = getNum("Enter length: ");
                double width = getNum("Enter width: ");
                printLn("Area is: ");
                print(areaRectangle(length, width));
                break;
            }
            case 3: {
                double base = getNum("Enter base: ");
                double height = getNum("Enter height: ");
                printLn("Area is: ");
                print(areaTriangle(base, height));
                break;
            }
            case 4: {
                double radius = getNum("Enter radius: ");
                printLn("Area is: ");
                print(areaCircle(radius));
                break;
            }
            default: {
                print("Invalid choice");
                break;
            }
        }
    }

    /* code */
    return 0;
}
