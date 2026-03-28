void flatten(struct TreeNode* root) {
    if(root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    root->left = NULL;
    root->right = left;

    struct TreeNode* curr = root;
    while(curr->right != NULL)
        curr = curr->right;

    curr->right = right;
}
