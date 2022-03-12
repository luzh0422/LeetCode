//
// Created by luzh on 2021/11/26.
//

#include "Solution700.h"

TreeNode * Solution700::searchBST(TreeNode *root, int val) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->val == val) {
        return root;
    } else if (root->val > val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}
