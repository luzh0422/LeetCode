//
// Created by luzh on 2021/4/25.
//

#include "Solution897.h"

TreeNode * Solution897::increasingBST(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }
    vector<int> ans = {};
    increasingBST(root, ans);
    TreeNode* res = new TreeNode(ans[0]);
    TreeNode* node = res;
    for (int i = 1; i < ans.size(); i++) {
        node->right = new TreeNode(ans[i]);
        node = node->right;
    }
    return res;
}

void Solution897::increasingBST(TreeNode *root, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }
    increasingBST(root->left, ans);
    ans.push_back(root->val);
    increasingBST(root->right, ans);
    return;
}
