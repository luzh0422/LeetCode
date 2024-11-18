//
// Created by luzehui on 2024/2/29.
//

#include "LeetCode2476.h"

vector<vector<int>> LeetCode2476::closestNodes(TreeNode *root, vector<int> &queries) {
    vector<int> sortedArray;
    constructSortedArray(root, sortedArray);
    int n = queries.size();
    vector<vector<int>> ans(n, vector<int>(2, -1));
    for (int i = 0; i < n; i++) {
        int query = queries[i];
        auto iter = lower_bound(sortedArray.begin(), sortedArray.end(), query);
        if (iter != sortedArray.end() && *iter == query) {
            ans[i][0] = *iter;
            ans[i][1] = *iter;
        } else {
            if (iter == sortedArray.end()) {
                ans[i][1] = -1;
            } else {
                ans[i][1] = *iter;
            }
            if (iter == sortedArray.begin()) {
                ans[i][0] = -1;
            } else {
                ans[i][0] = *(--iter);
            }
        }
    }
    return ans;
}

void LeetCode2476::constructSortedArray(TreeNode *root, vector<int> &sortedArray) {
    if (!root) {
        return;
    }
    constructSortedArray(root->left, sortedArray);
    sortedArray.push_back(root->val);
    constructSortedArray(root->right, sortedArray);
}
