//
// Created by luzehui on 2024/2/10.
//

#include "LeetCode94.h"

vector<int> LeetCode94::inorderTraversal(TreeNode *root) {
    vector<int> res;
    inorderTraversal(root, res);
    return res;
}

void LeetCode94::inorderTraversal(TreeNode *root, vector<int> &res) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
}
