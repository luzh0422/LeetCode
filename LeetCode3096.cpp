//
// Created by luzehui on 2024/7/19.
//

#include "LeetCode3096.h"


int LeetCode3096::minimumLevels(vector<int> &possible) {
    for(int& p : possible) {
        if (p == 0)
            p = -1;
    }
    vector<int> preSum;
    int sum = 0;
    preSum.push_back(sum);
    for (int p : possible) {
        sum += p;
        preSum.push_back(sum);
    }
    for (int i = 0; i < possible.size() - 1; i++) {
        if (preSum[i + 1] > sum - preSum[i + 1]) {
            return i + 1;
        }
    }
    return -1;
}
