//
// Created by 陆泽辉 on 2022/6/24.
//

#include "LeetCode515.h"
#include <queue>

vector<int> LeetCode515::largestValues(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<int> ret;
    queue<pair<TreeNode*, int>> q;
    q.emplace(root, 0);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        auto currNode = curr.first;
        auto currLevl = curr.second;
        if (ret.size() <= currLevl) {
            ret.emplace_back(currNode->val);
        } else if (ret[currLevl] < currNode->val) {
            ret[currLevl] = currNode->val;
        }
        if (currNode->left) {
            q.emplace(currNode->left, currLevl + 1);
        }
        if (currNode->right) {
            q.emplace(currNode->right, currLevl + 1);
        }
    }
    return ret;
}
