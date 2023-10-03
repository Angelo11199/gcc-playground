#include <iostream>
using namespace std;
int main() {
    string data[9][8] = {{
                             " | data 1 | ",
                             " | data 2 | ",
                             " | data 3 | ",
                             " | data 4 | ",
                             " | data 5 | ",
                             " | data 6 | ",
                             " | data 7 | ",
                             " | data 8 | ",
                         },
                         {
                             " | data d1 | ",
                             " | data d2 | ",
                             " | data d3 | ",
                             " | data d4 | ",
                             " | data d5 | ",
                             " | data d6 | ",
                             " | data d7 | ",
                             " | data d8 | ",
                         },
                         {
                             " | data c1 | ",
                             " | data c2 | ",
                             " | data c3 | ",
                             " | data c4 | ",
                             " | data c5 | ",
                             " | data c6 | ",
                             " | data c7 | ",
                             " | data c8 | ",
                         },
                         {
                             " | data b1 | ",
                             " | data b2 | ",
                             " | data b3 | ",
                             " | data b4 | ",
                             " | data b5 | ",
                             " | data b6 | ",
                             " | data b7 | ",
                             " | data b8 | ",
                         },
                         {
                             " | data a1 | ",
                             " | data a2 | ",
                             " | data a3 | ",
                             " | data a4 | ",
                             " | data a5 | ",
                             " | data a6 | ",
                             " | data a7 | ",
                             " | data a8 | ",
                         },
                         {
                             " | data d1 | ",
                             " | data d2 | ",
                             " | data d3 | ",
                             " | data d4 | ",
                             " | data d5 | ",
                             " | data d6 | ",
                             " | data d7 | ",
                             " | data d8 | ",
                         },
                         {
                             " | data d1 | ",
                             " | data d2 | ",
                             " | data d3 | ",
                             " | data d4 | ",
                             " | data d5 | ",
                             " | data d6 | ",
                             " | data d7 | ",
                             " | data d8 | ",
                         },
                         {
                             " | data d1 | ",
                             " | data d2 | ",
                             " | data d3 | ",
                             " | data d4 | ",
                             " | data d5 | ",
                             " | data d6 | ",
                             " | data d7 | ",
                             " | data d8 | ",
                         }};
    int rows,
        columns;  //* numbers
    for (rows = 0; rows <= 5; rows++) {
        cout << "\n";
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        for (columns = 0; columns <= 7; columns++) {
            cout << data[rows][columns];
        }
    }
    cout << "\n";
    cout << "-------------------------------------------------------------------------------------------------------" << endl;

    return 0;
}