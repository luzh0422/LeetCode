//
// Created by luzehui on 2024/3/12.
//

#include "LeetCode1261.h"

FindElements::FindElements(TreeNode *root) {
    root->val = 0;
    reconstructorTree(root);
}

void FindElements::reconstructorTree(TreeNode *root) {
    uS.insert(root->val);
    if (root->left) {
        root->left->val = root->val * 2 + 1;
        reconstructorTree(root->left);
    }
    if (root->right) {
        root->right->val = root->val * 2 + 2;
        reconstructorTree(root->right);
    }
}

bool FindElements::find(int target) {
    return uS.count(target);
}
