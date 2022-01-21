#include <thread>
#include <iostream>

int main()
{
	std::cout << std::endl << "thread::hardware_concurrency() = " << std::thread::hardware_concurrency() << std::endl;
	
	return 0;
}
