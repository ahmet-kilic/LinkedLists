#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList
{
    public: // DO NOT CHANGE THIS PART.
        LinkedList();
        LinkedList(const LinkedList &obj);

        ~LinkedList();

        Node<T> *getFirstNode() const; //
        Node<T> *getHead() const;
        Node<T> *getTail() const;
        int getNumberOfNodes();
        bool isEmpty(); //

        void insertAtTheFront(const T &data); //
        void insertAtTheEnd(const T &data); //
        void insertAfterGivenNode(const T &data, Node<T> *prev); //

        void removeNode(Node<T> *node);
        void removeAllNodes();

        Node<T> *findNode(const T &data); //

        void printAllNodes();
        void printReversed();

        LinkedList &operator=(const LinkedList &rhs);

    private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

    private: // DO NOT CHANGE THIS PART.
        Node<T> *head;
        Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->prev = head;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    /* TODO */
    *this = obj;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    removeAllNodes();
    delete this->head;
    delete this->tail;
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if(head->next == tail) return NULL;
    else return head->next;
}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    /* TODO */
    return head;
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    /* TODO */
    return tail;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() 
{
    /* TODO */
    int i = 0;
    if(isEmpty()) return 0;
    else{
        Node<T> *current;
        current = head->next;
        while(current != tail){
            i++;
            current = current->next;
        }
    }
    return i;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    /* TODO */
    if(head->next == tail && tail->prev == head) return 1;
    return 0;
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data)
{
    /* TODO */
    if(head->next == tail){
        head->next = new Node<T>(data, head, tail);
        tail->prev = head->next;
    }
    else{
        Node<T> *tmp;
        tmp = new Node<T>(data, head, head->next);
        head->next->prev = tmp;
        head->next = tmp;
    }
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    /* TODO */
    if(head->next == tail){
        head->next = new Node<T>(data, head, tail);
        tail->prev = head->next;
    }
    else{
        Node<T> *tmp;
        tmp = new Node<T>(data, tail->prev, tail);
        tail->prev->next = tmp;
        tail->prev = tmp;
    }
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{   
    /* TODO */
    if(prev == NULL) return;
    prev->next = new Node<T>(data, prev, prev->next);
    prev->next->next->prev = prev->next;
} 

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    Node<T> *current;
    current = head->next->next;
    while(current != tail){
        if(current->next == tail){
            delete current->prev;
            delete current;
            break;
        }
        delete current->prev;
        current = current->next;
    }
    head->next = tail;
    tail->prev = head;
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    /* TODO */
    Node<T> *current = head->next;
    while(current != tail){
        if(data == current->element) return current;
        current = current->next;
    }
    return NULL;
}

template<class T>
void LinkedList<T>::printAllNodes()
{
    /* TODO */
    if(isEmpty()) return;
    else{
        Node<T> *current;
        current = head->next;
        while(current != tail){
            std::cout << current->element << std::endl;
            current = current->next;
        }
    }
}

template<class T>
void LinkedList<T>::printReversed()
{
    /* TODO */
    if(isEmpty()) return;
    else{
        Node<T> *current;
        current = tail->prev;
        while(current != head){
            std::cout << current->element << std::endl;
            current = current->prev;
        }
    }
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs)
{
    /* TODO */
    if(this != &rhs){
        removeAllNodes();
        if(rhs.getHead()->next == rhs.getTail()){
            this->tail->prev = head;
            this->head->next = tail;
        }
        else{
            Node<T> *rhs_current = rhs.getHead()->next;
            while(rhs_current != rhs.getTail()){
                insertAtTheEnd(rhs_current->element);
                rhs_current = rhs_current->next;
            }
        }
    }
    return *this;
}

#endif //LINKED_LIST_HPP
