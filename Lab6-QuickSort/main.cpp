//============================================================================
// Description : Quick and Merge Sort
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

#include "SortTester.h"

using namespace std;

typedef unsigned int uint;
////
uint partition(SortTester &tester, int lowIndex, int highIndex)
{
	// {4,5,2,0,  7   ,8,3,9,1} 
	// pivot = location[4] value: 7q
	uint pivot = lowIndex + (highIndex - lowIndex) / 2;

	bool done = false; 
	while(!done)
	{
		//check if lowIndex > pivot 
		// LOCATIONS 
		// compare uses VALUES 
		while(tester.compare(lowIndex,pivot) <= 0)
		{
			if(lowIndex > pivot)
			{
				tester.swap(pivot,lowIndex); 
				lowIndex++; 
				pivot++;
	
			}
		
			else
			{
				lowIndex++; 
			}
			if(highIndex < lowIndex)
			{
				break; 
			}

		}

		// cheking high index 
		while(tester.compare(highIndex,pivot) >= 0) 
		{
			if(highIndex < pivot)
			{
				tester.swap(pivot,highIndex); 
				highIndex--;
				pivot--; 
				
			}
			else
			{
				highIndex--; 
			}
			if(highIndex < lowIndex)
			{
				break; 
			}
		}

		
		if(lowIndex > highIndex)
		{
			done = true; 
		}
		else{
			tester.swap(lowIndex,highIndex); 
		}

		//! end of while(!done)
	}
	return pivot; 
}
////

void quickSort(SortTester &tester, int lowIndex, int highIndex) {


	if(lowIndex >= highIndex) //or lowIndex < highIndex ? 
	{
		return; 
	}
	uint pivot = partition(tester,lowIndex,highIndex); 
	quickSort(tester,lowIndex,pivot-1); 
	quickSort(tester,pivot+1,highIndex);  


}

int main() {

	cout << "Ryan Test" << endl; 

 	uint size = 20;
	SortTester tester = SortTester(size);
	cout<<"Unsorted"<<endl;
	tester.print();
	quickSort(tester, 0, size-1);
	if (tester.isSorted()) {
		cout<<"PASSED List Sorted (5 pts)"<<endl;
	}
	else {
		tester.print();
		cout<<"FAILED List not Sorted"<<endl;
	}

}
