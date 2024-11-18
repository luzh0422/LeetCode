//
// Created by luzehui on 2024/1/25.
//

#include "LeetCode2859.h"

int LeetCode2859::sumIndicesWithKSetBits(vector<int> &nums, int k) {
    auto getCount = [](int num) -> int {
        int count = 0;
        while (num != 0) {
            count += num % 2;
            num /= 2;
        }
        return count;
    };
    int res = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (getCount(i) == k) {
            res += nums[i];
        }
    }
    return res;
}
