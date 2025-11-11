#include <iostream>
#include "Grafo.h"
using namespace std;


int main() {
    Grafo<string> g(6);
    g.addVertex("CDMX");
    g.addVertex("GDL");
    g.addVertex("MTY");
    g.addVertex("PUE");
    g.addVertex("QRO");
    g.addVertex("TOL");
    g.addEdge("CDMX", "GDL");
    g.addEdge("GDL", "MTY");
    g.addEdge("CDMX", "PUE");
    g.addEdge("PUE", "QRO");
    g.addEdge("QRO", "TOL");
    g.printMatrix();
    g.BFS("CDMX");
    g.resetVisited();
    g.DFS("CDMX");

    return 0;
}

