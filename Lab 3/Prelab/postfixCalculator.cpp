//Yash Kolli, ysk6dw@virginia.edu, 3/1/21, postfixCalculator.h

#include <iostream>
#include <stack>
#include <cstdlib>
#include "postfixCalculator.h"

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

