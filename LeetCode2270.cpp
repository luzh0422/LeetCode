//
// Created by luzehui on 25-1-13.
//

#include "LeetCode2270.h"

int LeetCode2270::waysToSplitArray(vector<int> &nums) {
    int n = nums.size(), res = 0;
    vector<long long> preSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    for (int i = 1; i < n; i++) {
        if (preSum[n] - preSum[i] <= preSum[i]) {
            res++;
        }
    }
    return res;
}
