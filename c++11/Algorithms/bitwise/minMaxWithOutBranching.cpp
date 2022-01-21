#include <bits/stdc++.h>
using namespace std;


#define CHARBIT 8

/*Function to find minimum of x and y*/
int min(int x, int y)
{
	return y + ((x - y) & ((x - y) >> (sizeof(int) * CHARBIT - 1)));
}

/*Function to find maximum of x and y*/
int max(int x, int y)
{
	return x - ((x - y) & ((x - y) >> (sizeof(int) * CHARBIT - 1)));
}

/* Driver code */
int main()
{
	int x = 15;
	int y = 6;
	cout<<"Minimum of "<<x<<" and "<<y<<" is ";
	cout<<min(x, y);
	cout<<"\nMaximum of"<<x<<" and "<<y<<" is ";
	cout<<max(x, y);
}

// This code is contributed by rathbhupendra

