//Kevin Wang
//Stacks
//BCS 370
//This program will display the stacks and overload the assignment operator (==) to see if two stacks are equal

#include <iostream>
#include "myStack.h"

using namespace std;


template<typename C>
void stackDisplay(const stackType<C>& stackObj) {
	stackType<int> stack;
	stack = stackObj;

	while (!stack.isEmptyStack()) {
		cout << stack.top() << "\n";
		stack.pop();
	}
}

template<typename C>
bool operator==(const stackType<C>& stackOne, const stackType<C>& stackTwo) { //const to not modify stacks, bool to return true or false on matching stacks
	
	stackType<int> firstStack, secondStack; //Create two local stack objects
	firstStack = stackOne; //Set local object equal to object passed in by function parameters
	secondStack = stackTwo; //Set local object equal to object passed in by function parameters
	bool stacksMatch = true; //Create a default bool

	//Check if the two stacks are the same size
	if(firstStack.size() == secondStack.size()) { //If both of the stacks are the same size, run through to check each element of stack
		while(firstStack.size()> 0) { //Loop until stack size is at first element
			if(firstStack.top() != secondStack.top()) { //See if the top of stack element is equal, if not return false
				stacksMatch = false;
			}
			firstStack.pop();
			secondStack.pop();
		}
	} else {
		//The stacks are not the same size
		stacksMatch = false;
	}
	
	return stacksMatch;
}


int main() {

	stackType<int> one;
	stackType<int> two;

	one.push(1); //Add first value
	one.push(10); //Add second value
	one.push(15);

	two.push(1); //Add first value
	two.push(10); //Add second value
	two.push(15);

	if(two == one) {
		cout << "Stacks are equal" << endl;
		cout << "Value in stack one: \n";
		stackDisplay(one);
		cout << "\n";
		cout << "Value in stack two: \n";
		stackDisplay(two);
	} else {
		cout << "Stacks are not equal" << endl;
		cout << "Value in stack one: \n";
		stackDisplay(one);
		cout << "\n";
		cout << "Value in stack two: \n";
		stackDisplay(two);
	}

	system("pause");
	return 0;
}