#include <math.h>

#include <iostream>
// include cstdllib
#include <cstdlib>
using namespace std;

void print(string s) {
    cout << s << endl;
}
// NUMBER 1
int isPositive() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int totalDigits = 0;
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        totalDigits++;
    }
    if (totalDigits > 4) {
        cout << "Number has more than 4 digits" << endl;
        exit(0);
    }
    // check if num is positive
    if (num > 0) {
        cout << "Number has " << totalDigits << " digits" << endl;
        cout << "Number is positive" << endl;
    } else {
        cout << "Number has " << totalDigits << " digits" << endl;
        cout << "Number is non-positive number" << endl;
    }
    return 0;
}
// NUMBER 2
int calculator() {
    // create a calculator using switch case
    float num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operator: ";
    cin >> op;
    cout << "The result of the operation is : ";
    switch (op) {
        case '+':
            cout << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 * num2 << endl;
            break;
        case '/':
            cout << num1 / num2 << endl;
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
    }
    return 0;
}
int main(int argc, char const *argv[]) {
    // Number 1
    calculator();
    // Number 2
    isPositive();
}
