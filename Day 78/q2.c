int timer;

void dfsAP(int node, int parent, int visited[], int disc[], int low[], int mark[], int adj[105][105], int n) {
    visited[node] = 1;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(int v = 0; v < n; v++) {
        if(adj[node][v] == 0)
            continue;

        if(v == parent)
            continue;

        if(!visited[v]) {
            dfsAP(v, node, visited, disc, low, mark, adj, n);
            if(low[v] < low[node])
                low[node] = low[v];

            if(low[v] >= disc[node] && parent != -1)
                mark[node] = 1;

            child++;
        }
        else {
            if(disc[v] < low[node])
                low[node] = disc[v];
        }
    }

    if(parent == -1 && child > 1)
        mark[node] = 1;
}
