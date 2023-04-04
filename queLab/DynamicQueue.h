#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

struct DynamicNode{ // node is the same as in the dynamic list code 
  char info;
  DynamicNode *next;
};

class DynamicQueue {
public:
	//---------------------------------------------------------------
	// constructors
	//---------------------------------------------------------------
	DynamicQueue();

	//---------------------------------------------------------------
	// methods (inserts and deletes)
	//---------------------------------------------------------------
	bool empty();
	void insert(char x);
	int remove();

    //---------------------------------------------------------------
    // v2 methods (Search or inserts and print)
    //---------------------------------------------------------------

    void searchInsert(char x);
    void print();

private:
	DynamicNode* front;
	DynamicNode* rear;
    int queSize;

};
#endif

