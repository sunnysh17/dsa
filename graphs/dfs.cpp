#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// DFS function using a stack
void dfs_stack(vector<vector<int>>& graph, int start) {
    stack<int> s;
    vector<bool> visited(graph.size(), false);

    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
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

    dfs_stack(graph, 0);

    return 0;
}
