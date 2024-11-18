//
// Created by luzehui on 2024/7/14.
//

#include "LeetCode807.h"

int LeetCode807::maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int m = grid.size();
    vector<vector<pair<int, int>>> records(m, vector<pair<int, int>>(m, {0, 0}));
    for (int i = 0; i < m; i++) {
        int maxVal = 0;
        for (int j = 0; j < m; j++) {
            maxVal = max(maxVal, grid[i][j]);
        }
        for (int j = 0; j < m; j++) {
            records[i][j].second = maxVal;
        }
        maxVal = 0;
        for (int j = 0; j < m; j++) {
            maxVal = max(maxVal, grid[j][i]);
        }
        for (int j = 0; j < m; j++) {
            records[j][i].first = maxVal;
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            res += min(records[i][j].first, records[i][j].second) - grid[i][j];
        }
    }
    return res;
}
