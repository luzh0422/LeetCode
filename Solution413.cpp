//
// Created by luzh on 2021/8/10.
//

#include "Solution413.h"

/**
 * 连续差分子序列问题；
 * @param nums
 * @return
 */
int Solution413::numberOfArithmeticSlices(vector<int> &nums) {
    int size = nums.size();
    if (size < 3) {
        return 0;
    }
    int ans = 0;
    int d = nums[0] - nums[1];
    int t = 0;
    for (int i = 2; i < size; i++) {
        if (nums[i - 1] - nums[i] == d) {
            /**
             * 和上一个差分子序列，依然可以构成差分子序列时，计数是上个查分子序列的长度 + 1；
             */
            t = t + 1;
        } else {
            /**
             * 和上一个差分子序列，不能构成差分子序列时，重新构造一个新的差分子序列；
             */
            d = nums[i - 1] - nums[i];
            t = 0;
        }
        ans += t;
    }
    return ans;
}
