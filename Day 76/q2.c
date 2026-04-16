struct Node* visited[105];

struct Node* clone(struct Node* node) {
    if(node == NULL)
        return NULL;

    if(visited[node->val] != NULL)
        return visited[node->val];

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = node->val;
    newNode->numNeighbors = node->numNeighbors;
    newNode->neighbors = malloc(node->numNeighbors * sizeof(struct Node*));

    visited[node->val] = newNode;

    for(int i = 0; i < node->numNeighbors; i++) {
        newNode->neighbors[i] = clone(node->neighbors[i]);
    }

    return newNode;
}

struct Node *cloneGraph(struct Node *s) {
    for(int i = 0; i < 105; i++)
        visited[i] = NULL;
    return clone(s);
}
