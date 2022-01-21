#include <thread>
#include <iostream>
#include <chrono>


int f1(int n)
{
	for (int i=0; i < 5; ++i)
	{
		std::cout << "f1 thread : " << ++n << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return n;
}

int f1_ref(int& n)
{
	for (int i=0; i < 5; ++i)
	{
		std::cout << "f1_ref thread  : " << ++n << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return n;
}

struct funObjStruct 
{
	int n = 0;
	void operator()()
	{
		for (int i=0; i< 5; ++i) 
		{
			std::cout << "funObjStruct thread : " << n << std::endl;	
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
};

int main()
{
	int n = 0;

	std::thread t1; //t1 is thread object however not referring to any thread

	std::cout << "main thread : before starting t1, " << t1.get_id() << " and is joinable : " << std::boolalpha << t1.joinable() << std::endl;

	// t1 = std::thread(f1, n); //starts a new thread and assign to t1

	std::thread t2(f1, ++n); //

	std::cout << "main thread : after starting t2, " << t2.get_id() << " and is joinable : " << t2.joinable() << std::endl;

	std::cout << "main thread : " << n << std::endl;

	std::thread t3(f1_ref, std::ref(n)); //when we want to pass reference, we should use std::ref as part of threads, just to ensure the 

	std::cout << "main thread : " << n << std::endl;

	funObjStruct fb;
	std::thread t4(fb);

	std::thread::id t2_id = t2.get_id(); 
	


	t2.join();
	t3.join();
	t4.join();


	std::cout << "main thread : after t2 joined already, " << t2.get_id() << " and is joinable : " << t2.joinable() << std::endl;
}
