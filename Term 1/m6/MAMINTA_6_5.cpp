#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    print("print  all numbers from n1 to n2");
    int nOne = getNum("Enter n: ");
    int nTwo = getNum("Enter n2: ");
    string num = "";
    // loop until none is lower than nTwo
    while (nOne >= nTwo) {
        nOne = getNum("Enter n: ");
        nTwo = getNum("Enter n2: ");
        if (nOne >= nTwo)
            print("n1 must be lower than n2");
        }
    while (nOne <= nTwo) {
        num += to_string(nOne) + " ";
        nOne++;
    }
    print(num);
}