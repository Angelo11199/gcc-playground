#include <iostream>
using namespace std;
int main() {
    string data[8][9] = {
        {
            "| Courses  | ",
            "| CCS0001  | ",
            "| CCS0001L | ",
            "| CCS0003  | ",
            "| CCS0003L | ",
            "| GED0004  | ",
            "| GED0006  | ",
            "| GED0009  | ",
            "| GED0011  | ",
        },
        {
            "Title                                      | ",
            "INTRODUCTION TO COMPUTING (LEC)            | ",
            "INTRODUCTION TO COMPUTING (LAB)            | ",
            "COMPUTER PROGRAMMING 1 (LEC)               | ",
            "COMPUTER PROGRAMMING 1 (LAB)               | ",
            "PHYSICAL EDUCATION 1                       | ",
            "PERSONAL AND PROFESSIONAL EFFECTIVENESS	| ",
            "READINGS IN PHILIPPINE HISTORY             | ",
            "SCIENCE, TECHNOLOGY AND SOCIETY	        | ",
        },
        {
            "Section  | ",
            " TW-05   | ",
            " TW-05   | ",
            " TW-05   | ",
            " TW-05   | ",
            " TW-05   | ",
            " TW-05   | ",
            " TW-05   | ",
            " TW-05   | ",
        },
        {
            "Units  | ",
            "  2    | ",
            "  1    | ",
            "  2    | ",
            "  1    | ",
            "  3    | ",
            "  2    | ",
            "  3    | ",
            "  3    | ",
        },
        {
            " Days  | ",
            "  T    | ",
            "  TH   | ",
            "  F    | ",
            "  M    | ",
            "  M/TH | ",
            "  F/T  | ",
            "  M/TH | ",
            "  F/T  | ",
        },
        {
            "        Time                            | ",
            "  4:00PM -6:40PM                        | ",
            "  4:00PM-6:50PM                         | ",
            "  4:00PM -6:40PM                        | ",
            "  4:00PM-6:50PM                         | ",
            "  11:00am -12:50pm/11:00am -12:50pm     | ",
            "  11:00:00AM-12:20PM/11:00:00AM-12:20PM | ",
            "  1:00PM-2:50PM/1:00PM-2:50PM           | ",
            "  1:00PM-2:50PM/1:00PM-2:50PM           | ",

        },
        {
            "ROOM   | ",
            "ONLINE | ",
            "F1207  | ",
            "ONLINE | ",
            "E409   | ",
            "F301   | ",
            "ONLINE | ",
            "F510   | ",
            "ONLINE | ",
        },

    };
    int rows = 0,
        columns = 0;
    for (rows = 0; rows < 9; rows++) {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;

        for (columns = 0; columns < 7; columns++) {
            cout << data[columns][rows];
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    return 0;
}