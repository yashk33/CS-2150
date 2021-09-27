//Yash Kolli, ysk6dw@virginia.edu, 3/29/21, hashTable.cpp

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "hashTable.h"

//hashTable constructor
hashTable::hashTable(int size){
  grid = new vector<list<string>>;
  gridSize = getPrime(size);
  
  for(int i = 0; i < gridSize; i++){
    list<string> temp;
    grid->push_back(temp);
  }
}

//hashTable destructor
hashTable::~hashTable(){
  delete grid;
}

//inserts word into hashTable
void hashTable::insert(const string& in){
  grid->at(hash(in)).push_back(in);
}

//searches in hashTable contains desired string
bool hashTable::contains(const string& in){
  return (find(grid->at(hash(in)).begin(), grid->at(hash(in)).end(), in) != grid->at(hash(in)).end());
}

//returns hash value for input word
int hashTable::hash(const string& in){
  int ret = 1;

  for(int i = 0; i < in.length(); i++){
    ret = ret * (((in[i]) * 323) % 328536); //hash function
  }

  ret = ret % gridSize;

   if(ret < 0)
    return ret + gridSize;
   
  return ret;
}

//checks if number is prime
bool hashTable::checkPrime(unsigned int in) {
    if ( in <= 1 )
        return false;
    if ( in == 2 )
        return true;
    if ( in % 2 == 0 )
        return false;
    for ( int i = 3; i*i <= in; i += 2 )
        if ( in % i == 0 )
            return false;
    return true;
}

//returns next closest prime number
int hashTable::getPrime (unsigned int in) {
    while (!checkPrime(++in));
    return in;
}
