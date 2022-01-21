#include "IntListSortingAlgo.hh"

#include <fstream>
#include <sstream>
#include <list>
#include <string.h>

int IntList::readIntListFromFile(std::string & fileName)
{
	std::ifstream ifs;
	ifs.open(fileName.c_str(), std::ifstream::in);

	if (!ifs.is_open()) 
	{
		std::cout << "error in opening file :"<< fileName.c_str() << std::endl;
		return RET_ERROR;
	}

	std::string line;
	std::getline(ifs, line);

	std::list<int> lineDetails;

	std::stringstream ss(line);
	std::string token;
	while(getline(ss, token, ','))
	{
		lineDetails.push_back(std::stoi(token));
	}
	
	int totalNumbers = lineDetails.size();
	if (lineDetails.front() != (lineDetails.size() -1))
	{
		std::cout << "error, total lenght :" << lineDetails.size() << " and given length :" << lineDetails.front() << std::endl;
		return RET_ERROR;
	}

	mSize = lineDetails.front();

	mpIntArr = new int[mSize];
	memset(mpIntArr, 0, mSize);
	if (nullptr != mpIntArr) 
	{
		lineDetails.pop_front();
		int i = 0;
		for (auto value : lineDetails)
		{
			mpIntArr[i++] = value;	
		}
	}
}

void IntList::printIntList()
{
	if (mpIntArr == nullptr)
	{	
		std::cout << "no elements in array" << std::endl;
		return ;
	}

	for (int i=0; i < mSize; i++) std::cout << " " << mpIntArr[i] ;
	std::cout << std::endl;
	return;
}

/* selection sort : from position to 0 to n, for each find the minimum element from the right side elements and swap that element to current position and repeat the same for all positions */
int IntList::doSelectionSort()
{
	std::cout << "selection sort :: time complexity : o(n*2) :: auxilary space : o(1) \n" ;
	int i=0, j=0, indexOfMin=0;	

	for (i = 0; i < mSize; i++ )
	{
		indexOfMin = i;
		for (j = i+1; j < mSize; j++)
		{
			if (mpIntArr[indexOfMin] > mpIntArr[j]) indexOfMin = j;
		}

		int temp = mpIntArr[indexOfMin];
		mpIntArr[indexOfMin] = mpIntArr[i];
		mpIntArr[i] = temp;
	}

	return RET_SUCCESS;
}


/* bubblesort : swap the adjacent elements if they are in wrong order */

int IntList::doBubbleSort()
{

	std::cout << "bubble sort :: time complexity : o(n*2) :: auxilary space : o(1) \n" ;
	int i=0, j=0;

	for (i = 0; i < (mSize - 1) ; i++)
	{
		bool allRInOrder = true;
		for (j=0; j < (mSize - 1 - i); j++)
		{
			if (mpIntArr[j] > mpIntArr[j+1]) 
			{
				int temp = mpIntArr[j]; 
				mpIntArr[j] = mpIntArr[j+1];
				mpIntArr[j+1] = temp;
				allRInOrder = false;
			}
		}
		if (allRInOrder) break;
	}

	return RET_SUCCESS;
}

int IntList::doBubbleSortRecursive(int size)
{
	if (size <= 1) return RET_SUCCESS;

	for (int i = 0; i < size-1; i++)
	{
		if (mpIntArr[i] > mpIntArr[i+1])
		{
			int temp = mpIntArr[i];
			mpIntArr[i] = mpIntArr[i+1];
			mpIntArr[i+1] = temp;
		}
	}

	doBubbleSortRecursive(size-1);
}

/* insertion sort : from current index take element, ask all its previous elements who are greater than the current element to one step right index */
int IntList::doInsertionSort()
{
	std::cout << "insertion sort :: time complexity : o(n*2) :: auxilary space : o(1) \n" ;
	for (int i=1; i < mSize; i++)
	{
		int key = mpIntArr[i];
		int keyIndex = i-1;

		while ((keyIndex >= 0) && (mpIntArr[keyIndex] > key))
		{
			mpIntArr[keyIndex+1] = mpIntArr[keyIndex--];
		}
		mpIntArr[keyIndex+1] = key;
	}
}

int IntList::doInsertionSortRecursive(int size)
{
	if (size <= 1) return RET_SUCCESS;

	doInsertionSortRecursive(size-1);
	int i = size-1;

	int key = mpIntArr[i];
	int keyIndex = i-1;

	while ((keyIndex >= 0) && (mpIntArr[keyIndex] > key))
	{
		mpIntArr[keyIndex+1] = mpIntArr[keyIndex--];
	}
	mpIntArr[keyIndex+1] = key;
}

int IntList::doMergeSort()
{
	std::cout << "merge sort :: time complexity : o(nlogn) :: auxilary space : o(n) \n" ;
	mergeSort(mpIntArr, 0, mSize-1);
}

int IntList::mergeSort(int *pIntArr, int start, int end)
{
	if ((nullptr == pIntArr) || (start >= end)) return RET_ERROR;

	int mid = start + (end - start ) / 2 ;

	mergeSort(pIntArr, start, mid);
	mergeSort(pIntArr, mid+1, end);
	mergeSortedPositions(pIntArr, start, mid, end);
}

int IntList::mergeSortedPositions(int *pIntArr, int start, int mid, int end)
{
	int firstArrLen = mid - start + 1;
	int secondArrLen = end - mid ;

	int *firstArr = new int[firstArrLen];
	int *secondArr = new int[secondArrLen];

	for (int i =0; i< firstArrLen; i++) firstArr[i] = pIntArr[start+i]; 
	for (int j =0; j< secondArrLen; j++)secondArr[j] = pIntArr[mid+1+j]; 

	int i=0, j=0, k=start;

	while ((i < firstArrLen) && (j < secondArrLen))
	{
		if (firstArr[i] <= secondArr[j]) pIntArr[k++] = firstArr[i++];
		else pIntArr[k++] = secondArr[j++];
	}

	while(i < firstArrLen) pIntArr[k++] = firstArr[i++];

	while(j < secondArrLen) pIntArr[k++] = secondArr[j++];

	delete [] firstArr;  	delete [] secondArr;
}


int IntList::doQuickSort(int *pIntArr, int start, int end)
{
	if ((nullptr == pIntArr) || (start >= end)) return RET_ERROR;

	int pi = partition(pIntArr, start, end);
	doQuickSort(pIntArr, start, pi-1);
	doQuickSort(pIntArr, pi+1, end);
}

int IntList::partition(int *pIntArr, int start, int end)
{
	int pivot = pIntArr[end];
	int i = start - 1 ;

	for (int j = start; j <= end; ++j)
	{
		if (arr[j] < pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[j]);
	return (i+1);
}


