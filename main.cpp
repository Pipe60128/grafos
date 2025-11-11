#include <iostream>
#include "Grafo.h"
using namespace std;


int main() {
    Grafo<string> g(10);
    g.addVertex("CDMX");
    g.addVertex("GDL");
    g.addVertex("MTY");
    g.addVertex("PUE");
    g.addVertex("QRO");
    g.addVertex("TOL");
    g.addEdge("CDMX", "GDL");
    g.addEdge("TOL", "QRO");
    g.addEdge("GDL", "MTY");
    g.printMatrix();

    
    return 0;
}

