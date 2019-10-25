#include <iostream>

#include "LinkedList.hpp"

int main() {
    LinkedList<int> llist;
    LinkedList<int> empty;
    Node<int> lel;


    llist.insertAtTheEnd(1);
    llist.insertAtTheEnd(2);
    llist.insertAtTheEnd(3);
    LinkedList<int> llist1(llist);
    std::cout << "List  PrintAllNodes:" << std::endl;
    llist.printAllNodes();
    std::cout << "List  Reversed:" << std::endl;
    llist.printReversed();
    std::cout << "List 1 Print all nodes" << std::endl;
    llist1.printAllNodes();
    std::cout << "List 1 print reversed" << std::endl;
    llist1.printReversed();


    return 0;
}
