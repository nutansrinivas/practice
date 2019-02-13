#include <iostream>
#include <iomanip>
#include <thread>

#include <chrono>
#include <ctime>

int main()
{
	using std::chrono::system_clock;
	std::time_t tt = system_clock::to_time_t(system_clock::now());
	struct std::tm* ptm = std::localtime(&tt);
	std::cout << "current time: " << std::put_time(ptm, "%X") << "\n" ;

	std::cout << "waiting for the next minute to begin...\n";

	++ptm->tm_min; ptm->tm_sec=0;
	std::this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));

	std::cout << std::put_time(ptm, "%X") << " reached\n";

	return 0;
}
