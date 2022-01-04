//trailing return type is useful if the return type is depends on argument names, such as 
//template <class T, class U> auto add(T t, U u) -> decltype(t + u);
//auto main() -> int {} - returns integer

#include <iostream>
#include <string>

void f0(const std::string & arg = "world")
{
	std::cout << "Hello,  " << arg << std::endl ;
}

int f1() ;

void ( *fp03() ) (const std::string &) { return f0; } //function returning a pointer to f0, pre-c+11 style

auto fp11() -> void(*) (const std::string &) { return f0; } //same as above with c++11 trailing return type

//function try blocks : primmary purpose of function try blocks is to respond to an exception thrown from the member initializer list in a constructor by logging and re-throwing, modifying exception object and re-throwing or terminating the program. They are rarely used with normal functions or destructors.
//

