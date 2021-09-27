//Yash Kolli, ysk6dw@virginia.edu, 2/16/21, bankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount {
public:
    bankAccount();                  
    bankAccount(double amount);
    ~bankAccount();                 

    double withdraw(double amount);
    double deposit(double amount);
    double getBalance();
    
private:
    double balance;
};

#endif
