#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << "Node " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices);

    cout << "Enter the edges in the format \"u v\":\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    printGraph(graph);

    return 0;
}
