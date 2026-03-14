int inorder(int* arr, struct TreeNode* root, int index) {
    if (root != NULL) {
        index = inorder(arr, root->left, index);
        arr[index++] = root->val;
        index = inorder(arr, root->right, index);
    }
    return index;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));
    *returnSize = inorder(arr, root, 0);
    return arr;
}
