// C++ program to multiply
// a number with 3.5
#include <iostream>
using namespace std;

int multiplyWith3Point5(int x)
{
	return (x<<1) + x + (x>>1);  //2x + x + (x/2)
}

/* Driver program to test above functions*/
int main()
{
	int x = 4;
	cout << " "<< multiplyWith3Point5(x);
	getchar();
	return 0;
}


// This code is contributed by shivanisinghss2110.

