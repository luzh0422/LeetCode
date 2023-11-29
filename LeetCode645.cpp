//
// Created by 陆泽辉 on 2022/8/20.
//

#include "LeetCode645.h"

TreeNode *LeetCode645::constructMaximumBinaryTree(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    auto root = constructMaximumBinaryTree(nums, 0, right);
    return root;
}

TreeNode *LeetCode645::constructMaximumBinaryTree(vector<int> &nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int maxVal = nums[left];
    int maxIndex = left;
    for (int i = left; i <= right; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxIndex = i;
        }
    }
    TreeNode* root = new TreeNode(maxVal);
    root->left = constructMaximumBinaryTree(nums, left, maxIndex - 1);
    root->right = constructMaximumBinaryTree(nums, maxIndex + 1, right);
    return root;
}
