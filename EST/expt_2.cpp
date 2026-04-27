class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto edge : edges) {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); 
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        
        pq.push({0,src});
        while(!pq.empty()) {
            auto top=pq.top();
            pq.pop();

            int dis=top.first;
            int node=top.second;

            if(dis>dist[node]) continue;

            for(auto it:adj[node]) {
                int adjNode=it.first;
                int weight=it.second;

                if(dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};