// Carl Christian G. Tilid
/* Construct a minimum cost spanning tree for Figure 2 using either Kruskal’s or Prim’s
algorithm. Show the progress of the construction of the tree. Indicate which edges are added in
every step.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to find the parent of a vertex using the union-find algorithm
int findParent(vector<int>& parent, int vertex) {
    if (parent[vertex] != vertex)
        parent[vertex] = findParent(parent, parent[vertex]);
    return parent[vertex];
}

// Function to perform union of two sets using the union-find algorithm
void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int root_u = findParent(parent, u);
    int root_v = findParent(parent, v);

    if (rank[root_u] < rank[root_v])
        parent[root_u] = root_v;
    else if (rank[root_u] > rank[root_v])
        parent[root_v] = root_u;
    else {
        parent[root_v] = root_u;
        rank[root_u] += 1;
    }
}

// Function to find the minimum cost spanning tree using Kruskal's algorithm
vector<Edge> kruskal(vector<Edge>& edges, int numVertices) {
    // Sort edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<Edge> minimumSpanningTree;
    vector<int> parent(numVertices + 1); // Increase the size by 1 to handle 1-based vertices
    vector<int> rank(numVertices + 1, 0);

    // Initialize parent array for union-find
    for (int i = 1; i <= numVertices; ++i)
        parent[i] = i;

    // Main loop of Kruskal's algorithm
    for (const Edge& edge : edges) {
        int src = edge.src;
        int dest = edge.dest;

        // Check if adding the edge creates a cycle
        if (findParent(parent, src) != findParent(parent, dest)) {
            minimumSpanningTree.push_back(edge);
            unionSets(parent, rank, src, dest);
        }
    }

    return minimumSpanningTree;
}

int main() {
    int numVertices = 8; // Number of vertices in the graph

    // Given list of edges (src edge weight)
    vector<Edge> edges = {
        {3, 7, 1},
        {1, 2, 2},
        {3, 4, 3},
        {4, 7, 5},
        {2, 6, 6},
        {1, 6, 8},
        {2, 3, 10},
        {6, 7, 11},
        {3, 6, 12},
        {7, 8, 15},
        {4, 8, 20},
        {1, 5, 22},
        {5, 6, 25}
    };

    vector<Edge> minimumSpanningTree = kruskal(edges, numVertices);

    cout << "The minimum cost spanning tree contains the following edges:\n";
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.src << " -- " << edge.dest << " (Weight: " << edge.weight << ")\n";
    }

    return 0;
}