#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, 1e9);
        
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;
                if(d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int mx = -1;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1;
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};
