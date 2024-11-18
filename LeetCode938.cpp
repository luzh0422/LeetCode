//
// Created by luzehui on 2024/2/26.
//

#include "LeetCode938.h"

int LeetCode938::rangeSumBST(TreeNode *root, int low, int high) {
    int res = 0;
    if (!root) {
        return res;
    }
    if (low <= root->val && root->val <= high) {
        res += root->val;
        res += rangeSumBST(root->left, low, high);
        res += rangeSumBST(root->right, low, high);
    } else  if (root->val > high) {
        res += rangeSumBST(root->left, low, high);
    } else  if (low > root->val) {
        res += rangeSumBST(root->right, low, high);
    }
    return res;
}
