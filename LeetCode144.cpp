//
// Created by luzehui on 2024/2/11.
//

#include "LeetCode144.h"

vector<int> LeetCode144::preorderTraversal(TreeNode *root) {
    vector<int> res;
    preorderTraversal(root, res);
    return res;
}

void LeetCode144::preorderTraversal(TreeNode *root, vector<int> &res) {
    if (!root)
        return;
    res.push_back(root->val);
    preorderTraversal(root->left, res);
    preorderTraversal(root->right, res);
}
