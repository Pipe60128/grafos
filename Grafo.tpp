#pragma once
#include "Grafo.h"
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
            cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}