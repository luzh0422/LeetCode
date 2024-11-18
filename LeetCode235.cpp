//
// Created by luzehui on 2024/2/27.
//

#include "LeetCode235.h"
#include <algorithm>

TreeNode *LeetCode235::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int minVal = std::min(p->val, q->val);
    int maxVal = std::max(p->val, q->val);
    return lowestCommonAncestor(root, minVal, maxVal);
}

TreeNode *LeetCode235::lowestCommonAncestor(TreeNode *root, int minVal, int maxVal) {
    if (!root) {
        return nullptr;
    }
    if (minVal <= root->val && root->val <= maxVal) {
        return root;
    }
    if (root->val > minVal) {
        return lowestCommonAncestor(root->left, minVal, maxVal);
    }
    return lowestCommonAncestor(root->right, minVal, maxVal);
}
