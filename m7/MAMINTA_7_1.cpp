#include "../include/snippets.h"
using namespace std;
/*
Write a program that performs temperature conversion from C to F, F to C and C to K based on the value of the choice argument that calls either of the three functions namely Celcius_to_Fahrenheit , Fahrenheit_to_Celcius and Celcius_to_Kelvin. If the user wishes to terminate the program, the user must type ‘N’ or ‘n’ to the question “Do you want to continue[Y/N]?” but if the user enters ‘Y’ or ‘y’ as the answer then the program must return to the main menu.
*/
int celsius_to_fahrenheit(int celsius) {
    return (celsius * 9 / 5) + 32;
}
int fahrenheit_to_celsius(int fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}
int celsius_to_kelvin(int celsius) {
    return celsius + 273.15;
}

int main(int argc, char const *argv[]) {
    bool isRunning = true;
    int choice, temp;
    while (isRunning) {
        choice = getNum("Enter 1 for Celsius to Fahrenheit, 2 for Fahrenheit to Celsius, 3 for Celsius to Kelvin, 4 to exit: ");
        temp = getNum("Enter temperature: ");
        switch (choice) {
            case 1:
                print("Celsius to Fahrenheit: " + to_string(celsius_to_fahrenheit(temp)));
                break;
            case 2:
                print("Fahrenheit to Celsius: " + to_string(fahrenheit_to_celsius(temp)));
                break;
            case 3:
                print("Celsius to Kelvin: " + to_string(celsius_to_kelvin(temp)));
                break;
            case 4:
                isRunning = false;
                break;
            default:
                print("Invalid choice");
                break;
        }
    }
    /* code */
    return 0;
}
