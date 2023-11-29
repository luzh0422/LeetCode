//
// Created by 陆泽辉 on 2023/2/6.
//

#include "LeetCode2331.h"

bool LeetCode2331::evaluateTree(TreeNode *root) {
    bool leftVal, rightVal;
    if (root->left) {
        if (root->left->val > 1) {
            leftVal = evaluateTree(root->left);
        } else {
            leftVal = root->left->val == 0 ? false : true;
        }
    }
    if (root->right) {
        if (root->right->val > 1) {
            rightVal = evaluateTree(root->right);
        } else {
            rightVal = root->right->val == 0 ? false : true;
        }
    }
    if (root->val == 2) {
        return leftVal | rightVal;
    } else if (root->val == 3) {
        return leftVal & rightVal;
    } else {
        return root->val;
    }
}
