#include <cstring>
#include <iostream>

using namespace std;
// prints in a new line
template <typename T>
void print(T Value) {
    cout << Value << endl;
}
// Prints in the same line
template <typename U>
void printLn(U s) {
    std::cout << s;
};
// gets a string from the user
string getStr(std::string prompt = "") {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}

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
    printLn("The capitalized string is: " + capitalized + "\n");
    print("The number of vowels are: ");
    for (i = 0; i < 7; i++) {
        if (i == 5) {
            print("White Space: " + to_string(vowelCount[i]));
            break;
        }
        printLn(vowels[i]);
        print(": " + to_string(vowelCount[i]));
    }
    return 0;
}