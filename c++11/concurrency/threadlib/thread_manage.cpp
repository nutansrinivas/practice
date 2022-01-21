#include <iostream>
#include <thread>



//std::thread t(fun, 1)  //fun(1)




std::mutex mtx;
mtx.lock();
mtx.unlock();

{
	std::lock_guard<std::mutex> lg(mtx) //lock guard takes care of calling lock on mutex and calling unlock on destroy
	{

	}
}
using lock_guard object we can't call unlock / lock apis on given mutex, where as std::unique_locks we can call

std::condition_variable	cv;
std::mutex mtx;
std::unique_locks<std::mutex> lck(mtx);
while(cv.wait_for(lck, std::chrono::seconds(1)) == std::cv_status::timeout) {}


