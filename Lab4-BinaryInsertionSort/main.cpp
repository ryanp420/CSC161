
//============================================================================
// Description : Binary Insertion Sort
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>

#include "SortTester.h"

using namespace std;

typedef unsigned int uint;

uint findInsertionLocation(SortTester &tester, uint start, uint end, uint index) {
   


return 0;

}

void insertionSort(SortTester &tester, uint size) {

//insert your code for insertion sort here
//HINT//
//First get your insertion sort working by just searching backward for location

//Then once that is working - work on implemnting the binary search for the insertion location
	
	// {4 , 5} 
	// -1 
	// <0 (don't swap)

	for(uint i = 1; i < size; i++)
	{
		int j = i; 
		while(j > 0 && tester.compare(j,j-1) < 0) // tester.isSorted() == false
		{
			tester.swap(j,j-1); 
			--j; 
			 
		}
	}

	//   {3 2 4 8} 
	//  { 5 6 2 8} 

}

int main() {
	uint size = 10;
	SortTester tester = SortTester(size);
	cout<<"Unsorted"<<endl;
	tester.print();
	insertionSort(tester, size);

	// testing to see if sorted 
	// cout << endl; 
	// cout << "Sorted: " << endl; 
	//tester.print(); 

	if (tester.isSorted()) {
		cout<<"PASSED List Sorted (10 pts)"<<endl;
	}
	else {
		tester.print();
		cout<<"FAILED List not Sorted"<<endl;
	}

	if (tester.areComparesBinary()) {
	   cout<<"PASSED Binary Insertion Sort (15 pts)"<<endl;
	}
	else {
	   cout<<"FAILED Binary Insertion Sort"<<endl;
	}

	if (tester.isSortStable()) {
	   cout<<"PASSED Extra Credit - sort is stable (5pts)"<<endl;
	}
	else {
	   cout<<"Sort is not stable - swap occured among entries with same value"<<endl;
	}
}
