#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    double input;
    cout << "Enter Philippine peso: ";
    cin >> input;
    double usd = input / 43.33089;
    cout << "The amount's equivalent to: " << endl;
    cout << "US Dollar is \t: \t" << usd << endl;
    cout << "Euro\t\t: \t" << usd * 0.734719 << endl;
    cout << "Yuan\t\t: \t" << usd * 6.346934 << endl;
    cout << "Koruna\t\t: \t" << usd * 18.77263 << endl;
    cout << "Krone\t\t: \t" << usd * 5.449007 << endl;
    cout << "Sheqel\t\t: \t" << usd * 3.726334 << endl;
    cout << "Dinar\t\t: \t" << usd * 0.274588 << endl;
    return 0;
}
