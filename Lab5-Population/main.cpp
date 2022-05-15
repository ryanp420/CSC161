//============================================================================
// Description : Population Modeling Problem
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

typedef unsigned int uint;

uint updatePopulation(uint currentPopulation) {
	uint numBirths = .0185*(currentPopulation);
	uint numDeaths = .0008*(currentPopulation);
	return currentPopulation + numBirths - numDeaths;
}

uint howManyGenerations(uint startAmount, uint finalAmount) {

	uint genCount = 0; 
	// base case 
	if(startAmount >= finalAmount)
	{
		return genCount; 
	}
	else
	{
		//cout << "Gen Account: " << genCount << "\n"; 
		return howManyGenerations(updatePopulation(startAmount) , finalAmount) + 1; 
	}

	// 

}

int main() 
{

	uint finalAmount = 1000000;
	//uint finalAmount = 105;
	uint startAmount = 100;
	if (howManyGenerations(startAmount, finalAmount) == 537) {
		cout<<"PASSED start=100, final=1000000"<<endl;
	}
	//cout << updatePopulation(startAmount); 
	cout << "# Generations: " << howManyGenerations(startAmount, finalAmount) << "\n"; 
	return 0;
}
