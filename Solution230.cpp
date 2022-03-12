//
// Created by luzh on 2021/10/17.
//

#include "Solution230.h"

int Solution230::kthSmallest(TreeNode *root, int k) {
    vector<int> rootVals = {};
    kthSmallest(root, rootVals);
    return rootVals[k - 1];
}

void Solution230::kthSmallest(TreeNode *root, vector<int> &rootVals) {
    if (root == nullptr) {
        return;
    }
    kthSmallest(root->left, rootVals);
    rootVals.push_back(root->val);
    kthSmallest(root->right, rootVals);
}
