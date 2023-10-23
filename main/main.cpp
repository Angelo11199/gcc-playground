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
void oddOrEven() {
    int num1 = getNum("input num: ");
    string result = num1 % 2 == 0 ? "even" : "odd";
    print(num1 + " is " + result);
    cout << num1 << " is " << result << endl;
}
void grades() {
    int grade = getNum("Enter a number: ");
    // int grade;
    // cin >> grade;
    cout << grade << endl;
    if (grade >= 91 && grade <= 100) print("A");
    if (grade >= 81 && grade <= 90) print("B");
    if (grade >= 70 && grade <= 80) print("C");
    if (grade >= 0 && grade <= 69)
        print("D");
    else
        print("Invalid grade");
}
void numero() {
    int num = getNum("Enter a number: ");
    switch (num) {
        case 1:
            print("Isa");
            break;
        case 2:
            print("Dalawa");
            break;
        case 3:
            print("Tatlo");
            break;

        default:
            print("Invalid input");
            break;
    }
}
void menuOfShapes() {
    print("S-Square");
    print("R-Rectangle");
    print("C-Circle");
    string choice = getStr("Enter a choice: ");
    choice[0] = toupper(choice[0]);

    switch (choice[0]) {
        case 'S':
            print("You Choose Square");
            break;
        case 'R':
            print("You Choose Rectangle");
            break;
        case 'C':
            print("You Choose Circle");
            break;
        default:
            break;
    }
}
void degree() {
    int degree = getNum("Enter a degree celsius: ");
    if (degree >= 100)
        print("Steam");

    if (degree <= 45 && degree >= 99)
        print("Water is boiling");
    else if (degree <= 46 && degree >= 1)
        print("Water ");
    else if (degree <= 0)
        print("Water is freezing");
}
void letterDisplay() {
    string letter = getStr("Enter a letter: ");
    // convert letter to uppercase
    letter[0] = toupper(letter[0]);
    switch (letter[0]) {
        case 'D':
            print("Destroyer");
            break;
        case 'B':
            print("Battleship");
            break;
        case 'F':
            print("Frigate");
            break;
        case 'C':
            print("Cruiser");
            break;

        default:
            print("Invalid input");
            break;
    }
}
int main(int argc, char const *argv[]) {
    // degree();
    letterDisplay();
    return 0;
}
