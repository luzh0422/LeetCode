//
// Created by 陆泽辉 on 2022/7/8.
//

#include "LeetCode1217.h"

int LeetCode1217::minCostToMoveChips(vector<int> &position) {
    int evenCount = 0, oddCount = 0;
    for (int& pos: position) {
        if (pos % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    return min(evenCount, oddCount);
}
