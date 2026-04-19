void dfs1(int node, int visited[], int graph[105][105], int n, int stack[], int* top) {
    visited[node] = 1;
    for(int i = 0; i < n; i++) {
        if(graph[node][i] && !visited[i])
            dfs1(i, visited, graph, n, stack, top);
    }
    stack[(*top)++] = node;
}

void dfs2(int node, int visited[], int rev[105][105], int n) {
    visited[node] = 1;
    for(int i = 0; i < n; i++) {
        if(rev[node][i] && !visited[i])
            dfs2(i, visited, rev, n);
    }
}
