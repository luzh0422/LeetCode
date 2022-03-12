//
// Created by luzh on 2021/4/27.
//

#include "Solution938.h"

int Solution938::rangeSumBST(TreeNode *root, int low, int high) {
    int sum = 0;
    rangeSumBST(root, low, high, sum);
    return sum;
}

void Solution938::rangeSumBST(TreeNode *root, int low, int high, int &sum) {
    if (root == nullptr) {
        return;
    }
    if (root->val == low) {
        sum += root->val;
        rangeSumBST(root->right, low, high, sum);
    } else if (root->val == high) {
        sum += root->val;
        rangeSumBST(root->left, low, high, sum);
    } else if (root->val > low && root->val < high) {
        sum += root->val;
        rangeSumBST(root->left, low, high, sum);
        rangeSumBST(root->right, low, high, sum);
    } else if (root->val > high) {
        rangeSumBST(root->left, low, high, sum);
    } else if (root->val < low) {
        rangeSumBST(root->right, low, high, sum);
    }
}
