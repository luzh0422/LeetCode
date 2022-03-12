//
// Created by luzh on 2021/9/28.
//

#include "Solution437.h"


int Solution437::pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return targetSum == 0 ? 1 : 0;
    }
    unordered_map<int, int> um = {};
    um[0] = 1;
    return pathSum(root, targetSum, um, 0);
}

int Solution437::pathSum(TreeNode *root, int targetSum, unordered_map<int, int> &um, int currSum) {
    int ans = 0;
    int currVal = root->val;
    currSum += currVal;
    if (um.count(currSum - targetSum)) {
        ans += um[currSum - targetSum];
    }
    if (um.count(currSum)) {
        um[currSum]++;
    } else {
        um[currSum] = 1;
    }
    if (root->left != nullptr) {
        ans += pathSum(root->left, targetSum, um, currSum);
    }
    if (root->right != nullptr) {
        ans += pathSum(root->right, targetSum, um, currSum);
    }
    um[currSum]--;
    return ans;
}
