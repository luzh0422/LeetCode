//
// Created by 陆泽辉 on 2023/9/13.
//

#include "LeetCode2596.h"

bool LeetCode2596::checkValidGrid(vector<vector<int>> &grid) {
    if (grid[0][0] != 0) {
        return false;
    }
    return dfs(grid, 0, 0, 0);
}

bool LeetCode2596::dfs(vector<vector<int>> &grid, int curr, int row, int column) {
    const vector<pair<int, int>> directions = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
    int m = grid.size();
    int n = grid[0].size();
    if (curr == m * n - 1) {
        return true;
    }
    for (auto& direction : directions) {
        int nextRow = row + direction.first;
        int nextCol = column + direction.second;
        if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && grid[nextRow][nextCol] == curr + 1) {
            return dfs(grid, curr + 1, nextRow, nextCol);
        }
    }
    return false;
}
