#include <iostream>
using namespace std;

void display(int indices[10]) {
    for (int i = 0; i < indices; ++i) {
        cout << indices[i] << " ";
    }
}

int main() {
    int numbers[10], indices[10];
    int numbersWithIndex[10][2];
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; ++i) {
        cin >> numbers[i];
        if (numbers[i] % 2 == 0) {
            numbersWithIndex[i][0] = numbers[i];
        }
    }
    display(indices);

    return 0;
}