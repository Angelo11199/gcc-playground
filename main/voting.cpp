#include <iostream>
// include rand
#include <cstdlib>

#include "../include/snippets.h"
using namespace std;
// define PIN VALUE
#define PIN 1234
#define PUK 23422342
int PresidentA = 0;
int PresidentB = 0;
int PresidentC = 0;

int votePresident() {
    char vote = getStr("Enter your vote:")[0];
    // switch case
    // lowercase vote
    vote = tolower(vote);
    switch (vote) {
        case 'a':
            print("You have voted for FPJ");
            PresidentA++;
            break;
        case 'b':
            print("You have voted for ROCO");
            PresidentB++;
            break;
        case 'c':
            print("You have voted for GMA");
            PresidentC++;
            break;
        default:
            print("Invalid vote");
            votePresident();
            break;
    }
    return vote;
}
int main(int argc, char const *argv[]) {
    while (true) {
        print("Welcome to the SGS Telecom voting system");
        print("Enter V to vote, R to see results, or Q to quit");
        char userChoice = getStr("Enter your choice:")[0];
        switch (userChoice) {
            case 'V':
            case 'v':
                // print availble presidents
                print("A. FPJ");
                print("B. ROCO");
                print("C. GMA");
                votePresident();
                break;
            case 'R':
            case 'r':
                print("President A: " + to_string(PresidentA));
                print("President B: " + to_string(PresidentB));
                print("President C: " + to_string(PresidentC));
                break;
            case 'Q':
            case 'q':
                print("Thank you for using the SGS Telecom voting system");
                return 0;
                break;
            default:
                print("Invalid choice");
                // clear screen
                system("clear");
                break;
        }
    }

    return 0;
}
