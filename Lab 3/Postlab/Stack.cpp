//Yash Kolli, ysk6dw@virginia.edu, 3/4/21, Stack.cpp

#include <iostream>
#include <cstdlib>
#include <string>

#include "List.h"
#include "Stack.h"
#include "ListItr.h"
#include "ListNode.h"
#include "postfixCalculator.h"

using namespace std;

Stack::Stack(){
  counter = 0;
  l = new List();
}

Stack::~Stack(){
  delete l;
}
    
void Stack::push(int e){
  itr = l->first();
  l->insertBefore(e, itr);
  counter++; 
}

int Stack::top(){
  itr = l->first();
  int ret = itr.retrieve();
  return ret;
}

void Stack::pop(){
  l->remove(top());
  counter--;
}

bool Stack::empty(){
  return counter == 0;
}
