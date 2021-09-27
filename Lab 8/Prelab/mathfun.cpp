//Yash Kolli, 4/12/2021 mathfun.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

int main(){
  int x;
  int y;

  cout << "Enter integer 1: " << endl;
  cin >> x;

  cout << "Enter integer 2: " << endl;
  cin >> y;

  cout << "Product: " << product(x, y) << endl;
  cout << "Power: " << power(x, y) << endl;

  return 0;
}
