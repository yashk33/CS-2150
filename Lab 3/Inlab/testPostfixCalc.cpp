//Yash Kolli, ysk6dw@virginia.edu, 3/1/21, testPostfixCalc.cpp

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

    else if(ins == "*")
      main.multiply();

    else if(ins == "/")
      main.divide();

    else if(ins == "~")
      main.negate();

    else
      main.insert(atoi(ins.c_str()));
  }

  if(main.s.empty())
    exit(-1);

  cout << main.getTopValue() << endl;
  
  return 0;
}
