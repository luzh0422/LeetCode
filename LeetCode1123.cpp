//
// Created by 陆泽辉 on 2023/9/6.
//

#include "LeetCode1123.h"
#include <queue>
#include <unordered_map>

using namespace std;

TreeNode *LeetCode1123::lcaDeepestLeaves(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }
    queue<pair<TreeNode*, int>> q;
    unordered_map<TreeNode*, TreeNode*> parentM;
    vector<TreeNode*> arr;
    int maxLevel = -1;
    q.push({root, 0});
    parentM[root] = nullptr;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        auto currNode = curr.first;
        auto level = curr.second;
        if (level > maxLevel) {
            arr.clear();
            arr.push_back(currNode);
            maxLevel = level;
        } else if (level == maxLevel)  {
            arr.push_back(currNode);
        }
        if (currNode->left) {
            parentM[currNode->left] = currNode;
            q.push({currNode->left, level + 1});
        }
        if (currNode->right) {
            parentM[currNode->right] = currNode;
            q.push({currNode->right, level + 1});
        }
    }
    if (arr.size() == 1) {
        return arr[0];
    }
    TreeNode* res = nullptr;
    auto check = [&]() -> bool {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (parentM[arr[i]] != parentM[arr[i + 1]]) {
                return false;
            }
        }
        return true;
    };
    while (!check()) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = parentM[arr[i]];
        }
    }
    return parentM[arr[0]];
}
