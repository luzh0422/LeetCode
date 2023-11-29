//
// Created by 陆泽辉 on 2022/7/21.
//

#include "LeetCode814.h"

TreeNode *LeetCode814::pruneTree(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }
    auto left = pruneTree(root->left);
    auto right = pruneTree(root->right);
    if (left == nullptr && right == nullptr && root->val == 0) {
        return nullptr;
    }
    root->left = left;
    root->right = right;
    return root;
}
