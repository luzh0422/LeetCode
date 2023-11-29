//
// Created by 陆泽辉 on 2023/5/1.
//

#include "LeetCode1376.h"

int LeetCode1376::numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
    vector<vector<int>> tree(n, {});
    for (int i = 0; i < n; i++) {
        if (manager[i] != -1) {
            tree[manager[i]].push_back(i);
        }
    }
    return numOfMinutes(headID, tree, informTime);
}

int LeetCode1376::numOfMinutes(int headId, vector<vector<int>> &tree, vector<int> &informTime) {
    int curr = informTime[headId];
    auto nodes = tree[headId];
    int nodeTime = 0;
    for (auto node : nodes) {
        nodeTime = max(nodeTime, numOfMinutes(node, tree, informTime));
    }
    return curr + nodeTime;
}
