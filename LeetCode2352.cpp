//
// Created by 陆泽辉 on 2023/6/6.
//

#include "LeetCode2352.h"

int LeetCode2352::equalPairs(vector<vector<int>> &grid) {
    vector<vector<int>> colGrid{};
    int row = grid.size(), col = grid[0].size();
    for (int i = 0; i < col; i++) {
        vector<int> temp{};
        for (int j = 0; j < row; j++) {
            temp.push_back(grid[j][i]);
        }
        colGrid.push_back(temp);
    }
    int res = 0;
    for (int i = 0; i < row; i++) {
        auto rowTemp = grid[i];
        for (int j = 0; j < col; j++) {
            auto colTemp = colGrid[j];
            if (rowTemp == colTemp) {
                res++;
            }
        }
    }
    return res;
}
