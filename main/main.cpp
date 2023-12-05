#include <iostream>
// include rand
#include <cstdlib>

#include "../include/snippets.h"
using namespace std;

// area of circle
double areaOfCircle(double radius) {
    return 3.14 * radius * radius;
}
double areaOfRectangle(double length, double width) {
    return length * width;
}
int main(int argc, char const *argv[]) {
    string choice;
    do {
        print("1. Area of circle");
        print("2. Area of rectangle");
        print("3. Exit");
        choice = getStr("Enter your choice: ");
        switch (choice[0]) {
            case '1':
                print("Area: " + to_string(areaOfCircle(getNum("Enter radius: "))));
                break;
            case '2':
                print("Area: " + to_string(areaOfRectangle(getNum("Enter length: "), getNum("Enter width: "))));
                break;
            case '3':
                print("Exiting...");
                break;
            default:
                print("Invalid choice");
                break;
        }
        /* code */
    } while (choice[0] != '3');

    return 0;
}
