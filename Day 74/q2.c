struct Node {
    int vertex;
    struct Node* next;
};

void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;
    struct Node* temp = adj[node];

    while(temp != NULL) {
        if(!visited[temp->vertex])
            dfs(temp->vertex, adj, visited);
        temp = temp->next;
    }
}

int countComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    struct Node* adj[2005] = {NULL};
    int visited[2005] = {0};

    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }

    return count;
}
