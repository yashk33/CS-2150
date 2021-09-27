//Yash Kolli, ysk6dw@virginia.edu, 2/16/21, bankAccount.cpp

#include "bankAccount.h"
using namespace std;

bankAccount::bankAccount() {
  balance = 0.00;
}

bankAccount::bankAccount(double amount) {
  balance = amount;
}

bankAccount::~bankAccount() {
   
}

double bankAccount::withdraw(double amount) {
  if(amount > balance)
    return amount;
  else {
    balance = balance - amount;
    return balance;
  }
}

double bankAccount::deposit(double amount) {
     balance = balance + amount;
     return balance;
}

double bankAccount::getBalance() {
  return balance;
}


