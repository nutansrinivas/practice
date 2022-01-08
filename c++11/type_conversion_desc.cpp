//implicit type conversion - carried by the compiler without of need of user initiated action, which trigger when an expression has more than one data type.
//every variable data type is changed to data type of the variable with largest data type.
//order of implicit : bool -> char -> short int > int -> unsigned int -> long -> unsigned long -> long long -> float -> double -> long double
//it is possible for implicit conversion to lose information, signs can be lost, overflow can occur

//explicit type conversion - user defined type casting, we can do this in two ways i.e 
//				1. by assigning its value  --> double x = 1.2;   int sum = (int) x + 1;  //explicit conversion of x from double to int
//				2. using cast operator  
// c++ supports 4 types of types of casting operators 1. Static cast  2. Dynamic cast  3. Const cast	4. Reinterpret cast			
// 1. static cast -- is s a compile time cast, it will do both implicit conversion as well as explicit conversion
// 		static cast will validate strict type checking. 		
#include <iostream>
using namespace std;
int static_cast_test()
{
	int a = 10;
	char c = 'a';

	// pass at compile time, may fail at run time
	int* q = (int*)&c;    /// compile time no issues, run time it is an issue ;
	//int* p = static_cast<int*>(&c);
	std::cout << (*q + 10) << std::endl;   //here is it abnormal value
	return 0;
}
	
class Base {};
class Derived_Public : public Base {}
class Derived_Private : private Base{}

int static_cast_test_inheritance()
{
	Derived_Public dpu;
	Derived_Private dpi;

	Base* bptr = (Base*) &dpu;  //allowed 
	Base* bptr_op = static_cast<Base*> (&dp1) ;  //also valid and allowed

	Base* bpiptr = (Base*) &dpi;  //allowed, runtime issues
	Base* bpiptr_op = static_cast<Base*> (&dpi); //compilation error as base class is inherited as prive so can't access using obj variable 

	return 0;
}

//2. dynamic cast - dynamic cast is maily used for safe downcast at runtime. it works only for polymorphic base class as it uses this information to decide safe downcast  i.e base class obj / pointer to derived class obj / pointer.   Derived* dp = dynamic_cast<Derived*> (base)

int main()
{
	//return static_cast_test();
	//return static_cast_test_inheritance();
}



