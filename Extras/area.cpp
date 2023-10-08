// include  math
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
//calculate the area of a rectangle
double length,width,area;
cout << "Enter the length of the rectangle: ";
cin >> length;
cout << "Enter the width of the rectangle: ";
cin >> width;
area = length * width;
cout << "The area of the rectangle is " << area << endl;
  return 0;
}