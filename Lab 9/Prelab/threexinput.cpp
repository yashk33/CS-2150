// Yash Kolli, 4/19/21, threexinput.cpp

#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone (int);

int main(){

  timer t;
  
  int x, n, ret;

  cout << "Enter a number: " << endl;
  cin >> x;
    
  cout << "Enter iterations of subroutine: " << endl;
  cin >> n;

  t.start();
  for(int i = 0; i < n; i++){
      ret = threexplusone(x);
  }
  t.stop();

  cout << "Steps: " << ret << endl;

  return 0;
}
