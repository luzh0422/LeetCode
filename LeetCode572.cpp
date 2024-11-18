//
// Created by luzehui on 2024/8/4.
//

#include "LeetCode572.h"

bool LeetCode572::isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (isSametree(root, subRoot)) {
        return true;
    } else if (root->left && isSubtree(root->left, subRoot)) {
        return true;
    } else if (root->right && isSubtree(root->right, subRoot)) {
        return true;
    }
    return false;
}

bool LeetCode572::isSametree(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr && root2 != nullptr || root1 != nullptr && root2 == nullptr || root1->val != root2->val) {
        return false;
    }
    return isSametree(root1->left, root2->left) && isSametree(root1->right, root2->right);
}
