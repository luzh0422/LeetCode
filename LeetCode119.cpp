//
// Created by luzehui on 25-1-28.
//

#include "LeetCode119.h"

vector<int> LeetCode119::getRow(int rowIndex) {
    if (rowIndex == 0) {
        return {1};
    }
    auto arr = getRow(rowIndex - 1);
    vector<int> res(rowIndex + 1, 0);
    res[0] = 1;
    res[rowIndex] = 1;
    for (int i = 1; i < rowIndex; i++) {
        res[i] = arr[i - 1]  + arr[i];
    }
    return res;
}
