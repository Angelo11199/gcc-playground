#include <iostream>

#include "../include/snippets.h"
using namespace std;
int main(int argc, char const *argv[]) {
    // create a reverse half triangle
    print("Create a reverse half triangle");
    int n = getNum("Enter n: ");
    if (n <= 0) {
        print("n must be greater than 0");
        return 0;
    }
    string triangle = "";
    for (int i = 0; i < n; i++) {
        triangle += "*";
        print(triangle);
    }
}