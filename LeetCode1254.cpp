//
// Created by 陆泽辉 on 2023/6/18.
//

#include "LeetCode1254.h"
#include <functional>

int LeetCode1254::closedIsland(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> visits(row, vector<int>(col, 0));
    vector<int> direction = {-1, 0, 1, 0, -1};
    function<bool(int, int)> dfs = [&](int currRow, int currCol) -> bool {
        if (currRow == 0 || currRow == row - 1 || currCol == 0 || currCol == col - 1) {
            return false;
        }
        bool dfsRes = true;
        for (int i = 0; i < 4; i++) {
            int nextRow = currRow + direction[i];
            int nextCol = currCol + direction[i + 1];
            if (visits[nextRow][nextCol] == 0 && grid[nextRow][nextCol] == 0) {
                visits[nextRow][nextCol] = 1;
                if (!dfs(nextRow, nextCol)) {
                    dfsRes = false;
                }
            }
        }
        return dfsRes;
    };
    int res = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visits[i][j] == 0 && grid[i][j] == 0 && dfs(i, j)) {
                res++;
            }
        }
    }
    return res;
}
