//
// Created by luzh on 2021/12/8.
//

#include "Solution689.h"

vector<int> Solution689::maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    vector<int> ans = {};
    int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
    int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
    int sum3 = 0, maxTotal = 0;
    for (int i = k * 2; i < nums.size(); ++i) {
        /**
         * 第一个窗口和；
         */
        sum1 += nums[i - k * 2];
        /**
         * 第二个窗口和；
         */
        sum2 += nums[i - k];
        /**
         * 第三个窗口和；
         */
        sum3 += nums[i];
        if (i >= k * 3 - 1) {
            if (sum1 > maxSum1) {
                maxSum1 = sum1;
                maxSum1Idx = i - k * 3 + 1;
            }
            if (maxSum1 + sum2 > maxSum12) {
                maxSum12 = maxSum1 + sum2;
                maxSum12Idx1 = maxSum1Idx;
                maxSum12Idx2 = i - k * 2 + 1;
            }
            if (maxSum12 + sum3 > maxTotal) {
                maxTotal = maxSum12 + sum3;
                ans = {maxSum12Idx1, maxSum12Idx2, i - k + 1};
            }
            sum1 -= nums[i - k * 3 + 1];
            sum2 -= nums[i - k * 2 + 1];
            sum3 -= nums[i - k + 1];
        }
    }
    return ans;
}
