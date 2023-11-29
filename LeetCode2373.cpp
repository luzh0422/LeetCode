//
// Created by 陆泽辉 on 2023/3/1.
//

#include "LeetCode2373.h"

vector<vector<int>> LeetCode2373::largestLocal(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int temp = 0;
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    temp = max(temp, grid[k][l]);
                }
            }
            res[i][j] = temp;
        }
    }
    return res;
}
