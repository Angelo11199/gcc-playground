#include <iostream>
// include rand
#include <cstdlib>

#include "../include/snippets.h"
using namespace std;
// define PIN VALUE
#define PIN 1234
#define PUK 4567

int checkInput(int correctNum, int attempts = 3, string prompt = "Enter your pin:", bool isPUK = true) {
    if (attempts < 1 && !isPUK) {
        bool PUKSuccess = checkInput(PUK, 3, "Enter your PUK:", false);
        print(PUKSuccess ? "PUK ACCEPTED" : "SIM BLOCKED");
        return PUKSuccess ? 1 : 0;
    }
    int Pin = getNum(prompt);
    if (Pin == correctNum)
        return 1;
    else {
        print("Incorrect " + to_string(attempts - 1) + " attempts remaining");
        return checkInput(correctNum, attempts - 1, prompt);
    }
}
int main(int argc, char const *argv[]) {
    bool success = checkInput(PIN);
    if (success) {
        print("welcome to SGS Telecom");

    } else
        print("You have failed to log in");
    return 0;
}
