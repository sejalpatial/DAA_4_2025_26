class Solution {
  public:
    vector<int>path;
    
    bool solve(int u,int cnt,vector<vector<int>>&edges,vector<int>&visited,int n)
    {
        if(cnt==n)
        {
            return true;
        }
        for(auto x:edges[u])
        {
            if(visited[x]==0)
            {
                path.push_back(x);
                visited[x]=1;
                if(solve(x,cnt+1,edges,visited,n))
                {
                    return true;
                }
                visited[x]=0;
                path.pop_back();
                
            }
        }return false;
    };
  
    
    bool check(int n, int m, vector<vector<int>> edges) {
        vector<vector<int>> adj(n+1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // code here
        for(int i=0;i<n;i++)
         {  vector<int>visited(n+1,0);
            path.clear();
            visited[i]=1;
            path.push_back(i);
            if(solve(i,1,adj,visited,n))
            {
                return true;
            }
            
        }return false;
        
    }
};
