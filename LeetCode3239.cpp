//
// Created by luzehui on 2024/11/15.
//

#include "LeetCode3239.h"

int LeetCode3239::minFlips(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int colRes = 0, rowRes = 0;
    for (int i = 0; i < n; i++) {
        int top = 0, bottom = m - 1;
        while (top < bottom) {
            if (grid[top][i] != grid[bottom][i])
                colRes++;
            top++;
            bottom--;
        }
    }
    for (int i = 0; i < m; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (grid[i][left] != grid[i][right])
                rowRes++;
            left++;
            right--;
        }
    }
    return min(colRes, rowRes);
}
