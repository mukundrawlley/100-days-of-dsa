int parent[1005];

int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa != pb)
        parent[pa] = pb;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    static int ans[2];
    *returnSize = 2;

    for(int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if(find(u) == find(v)) {
            ans[0] = u;
            ans[1] = v;
            return ans;
        }

        unionSet(u, v);
    }

    return ans;
}
