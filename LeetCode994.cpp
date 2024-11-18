//
// Created by luzehui on 2024/5/13.
//

#include "LeetCode994.h"
#include <queue>

int LeetCode994::orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0, count = 0;
    queue<tuple<int, int, int>> q;
    const vector<int> directions = {-1, 0, 1, 0, -1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0});
            }
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int row = get<0>(curr);
        int col = get<1>(curr);
        int time = get<2>(curr);
        for (int i = 0; i < 4; i++) {
            int nextRow = row + directions[i];
            int nextCol = col + directions[i + 1];
            if (nextRow >= 0 && nextRow < m && nextCol >= 0 &&
                nextCol < n && grid[nextRow][nextCol] == 1) {
                res = max(res, time + 1);
                grid[nextRow][nextCol] = 2;
                q.push({nextRow, nextCol, time + 1});
                count--;
            }
        }
    }
    return count == 0 ? res : -1;
}
