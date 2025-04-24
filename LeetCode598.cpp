//
// Created by luzehui on 25-2-2.
//

#include "LeetCode598.h"

int LeetCode598::maxCount(int m, int n, vector<vector<int>> &ops) {
    int minRow = m, minCol = n;
    for (auto& op : ops) {
        minRow = min(minRow, op[0]);
        minCol = min(minCol, op[1]);
    }
    return minRow * minCol;
}
