#include <iostream>


//though special member functions like constructor, copy constructor defined explicitly, to include defaulted member functions, shall delcare the api with defaulted kyword
//for example, to include default constructor of class Test,  Test() = default; or copy constructor Test(const Test&) = default;
//a class said to be trivial if it has default special member functions like constructor, copy,move constructor, assignment operator, 
//class can have self type variable either as static or of a pointer only
//in c, sizeof empty structure is 0, in c++ sizeof empty structure is 1 as we need to allocate a memory to allow to access the member functions by its object.


class TrivialTest 
{
	private :	
		int a;
		float b;
};
// TrivialTest is a trivial class because it has defaulted special member functions like constructor, copy constructor, move constructor, assigment operator..etc. 
//

class DefaultTest
{
	DefaultTest(int a1, int b1, int c1) : a(a1), b(b1), c(c1) {}

	DefaultTest() = default;	//so that it will create a default constructor too even we have parameterized constructor
	
 private :
	 int a;
	 int b;
	 std::string str;
};


//to avoid access to a function we can assign ==delete keyword for function declaration or definition

class newTest
{
	void* operator new(size_t size) = delete ;
	void* operator new[](size_t size) = delete ;
};

//newTest *ptr = new newTest() - is an error
