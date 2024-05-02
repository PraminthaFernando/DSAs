#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int destination;
    int weight;
};

// Implementation of Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int startVertex) {
    int vertexCount = graph.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> EdgeQ; // Store Edges using a Priority Queue

    vector<int> key(vertexCount, INT_MAX); // Vector to store the distance of neighbor in the MST of each vertex

    vector<int> parent(vertexCount, -1); // Vector to store the parent of each vertex in the MST

    vector<bool> inPath(vertexCount, false); // A vector to store whether a vertex is included in the MST

    // Insert the start vertex into the priority queue and set distance itself to 0
    EdgeQ.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!EdgeQ.empty()) {
        int u = EdgeQ.top().second;
        EdgeQ.pop();

        inPath[u] = true;

        // Traverse all adjacent vertices of vertices in the vertices list
        for (auto& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // Update parent vertices and distances of vertices
            if (!inPath[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                EdgeQ.push(make_pair(key[v], v));
            }
        }
    }

    int cost = 0;

    // Display Edges and Weights of MST
    cout << "Minimum Spanning Tree" << endl;
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < vertexCount; ++i) {
        cout << parent[i] << " - " << i << " \t  " << key[i] << endl;
        cost = cost + key[i];
    }
    // Display the Total cost of MST
    cout << "Cost of the minimum spanning tree: " << cost << endl;

}

int main() {
    int vertexCount = 6;

    // A vector of vectors to represent the graph
    vector<vector<Edge>> graph(vertexCount);

    //Add edges and weights to the graph
    graph[0].push_back({1, 3});
    graph[0].push_back({5, 1});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[1].push_back({4, 10});
    graph[2].push_back({3, 3});
    graph[2].push_back({5, 5});
    graph[3].push_back({4, 5});
    graph[4].push_back({5, 4});
    
    // Start Node
    int startVertex = 0;

    primMST(graph, startVertex);

    return 0;
}
