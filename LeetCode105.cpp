//
// Created by luzehui on 2024/2/20.
//

#include "LeetCode105.h"

TreeNode *LeetCode105::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size() - 1;
    return buildTree(preorder, inorder, 0, n, 0, n);
}

TreeNode *LeetCode105::buildTree(vector<int> &preorder, vector<int> &inorder, int preorderstart, int preorderend, int inorderstart, int inorderend) {
    if (preorderstart > preorderend) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[preorderstart]);
    int count = 0;
    for (int i = inorderstart; i <= inorderend; i++) {
        if (inorder[i] == preorder[preorderstart]) {
            break;
        }
        count++;
    }
    root->left = buildTree(preorder, inorder, preorderstart + 1, preorderstart + count, inorderstart, inorderstart + count);
    root->right = buildTree(preorder, inorder, preorderstart + 1 + count, preorderend, inorderstart + 1 + count, inorderend);
    return root;
}
