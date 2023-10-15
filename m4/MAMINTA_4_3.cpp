#include <math.h>

#include <iostream>

using namespace std;
bool checkNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false && str[i] != '.') {
            cout << "Invalid input!" << endl;
            return false;
        }
    return true;
}
double getNum(string prompt) {
    string num;
    do {
        cout << prompt << endl;
        cin >> num;
    } while (checkNumber(num) == false);
    return stoi(num);
}
int main(int argc, char const *argv[]) {
    // Write a program that solves for side c given the two sides a, b and angle C.
    double a, b, c, C;
    a = getNum("Enter side a: ");
    b = getNum("Enter side b: ");
    C = getNum("Enter angle C: ");
    c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(C));
    cout << "Side c is " << c << endl;
    /* code */
    return 0;
}
