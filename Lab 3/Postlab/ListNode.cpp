//Yash Kolli, ysk6dw@virginia.edu, 2/18/21, List.cpp

#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

#include <iostream>
using namespace std;

ListNode::ListNode(){
  next = NULL;
  previous = NULL;
  value = 0;
}
