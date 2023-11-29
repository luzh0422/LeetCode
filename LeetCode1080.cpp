//
// Created by 陆泽辉 on 2023/5/22.
//

#include "LeetCode1080.h"
#include <algorithm>

using namespace std;

TreeNode *LeetCode1080::sufficientSubset(TreeNode *root, int limit) {
    sufficientSubset(root, limit, 0);
    if (root->left == nullptr && root->right == nullptr && root->val < limit) {
        return nullptr;
    }
    return root;
}

int LeetCode1080::sufficientSubset(TreeNode *root, int limit, int curr) {
    curr += root->val;
    if (!root->left && !root->right) {
        return curr;
    }
    int leftVal = INT_MIN, rightVal = INT_MIN;
    if (root->left) {
        leftVal = sufficientSubset(root->left, limit, curr);
    }
    if (root->right) {
        rightVal = sufficientSubset(root->right, limit, curr);
    }
    // std::cout << "leftVal: " << leftVal << endl;
    // std::cout << "rightVal: " << rightVal << endl;
    if (leftVal < limit) {
        root->left = nullptr;
    }
    if (rightVal < limit) {
        root->right = nullptr;
    }
    return max(leftVal, rightVal);
}
