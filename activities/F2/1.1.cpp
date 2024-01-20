
#include "../../include/snippets.h"
using namespace std;
#define ARRAY_SIZE 10
int main(int argc, char const *argv[]) {
    int j = 0;
    int i = 0;
    int nums[ARRAY_SIZE];
    int indexes[ARRAY_SIZE][2];
    while (i < ARRAY_SIZE) {
        nums[i] = (int) getNum("Enter number: " + to_string(i+1) + ": ");
        if (nums[i] % 2 == 0) {
            indexes[j][0] =nums[i] ;
            indexes[j][1] =i ;
            j++;
        }
        i++;
    }
    print("The even numbers are: ");
    for ( i = 0; i < j; i++) {
        print(to_string(indexes[i][0]) + " at index " +to_string( indexes[i][1]));
    }
    

    return 0;
}
