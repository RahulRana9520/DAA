#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {         // Intermediate node
        for (int i = 0; i < V; i++) {     // Source node
            for (int j = 0; j < V; j++) { // Destination node
                // Check if path i -> k and k -> j exist
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    // Check for shorter path through vertex k
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    // Initialize the distance matrix
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    // Distance from node to itself is 0
    for (int i = 0; i < V; i++)
        dist[i][i] = 0;

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    floydWarshall(dist, V);

    // Output result
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
