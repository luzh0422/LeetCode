//
// Created by luzh on 2021/5/10.
//

#include "Solution872.h"

bool Solution872::leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> root1Arr = {};
    dfs(root1, root1Arr);
    vector<int> root2Arr = {};
    dfs(root2, root2Arr);
    return root1Arr == root2Arr;
}

void Solution872::dfs(TreeNode *root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        arr.push_back(root->val);
        return;
    }
    if (root->left != nullptr) {
        dfs(root->left, arr);
    }
    if (root->right != nullptr) {
        dfs(root->right, arr);
    }
    return;
}
