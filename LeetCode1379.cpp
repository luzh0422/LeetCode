//
// Created by luzehui on 2024/4/3.
//

#include "LeetCode1379.h"

TreeNode *LeetCode1379::getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
    if (!cloned) {
        return cloned;
    }
    if (cloned->val == target->val) {
        return cloned;
    }
    auto leftNode = getTargetCopy(original, cloned->left, target);
    if (leftNode) {
        return leftNode;
    }
    auto rightNode = getTargetCopy(original, cloned->right, target);
    if (rightNode) {
        return rightNode;
    }
    return nullptr;
}
