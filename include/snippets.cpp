
#include "snippets.h"

#include <iostream>
void print(std::string s) {
    std::cout << s << std::endl;
}
void printLine(std::string s) {
    std::cout << s;
}
double getNum(std::string prompt) {
    std::string num;
    char* p;
    do {
        std::cout << prompt;
        std::cin >> num;
        double convertedNum = strtod(num.c_str(), &p);
        if (*p)
            std::cout << "Invalid input" << std::endl;
        else
            return convertedNum;

    } while (true);
    return 0;
}

std::string getStr(std::string prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}
