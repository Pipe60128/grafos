#pragma once
#include "Grafo.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;

template <typename T>
int Grafo<T>:: indexOf(const T& v) const {
    for (int i =0; i<count; i++) {
        if (vertices[i] == v) {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool Grafo<T>:: addVertex(const T& v) {
    if (count >= n) {
        return false; //grafo lleno
    }
    if (indexOf(v) != -1) {
        return false; //el vertice ya existe
    }
    vertices[count++] = v;
    return true;
}

template <typename T>
bool Grafo<T>:: addEdge(const T& u, const T& v, int weight, bool directed) {
    int iu = indexOf(u);
    int iv = indexOf(v);
    if (iu == -1 || iv == -1) return false;
    matrix[iu][iv] = weight;
    if (!directed) matrix[iv][iu] = weight;
    return true;
    

}

template <typename T>
void Grafo<T>:: printMatrix() const {
    cout<<"------MATRIZ------"<<endl;
    for (int i = 0; i < count; i++) {
        cout << vertices[i] << " ";
    }
    cout<<"\n";
    for(int i  = 0; i < count; i++ ){
        cout << vertices[i] << " ";
        for (int j =0 ; j < count; j++){
            cout<<" "<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

template <typename T>
void Grafo<T>:: resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
}

template <typename T>
void Grafo<T>:: BFS(const T& start) {
    int startIndex = indexOf(start);
    if (startIndex == -1) {
        cout << "Nodo inical no encontrado" << endl;
        return;
    }

    Queue<int> q;
    visited[startIndex] = true;
    q.enQueue(startIndex);
    while (!q.isEmpty()) {
        int Index = q.deQueue();
        cout <<"  indice"<<Index<<"->  ";
        cout << vertices[Index] << "->";
        for (int neiIndex = 0; neiIndex < count; neiIndex++) {
            if (matrix[Index][neiIndex] != 0 && !visited[neiIndex] ){
                visited[neiIndex] = true;
                q.enQueue(neiIndex);
            }
        }
    }
    cout<<endl;

}

template <typename T>
void Grafo<T>:: DFS(const T& start) {
    int startIndex = indexOf(start);
    if (startIndex == -1) {
        cout << "Nodo inical no encontrado" << endl;
        return;
    }

    Stack<int> s;
    visited[startIndex] = true;
    s.push(startIndex);
    while (!s.isEmpty()) {
        int Index = s.pop();
        cout << vertices[Index] << "->";
        for (int neiIndex = 0; neiIndex < count; neiIndex++) {
            if (matrix[Index][neiIndex] != 0 && !visited[neiIndex] ){
                visited[neiIndex] = true;
                s.push(neiIndex);
            }
        }
    }
    cout<<endl;

}
