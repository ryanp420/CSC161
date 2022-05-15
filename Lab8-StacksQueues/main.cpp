
//============================================================================
// Date        : April 4 2022
// Description : Stacks and Queues, Post Fix Operator
// Version : 2 of lab 8 
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>
#include <stack>
#include <queue>



//! Stack = LIFO = last in first out 
// .empty()
// .size()
// .top() : top (first) element of stack 
// .push() : put element onto stack 
// .pop() : remove element from stack 

//! Queue = FIFO = first in first out 
// .front()
// .back()

using namespace std;


// void printStack(stack<int> s)
// {
// 	// If stack is empty then return
// 	if (s.empty())
// 	return;
// 	int x = s.top();
// 	// Pop the top element of the stack
// 	s.pop();
// 	// Recursively call the function PrintStack
// 	printStack(s);
// 	// Print the stack element starting
// 	// from the bottom
// 	cout << x << " ";
// 	// Push the same element onto the stack
// 	// to preserve the order
// 	s.push(x);
// }

int evalPostfix(std::queue<char> expression) 
{
	char item; 


	char list [2]; 
	list[1] = '\0'; 

	std::stack<int> myStack; 

	while(!expression.empty())
	{
		item = expression.front(); 

		//cout << item << ", "; 


		if(item == '+' || item == '-' || item == '*' || item == '/')
		{
			// assumes at least 2 items on stack
			int num2 = myStack.top(); 
			myStack.pop(); 
			int num1 = myStack.top(); 
			myStack.pop(); 
			// 5 + 7 
			
			switch (item)
			{
				case '+':
					//cout << "Sum = " << num1 + num2; 
					myStack.push(num1 + num2); 
				break; 

				case '-':
					//cout << "Result = " << num1 - num2; 
					myStack.push(num1 - num2); 
				break; 

				case '*':
					myStack.push(num1 * num2); 
				break; 

				case '/':
					myStack.push(num1 / num2); 
				break; 

				default: 
					cout << "Recieved an operator not in list" << endl; 
			}

		}
		else
		{
			// push operands onto stack 
			
			list[0] = item; 
			myStack.push(atoi(list)); 

			//! old 1.0 myStack.push(atoi(&item))
			// &item character pointer so a single pointer
			// atoi() accepts c-strings
		}


		//un commenting this function and printing this out may work
		//old 1.0 printStack(myStack); 
		expression.pop(); 
	}


	// if operand (1,2,3 etc...) push onto stack
	// if operator (+,-,*,/) pull operands from stack, excecute operation
	// push result ont operand stack


	// when queue is empty, return top of stack 
	return myStack.top(); 

}


int main() {

	cout << "Ryan Test " << endl; 

	std::queue<char> queue1, queue2;
	//basic simple addition
	queue1.push('1');
	queue1.push('2');
	queue1.push('+');
	cout<<"Queue1 evaluates to "<<evalPostfix(queue1)<<std::endl;

	queue2.push('5');
	queue2.push('6');
	queue2.push('7');
	queue2.push('+');

	queue2.push('1');
	queue2.push('2');
	queue2.push('+');

	queue2.push('-');
	queue2.push('*');
	queue2.push('4');
	queue2.push('/');

	// ! Pointer problem when using atoi(); 
	// right after 4 in memory, there was a 2
	// giving us 42 , messing up the calculation
	// creating the char list [array] we are forcing
	// there to be a delimeter after each character
	// we pass in 
	// so the compiler knows when to stop


	//in atoi() case
	//it stops at somthing that's not a number

	cout<<"Queue2 evaluates to "<<evalPostfix(queue2)<<std::endl;

	return 0;
}

