#include <bits/stdc++.h>
using namespace std;

int n = 5;
vector<vector<int>> adj = {
    {1, 3},
    {0, 2, 3, 4},
    {1, 4},
    {0, 1, 4},
    {1, 2, 3}
};

vector<bool> visited(n, false);
vector<int> path;

bool hasEdge(int u, int v) {
    for (int x : adj[u]) {
        if (x == v) return true;
    }
    return false;
}

bool solve(int u, int count) {
    if (count == n) {
        return hasEdge(u, path[0]); 
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            path.push_back(v);

            if (solve(v, count + 1))
                return true;

            visited[v] = false;  
            path.pop_back();
        }
    }
    return false;
}

int main() {
    visited[0] = true;
    path.push_back(0);

    if (solve(0, 1)) {
        for (int x : path)
            cout << x << " ";
        cout << path[0]; // closing cycle
    } else {
        cout << "No Hamiltonian Cycle";
    }
    return 0;
}