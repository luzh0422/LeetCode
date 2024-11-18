//
// Created by luzehui on 2024/3/17.
//

#include "LeetCode2684.h"
#include <unordered_set>

int LeetCode2684::maxMoves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    unordered_set<int> q1, q2;
    for (int i = 0; i < m; i++) {
        q1.insert(i);
    }
    for (int i = 1; i < n; i++) {
        q2.clear();
        for (auto node : q1) {
            for (int j = node - 1; j <= node + 1; j++) {
                if (j >= 0 && j < m && grid[j][i] > grid[node][i]) {
                    q2.insert(j);
                }
            }
        }
        swap(q1, q2);
        if (q1.empty()) {
            return i - 1;
        }
    }
    return n - 1;
}
