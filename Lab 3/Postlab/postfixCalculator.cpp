//Yash Kolli, ysk6dw@virginia.edu, 3/1/21, postfixCalculator.cpp

#include <iostream>
#include <cstdlib>
#include "postfixCalculator.h"
#include "Stack.h"

using namespace std;

postfixCalculator::postfixCalculator(){

}

void postfixCalculator::insert(int e){
  s.push(e);
}

int postfixCalculator::getTopValue(){
  return s.top();
}


void postfixCalculator::add(){
  int t1 = s.top();
  s.pop();
  
  int t2 = s.top();
  s.pop();

  s.push(t1 + t2);
}

void postfixCalculator::subtract(){
  int t1 = s.top();
  s.pop();
  
  int t2 = s.top();
  s.pop();

  s.push(t2 - t1);
}

void postfixCalculator::multiply(){
  int t1 = s.top();
  s.pop();
  
  int t2 = s.top();
  s.pop();

  s.push(t1 * t2);
}

void postfixCalculator::divide(){
  int t1 = s.top();
  s.pop();
  
  int t2 = s.top();
  s.pop();

  s.push(t2/t1);
}

void postfixCalculator::negate(){
  int t1 = s.top();
  s.pop();
  
  int t2 = t1 * -1;
  
  s.push(t2);
}
