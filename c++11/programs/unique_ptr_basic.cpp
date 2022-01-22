#include <iostream>
#include <memory>

int main () {

	std::unique_ptr<int> foo;
	int* p = nullptr;
	{
		foo = std::unique_ptr<int>(new int(10));
	}
	p = foo.get();
	if (p) std::cout << "p exits" ;

}
