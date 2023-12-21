#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    // compute factorial using while loop
    print("Compute factorial using while loop");
    long int n = getNum("Enter n: ");
    long int factorial = 1;
    while (n > 0) {
        factorial *= n;
        n--;
    }
    print("Factorial is " + to_string(factorial));
    return 0;
}
