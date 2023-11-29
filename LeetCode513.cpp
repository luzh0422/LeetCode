//
// Created by 陆泽辉 on 2022/6/22.
//

#include "LeetCode513.h"
#include <queue>

using namespace std;

int LeetCode513::findBottomLeftValue(TreeNode *root) {
    if (root == nullptr) {
        return -1;
    }
    queue<pair<TreeNode*, int>> q;
    q.emplace(root, 0);
    int val = -1, level = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto node = p.first;
        auto currLevel = p.second;
        if (currLevel > level) {
            level = currLevel;
            val = node->val;
        }
        if (node->left) {
            q.emplace(node->left, currLevel + 1);
        }
        if (node->right) {
            q.emplace(node->right, currLevel + 1);
        }
    }
    return val;
}
