// C++ program to find the length of the longest substring
// without repeating characters
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

int longestUniqueSubsttr(string str)
{
	int n = str.size();

	int maxLength = 0; // result

	// last index of all characters is initialized as -1
	vector<int> lastIndex(256, -1);

	// Initialize start of current window
	int startWindow = 0;

	// Move end of current window
	for (int index = 0; index < n; j++) {

		startWindow = max(startWindow, lastIndex[str[index]] + 1);

		maxLength = max(maxLength, index - startWindow + 1);

		lastIndex[str[index]] = index;
	}
	return maxLength;
}

// Driver code
int main()
{
	string str = "geeksforgeeks";
	cout << "The input string is " << str << endl;
	int len = longestUniqueSubsttr(str);
	cout << "The length of the longest non-repeating character substring is " << len;
	return 0;
}

