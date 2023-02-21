#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS function
void bfs(vector<vector<int>>& graph, int start) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        cout << currNode << " ";

        for (int neighbor : graph[currNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

// Driver code
int main() {
    int numNodes = 6;
    vector<vector<int>> graph(numNodes);

    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 3};
    graph[3] = {1, 2, 4, 5};
    graph[4] = {3};
    graph[5] = {3};

    bfs(graph, 0);

    return 0;
}
