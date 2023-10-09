// include  math
#include <stdio.h>

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    // check if input is a  leaf year
    int year;
    cout << "Enter a year: ";
    cin >> year;
    if (year % 400 == 0) {
        cout << year << " is a leap year." << endl;
    }
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            cout << year << " is a leap year." << endl;

        } else {
            cout << year << " is not a leap year." << endl;
        }
    }
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            cout << year << " is not a leap year." << endl;

        } else {
            cout << year << " is a leap year." << endl;
        }
    } else {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}
