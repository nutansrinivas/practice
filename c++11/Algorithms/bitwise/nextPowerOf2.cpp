// C++ program to find smallest
// power of 2 greater than or
// equal to n
#include<bits/stdc++.h>
using namespace std;

unsigned int nextPowerOf2(unsigned int n)
{
	unsigned int p = 1;
	if (n && !(n & (n - 1)))
		return n;

	while (p < n)
		p <<= 1;
	
	return p;
}

// Driver Code
int main()
{
	unsigned int n = 5;
	cout << nextPowerOf2(n);
	return 0;
}

// This code is contributed by rathbhupendra

