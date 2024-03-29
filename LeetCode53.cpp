//
// Created by luzehui on 2023/11/20.
//

#include "LeetCode53.h"

int LeetCode53::maxSubArray(vector<int> &nums) {
    int n = nums.size();
    int res = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        res = max(res, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return res;
}
