#include <iostream>
#include "../include/snippets.h"
using namespace std;
void printNumbers(){
// create a loop that counts down 
int max = 5;
int min = 1;
print("for loop");
for (int i = max; i >= min; i--) {
    for (int j = 1; j <= i; j++) {
        cout << j << " ";
    }
    cout << endl;
}

// convert to while loop
print("while loop");
while(max >= min){
    int j = 1;
    while(j <= max){
        cout << j << " ";
        j++;
    }
    cout << endl;
    max--;
}
print("do while loop");
// convert to do while loop
max = 5;
do{
    int j =1;
    do{
        cout << j << " ";
        j++;
    }while(j <= max);
    cout << endl;
    max--;
}while(max >= min);
}
void halfTriangle (){
    int maxHeight = 8;
    print("for loop");

    for (int i = 1; i <= maxHeight; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        print("");
    }
    // convert to while loop
    print("while loop");

    int temp = 1;
    while(temp <= maxHeight){
        int j = 1;
        while(j <= temp){
            cout << "*";
            j++;
        }
        print("");
        temp++;
    }
    //convert to do while loop
    print("do while loop");
    temp = 1;
    do{
        int j = 1;
        do{
            cout << "*";
            j++;
        }while(j <= temp);
        print("");
        temp++;
    }while(temp <= maxHeight);
}
void printNums(int max){
    print("for loop");
    for (int i = 1; i <= max; i++) {
        // print a count till max
        for (int j = 0; j <= max; j++) {
            cout<<j;
        }
        print("");
    }
    // convert to while loop
    print("while loop");

    int temp = max;
    while(temp >= 0){
        int j = 0;
        while(j <= max){
            cout<<j;
            j++;
        }
        print("");
        temp--;
    }
    // convert to do while loop
    print("do while loop");
        do{
        int j = 0;
        do{
            cout<<j;
            j++;
        }while(j <= max);
        print("");
        temp--;
    } while(temp >= 0);

}
int main(int argc, char const *argv[]) {
    printNumbers();
    // halfTriangle();
    // printNums(1);
}
