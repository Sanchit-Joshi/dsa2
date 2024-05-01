#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Function to add an edge in an undirected graph.
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}


// Function to perform DFS on the graph
void DFS(vector<vector<int>>& adj, int v, int start) {
    vector<bool> visited(v, false);
    stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
        start = stack.top();
        stack.pop();

        if (!visited[start]) {
            cout << start << " ";
            visited[start] = true;
        }

        for (int i = 0; i < v; i++)
            if (adj[start][i] && !visited[i])
                stack.push(i);
}
}

// Function to perform BFS on the graph
void BFS(vector<vector<int>>& adj, int v, int start) {
    vector<bool> visited(v, false);
    queue<int> q;
    cout<<start<<" ";
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        start = q.front();
        q.pop();
        for (int i = 0; i < v; i++) {
            if (adj[start][i] == 1 && !visited[i]) {
                cout<<i<<" ";
                visited[i] = true;
                q.push(i);
            }
        }
    }
}


int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> adj[i][j];
        }
    }

    int start;
    cout << "Enter the starting node for DFS and BFS: ";
    cin >> start;

    cout << "DFS traversal starting from node " << start << ": ";
    DFS(adj, V, start);

    cout << "\nBFS traversal starting from node " << start << ": ";
    BFS(adj, V, start);

    return 0;
}