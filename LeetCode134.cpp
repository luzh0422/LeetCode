//
// Created by luzehui on 2024/10/6.
//

#include "LeetCode134.h"

int LeetCode134::canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0, current = 0;
    size_t n = gas.size();
    int res = -1;
    for (size_t i = 0; i < n; i++) {
        total += gas[i] - cost[i];
        current += gas[i] - cost[i];
        if (current < 0) {
            current = 0;
            res = i + 1;
        }
    }
    if (total < 0) {
        return -1;
    }
    return res;
}
