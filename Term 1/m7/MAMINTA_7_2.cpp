#include "../include/snippets.h"
using namespace std;

int cube() {
    int side = getNum("Enter side: ");
    return side * side * side;
}
int rectangularPrism() {
    int length = getNum("Enter length: ");
    int width = getNum("Enter width: ");
    int height = getNum("Enter height: ");
    return length * width * height;
}
int cylinder() {
    int radius = getNum("Enter radius: ");
    int height = getNum("Enter height: ");
    return 3.14 * radius * radius * height;
}
int cone() {
    int radius = getNum("Enter radius: ");
    int height = getNum("Enter height: ");
    return 3.14 * radius * radius * height / 3;
}
int sphere() {
    int radius = getNum("Enter radius: ");
    return 4 * 3.14 * radius * radius * radius / 3;
}
int main(int argc, char const *argv[]) {
    int choice;
    do {
        print("1. Cube");
        print("2. Rectangular Prism");
        print("3. Cylinder");
        print("4. Cone");
        print("5. Sphere");
        print("6. Exit");
        choice = getNum("Enter your choice: ");
        switch (choice) {
            case 1:
                print("Volume: " + to_string(cube()));
                break;
            case 2:
                print("Volume: " + to_string(rectangularPrism()));
                break;
            case 3:
                print("Volume: " + to_string(cylinder()));
                break;
            case 4:
                print("Volume: " + to_string(cone()));
                break;
            case 5:
                print("Volume: " + to_string(sphere()));
                break;
            case 6:
                print("Exiting...");
                break;
            default:
                print("Invalid choice");
                break;
        }
    } while (choice != 6);
    return 0;
}
