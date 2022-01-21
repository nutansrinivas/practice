#include <iostream>


// 1,2,3,4,5,6

// num. of subarrays statr with 1 is - 6 ,  2 - 5,  3 - 4, 4 - 3, 5 - 2, 6 - 1   : formula is n - i where i shall be in between 0 to n-1
// num. of subarrays have, not start with 1 - 0, 2 - 5, 3 - 8, 4 - 9, 5 - 8, 6 - 5 : formul is ( n - i ) * i
// so total sum is =  sum of (n - i) + (n - i) * i  where i = 0 to n-1


int subArraySum(int arr[], int n)
{
	int result = 0, temp = 0;

	for (int i = 0; i < n; ++i)
	{
		temp = 0;

		for (int j = i; j < n; ++j) 	//1, 2, 3, 4, 5
		{
			temp += arr[j];		// temp = 1 + 2 + 3 + 4 + 5 + 6
			result += temp;		// result = 1 + [ 1 + 2 ] + [ 1 + 2 + 3 ] + [ 1 + 2 + 3 + 4 ] + [ 1 + 2 + 3 + 4 + 5 ] + [ 1+2+3+4+5+6 ]
		}
	}
	return result;
}

int getSubArrayOfSum(int arr[], int n, int sum)
{
	int result = 0, temp = 0;

	for (int i = 0; i < n; ++i)
	{
		temp = 0;

		for (int j = i; j < n; ++j) 	//1, 2, 3, 4, 5
		{
			temp += arr[j];		// temp = 1 + 2 + 3 + 4 + 5 + 6
			if (temp == sum)
			{
				std::cout << "subarray of index " << i << " to " << j << " give the sum " << sum << std::endl;
				return 1;
			}
			else if (temp > sum) break ;
		}
	}
	return 0;
}

//1, 2, 3, 4, 5 - 

int getSubArrayOfSum_op(int arr[], int n, int sum)
{
	int cur_sum = 0, start = 0;

	for (int i = 0; i < n; ++i)
	{
		cur_sum += arr[i];

		while ((cur_sum > sum) && (start < i))
		{
			cur_sum -= arr[start];
			++start;
		}

		if (cur_sum == sum) 
		{
			std::cout << "sum of sub array of index from [" << start << "] to [" << i << "] is " << sum << std::endl ;
			return 1;
		}
	}
	return 0;
}


int getSmallestSubArrayOfSumGT(int ar[], int arrLen, int sum)
{
	int cur_sum = 0;
	int minLen

	for (int startIndex = 0; startIndex < arrLen; ++startIndex)
	{
		
		for (int endIndex = 0; endIndex < arrLen; ++endIndex)
		{
			cur_sum += arr[endIndex];

			if (cur_sum > sum) 
		}
	}
}

int main()
{
	//std::array<int, 3> arr1{ {1,2,3} };  //need additional { } to hold in c++11
	//std::array<int> arr2 = {1,2,3};  //not required additional { } after = 

	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
	int arlen = sizeof(arr) / sizeof(arr[0]) ;
	
	getSubArrayOfSum_op(arr, arlen, 23);
}
