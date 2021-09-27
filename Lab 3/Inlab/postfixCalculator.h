//Yash Kolli, ysk6dw@virginia.edu, 3/1/21, postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

class postfixCalculator{
 public:
  postfixCalculator();

  void insert(int e);
  int getTopValue();

  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  
  stack<int> s;
};

#endif
