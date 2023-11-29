//
// Created by 陆泽辉 on 2023/5/26.
//

#include "LeetCode1091.h"
#include <queue>

int LeetCode1091::shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
        return -1;
    }
    vector<vector<int>> visits(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.emplace(0, 1);
    visits[0][0] = 1;
    vector<pair<int, int>> nexts = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int pos = curr.first;
        int dis = curr.second;
        int row = pos / n;
        int col = pos % n;
        if (row == n - 1 && col == n - 1) {
            return dis;
        }
        dis++;
        for (int i = 0; i < 8; i++) {
            int nextRow = row + nexts[i].first;
            int nextCol = col + nexts[i].second;
            if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && visits[nextRow][nextCol] < 1 && grid[nextRow][nextCol] < 1) {
                visits[nextRow][nextCol] = 1;
                q.emplace(nextRow * n + nextCol, dis);
            }
        }
    }
    return -1;
}
