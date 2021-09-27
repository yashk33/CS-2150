//Yash Kolli, ysk6dw@virginia.edu, 3/29/21, hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class hashTable{

 public:

  hashTable(int size);
  ~hashTable();

  void insert(const string& in);
  bool contains(const string& in);
  int hash(const string& in);

  bool checkPrime(unsigned int in);
  int getPrime(unsigned int in);

  int gridSize;
  vector<list<string>> *grid;

};

#endif
