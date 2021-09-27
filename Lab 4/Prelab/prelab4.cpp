//Yash Kolli, ysk6dw@virginia.edu, 3/14/21, prelab4.cpp

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void outputBinary(unsigned int x){
  string ret = "";
  
  for(int i = 31; i >= 0; i--){
    int temp = pow(2, i);

    if(x/temp == 0){
      ret = ret + "0";		    
    }

    else{
      ret = ret + "1";
      x = x - temp;
    }

    if(i%4 == 0){
      ret = ret + " ";
    }
  }

  cout << ret << endl;
}

void overflow(){
  unsigned int ret = UINT_MAX;
  cout << UINT_MAX << " + 1 = " << UINT_MAX+1 << endl;
}

int main(){
  unsigned int x;
  cin >> x;
  
  sizeOfTest();
  overflow();
  outputBinary(x);
  
  return 0;
}
