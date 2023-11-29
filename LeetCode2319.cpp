//
// Created by 陆泽辉 on 2023/1/31.
//

#include "LeetCode2319.h"

bool LeetCode2319::checkXMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j || i + j == n - 1) && grid[i][j] == 0 || i != j && grid[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
