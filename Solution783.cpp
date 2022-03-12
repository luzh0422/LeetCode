//
// Created by luzh on 2021/4/13.
//

#include "Solution783.h"
#include <algorithm>

#define INT_MAX __INT_MAX__

int Solution783::minDiffInBST(TreeNode *root) {
    if (root == nullptr) return 0;
    int currVal = root->val;
    int ans = INT_MAX;
    if (root->left != nullptr) {
        int leftVal = findLeftMaxVal(root->left);
        ans = std::min(ans, currVal - leftVal);
        ans = std::min(ans, minDiffInBST(root->left));
    }
    if (root->right != nullptr) {
        int rightVal = findRightMinVal(root->right);
        ans = std::min(ans, rightVal - currVal);
        ans = std::min(ans, minDiffInBST(root->right));
    }
    return ans;
}

int Solution783::findLeftMaxVal(TreeNode *root) {
    if (root->right != nullptr) {
        return findLeftMaxVal(root->right);
    } else {
        return root->val;
    }
}

int Solution783::findRightMinVal(TreeNode *root) {
    if (root->left) {
        return findRightMinVal(root->left);
    } else {
        return root->val;
    }
}
