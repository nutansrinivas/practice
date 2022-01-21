
#include <stdlib.h>
#include <iostream>

struct sample
{
	public :
		sample(int a, std::string b)
		{
			i = a;
			test = b;
		}
		int getSampleInt() {return i;}
		std::string getTest() { return test;}
	private :	
		int i;
		std::string test;
};

int main()
{
	sample  s(10, "srinivas");

	std::cout << s.getSampleInt() << std::endl;
	std::cout << s.getTest() << std::endl;

}
