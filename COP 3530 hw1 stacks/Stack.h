#ifndef STACK_H
#define STACK_H

const int STACKSIZE = 100; // max size

class Stack 
{
public:
	//---------------------------------------------------------------
	// constructors
	//---------------------------------------------------------------
	Stack(); // default constructor

	//---------------------------------------------------------------
	// methods (inserts and deletes)
	//---------------------------------------------------------------
	char pop();
	void push(char x);
	char peek();
	bool empty();

private:
	int top; // indicates the top element
	char items[STACKSIZE] = {};
};


#endif