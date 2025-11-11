#pragma once
#include "Queue.h"
#include "Node.h"
using namespace std;
#include <iostream>

template <typename T>
void Queue<T> :: clear(){
    Node<T>* current = topNode;
    while (current){
        Node<T>* next = current->next;
        delete current;
        current = next;
        --count;
    }
    topNode = nullptr;
    tailNode = nullptr;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}


template <typename T>
void Queue<T> :: enQueue(const T& v){
    Node<T>* newNode = new Node(v);
    if (!topNode){ 
        topNode = tailNode = newNode;
    } else {
    Node<T>* newNode = new Node(v);
    tailNode->next = newNode;
    tailNode = newNode; 
    }
    ++count;
}

template <typename T>
T Queue<T>::deQueue(){
    if (isEmpty()) {
        throw runtime_error("Queue is empty!");
    }

    Node<T>* temp = topNode;
    T value = temp->data;
    topNode = topNode->next;
    delete temp;
    --count;
/**
    if (topNode == nullptr) {
        tailNode = nullptr; 
    } */

    return value;
}

template <typename T>
void Queue<T> :: print() {
    if (isEmpty()) {
            cout<< "lista vacia" << endl;
        } else {
            const Node<T>* current = topNode;
            cout<<"[";
            while (current) {
                cout<<" "<<current->data<<" ->";
                current = current->next;
            }
            cout<<"]"<<endl;
        }
}



