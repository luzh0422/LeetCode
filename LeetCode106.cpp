//
// Created by luzehui on 2024/2/21.
//

#include "LeetCode106.h"

TreeNode *LeetCode106::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size() - 1;
    return buildTree(inorder, postorder, 0, n, 0, n);
}

TreeNode *LeetCode106::buildTree(vector<int> &inorder, vector<int> &postorder, int inorderstart, int inorderend, int postorderstart, int postorderend) {
    if (postorderstart > postorderend) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(postorder[postorderend]);
    int count = 0;
    for (int i = inorderstart; i <= inorderend; i++) {
        if (inorder[i] == postorder[postorderend]) {
            break;
        }
        count++;
    }
    root->left = buildTree(inorder, postorder, inorderstart, inorderstart + count - 1, postorderstart, postorderstart + count - 1);
    root->right = buildTree(inorder, postorder, inorderstart + count + 1, inorderend, postorderstart + count, postorderend - 1);
    return root;
}
