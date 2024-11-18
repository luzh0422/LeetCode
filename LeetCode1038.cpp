//
// Created by luzehui on 2023/12/4.
//

#include "LeetCode1038.h"

TreeNode *LeetCode1038::bstToGst(TreeNode *root) {
    bstToGst(root, 0);
    return root;
}

int LeetCode1038::bstToGst(TreeNode *root, int val) {
    if (root == nullptr) {
        return 0;
    }
    int currVal = val;
    if (root->right != nullptr) {
        currVal = bstToGst(root->right, val);
    }
    currVal += root->val;
    root->val = currVal;
    if (root->left != nullptr) {
        return bstToGst(root->left, currVal);
    }
    return currVal;
}
