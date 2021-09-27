//Yash Kolli, ysk6dw@virginia.edu, 2/16/21, LifeCycle.h

#include <iostream>
using namespace std;

#ifndef INTCELL_H
#define INTCELL_H

// Declare the MyObject class
class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

#endif
