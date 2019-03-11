#include <iostream>
#include <thread>
#include <future>
#include <functional>

int main()
{
	std::promise<int> prom;
	std::future<int> fut = prom.get_future();

	std::thread th1(print_int, std::ref(fut));
	prom.set_value(10);

	th1.join();
	return 0;
}
