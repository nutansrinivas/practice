#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <cstring>
#include <pthread.h>

std::mutex iomutex;

void f(int num)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));

	sched_param sch;   //struct sched_params defined in pthreads.h 
	int policy;
	pthread_getschedparam(pthread_self(), &policy, &sch);

	std::lock_guard<std::mutex> lk(iomutex);

	std::cout << std::endl << "thread " << num << "is expecting a priority " << sch.sched_priority << std::endl;

	return ;
}

int main()
{
	std::thread t1(f, 1), t2(f, 2);

	sched_param sch;
	int policy;

	pthread_getschedparam(t1.native_handle(), &policy, &sch);
	sch.sched_priority = 20;

	if (0 != pthread_setschedparam(t1.native_handle(), SCHED_FIFO, &sch))
	{
		std::cout << std::endl << "failed to set " << std::strerror(errno) << std::endl;
	}

	t1.join() ;
	t2.join();
	//pthread_join(t2.native_handle(), nullptr);
}
