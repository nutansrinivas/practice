#include <bits/stdc++.h>

using namespace std;

int funReturnInt() { return 5; }
char funReturnChar() { return 'n'; }

class TestTest
{
	int a;
	int b;
	string s;
};


template <class A, class B>
auto findMin(A a, B b) -> decltype(a<b?a:b)
{
	return (a < b ? a : b );
}


int main()
{
	auto x = 43;
	auto y = 3.37;
	auto ptr = &x;
	TestTest a ;

	decltype (funReturnInt()) p;
	decltype (funReturnChar()) q;

	cout 	<< 	typeid(x).name() << endl
				<<	typeid(y).name() << endl
				<<	typeid(a).name() << endl
				<<	typeid(p).name() << endl
				<<	typeid(q).name() << endl
				<< 	typeid(ptr).name() << endl ;

	cout 	<< 	findMin(4, 3.4) << endl;
	cout 	<< 	findMin(5.4, 3) << endl;
	return 0;				
}
