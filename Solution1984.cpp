//
// Created by luzh on 2022/2/11.
//

#include "Solution1984.h"

int Solution1984::minimumDifference(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = INT_MAX;
    for (int i = k - 1; i < n; i++) {
        ans = min(ans, nums[i] - nums[i - k + 1]);
    }
    return ans;
}
