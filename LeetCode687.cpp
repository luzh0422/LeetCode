//
// Created by 陆泽辉 on 2022/9/2.
//

#include "LeetCode687.h"
#include <algorithm>

int LeetCode687::longestUnivaluePath(TreeNode *root) {
    /**
     * res用来存储链路上的最长值；
     */
    int res = 0;
    longestUnivaluePath(root, res);
    return res;
}

/**
 * 用于求解从根节点开始的最长链路；
 */
int LeetCode687::longestUnivaluePath(TreeNode *root, int &res) {
    if (root == nullptr) {
        return 0;
    }
    int left = longestUnivaluePath(root->left, res);
    int right = longestUnivaluePath(root->right, res);
    int left1 = 0, right1 = 0;
    if (root->left && root->left->val == root->val) {
        left1 = left + 1;
    }
    if (root->right && root->right->val == root->val) {
        right1 = right + 1;
    }
    res = std::max(res, left1 + right1);
    return std::max(left1, right1);
}

