#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    // multiply using while loopa and without using * operator
    print("Multiply using while loop and without using * operator");
    int a = getNum("Enter a: ");
    int b = getNum("Enter b: ");
    int product = 0;
    while (b > 0) {
        product += a;
        b--;
    }
    print("Product is " + to_string(product));
    /* code */
    return 0;
}
