//
// Created by luzh on 2021/11/18.
//

#include "Solution563.h"

int Solution563::findTilt(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int leftTilt = findTilt(root->left);
    int rightTilt = findTilt(root->right);
    int ans = abs(sum(root->left) - sum(root->right));
    ans += leftTilt + rightTilt;
    return ans;
}

int Solution563::sum(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    if (sums.count(root)) {
        return sums[root];
    }
    int ans = root->val + sum(root->left) + sum(root->right);
    sums[root] = ans;
    return ans;
}
