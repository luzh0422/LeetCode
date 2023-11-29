//
// Created by 陆泽辉 on 2023/4/18.
//

#include "LeetCode1026.h"
#include <algorithm>

using namespace std;

int LeetCode1026::maxAncestorDiff(TreeNode *root) {
    return max(maxAncestorDiff(root->left, root->val, root->val), maxAncestorDiff(root->right, root->val, root->val));
}

int LeetCode1026::maxAncestorDiff(TreeNode *root, int minVal, int maxVal) {
    if (root == nullptr) {
        return 0;
    }
    int curr = max(abs(root->val - minVal), abs(root->val - maxVal));
    int left = maxAncestorDiff(root->left, min(minVal, root->val), max(maxVal, root->val));
    int right = maxAncestorDiff(root->right, min(minVal, root->val), max(maxVal, root->val));
    return max(max(curr, left), right);
}
