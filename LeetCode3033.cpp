//
// Created by luzehui on 2024/7/5.
//

#include "LeetCode3033.h"

vector<vector<int>> LeetCode3033::modifiedMatrix(vector<vector<int>> &matrix) {
    vector<pair<int, int>> records;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < n; i++) {
        records.clear();
        int maxVal = INT_MIN;
        for (int j = 0; j < m; j++) {
            if (matrix[j][i] == -1) {
                records.emplace_back(j, i);
            }
            maxVal = max(maxVal, matrix[j][i]);
        }
        for (int j = 0; j < records.size(); j++) {
            auto p = records[j];
            matrix[p.first][p.second] = maxVal;
        }
    }
    return matrix;
}
