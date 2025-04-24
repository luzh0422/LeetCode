//
// Created by luzehui on 25-2-9.
//

#include "LeetCode63.h"

int LeetCode63::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    int m = obstacleGrid.size(), n = obstacleGrid[0].size(), res = 0;
    vector<vector<int>> cache(m, vector<int>(n, -1));
    return backtrack(obstacleGrid, 0, 0, m, n, cache);
}

int LeetCode63::backtrack(vector<vector<int>> &obstacleGrid, int row, int col, int m, int n, vector<vector<int>>& cache) {
    if (cache[row][col] != -1) {
        return cache[row][col];
    }
    if (row == m - 1 && col == n - 1) {
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        return 1;
    }
    int res = 0;
    if (row + 1 < m && obstacleGrid[row + 1][col] == 0) {
        res += backtrack(obstacleGrid, row + 1, col, m, n, cache);
    }
    if (col + 1 < n && obstacleGrid[row][col + 1] == 0) {
        res += backtrack(obstacleGrid, row, col + 1, m, n, cache);
    }
    cache[row][col] = res;
    return res;
}
