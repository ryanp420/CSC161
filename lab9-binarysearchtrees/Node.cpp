
#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int t_data, Node* t_left, Node* t_right) {
	data = t_data;
	left = t_left;
	right = t_right;
}

void Node::insert(int new_data) {
	Node* newNode = new Node(new_data);		

	if(new_data < data)
	{
		if(left == nullptr)
			left = newNode; 
		else
			left->insert(new_data); 
	}
	else
	{
		if(right == nullptr)
			right = newNode;
		else
			right->insert(new_data);  
	} 

}

bool Node::isLeaf() {
	//! Node has 0 children 

	if (left == nullptr && right == nullptr)
	{
		return true; 
	}
	
	return false; 
}

uint32_t Node::height() {

	int leftHeight;
	int rightHeight; 

	if(left == nullptr)
	{
		leftHeight = -1; 
	}
	else 
	{
		leftHeight = left->height(); 
	}

	if(right == nullptr)
	{
		rightHeight = -1; 
	}
	else
	{
		rightHeight = right->height(); 
	}
	
	return 1 + max(leftHeight,rightHeight);  
}

bool Node::isFull(){
	//! Each Node has 0 or 2 children 
	//! every level has node filled 

	if(isLeaf())
	{
		// 0 children 
		return true; 
	}
	
	if (left && right)
		return left->isFull() && right->isFull(); 

	return false; 
	

}
uint32_t Node::countNodes() {

	uint32_t total = 1; 

	if (left != nullptr)
	{
		total+= left->countNodes();  	
	}

	if(right != nullptr)
	{	
		total+= right->countNodes(); 
	}

	return total; 

}


// ! Personal print 
void Node::printIt(int space){
		
	space += 5;

	if (right)
		right->printIt(space);

	for (int i= 5; i < space; i++)
		cout << " ";
	cout << data << "\n";
	
	if (left)
		left->printIt(space);
}
