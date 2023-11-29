//
// Created by 陆泽辉 on 2023/9/18.
//

#include "LeetCode337.h"

int LeetCode337::rob(TreeNode *root) {
    unordered_map<TreeNode*, int> uM{};
    return max(rob(root, 0, uM), rob(root, 1, uM));
}

int LeetCode337::rob(TreeNode *root, int tag, unordered_map<TreeNode*, int>& uM) {
    if (root == nullptr) {
        return 0;
    }
    if (tag == 0) {
        /**
         * 不取当前节点；
         */
        if (uM.count(root)) {
            return uM[root];
        }
        uM[root] = max(rob(root->left, 1, uM), rob(root->left, 0, uM)) + max(rob(root->right, 1, uM), rob(root->right, 0, uM));
        return uM[root];
    } else {
        /*
         * 取当前节点；
         */
        return rob(root->left, 0, uM) + rob(root->right, 0, uM) + root->val;
    }
}
