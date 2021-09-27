//Yash Kolli, ysk6dw@virginia.edu, 3/1/21, postfixCalculator.h

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include "postfixCalculator.h"

using namespace std;

int main(){
  postfixCalculator main;

  while(true){
    string ins;
    cin >> ins;
    
    if(!cin.good())
      break;
    
    if(ins == "+")
      main.add();

    else if(ins == "-")
      main.subtract();

    else
      main.insert(atoi(ins.c_str()));
  }

  cout << main.getTopValue() << endl;
  
  return 0;
}
