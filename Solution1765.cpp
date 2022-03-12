//
// Created by luzh on 2022/1/29.
//

#include "Solution1765.h"

#include <queue>

vector<vector<int>> Solution1765::highestPeak(vector<vector<int>> &isWater) {
    int m = isWater.size();
    int n = isWater[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    queue<int> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j] == 1) {
                ans[i][j] = 0;
                q.push(i * n + j);
            }
        }
    }
    vector<int> dirs = {1, 0, -1, 0, 1};
    while (!q.empty()) {
        int currIndex = q.front();
        q.pop();
        int row = currIndex / n;
        int column = currIndex % n;
        int curr = ans[row][column];
        for (int i = 0; i < 4; i++) {
            if (row + dirs[i] >= m || row + dirs[i] < 0 || column + dirs[i + 1] >= n || column + dirs[i + 1] < 0) {
                continue;
            } else if (ans[row + dirs[i]][column + dirs[i + 1]] == -1) {
                ans[row + dirs[i]][column + dirs[i + 1]] = curr + 1;
                q.push((row + dirs[i]) * n + column + dirs[i + 1]);
            }
        }
    }
    return ans;
}
