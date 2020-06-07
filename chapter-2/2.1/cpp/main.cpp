#include <iostream>
#include "Node.h"

void append(Node* head, Node* next){
    Node* curr = head;
    while(curr->getNext() != NULL){
        curr = curr->getNext();
    }
    curr->setNext(next);
}

int main(int argc, char* argv[]){
    Node* head = new Node(0, NULL);
    Node* two = new Node(1, NULL);
    Node* thr = new Node(2, NULL);

    append(head, two);
    append(head, thr);

    Node* curr = head;
    while(curr->getNext() != NULL){
        std::cout << "[" << curr->getData() << "] -> " ;
        curr = curr->getNext();
    }
    std::cout << "[" << curr->getData() << "]\n";

    delete head;
    delete two;
    delete thr;

    return 0;
}