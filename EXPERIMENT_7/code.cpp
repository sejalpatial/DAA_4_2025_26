#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k) {

        vector<vector<pair<int,int>>> adj(n); //O(V)
        for(auto f:flights){    //O(E)
            adj[f[0]].push_back({f[1],f[2]});
        }
        vector<int>cost(n, INT_MAX); //O(V)
        cost[src]=0;
        queue<pair<int, pair<int,int>>>q;
        q.push({src,{0, 0}});

        while(!q.empty()){ //O(K*V)
            auto front=q.front();
            q.pop();

            int node=front.first;
            int currCost=front.second.first;
            int stops=front.second.second;

            if(stops>k) continue;

            for(auto it : adj[node]){
                int next = it.first;
                int price = it.second;

                if(currCost + price < cost[next]){
                    cost[next] = currCost + price;
                    q.push({next, {cost[next], stops + 1}});
                }
            }
        }

        if(cost[dst] == INT_MAX) return -1;
        return cost[dst];
    }
};

int main() {
    Solution obj;

    int n = 4;
    vector<vector<int>>flights={
        {0,1,100},
        {1,2,100},
        {2,3,100},
        {0,2,500}
    };

    int src=0;
    int dst=3;
    int k=1;

    int result = obj.findCheapestPrice(n, flights, src, dst, k);// O(E * K)
    cout << "Cheapest Price: " << result << endl;
    return 0;
}
//TIME COMPLEXITY O(E*K)
//SPACE COMPLEXITY O(V+E)