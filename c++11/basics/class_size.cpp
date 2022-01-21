#include <iostream>

class	TwoIntWithChar 
{

	long long d;
	char c;
	int a;
	int b;
};


class OneIntWithChar 
{
	int a;
	char c;
};

class OnlyChar
{
	char c;
};

class EmptyClass
{
};

class EmptyClassWithAPI
{
	void printClass()
	{
		std::cout << "test" ;
	}
};

class basevirtual
{
	virtual void printBaseVirtual();
};

class derivedvirtual : public basevirtual
{
	void printBaseVirtual() {}
};

class basevirtualWithChar
{
	virtual void printBaseVirtual();
	int a;
};

int main()
{
	std::cout << "TwoIntWithChar : " << sizeof(TwoIntWithChar) << std::endl;
	std::cout << "OneIntWithChar : " << sizeof(OneIntWithChar) << std::endl;
	std::cout << "OnlyChar			 : " << sizeof(OnlyChar) << std::endl;
	std::cout << "EmptyClass 		 : " << sizeof(EmptyClass) << std::endl;
	std::cout << "EmptyClassWithAPI 		 : " << sizeof(EmptyClassWithAPI) << std::endl;
	std::cout << "basevirtual						 : " << sizeof(basevirtual) << std::endl ;
	std::cout << "basevirtualWithChar		 : " << sizeof(basevirtualWithChar) << std::endl ;
	std::cout << "derivedvirtual				 : " << sizeof(derivedvirtual) << std::endl ;

}
