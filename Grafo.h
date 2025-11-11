#ifndef GRAFO_H
#define GRAFO_H

template <typename T>
class Grafo {
    private:
        int n; //capacidad maxina
        int count; //nodos usados
        T* vertices;
        int** matrix;
        bool* visited;
        int indexOf(const T& v) const;
    public:
        //constructor 
        Grafo(int capacity): n(capacity), count(0) {
            vertices = new T[n];
            matrix = new int*[n];
            visited = new bool[n];
            for (int i=0; i < n; i++) {
                matrix[i] = new int[n];
                visited[i] = false;
                for (int j = 0;j <n; j++) {
                    matrix[i][j] = 0;


                }
            }
        }
        //destructor
        ~Grafo() {
            for (int i=0; i<n; i++) {
                delete[] matrix[i];
            }
                delete[] matrix;
                delete[] vertices;
            
        }

        //agregar vertice
        bool addVertex(const T& v);
        bool addEdge(const T& u, const T& v, int weight= 1, bool directed = false);
        void printMatrix() const;
        void DFS(const T& start);
        void BFS(const T& start);
        void resetVisited();


};

#include "Grafo.tpp"
#endif //GRAFO_H