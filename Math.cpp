// include  math
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
  string name; 
  double a,p,sq;
  cout << "Enter a number ";
  cin >> a;
  p = pow(a,2);
  sq = sqrt(a);
    cout << "The square of " << a << " is " << p << endl;
    cout << "The square root of " << a << " is " << sq << endl;
  return 0;

}
