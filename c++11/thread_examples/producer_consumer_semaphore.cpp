#include <iostream>
#include <thread>
#include <string>
#include <list>
#include <vector>
#include <mutex>
#include <condition_variable>


std::mutex pm;

class ResourceBin
{
	public :

		ResourceBin() { std::cout << "resource container is created " << std::endl ; }

		void add(int i) 
		{
			std::unique_lock<std::mutex> lock(rsrcLock); 
			_skuList.push_back(i) ; 
			if (_skuList.size() == 1)
			{
				cv.notify_all();
			}
		}

		int remove() 
		{ 
			std::unique_lock<std::mutex> lock(rsrcLock);

			if (_skuList.empty() && prodInProg)
			{
				std::cout << "thread id : " << std::this_thread::get_id() << ", waiting on resource " << std::endl;
				cv.wait(lock, [&]() { return _skuList.size() > 0 || prodInProg; });  //stop wait, if return value is true, then it will stop wait
				//cv.wait_for(lock, 2500ms, [&](){return _skuList.size() > 0;});
				//cv.wait_until(lock, std::chrono::system_clock::now() + 2500ms, [&](){return _skuList.size() > 0;});
			}
			else if (!prodInProg) 
			{
				std::cout << std::this_thread::get_id() << " CLEAR ALL" << std::endl;
				clearedFlag = true;
				return 0;
			}

			int tsrc = _skuList.front();
			_skuList.pop_front() ;

			return tsrc;
		}

		void startProduction() {  if (!prodInProg) { prodInProg = true; clearedFlag = false; } }
		void stopProduction() { if (prodInProg) prodInProg = false; }

		bool isClearedFlag() { return clearedFlag; }
	private : 
		std::list<int> _skuList;
		std::mutex rsrcLock;
		std::condition_variable cv;
		bool prodInProg = false;
		bool clearedFlag = true;
};

class Producer
{
	public :

		Producer(ResourceBin & lrBin) : rBin(lrBin) {}
		void doYourJob(int tn) 
		{
			int i=0;
			rBin.startProduction();
			while (cnt < 1000)
			{
				++i;
				rBin.add(++cnt);	
				//std::cout << "tn :" << tn << ", tId : " << std::this_thread::get_id() << ", adding : " << cnt << std::endl;
			}
			pm.lock();
			std::cout << "tn :" << tn << ", tId : " << std::this_thread::get_id() << ", produced : " << i << std::endl;
			pm.unlock();
			rBin.stopProduction();
		}


	private : 
		ResourceBin & rBin;
		int cnt = 0;

};

class Consumer
{
	public :
		Consumer(ResourceBin & lrBin) : rBin(lrBin) {}

		void doYourJob(int tn)
		{
			int i = 0;
			while (!rBin.isClearedFlag()) 
			{
				++i;
				rBin.remove();
				//std::cout << "tn : " << tn << ", tId : " << std::this_thread::get_id() << ",consuming : " << rBin.remove()  << std::endl ;
			}
			pm.lock();
			std::cout << "tn : " << tn << ", tId : " << std::this_thread::get_id() << ",consumed : " << i << std::endl ;
			pm.unlock();
		}

	private : 
		ResourceBin & rBin;
};

int main()
{
	std::vector<std::thread> producerList, consumerList;
	ResourceBin rsb;

	Producer prod(std::ref(rsb));
	Consumer cons(std::ref(rsb));

	int producerCnt = 0, consumerCnt = 0 ;
	std::cout << "enter producer count : " ;
	std::cin >> producerCnt ;
	std::cout << std::endl ;

	std::cout << "enter consumer count : " ;
	std::cin >> consumerCnt ;
	std::cout << std::endl ;


	for (int i = 0; i < consumerCnt; ++i) consumerList.push_back(std::thread(&Consumer::doYourJob, std::ref(cons), i+1));
	for (int i = 0; i < producerCnt; ++i) producerList.push_back(std::thread(&Producer::doYourJob, std::ref(prod), i+1));


	for (int i=0; i < consumerCnt; ++i) consumerList[i].join();
	for (int i=0; i < producerCnt; ++i) producerList[i].join();

	return 0;
}
