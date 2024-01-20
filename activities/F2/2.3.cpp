#include <cstring>
#include <iostream>

#include "../../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    string userInput = getStr("Enter a string: ");
    string capitalized = "";
    int length = userInput.length();
    int i = 0;
    char vowels[] = {'A', 'E', 'I', 'O', 'U', ' '};
    int vowelCount[] = {0, 0, 0, 0, 0, 0};
    while (i < length) {
        capitalized += toupper(userInput[i]);
        for (int j = 0; j < 6; j++) {
            if (toupper(userInput[i]) == vowels[j]) {
                vowelCount[j]++;
                break;
            }
        }
        i++;
    }
    print("The capitalized string is: " + capitalized);
    print("The number of vowels are: ");
    for (int i = 0; i < 7; i++) {
        if (i == 5) {
            cout << "White Space: " << vowelCount[i] << endl;
            break;
        }
        cout << vowels[i] << ": " << vowelCount[i] << endl;
    }

    return 0;
}
