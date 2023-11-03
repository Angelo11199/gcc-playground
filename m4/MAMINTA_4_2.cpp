#include <math.h>

#include <iomanip>
#include <iostream>

using namespace std;
bool checkNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false && str[i] != '.') {
            cout << "Invalid input!" << endl;
            return false;
        }
    return true;
}
double getNum(string prompt) {
    string num;
    do {
        cout << prompt << endl;
        getline(cin, num);
    } while (checkNumber(num) == false);
    return stoi(num);
}
string getInput(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}
void printStatement(string id, string name, string payrollPeriod, double salary, double lates, double tax, double total) {
    cout << "FEU – Institute of Technology" << endl;
    cout << "Employee ID" << setw(20) << id << setw(39) << "Payroll Period:" << payrollPeriod << endl;
    cout << "Employee Name" << setw(18) << name
         << endl;
    cout << endl;
    cout << "INCOME" << setw(40) << "DEDUCTIONS" << endl;
    cout << "Monthly Salary "
         << "Php " << setprecision(7) << showpoint << salary << setw(27) << "Lates and absences" << setw(10) << "(" << lates << ")" << endl;
    cout << setw(46) << "Philhealth" << setw(20)
         << "(1000.00)" << endl;
    cout << setw(44) << "Pag-ibig" << setw(21)
         << "(800.00)" << endl;
    cout << setw(39) << "SSS" << setw(27)
         << "(1200.00)" << endl;
    cout << setw(51) << "Withholding tax" << setw(15)
         << "(" << tax << ")" << endl;
    cout << "Total Earnings: Php" << setprecision(7) << salary << endl;
    cout << "Total Deductions: Php " << setprecision(7) << tax + 1200 + 800 + 1000 << endl;
    cout << "Net Pay: " << total << endl;
}
int main(int argc, char const *argv[]) {
    string id, name, payrollPeriod;
    double salary, lates = 0, hourly = 75;
    payrollPeriod = getInput("Enter payroll period: ");
    id = getInput("Enter employee ID: ");
    salary = getNum("Enter monthly salary: ");
    name = getInput("Enter employee name: ");
    lates = getNum("Enter lates and absences in MINUTES: ");
    if (lates) {
        lates = (lates / 60) * hourly;
    }
    double tax = salary * 0.12;
    double total = salary - tax - 3000 - lates;
    printStatement(id, name, payrollPeriod, salary, lates, tax, total);
    return 0;
}
