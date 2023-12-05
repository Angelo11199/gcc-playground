using namespace std;
#include "../include/snippets.h"
/**Write a program that uses recursion to compute for the highest common factor of two numbers.
 *
 */
int hcf(int a, int b) {
    if (b == 0) return a;
    return hcf(b, a % b);
}

int main(int argc, char const *argv[]) {
    bool exit = false;
    while (!exit) {
        int a = getNum("Enter a: ");
        int b = getNum("Enter b: ");
        if (a == 0 && b == 0) {
            print("Exiting...");
            exit = true;
            continue;
        }
        print("HCF: " + to_string(hcf(a, b)));
    }

    return 0;
}
