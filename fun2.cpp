#include <stdio.h>

#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    /* code */
    int n, num, digit, rev = 0;
    cout << "Enter a number: ";
    cin >> num;
    n = num;
    do {
        digit = num * 10;
        rev = (rev * 10) + digit;
        num /= 10;
    } while (num != 0);
    cout << "The reverse of the number is: " << rev << endl;
    if (n == rev)
        cout << "The number is a palindrome" << endl;
    else
        cout << "The number is not a palindrome" << endl;
    return 0;
}
