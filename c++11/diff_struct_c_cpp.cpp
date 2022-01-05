//difference b/w structures in c and cpp
//in c - only data members are allowed, can't have static members and constructors, direct initialization of members are not allowed, don't have access modifiers, size of empty structure in c is 0,
//in cpp - both data members and methods are allowed, can have static members and constructors, direct initilization of members are allowed, have access modifies,  size of empty structure in cpp is 1
//
//

// Program 4
// C++ program to demonstrate Inheritance in structure
#include <iostream>
using namespace std;

struct Base {
public:
	int x;
};

struct Derived : Base {
public:
	int y;
}; // Is equivalent to struct Derived : public Base {}

int main()
{
	Derived d;
	d.x = 20; // Works fine because inheritance is public
	cout << d.x;
	getchar();
	return 0;
}

