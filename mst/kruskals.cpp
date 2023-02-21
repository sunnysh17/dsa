#include <iostream>
#include <algorithm>
using namespace std;

// structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// function to find the subset of an element i
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// function to perform union of two subsets x and y
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// function to compare two edges based on their weight
int compare(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight > edge2->weight;
}

// function to perform Kruskal's algorithm
void KruskalMST(Edge edges[], int V, int E) {
    // sort the edges in non-decreasing order by their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // create a subset for each vertex
    Subset* subsets = new Subset[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // initialize result to store the minimum spanning tree
    Edge* result = new Edge[V - 1];
    int i = 0, e = 0;

    // iterate over all the edges in non-decreasing order
    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];

        // check if including the edge in the result will create a cycle
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (i = 0; i < e; i++) {
        cout << result[i].src << " - " << result[i].dest << " (" << result[i].weight << ")" << endl;
    }
}

// driver function
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Edge edges[E];
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    KruskalMST(edges, V, E);

    return 0;
}
