#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const* argv[]) {
    double grade1, grade2, grade3;
    grade1 = getNum("Enter grade 1: ");
    grade2 = getNum("Enter grade 2: ");
    grade3 = getNum("Enter grade 3: ");
    double average = (grade1 + grade2 + grade3) / 3.0;
    if (average > 70)
        print("Passed! :) :) :)");
    else
        print("Failed! :( :( :(");
    return 0;
}
