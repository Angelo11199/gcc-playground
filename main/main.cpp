#include <iostream>
// include rand
#include <cstdlib>

#include "../include/snippets.h"
using namespace std;
void numGame() {
    // create a random guessing game
    int num;
    cin >> num;
    int randNum = rand() % 100;
    while (num != randNum) {
        if (num > randNum) {
            print("Too high");
        } else {
            print("Too low");
        }
        num = getNum("Enter a guess (1-100): ");
    }
    print("You got it!");
}
void multiplication(int n, int max = 10) {
    while (n <= 0) {
        n = getNum("Enter a number: ");
        if (n > 0) {
            multiplication(n);
            break;
        } else
            print("Please enter a positive NON ZERO number");
    }
    for (int i = 1; i <= max; i++)
        print(to_string(n) + " * " + to_string(i) + " = " + to_string(n * i));
}
// deg
int main(int argc, char const *argv[]) {
    multiplication(getNum("Enter a number: "));
    return 0;
}
