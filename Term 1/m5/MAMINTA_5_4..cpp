#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    string figure = "";
    do {
        print("Enter figure (c/r/s): ");
        getline(cin, figure);
        if (figure != "c" && figure != "r" && figure != "s")
            print("Invalid figure");
    } while (figure != "c" && figure != "r" && figure != "s");
    switch (figure[0]) {
        case 'c': {
            double length = getNum("Enter length: ");
            double width = getNum("Enter width: ");
            print("Area is " + to_string(length * width));
            break;
        }
        case 'r': {
            double length = getNum("Enter length: ");
            double width = getNum("Enter width: ");
            print("Area is " + to_string(length * width));
            break;
        }
        case 's': {
            double base = getNum("Enter base: ");
            double height = getNum("Enter height: ");
            print("Area is " + to_string(0.5 * base * height));
            break;
        }
        default:
            print("Invalid figure");
    }
    return 0;
}
