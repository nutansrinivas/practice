#include <iostream>

#define RET_ERROR -1
#define RET_SUCCESS 0

class IntList
{

	public :
		IntList() {mpIntArr = nullptr; mSize = 0; mMaxSize = 100 ;  }
		IntList(size_t maxSize) {mpIntArr=nullptr; mSize=0; mMaxSize=maxSize;}

		int readIntListFromFile(std::string & fileName);
		int readFromConsole();

		void printIntList();

		int doSelectionSort();

		int doBubbleSort();
		int doBubbleSortRecursive(int size);

		int doInsertionSort();
		int doInsertionSortRecursive(int size);


		int doMergeSort();
		int mergeSort(int *pIntArr, int start, int end);
		int mergeSortedPositions(int *pIntArr, int start, int mid, int end);


	private :
		int *mpIntArr;
		size_t mSize;
		size_t mMaxSize;
};
