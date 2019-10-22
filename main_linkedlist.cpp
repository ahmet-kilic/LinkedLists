#include <iostream>

#include "LinkedList.hpp"

int main() {
    LinkedList<int> llist;
    LinkedList<int> llist2;
    LinkedList<int> llist3;
    LinkedList<int> empty;
    Node<int> *test;

    llist.insertAtTheEnd(1);
    llist.insertAtTheEnd(2);
    llist.insertAtTheEnd(3);
    llist2.insertAtTheFront(1);
    llist2.insertAtTheFront(2);
    llist2.insertAtTheFront(3);
    llist3.insertAtTheEnd(0);

    std::cout << "Empty List function tests" << std::endl;
    empty.printAllNodes();
    std::cout << "print allnodes done" << std::endl;
    empty.printReversed();
    std::cout << "print reversed done" << std::endl;

    std::cout << "List 1 PrintAllNodes:" << std::endl;
    llist.printAllNodes();
    std::cout << "List 1 PrintReversed:" << std::endl;
    llist.printReversed();
    std::cout << "List 2 Print All NODES:" << std::endl;
    llist2.printAllNodes();
    std::cout << "List 2 printreversed:" << std::endl;
    llist2.printReversed();
    std::cout << "List 3 printallnodes:" << std::endl;
    llist3.printAllNodes();
    std::cout << "List 3 printreversed" << std::endl;
    llist3.printReversed();

    std::cout << "List 1 first node" << std::endl;
    std::cout << llist.getFirstNode()->element << std::endl;
    std::cout << "List 2 first node" << std::endl;
    std::cout << llist2.getFirstNode()->element << std::endl;
    std::cout << "List 3 first node" << std::endl;
    std::cout << llist3.getFirstNode()->element << std::endl;
    std::cout << "List 1 gethead" << std::endl;
    std::cout << llist.getHead()->next->element << std::endl;
    std::cout << "List 2 gethead" << std::endl;
    std::cout << llist2.getHead()->next->element << std::endl;
    std::cout << "List 3 gethead" << std::endl;
    std::cout << llist3.getHead()->next->element << std::endl;
    std::cout << "List 1 gettail" << std::endl;
    std::cout << llist.getTail()->prev->element << std::endl;
    std::cout << "List 2 gettail" << std::endl;
    std::cout << llist2.getTail()->prev->element << std::endl;
    std::cout << "List 3 gettail" << std::endl;
    std::cout << llist3.getTail()->prev->element << std::endl;

    std::cout << "List 1 number of nodes" << std::endl;
    std::cout << llist.getNumberOfNodes() << std::endl;
    std::cout << "List 2 number of nodes" << std::endl;
    std::cout << llist2.getNumberOfNodes() << std::endl;
    std::cout << "List 3 number of nodes" << std::endl;
    std::cout << llist3.getNumberOfNodes() << std::endl;

    std::cout << "Empty test number of nodes" << std::endl;
    std::cout << empty.getNumberOfNodes() << std::endl;

    std::cout << "Empty test get first" << std::endl;
    if(empty.getFirstNode() == NULL) std::cout << "NULL" << std::endl;
    

    return 0;
}