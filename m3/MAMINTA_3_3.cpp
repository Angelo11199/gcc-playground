#include <iostream>
#include <stdexcept>
using namespace std;
bool checkNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false) {
            cout << "Invalid input!" << endl;
            return false;
        }
    return true;
}
int getNum(string prompt) {
    string num;
    do {
        cout << prompt << endl;
        cin >> num;
    } while (checkNumber(num) == false);
    return stoi(num);
}
int main() {
    int num1, num2;
    num1 = getNum("Enter first number: ");
    num2 = getNum("Enter second number:");
    // display sum, difference, product, quotient, and remainder
    cout << "Sum: " << num1 + num2 << endl;
    cout << "Difference: " << num1 - num2 << endl;
    cout << "Product: " << num1 * num2 << endl;
    try {
        if (num2 == 0) throw runtime_error("Divide by zero exception");
        cout << "Quotient: " << num1 / num2 << endl;
        cout << "Remainder: " << num1 % num2 << endl;

    } catch (runtime_error& e) {
        cout << "Quotient: CANNOT BE" << endl;
        cout << "Remainder: CANNOT BE" << endl;
    }

    return 0;
}