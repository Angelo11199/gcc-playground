#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    print("add all numbers from 0 to n");
    int n = getNum("Enter n: ");
    int sum = 0;
    for (int i = 0; i <= n; i++) sum += i;
    print("Sum is " + to_string(sum));
}