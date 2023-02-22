#include <iostream>
using namespace std;

const int MAX = 100;

class Graph {
    int V;
    int matrix[MAX][MAX];
public:
    Graph(int v) {
        V = v;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest) {
        matrix[src][dest] = 1;
        matrix[dest][src] = 1;
    }

    void printMatrix() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printMatrix();
    return 0;
}
