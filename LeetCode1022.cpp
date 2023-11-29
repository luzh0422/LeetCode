//
// Created by 陆泽辉 on 2022/5/30.
//

#include "LeetCode1022.h"

int LeetCode1022::sumRootToLeaf(TreeNode *root) {
    return this->sumRootToLeaf(root, "");
}

int LeetCode1022::sumRootToLeaf(TreeNode *root, string curr) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return binaryToDecimal(curr + to_string(root->val));
    }
    int ret = 0;
    if (root->left != nullptr) {
        ret += sumRootToLeaf(root->left, curr + to_string(root->val));
    }
    if (root->right != nullptr) {
        ret += sumRootToLeaf(root->right, curr + to_string(root->val));
    }
    return ret;
}

int LeetCode1022::binaryToDecimal(string binary) {
    int ret = 0, n = binary.size();
    for (int i = 0; i < n; i++) {
        ret = ret << 1;
        ret += binary[i] - '0';
    }
    return ret;
}
