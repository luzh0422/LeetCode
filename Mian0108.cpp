//
// Created by 陆泽辉 on 2022/9/30.
//

#include "Mian0108.h"
#include <functional>

void Mian0108::setZeroes(vector<vector<int>> &matrix) {
    vector<pair<int, int>> records;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                records.emplace_back(i, j);
            }
        }
    }
    std::function<void(int row, int column)> setZero = [&](int row, int column) -> bool {
        for (int i = 0; i < m; i++) {
            matrix[i][column] = 0;
        }
        for (int i = 0; i < n; i++) {
            matrix[row][i] = 0;
        }
    };
    for (auto& record : records) {
        int row = record.first;
        int column = record.second;
        setZero(row, column);
    }
    return;
}
