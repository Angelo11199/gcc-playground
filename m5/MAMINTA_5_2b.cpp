#include <algorithm>
#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    string months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    string month;
    int day, year, monthNumber;
    bool found = false;
    do {
        print("Enter month: ");
        cin >> month;
        transform(month.begin(), month.end(), month.begin(), ::tolower);
        for (int i = 0; i < 12; i++) {
            if (month == months[i]) {
                found = true;
                monthNumber = i;
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
    // switch case horoscope
    switch (monthNumber) {
        case 0:
            if (day >= 20)
                print("Aquarius");
            else
                print("Capricorn");
            break;
        case 1:
            if (day >= 19)
                print("Pisces");
            else
                print("Aquarius");
            break;
        case 2:
            if (day >= 21)
                print("Aries");
            else
                print("Pisces");
            break;
        case 3:
            if (day >= 20)
                print("Taurus");
            else
                print("Aries");
            break;
        case 4:
            if (day >= 21)
                print("Gemini");
            else
                print("Taurus");
            break;
        case 5:
            if (day >= 21)
                print("Cancer");
            else
                print("Gemini");
            break;
        case 6:
            if (day >= 23)
                print("Leo");
            else
                print("Cancer");
            break;
        case 7:
            if (day >= 23)
                print("Virgo");
            else
                print("Leo");
            break;
        case 8:
            if (day >= 23)
                print("Libra");
            else
                print("Virgo");
            break;
        case 9:
            if (day >= 23)
                print("Scorpio");
            else
                print("Libra");
            break;
        case 10:
            if (day >= 22)
                print("Sagittarius");
            else
                print("Scorpio");
            break;
        case 11:
            if (day >= 22)
                print("Capricorn");
            else
                print("Sagittarius");
            break;
    }
    return 0;
}
