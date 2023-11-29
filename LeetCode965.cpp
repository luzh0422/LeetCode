//
// Created by 陆泽辉 on 2022/5/24.
//

#include "LeetCode965.h"

bool LeetCode965::isUnivalTree(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    if (root->left != nullptr && root->val != root->left->val) {
        return false;
    }
    if (root->right != nullptr && root->val != root->right->val) {
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
