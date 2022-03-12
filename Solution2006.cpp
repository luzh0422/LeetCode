//
// Created by luzh on 2022/2/9.
//

#include "Solution2006.h"

int Solution2006::countKDifference(vector<int> &nums, int k) {
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(nums[i] - nums[j]) == k) {
                ans++;
            }
        }
    }
    return ans;
}
