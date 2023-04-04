#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>

void DynamicQueue::searchInsert(char x) {

    // three parts: the traversal and searching, moving the match, and removing node based on quesize then inserting

    DynamicNode *searchNode = front;// has to be front because it cannot move back
    DynamicNode *trailNode = nullptr;
    int size = 0;
    //traversal and search
    // two conditions to stop the loop: if the searchNode is a nullptr and if the data matches with the search
    //it will stop on where the data matches meaning that there is no need to keep the rest of the function on a loop

    //std::cout << "searching... \n";

    while (searchNode != nullptr && searchNode->info != x)
    {
        trailNode = searchNode;
        searchNode = searchNode->next;

        //while looping it will count the size
        //the size only matters when it cant find a match and will count the whole size of the queue this way

        size++;
    }
    //separating the search loop from the function adds a lot more encapsulation, it is also able to count the size

    //if match not found: check the queue size and insert at the rear
    if(searchNode == nullptr)
    { // two sub parts: if queue size is not full, just insert; if queue size is full, delete the front and insert

        //sub part 1
        if(size < queSize) // if quesize isnt full
        {
            std::cout << " Inserting " << x << " in rear. ";

            insert(x); // inserts new node at the rear
        }
        //sub part 2
        else // if quesize is full
        {
            std::cout << " Queue is full, removing front. Inserting " << x << " in rear. ";
            remove(); // removes front while moving front to node->next
            insert(x); // inserts new node at the rear
        }
    }

    // if match is found: move node to recent (rear)
    else
    {
        std::cout << " Key already in queue, moving " << x <<  " to rear. ";

        if (searchNode != rear) { // if current is not the most recent. this condition goes first for easier logic for the front
            // if its alr rear then there is no point to move to the same spot

            if (searchNode == front)// if current is the least recent and at the start of the list, move the ptr next in chain
            {
                front = searchNode->next; // move the front header to the next in line,
                // (since I know what the front node is i dont have to express front and express the node)
            }

            else //if search node is not front, save the chain (chain of links, chain of memories)
            {
                trailNode->next = searchNode->next; // assign the current link to the prev which saves the chain past current
            }

            //moving the current node to rear
            searchNode->next = nullptr; //first make the current's link null (cut of the chain),
            rear->next = searchNode; // then make the rear node's link (since rear is not known, call rear directly pt to current
            rear = searchNode; // then make rear pt to current since now current is behind rear
        }
    }
}

void DynamicQueue::print() {
    if(empty())
    {
        std::cout<< "Empty list \n";
    }

    DynamicNode* printNode = front; //traversal ptr node

    std::cout << "Queue: "; // says what it is

    while(printNode != nullptr) { // traversal
        std::cout << printNode->info; // print data

        if(printNode->next != nullptr) // if the queue link is not null
        {
            std::cout << "->"; // print a link
        }
        else
        {
            std::cout << "\n"; // make a space
        }
        printNode = printNode->next; // increment
    }
}
