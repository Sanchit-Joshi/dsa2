#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Graph{
    public:
    vector<vector<int>> graph;

    void CreateGraph(int V){
        graph = vector<vector<int>>(V, vector<int>(V));
        for(int i=0 ; i<V;i++){
            for(int j =0; j<V;j++){
                cin>>graph[i][j];
            }
        }
    }

    int primMst(int V){
        int sum = 0;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> vis(V,0);
        vector<int> parent(V,-1);
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if(vis[node]) continue;
            vis[node] = true;
            sum += wt;
            for(int adjNode = 0; adjNode < V; adjNode++){
            if(graph[node][adjNode] && !vis[adjNode]){
            pq.push({graph[node][adjNode], adjNode});
            parent[adjNode] = node;
                }
            }
        }

        for(int i =1; i<V;i++){
            cout<<parent[i]<<" - "<<i<<endl;
        }
        return sum;
    }
};

int main(){
    Graph graph;
    cout<<"\nEnter Number of vertices in graph: ";
    int V;
    cin>>V;
    graph.CreateGraph(V);
    cout<<graph.primMst(V);

    return 0;
}