#include <iostream>

//c++11 allows build facility to prevent overriding of virtual function using final specifier
// if method foo is defined in base as virtual and final, then in derived class we can't define same redefine same api with override keyword. without override keyword ans same method name treated as new api and is not 	

//by default, base class methods are included in derived class, if an api defined with same in derived class with different parameters or different return type it hides the base class method of same name. to avoid this scenario, it is best practice to include overide to ensure it matches the same prototype.

class Base
{
	public :
		virtual void foo() final
		{
			std::cout << "this is a final definition" << std::endl;
		}

		virtual void new_api() final { std::cout << "same name api without override allowed to redefine in derived class" << std::endl; }
		virtual void no_override_api() final { std::cout << "same name api with override is not allowed in derived class"<< std::endl; }
		void test_override() { std::cout << "test_override api from base class " << std::endl; }
};

class Derived
{
	public :
		//by default foo is not available in derived class as it will not inherited from base class due to final in base class
		void new_api()		//is still valid, however if we add override keyword it will through error as foo in base is final
		{
			std::cout << "this is derived class override definition" << std::endl;
		}

		void test_override(int a) { std::cout << "test override api from derived class" << std::endl ;}
		//void no_override_api() override //will through compilation error
};

int main()
{
	Derived d;

	//d.foo();  // doesn't have foo in derived class
	d.new_api(); //is called of derived class definition
	//d.test_override();   - this will through an error  as this api will not be available
}
