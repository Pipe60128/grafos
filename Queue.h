#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

template <typename T>
class Queue{
    private:
        Node<T>* topNode;
        Node<T>* tailNode;
        unsigned int count;
    public:
        Queue(): topNode(nullptr),tailNode(nullptr), count(0) {}
        ~Queue(){
            while(topNode){
                Node<T>* temp = topNode;
                topNode = topNode->next;
                delete temp;
            }
        }
        void clear();
        T deQueue(); 
        void enQueue(const T& v); 
        bool isEmpty() const;
        bool isFull();
        void print();

};
#include "Queue.tpp"
#endif //QUEUE_H