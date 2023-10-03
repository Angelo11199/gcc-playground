#include <stdio.h>

#include <climits>
#include <iostream>
using namespace std;
unsigned long long factorial(unsigned long long factorialNum) {
    if (factorialNum > 20) {
        unsigned long long result = 1;
        for (int i = 2; i <= factorialNum; ++i) {
            // check if result is going to overflow
            result *= i;
            cout << "Result: " << result << std::endl;
            if (result > ULLONG_MAX / i) {
                cout << "Overflowed at: " << i << std::endl;
                return 1;
            }
        }
        return result;
    }
    if (factorialNum <= 1)
        return factorialNum;
    else
        return factorialNum * factorial(factorialNum - 1);
}

long long int permutations(int size, int TotalSelected) {
    if (TotalSelected < 0 || TotalSelected > size)
        return 0;
    unsigned long long numerator = factorial(size);
    unsigned long long denominator = factorial(size - TotalSelected);
    cout << "Numerator: " << numerator << std::endl;
    cout << "Denominator: " << denominator << std::endl;
    return numerator / denominator;
}

int main(int argc, char const *argv[]) {
    long long int result = permutations(20, 10);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
