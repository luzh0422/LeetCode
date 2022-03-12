//
// Created by luzh on 2021/3/21.
//

#include "Solution73.h"

void Solution73::setZeroes(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int column = matrix[0].size();
    vector<pair<int, int>> cache = {};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (!matrix[i][j]) {
                cache.push_back(std::pair<int, int>(i, j));
            }
        }
    }
    for (int i = 0; i < cache.size(); i++) {
        int zeroRow = cache[i].first;
        int zeroColumn = cache[i].second;
        for (int j = 0; j < row; j++) {
            matrix[j][zeroColumn] = 0;
        }
        for (int j = 0; j < column; j++) {
            matrix[zeroRow][j] = 0;
        }
    }
    return;
}
