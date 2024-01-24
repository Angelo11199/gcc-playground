#include <iostream>
#include <string>

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
};
// gets a number from the user
double getNum(std::string prompt = "") {
    std::string num;
    char* p;
    do {
        std::cout << prompt;
        std::cin >> num;
        double convertedNum = strtod(num.c_str(), &p);
        if (*p) {
            std::cout << "Invalid input" << std::endl;
        } else {
            std::cin.ignore();
            return convertedNum;
        }
    } while (true);
    return 0;
};
#define ARRAY_SIZE 10
int main(int argc, char const* argv[]) {
    int j = 0;
    int i = 0;
    int nums[ARRAY_SIZE];
    int indexes[ARRAY_SIZE][2];
    while (i < ARRAY_SIZE) {
        nums[i] = (int)getNum("Enter number: " + to_string(i + 1) + ": ");
        if (nums[i] % 2 == 0) {
            indexes[j][0] = nums[i];
            indexes[j][1] = i;
            j++;
        }
        i++;
    }
    print("The even numbers are: ");
    for (i = 0; i < j; i++) {
        print(to_string(indexes[i][0]) + " at index " + to_string(indexes[i][1]));
    }

    return 0;
}
