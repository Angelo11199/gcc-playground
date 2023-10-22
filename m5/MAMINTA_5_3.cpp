#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    double salary = getNum("Enter salary: ");
    double sales = getNum("Enter sales: ");
    // check if salary is greater than 50k
    if (salary >= 50000) print("income is" + to_string(575 + (sales * 0.16)));
    if (salary < 50000 && salary >= 40000) print("income is " + to_string(550.0 + (sales * 0.14)));
    if (salary < 40000 && salary >= 30000) print("income is " + to_string(525.0 + (sales * 0.12)));
    if (salary < 30000 && salary >= 20000) print("income is " + to_string(500.0 + (sales * 0.09)));
    if (salary < 20000 && salary >= 10000) print("income is " + to_string(450.0 + (sales * 0.05)));
    if (salary < 10000) print("income is" + to_string(400 + (sales * 0.03)));
    /* code */
    return 0;
}
