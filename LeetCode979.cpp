//
// Created by 陆泽辉 on 2023/7/14.
//

#include "LeetCode979.h"
#include <algorithm>

int LeetCode979::distributeCoins(TreeNode *root) {
    getSum(root);
    return sum;
}

int LeetCode979::getSum(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int left = getSum(root->left);
    int right = getSum(root->right);
    sum += std::abs(left) + std::abs(right); // 左子树节点和右子树节点，多余的金币量；

    return root->val + left + right - 1; // 返回节点多余的金币量；
}
