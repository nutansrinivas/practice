
#include <stdio.h>
#include <vector>
#include <iostream>


class Solution {
	public:
		void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {

			if ( !n) return;
			int k = m+n -1, i=m-1, j=n-1;

			if (nums1.size() > 0)
			{
				for(; k >= 0; )
				{
					if (nums1[i] > nums2[j])
					{
						nums1[k] = nums1[i]; i--;         
					}
					else
					{
						nums1[k] = nums2[j]; j--;
					}
					k--;
					if (i < 0 || j < 0) break;
				}
			}

			if (i < 0)
			{
				for (; (k >=0 && j>=0); k--, j--)
				{
					nums1[k] = nums2[j];
				}
			}

			return ;
		}
};


int main()
{
	std::vector<int> vt1 = {0};
	std::vector<int> vt2 = {1};

	Solution sol;

	sol.merge(vt1, vt1.size(), vt2, vt2.size());

	for (auto i : vt1)
		std::cout << i << "," ;
}
