//
// Created by luzehui on 2024/4/29.
//

#include "LeetCode1329.h"

vector<vector<int>> LeetCode1329::diagonalSort(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    auto customSort = [&](int row, int col) -> void {
        while (row >= 0 && col >= 0) {
            int maxVal = mat[row][col];
            int indexRow = row, indexCol = col;
            int nextRow = row - 1, nextCol = col - 1;
            while (nextRow >= 0 && nextCol >= 0) {
                if (mat[nextRow][nextCol] > maxVal) {
                    maxVal = mat[nextRow][nextCol];
                    indexRow = nextRow;
                    indexCol = nextCol;
                }
                nextRow--;
                nextCol--;
            }
            mat[indexRow][indexCol] = mat[row][col];
            mat[row][col] = maxVal;
            row--;
            col--;
        }
    };
    for (int i = 0; i < m; i++) {
        customSort(i, n - 1);
    }
    for (int i = 0; i < n; i++) {
        customSort(m - 1, i);
    }
    return mat;
}
