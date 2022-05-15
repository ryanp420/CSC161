//============================================================================
// Date   : April 6 2022
// Description : Binary Search Tree
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>
#include <stack>
#include <queue>


#include "Node.h"

using namespace std;



typedef unsigned int uint;
int main() {

	cout << "The max of 1 and 5 is = " << max(1,5) << endl; 

	Node* tree1Root = new Node(5);
	cout << "Is Full Version 1 = " << tree1Root->isFull() << endl; 


	tree1Root->insert(4);  
	tree1Root->insert(6);  

	tree1Root->insert(3);
	tree1Root->insert(7);
	tree1Root->insert(2);
	tree1Root->insert(8);
	tree1Root->insert(1);
	tree1Root->insert(9);

	cout << "Tree Root 1" <<  endl; 
	tree1Root->printIt(5); 
	

	cout << "Is Full Version 2 = " << tree1Root->isFull() << endl; 
	cout << "Count Nodes = " << tree1Root->countNodes() << endl; 


	if (!tree1Root->isFull()) {
		std::cout<<"tree1Root->isFull(): PASSED"<<std::endl;
	}
	else {
		std::cout<<"tree1Root->isFull(): FAILED"<<std::endl;
	}

	if (tree1Root->height() == 4) {
		std::cout<<"tree1Root->height(): PASSED"<<std::endl;
	}
	else {
		std::cout<<"tree1Root->height(): FAILED expected: 4 actual: "<<tree1Root->height()<<std::endl;
	}

	if (tree1Root->countNodes() == 9) {
		std::cout<<"tree1Root->countNodes(): PASSED"<<std::endl;
	}
	else {
		std::cout<<"tree1Root->countNodes(): FAILED expected: 9 actual: "<<tree1Root->countNodes()<<std::endl;
	}

	Node* tree2Root = new Node(4);
	tree2Root->insert(2);
	tree2Root->insert(1);
	tree2Root->insert(3);
	tree2Root->insert(6);
	tree2Root->insert(5);
	tree2Root->insert(7);


	cout << "Tree Root 2" <<  endl; 
	tree2Root->printIt(5); 

	if (tree2Root->isFull()) {
		std::cout<<"tree2Root->isFull(): PASSED"<<std::endl;
	}
	else {
		std::cout<<"tree2Root->isFull(): FAILED"<<std::endl;
	}

	if (tree2Root->height() == 2) {
		std::cout<<"tree2Root->height(): PASSED"<<std::endl;
	}
	else {
		std::cout<<"tree2Root->height(): FAILED expected: 2 actual: "<<tree2Root->height()<<std::endl;
	}

	if (tree2Root->countNodes() == 7) {
		std::cout<<"tree2Root->countNodes(): PASSED"<<std::endl;
	}
	else {
		std::cout<<"tree2Root->countNodes(): FAILED expected: 7 actual: "<<tree2Root->countNodes()<<std::endl;
	}


}
