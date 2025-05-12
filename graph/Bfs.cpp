#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);  // Visited array
        vis[0] = 1;             //Marks node 0 as visited because BFS starts from 0.

        queue<int> q;
        q.push(0);               //Pushes node 0 into the queue because BFS starts from 0.
        vector<int> bfs;

        while (!q.empty()) {
            int node = q.front();  //Extracts the front node from the queue (q.front()).
            q.pop();               //Removes that node from the queue (q.pop()).
            bfs.push_back(node);   //Adds the current node to the BFS result.

            for (auto it : adj[node]) {
                if (!vis[it]) {     //Checks if the neighbor it is unvisited.
                    vis[it] = 1;    //Marks it as visited (vis[it] = 1).
                    q.push(it);     //Pushes it into the queue so it will be processed later.
                }
            }
        }
        return bfs;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v) format:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);  // For undirected graph
    }

    Solution obj;
    vector<int> bfsResult = obj.bfsOfGraph(V, adj);

    // Printing BFS Traversal
    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
