bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[105];
    for(int i = 0; i < graphSize; i++)
        color[i] = -1;

    int queue[1000];

    for(int i = 0; i < graphSize; i++) {
        if(color[i] != -1)
            continue;

        int front = 0, rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while(front < rear) {
            int node = queue[front++];

            for(int j = 0; j < graphColSize[node]; j++) {
                int next = graph[node][j];

                if(color[next] == -1) {
                    color[next] = 1 - color[node];
                    queue[rear++] = next;
                }
                else if(color[next] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}
