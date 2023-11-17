#include <iostream>
// include rand
#include <cstdlib>

#include "../include/snippets.h"
using namespace std;
// define PIN VALUE
#define PIN 1234
#define PUK 4567

int checkInput(int correctNum, int attempts = 3, string prompt = "Enter your pin:") {
    if (attempts == 0) return 0;
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
    print(success ? "Correct PIN" : "Incorrect PIN");
    if (!success) {
        bool pukSuccess = checkInput(PUK, 3, "Enter your PUK:");
        print(pukSuccess ? "Correct PUK" : "SIM BLOCKED");
    }
    return 0;
}
