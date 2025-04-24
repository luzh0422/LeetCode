//
// Created by luzehui on 25-2-15.
//

#include "LeetCode1706.h"

vector<int> LeetCode1706::findBall(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> cache(m, vector<int>(n, -2));
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        res[i] = findBall(grid, cache, 0, i, m, n);
    }
    return res;
}

int LeetCode1706::findBall(vector<vector<int>> &grid, vector<vector<int>> &cache, int row, int col, int m, int n) {
    if (cache[row][col] != -2) {
        return cache[row][col];
    }
    if (grid[row][col] == 1) {
        if (col + 1 == n || grid[row][col + 1] == -1) {
            cache[row][col] = -1;
            return -1;
        }
        cache[row][col] = row + 1 == m ? col + 1 : findBall(grid, cache, row + 1, col + 1, m, n);
    } else {
        if (col == 0 || grid[row][col - 1] == 1) {
            cache[row][col] = -1;
            return -1;
        }
        cache[row][col] = row + 1 == m ? col - 1 : findBall(grid, cache, row + 1, col - 1, m, n);
    }
    return cache[row][col];
}
