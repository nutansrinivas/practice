#include <iostream>
#include <type_traits>
#include <cstdint> 
#include <map>
#include <string>

int main()
{
	int i = 32;
	
	//understnading auto keyword
	// in c++11 - for variables - type of the variable that is being declared will be automatically deduced from its iniitalizer
	// in c++14 - for functions - specifies the return type will be deduced from its return statement
	// in c++17 - for non-type template parameters, specifies that type will be deduced from the argument
	
	
	//auto i=0, d=0.5 	- is invalid 
	//auto i=5,  *p=&i  	- is valid
	//auto al = {10, 11, 12};
	//auto lambda = [](int x) { return x + 3; };
	//

	std::map<std::string, std::string> sites;

	sites.insert({ "GeeksforGeeks", "Coding Resources" });
	sites.insert({ "StackOverflow", "Q-A type" });
	sites.insert({ "Wikipedia", "Resources + References" });

	for (auto & [ key, value ] : sites)
	{
		std::cout << key.c_str() << " " << value.c_str() << std::endl;
	}


	//explain on decltype

	decltype(i) j = 33;  //decltype(i) replace with int

	std::cout << std::is_same<int, std::int32_t>::value << std::endl;   //added in c++11

	std::cout << std::is_same<decltype(i), decltype(j)>::value << std::endl;  //added in c++17
	std::cout << std::boolalpha << std::is_same_v<decltype(i), decltype(j)> << std::endl;

	return 0;
}

//compiling : g++  -std=c++17 auto_decl_type.cpp 
