#include <algorithm>
#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    string months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    string month;
    int day, year;
    bool found = false;
    do {
        print("Enter month: ");
        cin >> month;
        transform(month.begin(), month.end(), month.begin(), ::tolower);
        for (int i = 0; i < 12; i++) {
            if (month == months[i]) {
                found = true;
                break;
            } else
                found = false;
        }
    } while (!found);
    do {
        day = getNum("Enter day: ");
        year = getNum("Enter year: ");
        if (year > 9999) print("Invalid year");
        if (day > 31) print("Invalid day");
    } while (year > 9999 || day > 31);
    if (month == "january" && day >= 20 || month == "february" && day <= 18)
        print("Aquarius");
    else if (month == "february" && day >= 19 || month == "march" && day <= 20)
        print("Pisces");
    else if (month == "march" && day >= 21 || month == "april" && day <= 19)
        print("Aries");
    else if (month == "april" && day >= 20 || month == "may" && day <= 20)
        print("Taurus");
    else if (month == "may" && day >= 21 || month == "june" && day <= 20)
        print("Gemini");
    else if (month == "june" && day >= 21 || month == "july" && day <= 22)
        print("Cancer");
    else if (month == "july" && day >= 23 || month == "august" && day <= 22)
        print("Leo");
    else if (month == "august" && day >= 23 || month == "september" && day <= 22)
        print("Virgo");
    else if (month == "september" && day >= 23 || month == "october" && day <= 22)
        print("Libra");
    else if (month == "october" && day >= 23 || month == "november" && day <= 21)
        print("Scorpio");
    else if (month == "november" && day >= 22 || month == "december" && day <= 21)
        print("Sagittarius");
    else if (month == "december" && day >= 22 || month == "january" && day <= 19)
        print("Capricorn");
    else
        print("Invalid date");

    return 0;
}
