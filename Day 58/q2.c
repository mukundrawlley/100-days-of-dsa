struct TreeNode* build(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if(inStart > inEnd)
        return NULL;

    int val = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = NULL;
    root->right = NULL;

    if(inStart == inEnd)
        return root;

    int index;
    for(index = inStart; index <= inEnd; index++) {
        if(inorder[index] == val)
            break;
    }

    root->left = build(preorder, inorder, inStart, index - 1, preIndex);
    root->right = build(preorder, inorder, index + 1, inEnd, preIndex);

    return root;
}
