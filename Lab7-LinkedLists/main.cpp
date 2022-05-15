
//============================================================================
// Description : Linked Lists 
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>
#include <cmath> 

#include "Node.h"

using namespace std;

typedef unsigned int uint;

void printList(Node* list) {
	while (list != nullptr) {
		cout << list->data << "  ";
		list = list->next;
	}
	cout<<endl;
}

int addLists(Node* listA, Node* listB) {
// code implementation 
	
	int valueA = 0; 
	int multiplier = 0; 
	while(listA != NULL)
	{
		valueA = valueA + listA->data * (pow(10.0,multiplier));
		multiplier++;  
		listA = listA->next; 
		
	}

	int valueB = 0; 
	multiplier = 0; 
	while(listB != NULL)
	{
		valueB = valueB + listB->data * (pow(10.0,multiplier));
		multiplier++;  
		listB = listB->next; 
		
	}

	return valueA + valueB; 
}
Node* genList(int number) {
	Node* headOfList = new Node(number%10);
	Node* listIterator = headOfList;
	number = number / 10;
	while (number > 0) {
		listIterator->next = new Node(number%10);
		listIterator = listIterator->next;
		number = number/10;
	}
	return headOfList;
}

int main() {


	srand(time(NULL));
	int numA = rand()%10000000;
	int numB = rand()%10000000;
	Node* listA = genList(numA);
	Node* listB = genList(numB);

	cout << "Original Num A = " << numA <<"\n"; 
	printList(listA); 

	cout << "Node B = " << numB <<"\n"; 
	printList(listB); 



	int sum = addLists(listA, listB);
	if ( sum == (numA + numB)) {
		cout<<"PASSED basic test (9 pts)"<<endl;
	}
	else {
		cout<<"FAILED expected: "<<numA + numB<<" actual: "<<sum<<endl;
	}


	int numC = rand()%100<<12;
	int numD = rand()%100;
	Node* listC = genList(numC);
	Node* listD = genList(numD);
	sum = addLists(listC, listD);
	if ( sum == (numC + numD)) {
		cout<<"PASSED A: "<<numA<<" much greater than B:"<<numD<<endl;
		cout<<"PASSED A much greater than B (8 pts)"<<endl;
	}
	else {
		cout<<"FAILED expected: "<<numC + numD<<" actual: "<<sum<<endl;
	}

	int numF = rand()%100<<12;
	int numE = rand()%100;
	Node* listE = genList(numE);
	Node* listF = genList(numF);
	sum = addLists(listE, listF);
	if ( sum == (numE + numF)) {
		cout<<"PASSED B: "<<numF<<" much greater than A:"<<numE<<endl;
		cout<<"PASSED B much greater than A (8 pts)"<<endl;
	}
	else {
		cout<<"FAILED expected: "<<numE + numF<<" actual: "<<sum<<endl;
	}

	return 0;
}

