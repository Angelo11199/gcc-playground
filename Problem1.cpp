// include  math
#include <math.h>
#include <stdio.h>

#include <cctype>
#include <iostream>
using namespace std;

double convert(int userInput, string currency) {
    if (currency == "php") {
        return userInput * 1;
    } else if (currency == "usd") {
        return 1 / 43.33089;
    } else if (currency == "eur") {
        return (userInput / 43.33089) * 0.734719;
    } else if (currency == "yuan") {
        return (userInput / 43.33089) * 6.346934;
    } else if (currency == "koruna") {
        return (userInput / 43.33089) * 21.439;
    }
    return 0;
}
double heronsFormula(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
double slope(double x1, double y1, double x2, double y2) {
    double m = (y2 - y1) / (x2 - x1);
    return m;
}
int main(int argc, char const *argv[]) {
    double userValueInput = 0;
    string userInput = "";
    double result = 0;
    cout << "Enter a value: ";
    cin >> userValueInput;
    cout << "Enter a currency: ";
    cin >> userInput;
    // lowercase the user input
    for (int i = 0; i < userInput.length(); i++) {
        userInput[i] = tolower(userInput[i]);
    }
    result = convert(userValueInput, userInput);
    return 0;
}

// php : 43.33089 = 1$
// usd : 1.000
// eur :   0.734719
// yuan :  6.346934
// koruna :  21.439