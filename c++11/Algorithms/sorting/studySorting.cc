#include <iostream>
#include "IntListSortingAlgo.hh"

int main(int argc, char* argv[])
{
	if (argc <= 1) 
	{
		std::cout << "usage is ./studySorting inputFileName" << std::endl;
		return RET_ERROR;
	}

	IntList	sortingAlgo;
	std::string fileName = argv[1];
	sortingAlgo.readIntListFromFile(fileName);
	sortingAlgo.printIntList();
	//sortingAlgo.doSelectionSort();
	//sortingAlgo.doBubbleSort();
	sortingAlgo.printIntList();
	sortingAlgo.doMergeSort();
	sortingAlgo.printIntList();

	return 0;
}
