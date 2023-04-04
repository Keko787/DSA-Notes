#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------


/********************************************************************************
default constructor
********************************************************************************/
DynamicQueue::DynamicQueue() {
	front = nullptr;
	rear = nullptr;
    queSize = 4; // list size limit
}

bool DynamicQueue::empty() {
	return (front == nullptr); // if front is nothing
}

void DynamicQueue::insert(char x) {
	DynamicNode* newNode = new DynamicNode;
    newNode->info =x;
    newNode->next = nullptr; // end of the list means its pt to nothing after

	if (empty()) { // if the list is empty
		front = newNode; // the new node is the first so front is assigned to it
	}
	else {
		rear->next = newNode; // if not front, assign the link from rear to the newNode, so its after rear
        // (becoming new rear)
	}

	rear = newNode; // either way since it is still an insert the newNode is the most recent and must be called rear
    //note: a node can be have front and rear pt to them at the same time so it can be front and rear at the same time
    // note: think of rear as top but not as an index but as a head ptr
    // rear is now pt to newnode (is now the new rear)
}

int DynamicQueue::remove() // removes front
{
	if (empty()) {
		std::cout << "queue underflow";
		exit(1);
	}

	DynamicNode* p = front; // node p pts to first node in que
	char temp = p->info; // saves the info from front node
	front = p->next; //moves front ptr to next in line.
    // Note: when the ptr is being assigned to a node thats when the node becomes that or being pointed by that
	delete p; //wipes out p to be overwritten
	if (front == nullptr) // if it becomes empty then assign rear as nullptr
		rear = nullptr;

	return temp; // return the info of the deleted node to confirm
}
