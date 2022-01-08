//algorithm lib provides functions for searching, sorting, counting, manipulation

#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>

int modify_sequence_algo();
int non_modify_sequence_algo();


int main()
{
	modify_sequence_algo();
}

int modify_sequence_algo()
{
	std::vector<int> from_vector(10);
	std::iota(from_vector.begin(), from_vector.end(), 0);  //it will vector by increasing element 1 from 0, i.e 0,1,2,3,4,5,6,7,8,9

//std::copy, std::copy_if	
	{
		std::vector<int> to_vector(from_vector.size());
		std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector));   //or 
		//std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());   //or  to_vector = from_vector;

		std::copy(from_vector.begin(), from_vector.end(), std::ostream_iterator<int>(std::cout, ", "));

		//to_vector.clear();
		std::copy_if(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector), [](int x){ return x % 2 != 0;}); 

		std::cout << std::endl;
		//to_vector.clear();
		std::copy_n(from_vector.begin(), 4, std::back_inserter(to_vector));
		std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, ", "));
		std::cout << std::endl;
	}
//std::fill, std::fill_n
	 {
		std::vector<int> to_vector(from_vector.size());
		std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
		std::fill(to_vector.begin(), to_vector.end(), 100);
		std::for_each(to_vector.begin(), to_vector.end(), [](int x) { std::cout << x << ", " ; return true; });
	}	
	
//std::transform
	 {
		 std::vector<int> to_vector(from_vector.size());
		 std::transform(from_vector.begin(), from_vector.end(), to_vector.begin(), [](int x){ return x+10;});	
		 std::for_each(to_vector.begin(), to_vector.end(), [](int x) { std::cout << x << ", " ; return true; });
		 std::cout << std::endl ;
	 }
	return 0;
}


int non_modify_sequence_algo()
{

	std::vector<int> v(10,2);
	std::partial_sum(v.cbegin(), v.cend(), v.begin()); 

	std::cout << "among the numbers are : " << std::endl;
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

//std::all_of - return true if and only if all are true, even empty set also returns true
//
	if (std::all_of(v.cbegin(), v.cend(), [](int i){return i % 2 == 0 ; }))
	{
		std::cout << "all are even numbers only" << std::endl;
	}

	struct DivisibleBy
	{
		const int d;
		DivisibleBy(int n) : d(n) {}
		bool operator()(int n) const { return n % d == 0; }
	};

//std::any_of - atleast one is true, empty set returns false	
	if (std::any_of(v.cbegin(), v.cend(), DivisibleBy(7)))
	{
		std::cout << "atleast one number is divisible by 7 " << std::endl;
	}

	if (std::none_of(v.cbegin(), v.cend(), [](int n) { return n % 5 == 0; }))
	{
		std::cout << "none of the numbers are divisible by 5" << std::endl ;
	}
//std::for_each
	int sum = 0;
	std::for_each(v.cbegin(), v.cend(), [&sum](const int & i) {sum+=i;});
	std::cout << "sum of the elements : " << sum << std::endl ;
	
//std::count, std::count_if	
	for (const int target : {3, 4, 5})
	{
		const int num_items  = std::count(v.cbegin(), v.cend(), target);  //count the matching values like 3, 4, 5
		std::cout << "number : " << target << ", count : " << num_items << std::endl;
	}		

	int count_div4 = std::count_if(v.begin(), v.end(), [](int i){return i%4 == 0;});
	std::cout << "count of numbers divisible by 4 : " << count_div4 << std::endl;

//std::find, std::find_if, std::find_if_not	
	auto result = std::find(v.cbegin(), v.cend(), 8);
	if (result != v.cend()) std::cout << "found value 3 in the vector : " << *result << std::endl;

	result = std::find_if(v.cbegin(), v.cend(), [](const int & i) { return i % 2 == 0; });
	if (result != v.cend()) std::cout << "first even number is : " << *result << std::endl;

	auto is_even = [](const int & i) { return i % 2 == 0; };
	result = std::find_if_not(v.cbegin(), v.cend(), is_even);
	if (result != v.cend()) std::cout << "first odd number is : " << *result << std::endl;

//std::find_first_of  - search the elements v for any of the element in t1, i.e any of the element in t1 is available in v or not
	const auto t1 = {3, 14, 19, 10, 2};
	auto result2 = std::find_first_of(v.cbegin(), v.cend(), t1.begin(), t1.end());
	if (result2 == v.end()) std::cout << "any of t members are not available in v" << std::endl;
	else std::cout << "member of t is found in v at position : " << std::distance(v.cbegin(), result2) << ", and its value is : " << *result2 << std::endl;

//std::search - search for the first occurrence of the sequence of elements 
	
	std::string str = "why waste time learning, when ignorance is instantaneous?";
	std::vector<char> vec(str.begin(), str.end());
	std::string search_pattern = "learning";
	std::search(vec.begin(), vec.end(), search_pattern.begin(), search_pattern.end());

	return 0;
}



