//
// Created by luzh on 2021/11/7.
//

#include "Solution599.h"

int Solution599::maxCount(int m, int n, vector<vector<int>> &ops) {
    if (ops.size() == 0) {
        return m * n;
    }
    int minRow = INT_MAX;
    int minColumn = INT_MAX;
    for (auto op : ops) {
        int row = op[0], column = op[1];
        minRow = min(row, minRow);
        minColumn = min(column, minColumn);
    }
    return minRow * minColumn;
}
