#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, node, adj, vis)) return true;
        } else if (it != parent) {
            return true;
        }
    }
    return false;
}
