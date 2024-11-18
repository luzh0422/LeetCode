//
// Created by luzehui on 2024/2/28.
//

#include "LeetCode2673.h"

int LeetCode2673::minIncrements(int n, vector<int> &cost) {
    int ans = 0;
    for (int i = n - 2; i >= 0; i -= 2) {
        ans += abs(cost[i + 1] - cost[i]);
        cost[i / 2] += max(cost[i + 1], cost[i]);
    }
    return ans;
}
