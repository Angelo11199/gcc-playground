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
    double a, b, c;
    a = getNum("Enter side A: ");
    b = getNum("Enter side B: ");
    c = sqrt(pow(a, 2) + pow(b, 2));
    cout << "The hypotenuse is: " << c << endl;
    /* code */
    return 0;
}
