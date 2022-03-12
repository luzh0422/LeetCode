//
// Created by luzh on 2021/12/13.
//

#include "Solution807.h"

int Solution807::maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int n = grid.size();
    maxRow.resize(n, 0);
    maxColumn.resize(n, 0);
    for (int i = 0; i < n; i++) {
        int currRow = 0;
        int currColumn = 0;
        for (int j = 0; j < n; j++) {
            currRow = max(currRow, grid[i][j]);
            currColumn = max(currColumn, grid[j][i]);
        }
        maxRow[i] = currRow;
        maxColumn[i] = currColumn;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int max = min(maxRow[i], maxColumn[j]);
            int curr = grid[i][j];
            if (curr < max) {
                ans += max - curr;
            }
        }
    }
    return ans;
}
