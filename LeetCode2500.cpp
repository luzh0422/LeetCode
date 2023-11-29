//
// Created by 陆泽辉 on 2023/7/27.
//

#include "LeetCode2500.h"

int LeetCode2500::deleteGreatestValue(vector<vector<int>> &grid) {
    for (auto& arr : grid) {
        std::sort(arr.begin(), arr.end());
    }
    int res = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < n; i++) {
        int maxVal = INT_MIN;
        for (int j = 0; j < m; j++) {
            maxVal = max(maxVal, grid[j][i]);
        }
        res += maxVal;
    }
    return res;
}
