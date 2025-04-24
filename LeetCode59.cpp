//
// Created by luzehui on 25-2-7.
//

#include "LeetCode59.h"

vector<vector<int>> LeetCode59::generateMatrix(int n) {
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> res(n, vector<int>(n, -1));
    int index = 0, row = 0, col = 0;
    for (int i = 0; i < n * n; i++) {
        res[row][col] = i + 1;
        int nextRow = row + directions[index][0];
        int nextCol = col + directions[index][1];
        if (nextRow >= n || nextRow < 0 || nextCol >= n || nextCol < 0 || res[nextRow][nextCol] != -1) {
            index = (index + 1) % 4;
        }
        row += directions[index][0];
        col += directions[index][1];
    }
    return res;
}
