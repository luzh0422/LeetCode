//
// Created by 陆泽辉 on 2022/7/31.
//

#include "LeetCode1161.h"
#include <queue>
#include <unordered_map>
#include <vector>

int LeetCode1161::maxLevelSum(TreeNode *root) {
    std::queue<std::pair<TreeNode*, int>> q;
    std::unordered_map<int, int> uM;
    q.emplace(root, 1);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto node = p.first;
        auto level = p.second;
        if (uM.count(level)) {
            uM[level] += node->val;
        } else {
            uM.insert(std::unordered_map<int, int>::value_type(level, node->val));
        }
        if (node->left) {
            q.emplace(node->left, level + 1);
        }
        if (node->right) {
            q.emplace(node->right, level + 1);
        }
    }
    std::vector<std::pair<int, int>> vec(uM.begin(), uM.end());
    std::sort(vec.begin(), vec.end(), [](std::pair<int, int>& p1, std::pair<int, int>& p2) -> bool {
        if (p1.second > p2.second) {
            return true;
        } else if (p1.second == p2.second) {
            return p1.first < p2.first;
        } else {
            return false;
        }
    });
    return vec[0].first;
}
