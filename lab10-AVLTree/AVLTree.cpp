
//============================================================================
// Name        : AVLTree
// Description : AVL Tree functions
//! NEW april 29 
//============================================================================

#include "AVLTree.h"

#include <iostream>

using namespace std;
//************** already implemented helper functions
AVLTree::AVLTree(int t_data, AVLTree* t_parent, AVLTree* t_left, AVLTree* t_right) {
	data = t_data;
	height = 0;
	parent = t_parent;
	left = t_left;
	right = t_right;
}

bool AVLTree::isLeaf() {
	return ((left == nullptr) and (right == nullptr));
}

uint32_t AVLTree::getHeight() {
	return height;
}

//******************************************************

int AVLTree::getBalance() {
 
	int leftHeight, rightHeight; 

	if(left != nullptr)
	{
		leftHeight = left->height; 
	}
	else
	{
		leftHeight = -1; 
	}
	
	if(right != nullptr)
	{
		rightHeight = right->height; 
	}
	else
	{
		rightHeight = -1; 
	}

	return leftHeight - rightHeight; 
	

}

AVLTree* AVLTree::rotateRight() {

	AVLTree* root; 

	int leftBalance = left->getBalance(); 

	if(leftBalance < 0) 
	{
	
		root = left; 
		left = root->right; 
		root->right = left->left; 
		left->left = root; 
	}

	
		root = left; 
		left = root->right; 
		root->right = this; 
	

	return root; 

}

AVLTree* AVLTree::rotateLeft() {

	AVLTree* root; 

	int rightBalance = right->getBalance(); 

	if(rightBalance > 0) 
	{
		root = right; 
		right = root->left; 
		root->left = right->right; 
	}

	
	root = right; 
	right = root->left; 
	root->left = this; 

	return root; 

}

AVLTree* AVLTree::rebalance() {

	int balance; 


	if(left != nullptr)
	{
		if(!(left->isBalanced()))
		{
			left = left->rebalance();  
		}
	}

	if(right != nullptr)
	{
		if(!(right->isBalanced()))
		{
			right = right->rebalance(); 
		}
	}
	balance = getBalance(); 


	if(balance > 1)
	{
		return rotateRight(); 
	}
	else if(balance < -1)
	{
		return rotateLeft(); 
	}
	else 
	{
		return this; 
	}

}

AVLTree* AVLTree::insert(int new_data) {
	AVLTree* newNode = new AVLTree(new_data);	
	AVLTree* current = this; 


	while(newNode->parent == nullptr)
	{
		if(new_data < current->data)
		{
			if(current->left == nullptr)
			{
				current->left= newNode; 
				newNode->parent = current;
            
			}
			else
			{
				
				current = current->left; 
				//!left->updateHeight();
			}
		}
		else
		{
			if(current->right == nullptr)
			{
				current->right = newNode;
				newNode->parent = current;
				
			}
			else
			{
				current = current->right; 
				//!right->updateHeight();
			}
		} 
		
		
	}


	return rebalance(); 
}


//***************************
//Do not edit code below here
uint32_t AVLTree::countNodes() {
	if (isLeaf()) {
		return 1;
	}
	if (left != nullptr) {
		if (right != nullptr) {
			return 1 + left->countNodes() + right->countNodes();
		}
		return 1+ left->countNodes();
	}
	return 1 + right->countNodes();
}

void AVLTree::updateHeight() {
	if (isLeaf()) {
		height = 0;
		return;
	}
	if (left != nullptr) {
		left->updateHeight();
		if (right != nullptr) {
			right->updateHeight();
			height = (1 + max(left->getHeight(), right->getHeight()));
			return;
		}
		height = 1 + left->getHeight();
		return;
	}
	right->updateHeight();
	height = 1 + right->getHeight();
	return;
}

bool AVLTree::isBalanced() {
	if ( isLeaf() ) {
		return true;
	}
	updateHeight();
	if (left == nullptr) {
		return ( right->getHeight() < 1 );
	}
	if (right == nullptr) {
		return ( left->getHeight() < 1 );
	}
	return ( left->isBalanced() and right->isBalanced() and (getBalance() < 2) and (getBalance() > -2) );
}
