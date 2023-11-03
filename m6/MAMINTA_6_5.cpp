#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    print("print  all numbers from n1 to n2");
    int nOne = getNum("Enter n: ");
    int nTwo = getNum("Enter n2: ");
    string num = "";
    while (nOne <= nTwo) {
        num += to_string(nOne) + " ";
        nOne++;
    }
    print(num);
}