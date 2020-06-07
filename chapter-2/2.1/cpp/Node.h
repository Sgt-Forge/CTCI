#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
    private:
        T data;
        Node* next;

    public:
        Node(T data, Node* next);
        ~Node();

        T getData();
        Node* getNext();
        void setData(T data);
        void setNext(Node* next);
};

#endif