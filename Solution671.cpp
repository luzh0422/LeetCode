//
// Created by luzh on 2021/7/27.
//

#include "Solution671.h"
#include <algorithm>

int Solution671::findSecondMinimumValue(TreeNode *root) {
    if (root->left == nullptr || root->right == nullptr) {
        return -1;
    }
    if (root->left->val == root->right->val) {
        int leftSecondMinVal = findSecondMinimumValue(root->left);
        int rightSecondMinVal = findSecondMinimumValue(root->right);
        if (leftSecondMinVal == -1 && rightSecondMinVal == -1) {
            return -1;
        } else if (leftSecondMinVal != -1 && rightSecondMinVal != -1) {
            return std::min(leftSecondMinVal, rightSecondMinVal);
        } else if (leftSecondMinVal != -1) {
            return leftSecondMinVal;
        } else {
            return rightSecondMinVal;
        }
    } else if (root->left->val > root->right->val) {
        int rightSecondMinVal = findSecondMinimumValue(root->right);
        if (rightSecondMinVal != -1) {
            return std::min(root->left->val, rightSecondMinVal);
        } else {
            return root->left->val;
        }
    } else {
        int leftSecondMinVal = findSecondMinimumValue(root->left);
        if (leftSecondMinVal != -1) {
            return std::min(root->right->val, leftSecondMinVal);
        } else {
            return root->right->val;
        }
    }
}
