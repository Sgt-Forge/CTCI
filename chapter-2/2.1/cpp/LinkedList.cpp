#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList(Node<T>* head){
    this->head = head;
}

template <class T>
Node<T>* LinkedList<T>::getHead(){ return this->head; }


template <class T>
Node<T>* LinkedList<T>::getTail(){
    Node* curr = this->head;
    while(curr->getNext()){
        curr = curr->getNext();
    }

    return curr;
}

template <class T>
void LinkedList<T>::append(Node<T>* node){
    Node* curr = this->head;
    while(curr->getNext()){
        curr = curr->getNext();
    }

    curr->setNext(node);
    this->tail = node;
}

template <class T>
Node<T>* LinkedList<T>::pop(){}