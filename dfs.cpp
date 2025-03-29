#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // Helper DFS function
    void dfsUtil(int node, vector<int> adj[], vector<int>& vis, vector<int>& ls) {
        vis[node] = 1;  // Mark the node as visited
        ls.push_back(node);  // Store the node in the traversal result

        // Traverse all its neighbors
        for (auto it : adj[node]) {
            if (!vis[it]) {  // If the neighbor is not visited, recursively call DFS
                dfsUtil(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfs(int V, vector<int> adj[], int start) {
        vector<int> vis(V, 0);  // Visited array initialized to 0 (unvisited)
        vector<int> ls;  // Stores the DFS traversal result

        dfsUtil(start, adj, vis, ls);  // Call helper DFS function

        return ls;  // Return the final DFS traversal
    }
};

// Driver Code
int main() {
    int V, E, start;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    
    vector<int> adj[V];  // Adjacency list representation of the graph
    cout << "Enter edges (u v) (0-based index):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }
    
    cout << "Enter starting node: ";
    cin >> start;
    
    Solution obj;
    vector<int> dfsResult = obj.dfs(V, adj, start);

    // Print the DFS traversal
    cout << "DFS Traversal: ";
    for (auto node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}