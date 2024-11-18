//
// Created by luzehui on 2024/11/9.
//

#include "LeetCode3242.h"

NeighborSum::NeighborSum(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();
    mGrid = grid;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            records[grid[i][j]] = i * m + j;
        }
    }
}

int NeighborSum::adjacentSum(int value) {
    int num = records[value];
    int row = num / m, column = num % m;
    int res = 0;
    if (row != 0) {
        res += mGrid[row - 1][column];
    }
    if (column != 0) {
        res += mGrid[row][column - 1];
    }
    if (row != m - 1) {
        res += mGrid[row + 1][column];
    }
    if (column != n - 1) {
        res += mGrid[row][column + 1];
    }
    return res;
}

int NeighborSum::diagonalSum(int value) {
    int num = records[value];
    int row = num / m, column = num % m;
    int res = 0;
    if (row != 0) {
        if (column != 0) {
            res += mGrid[row - 1][column - 1];
        }
        if (column != n - 1) {
            res += mGrid[row - 1][column + 1];
        }
    }
    if (row != m - 1) {
        if (column != 0) {
            res += mGrid[row + 1][column - 1];
        }
        if (column != n - 1) {
            res += mGrid[row + 1][column + 1];
        }
    }
    return res;
}
