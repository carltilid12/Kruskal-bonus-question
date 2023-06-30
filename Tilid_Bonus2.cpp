#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> getEdges(const std::vector<std::vector<bool>>& graph) {
    std::vector<std::pair<int, int>> edges;
    int n = graph.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) {
                edges.push_back(std::make_pair(i+1, j+1));
            }
        }
    }

    return edges;
}

int countEdges(const std::vector<std::vector<bool>>& graph) {
    int numEdges = 0;
    int n = graph.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) {
                numEdges++;
            }
        }
    }

    return numEdges;
}

int main() {
    // 1->(2,4), 2->5, 3->1, 4->(3,6,7), 5->(3,8), 6->3, 7->8, 8->(6,10), 9->7, 10->9 first values being vertices having directed edges(2nd values)
    std::vector<std::vector<bool>> graph = {
        {false, true, false, true, false, false, false, false, false, false},
        {false, false, false, false, true, false, false, false, false, false},
        {true, false, false, false, false, false, false, false, false, false},
        {false, false, true, false, false, true, true, false, false, false},
        {false, false, true, false, false, false, false, true, false, false},
        {false, false, true, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, true, false, false},
        {false, false, false, false, false, true, false, false, false, true},
        {false, false, false, false, false, false, true, false, false, false},
        {false, false, false, false, false, false, false, false, true, false}
    };

    std::vector<std::pair<int, int>> edges = getEdges(graph);

    // Print the edges
    std::cout << "Edges:" << std::endl;
    for (const auto& edge : edges) {
        std::cout << edge.first << " -> " << edge.second << std::endl;
    }

        // Call the function to count edges
    int edgeCount = countEdges(graph);
    std::cout << "Number of edges: " << edgeCount << std::endl;

    return 0;
}