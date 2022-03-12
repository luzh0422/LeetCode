//
// Created by luzh on 2021/7/20.
//

#include "Solution1877.h"

int Solution1877::minPairSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int ans = INT_MIN;
    while (left <= right) {
        ans = max(ans, nums[left] + nums[right]);
        left++;
        right--;
    }
    return ans;
}
