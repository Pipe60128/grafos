#include <iostream>
#include "Grafo.h"
using namespace std;


int main() {
    int m = 4;
    int n = 4;
    int matriz[m][n]= {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    for(int i = 0; i < m; i++) {
        cout<< i+1 << " |";
        for(int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}