//Yash Kolli, ysk6dw@virginia.edu, 3/18/21, bitCounter.cpp

#include <iostream>
#include <string.h>

using namespace std;

int bitCounter(int x){
  if(x > 1)
    return bitCounter(x % 2) + bitCounter(x / 2);
 
  else if(x == 1)
    return 1;
  
  return 0;
}

int getNum(char x){
  if(x >= '0' && x <= '9')
    return (int)(x - '0');
  return (int)(x - 'A' + 10);
}

char getChar(int x){
  if(x < 10)
    return (char)(x + '0');
  return (char)(x - 10 + 'A');
}

string baseConverter(char* x, int startBase, int endBase){
  int base10 = 0;
  int pow = 1;

  for(int i = strlen(x) - 1; i >= 0; i--){
    base10 += getNum(x[i]) * pow;
    pow *=  startBase;
  }

  string returnVal;

  while(base10 > 0){
    int temp = base10 % endBase;
    base10 /= endBase;
    returnVal += getChar(temp);
  }

  int len = returnVal.length();

  for(int k = 0; k < len/2; k++){
    swap(returnVal[k], returnVal[len - k - 1]);
  }

  return returnVal;
}

int main(int argc, char **argv){

  if(argc != 5){
    cout << "Please Have A Valid Input" << endl;
    exit(0);
  }

  cout << argv[1] <<  " has " <<  bitCounter(atoi(argv[1])) << " bit(s)" << endl;
  cout << argv[2] <<  " (base " << argv[3] << ") = " << baseConverter(argv[2], atoi(argv[3]), atoi(argv[4])) << " (base " << argv[4] << ")" << endl;


  return 0;
}
