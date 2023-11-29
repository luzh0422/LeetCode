//
// Created by luzehui on 2023/11/25.
//

#include "LeetCode1457.h"

int LeetCode1457::pseudoPalindromicPaths(TreeNode *root) {
    vector<int> records(11, 0);
    return dfs(root, records);
}

int LeetCode1457::dfs(TreeNode *root, vector<int> record) {
    record[root->val]++;
    if (root->left == nullptr && root->right == nullptr) {
        int count = 0;
        for (int i = 1; i <= 10; i++) {
            if (record[i] % 2 == 1) {
                count++;
            }
        }
        return count < 2 ? 1 : 0;
    }
    int res = 0;
    if (root->left != nullptr) {
        res += dfs(root->left, record);
    }
    if (root->right != nullptr) {
        res += dfs(root->right, record);
    }
    return res;
}
