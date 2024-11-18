//
// Created by luzehui on 2024/8/2.
//

#include "LeetCode3128.h"

long long LeetCode3128::numberOfRightTriangles(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> rows(m, 0), cols(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                rows[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[j][i] == 1) {
                cols[i]++;
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                res += (cols[j] - 1) * (rows[i] - 1);
            }
        }
    }
    return res;
}
