#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>



int main()
{
	std::thread threads[10];

	for (int i=0; i<10; i++)
		threads[i] = std::thread(print_thread_id, i+1);

	for (auto & th : threads) th.join();
}
