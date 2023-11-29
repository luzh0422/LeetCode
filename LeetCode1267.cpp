//
// Created by 陆泽辉 on 2023/8/24.
//

#include "LeetCode1267.h"

int LeetCode1267::countServers(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> rows(m, 0);
    vector<int> cols(n, 0);
    for (int i = 0; i < m; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            temp += grid[i][j];
        }
        rows[i] = temp;
    }
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < m; j++) {
            temp += grid[j][i];
        }
        cols[i] = temp;
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
                res++;
            }
        }
    }
    return res;
}
