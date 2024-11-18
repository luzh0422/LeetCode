//
// Created by luzehui on 2024/2/12.
//

#include "LeetCode145.h"

vector<int> LeetCode145::postorderTraversal(TreeNode *root) {
    vector<int> res;
    postorderTraversal(root, res);
    return res;
}

void LeetCode145::postorderTraversal(TreeNode *root, vector<int> &res) {
    if (!root)
        return;
    postorderTraversal(root->left, res);
    postorderTraversal(root->right, res);
    res.push_back(root->val);
}
