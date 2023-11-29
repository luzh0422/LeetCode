//
// Created by 陆泽辉 on 2023/5/30.
//

#include "LeetCode1110.h"

vector<TreeNode *> LeetCode1110::delNodes(TreeNode *root, vector<int> &to_delete) {
    unordered_set<int> cache(to_delete.begin(), to_delete.end());
    vector<TreeNode*> res;
    delNodes(root, nullptr, cache, res, -1);
    return res;
}

void LeetCode1110::delNodes(TreeNode *root, TreeNode *parent, unordered_set<int> &cache, vector<TreeNode *> &res, int direction) {
    if (cache.count(root->val)) {
        if (parent != nullptr) {
            if (direction == 0) {
                parent->left = nullptr;
            } else if (direction == 1) {
                parent->right = nullptr;
            }
        }
        if (root->left) {
            delNodes(root->left, nullptr, cache, res, 0);
        }
        if (root->right) {
            delNodes(root->right, nullptr, cache, res, 1);
        }
    } else {
        if (parent == nullptr) {
            res.push_back(root);
        }
        if (root->left) {
            delNodes(root->left, root, cache, res, 0);
        }
        if (root->right) {
            delNodes(root->right, root, cache, res, 1);
        }
    }
}
