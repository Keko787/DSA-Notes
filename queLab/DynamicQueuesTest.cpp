#include <iostream>
#include "DynamicQueue.h"

int main()
{
    // test DynamicQueue
    DynamicQueue queue = DynamicQueue();


    // first test case
    std::cout << "Test case 1: \n";

    std::cout << "Read key a.";
    queue.searchInsert('a');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key b.";
    queue.searchInsert('b');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key w.";
    queue.searchInsert('w');
    queue.print();
    std::cout << "\n";

    //repeat
    std::cout << "Read key b.";
    queue.searchInsert('b');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key z.";
    queue.searchInsert('z');
    queue.print();
    std::cout << "\n";

    //overfill
    std::cout << "Read key e.";
    queue.searchInsert('e');
    queue.print();
    std::cout << "\n";

    //clears the chain for next test case
    queue.remove();
    queue.remove();
    queue.remove();
    queue.remove();


    //second test case

    std::cout << "Test case 2: \n";

    std::cout << "Read key b.";
    queue.searchInsert('b');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key c.";
    queue.searchInsert('c');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key t.";
    queue.searchInsert('t');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key s.";
    queue.searchInsert('s');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key a.";
    queue.searchInsert('a');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key c.";
    queue.searchInsert('c');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key c.";
    queue.searchInsert('c');
    queue.print();
    std::cout << "\n";

    std::cout << "Read key s.";
    queue.searchInsert('s');
    queue.print();
    std::cout << "\n";


}

