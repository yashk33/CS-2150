//Yash Kolli, ysk6dw@virginia.edu, 3/4/21, Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>

#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

using namespace std;

class Stack{
 public:
  Stack();
  ~Stack();
    
  void push(int e);
  int top();
  void pop();
  bool empty();

 private:
  List *l;
  ListItr itr;
  int counter;
  
};

#endif
