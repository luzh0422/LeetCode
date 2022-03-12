//
// Created by luzh on 2021/7/19.
//

#include "Solution1838.h"

int Solution1838::maxFrequency(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    long long total = 0;
    int l = 0, res = 1;
    for (int r = 1; r < n; ++r) {
        /**
         * 变动右指针，每一次变动都修改当前窗口内的总数；
         */
        total += (long long)(nums[r] - nums[r - 1]) * (r - l);
        /**
         * 当需要修改的次数大于k时(窗口内的总数不满足条件时)，滑动左指针；
         */
        while (total > k) {
            total -= nums[r] - nums[l];
            l++;
        }
        res = max(res, r - l + 1);
    }
    return res;
}
