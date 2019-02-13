#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<bool> ready(false) ;
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int id)
{
	while (!ready) { std::this_thread::yield(); }
 	for (volatile int i=0; i<100000; ++i) ;
	if (!winner.test_and_set()) std::cout << "thread # " << id << "won!" << std::endl;
}

int main()
{
	std::vector<std::thread> vThreads;
	std::cout << "spawning 10 threads that count 1 million" << std::endl;
	for (int i=1; i<=10; ++i) vThreads.push_back(std::thread(count1m, i)); 
	ready = true;

	for(auto & th : vThreads) th.join();

	return 0;
}

