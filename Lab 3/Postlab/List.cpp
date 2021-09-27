//Yash Kolli, ysk6dw@virginia.edu, 2/18/21, List.cpp

#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

#include <iostream>
using namespace std;

List::List() {
  head = new ListNode();
  tail = new ListNode();

  head->next = tail;
  tail->previous = head;

  count = 0;
}

List::List(const List& source) {
  head = new ListNode();
  tail = new ListNode();

  head->next = tail;
  tail->previous = head;

  count = 0;

  ListItr iter(source.head->next);
  while (!iter.isPastEnd()){
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
  count = 0;
}

List& List::operator=(const List& source){
  if(this == &source){
    return *this;
  }

  else{
    makeEmpty();

  ListItr iter(source.head->next);
  while (!iter.isPastEnd()){
     insertAtTail(iter.retrieve());
     iter.moveForward();
    }
  }
  
  return *this;
}

bool List::isEmpty() const{
  if(count == 0)
    return true;
  else
    return false;
}

void List::makeEmpty(){
  ListItr temp;
  temp.current = head->next;

  while(temp.current != tail){
    temp.moveForward();
    delete (temp.current)->previous;
  }

  head->next = tail;
  tail->previous = head;

  count = 0;  
}

ListItr List::first(){
  ListItr ret;
  ret.current = head->next;
  return ret;
}

ListItr List::last(){
  ListItr ret;
  ret.current = tail->previous;
  return ret;
}

void List::insertAfter(int x, ListItr position){
  ListNode* ins = new ListNode;
  ins->value = x;

  ins->next = position.current->next;
  position.current->next->previous = ins;

  ins->previous = position.current;
  position.current->next = ins;

  count = count + 1;
}

void List::insertBefore(int x, ListItr position){
  ListNode* ins = new ListNode;
  ins->value = x;

  ins->previous = position.current->previous;
  position.current->previous->next = ins;

  ins->next = position.current;
  position.current->previous = ins;

  count = count + 1;
}

void List::insertAtTail(int x){
  ListNode* ins = new ListNode;
  ins->value = x;
  
  ins->previous = tail->previous;
  tail->previous->next = ins;

  ins->next = tail;
  tail->previous = ins;

  count = count + 1;
}

ListItr List::find(int x){
  ListItr temp(head->next);

  while(!temp.isPastEnd()){
    if(temp.retrieve() == x)
      return temp;
    temp.moveForward();
  }
  
  temp.current = tail;

  return temp;
}

void List::remove(int x){
  ListItr temp = find(x);
  
  if(temp.current == tail)
    return;

  temp.current->previous->next = temp.current->next;
  temp.current->next->previous = temp.current->previous;
  
  delete temp.current;
  count--;
}

int List::size() const{
  return count;
}

void printList(List& source, bool direction){
  ListItr forward = source.first();
  ListItr backward = source.last();
  
  
  if(direction){
    while(!forward.isPastEnd()){
      cout << forward.retrieve();
      forward.moveForward();
    }
  }
  
  else{
    while(!backward.isPastBeginning()){
      cout << backward.retrieve();
      backward.moveBackward();
    }
  }
}


