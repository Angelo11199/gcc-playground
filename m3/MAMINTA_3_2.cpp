#include <iostream>
#include <typeinfo>
using namespace std;
int main(int argc, char const *argv[]) {
    int number = 10;
    char letter = 'a';
    bool result = true;
    float decimal = 3.14;
    cout << "Variable name\tData Type\tInitial value\n";
    cout << "Number\t\t"
         << "integer"
         << "\t\t" << number << endl;
    cout << "Letter\t\t"
         << "character"
         << "\t" << letter << endl;
    cout << "Result"
         << "\t\tboolean"
         << "\t\t" << result << endl;
    cout << "Decimal\t\t"
         << "float"
         << "\t\t" << decimal << endl;

    return 0;
}
