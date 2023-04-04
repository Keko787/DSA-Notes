#include "Stack.h"
#include <iostream>

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
Stack::Stack() {
    top = -1;
}

int main(){

/// task 1

    Stack newStack = Stack(); // initilizing obj

    char name[] = {'K','O','S','T','A','G','E',}; //array (for more features l8r)

    int nameLim = 7; //conditional

    for(int i = 0; i < nameLim; i++) //first loop that pushes letters into a stack and display the array
    {
        newStack.push(name[i]);
        std::cout << newStack.peek();
    }

    std::cout << "\n"; // spacing

    for(int j = nameLim; j > 0; j--) // second loop that pops the stack and displays the array in reverse
    {
        std::cout << newStack.peek();
        newStack.pop();
    }



}
/********************************************************************************
methods (insert and delete)
********************************************************************************/
bool Stack::empty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::push(char x) {
    if (top == STACKSIZE - 1) {
        std::cout << "Stack Overflow PUSH" << std::endl;
        exit(1);
    }

    items[++top] = x;
}

char Stack::pop() {
    if (empty()) {
        std::cout << "Stack Underflow POP" << std::endl;
        exit(1);
    }

    return items[top--];
}

char Stack::peek() {
    if (empty()) {
        std::cout << "Stack Underflow PEEK" << std::endl;
        exit(1);
    }

    return items[top];
}