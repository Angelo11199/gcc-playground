// note : NOT WORKING ON DEV C++ 5.11
#include <iomanip>   // IO manipulation
#include <iostream>  // IO
using namespace std;

struct WeeklyTemp {
    string city;
    double monday;
    double tuesday;
    double wednesday;
    double thursday;
    double friday;
    double saturday;
    double sunday;
};

// Prints in the same line
template <typename U>
void printLn(U s) {
    std::cout << s;
};
// gets a number from the user
double getNum(std::string prompt = "") {
    std::string num;
    char *p;
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
}

// gets a string from the user
std::string getStr(std::string prompt = "") {
    std::string s;
    std::cout << prompt;
    getline(std::cin, s);
    return s;
}
// setting the precision of the output to 4 decimal places
void printWithPrecision(double num) {
    cout << fixed << setprecision(4) << num;
}
// prints the value with a new line
template <typename T>
void print(T Value) {
    std::cout << Value << std::endl;
}
// Unit testing
void test(WeeklyTemp &cityInfo) {
    print("Unit testing mode");
    cityInfo.city = "San Jose del Monte";
    cityInfo.monday = 35.5;
    cityInfo.tuesday = 34.6;
    cityInfo.wednesday = 32.55;
    cityInfo.thursday = 36.4;
    cityInfo.friday = 37.1;
    cityInfo.saturday = 30.5;
    cityInfo.sunday = 32.55;
}
int main(int argc, char const *argv[]) {
    WeeklyTemp cityInfo;
    // test(cityInfo);  // uncomment for unit testing
    cityInfo.city = getStr("Enter City name:");                        // getting userInput
    cityInfo.monday = getNum("Enter degees from monday to sunday: ");  // getting userInput
    cityInfo.tuesday = getNum("");                                     // getting userInput
    cityInfo.wednesday = getNum("");                                   // getting userInput
    cityInfo.thursday = getNum("");                                    // getting userInput
    cityInfo.friday = getNum("");                                      // getting userInput
    cityInfo.saturday = getNum("");                                    // getting userInput
    cityInfo.sunday = getNum("");                                      // getting userInput
    double average = (cityInfo.monday + cityInfo.tuesday + cityInfo.wednesday + cityInfo.thursday + cityInfo.friday + cityInfo.saturday + cityInfo.sunday) / 7;
    printLn("The average temperature in " + cityInfo.city + " is ");
    printWithPrecision(average);
    print(" degrees.");
    return 0;
}
