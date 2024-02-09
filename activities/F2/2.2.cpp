#include <iostream>
#define MAX_SIZE 100
using namespace std;
// prints in a new line
template <typename T>
void print(T Value) {
    cout << Value << endl;
}
// Prints in the same line
template <typename U>
void printLn(U s) {
    std::cout << s;
};
// gets a string from the user
string getStr(std::string prompt = "") {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}
// gets a number from the user
double getNum(std::string prompt = "") {
    std::string num;
    char* p;
    do {
        std::cout << prompt;
        std::cin >> num;
        double convertedNum = strtod(num.c_str(), &p);
        if (*p) {
            std::cout << "Invalid input" << std::endl;
        } else {
            std::cin.ignore();
            return convertedNum;
        }
    } while (true);
    return 0;
}

// Heapify function to maintain the heap property
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// Heap Sort function
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main(int argc, char const* argv[]) {
    int size;
    while (size > MAX_SIZE) {
        size = getNum("Enter size of array: ");
        if (size > MAX_SIZE) print("Size must be less than " + to_string(100));
    }
    int nums[size];
    for (int i = 0; i < size; i++) {
        nums[i] = (int)getNum("Enter " + to_string(i + 1) + " number: ");
        if (nums[i] > 2147483647) {  // check if number is greater than max int
            printLn("Number must be less than 2147483647");
            i--;
        }
    }
    heapSort(nums, size);
    printLn("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printLn(nums[i]);
        printLn(" ");
    }
    /* code */
    return 0;
}