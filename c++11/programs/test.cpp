#include <stdio.h> 
#include <iostream>

class A
{
	private :
		int a, b;

	public :
		
		A(int a, int b) : a(a), b(b) 
		{
			std::cout << "create A with a="<<a << ", b=" << b <<std::endl;
		}

};

class B : public A
{
	private :
		int c, d;
	
	public :
	
	B(int c, int d) : A(1,2), c(c), d(d)
	{
			std::cout << "create B with c="<<c << ", d=" << d <<std::endl;
	}	
};


int main()
{
	B b(1,2);
		
}

