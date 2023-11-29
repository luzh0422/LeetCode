//
// Created by 陆泽辉 on 2023/8/25.
//

#include "LeetCode1448.h"
#define INT_MIN 0xffffffff

int LeetCode1448::goodNodes(TreeNode *root) {
    return goodNodes(root, INT_MIN);
}

int LeetCode1448::goodNodes(TreeNode *root, int currMaxVal) {
    if (root == nullptr) {
        return 0;
    }
    int res = 0;
    if (root->val >= currMaxVal) {
        currMaxVal = root->val;
        res = 1;
    }
    res += goodNodes(root->left, currMaxVal);
    res += goodNodes(root->right, currMaxVal);
    return res;
}

