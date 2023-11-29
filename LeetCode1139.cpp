//
// Created by 陆泽辉 on 2023/2/17.
//

#include "LeetCode1139.h"

int LeetCode1139::largest1BorderedSquare(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> left(n, vector<int>(m, 0));
    vector<vector<int>> up(n, vector<int>(m, 0));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
                up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
                int border = min(left[i][j], up[i][j]);
                while (left[i - border + 1][j] < border || up[i][j - border + 1] < border) {
                    border--;
                }
                res = max(res, border * border);
            }
        }
    }
    return res;
}
