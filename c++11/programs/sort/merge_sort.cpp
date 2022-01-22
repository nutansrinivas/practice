class Solution {
	public:
		vector<int> sortArray(vector<int>& nums) {
			mergeSortArray(nums, 0, nums.size()-1);
			return nums;
		}

		void mergeSortArray(std::vector<int> & arr, int start, int end)
		{
			if (start >= end) return ;

			int mid = (start + end) / 2;
			//std::cout << "calling left mergeSort with start : " << start << ", mid : " << mid << ", end : " << end << std::endl;
			mergeSortArray(arr, start, mid);

			//std::cout << "calling right mergeSort with start : " << start << ", mid : " << mid << ", end : " << end << std::endl;
			mergeSortArray(arr, mid+1, end);

			//std::cout << "calling mergeArray with start : " << start << ", mid : " << mid << ", end : " << end << std::endl;
			mergeArray(arr, start, mid, end);
		}

		void mergeArray(std::vector<int> & arr, int start, int mid, int end)
		{

			int n1 = mid - start + 1;
			int n2 = end - mid;


			std::vector<int> leftArr(n1), rightArr(n2);


			//if (n1 > 0) std::copy(arr.begin()+start, arr.begin()+n1,  leftArr.begin());
			//if (n2 > 0) std::copy(arr.begin()+mid+1, arr.end(), rightArr.begin());

			for (int i=0; i<n1; ++i) leftArr[i] = arr[start+i];
			for (int i=0; i<n2; ++i) rightArr[i] = arr[mid+1+i]; 


			int i=0;
			int j=0;
			int k=start;

			while ((i < n1) && (j<n2))
			{
				//std::cout << "copying from n1,n2 : i : " << i << ", j : " << j << ", k : " << k << std::endl ;

				if (leftArr[i] <= rightArr[j]) 
				{
					arr[k] = leftArr[i];
					++i;
				}
				else
				{
					arr[k] = rightArr[j];
					++j;
				}
				++k;
			}


			while (i < n1) 
			{
				//std::cout << "copying from n1 : i : " << i << ", j : " << j << ", k : " << k << std::endl ;
				arr[k] = leftArr[i];
				++k;
				++i;
			}

			while (j < n2)
			{
				//std::cout << "copying from n2 : i : " << i << ", j : " << j << ", k : " << k << std::endl ;
				arr[k] = rightArr[j];
				++k;
				++j;
			}
			return;
		}

};
