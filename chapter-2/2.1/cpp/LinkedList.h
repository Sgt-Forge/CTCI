#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList(Node<T>* head);
    ~LinkedList();

    Node<T>* getHead();
    Node<T>* getTail();
    void append(Node<T>* node);
    Node<T>* pop();
};

#endif