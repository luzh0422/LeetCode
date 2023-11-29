//
// Created by 陆泽辉 on 2022/5/5.
//

#include "LeetCode713.h"

int LeetCode713::numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int left = 0, right = 0, n = nums.size();
    int curr = 1;
    int ans = 0;
    for (; right < n; right++) {
        curr *= nums[right];
        while (left <= right && curr >= k) {
            curr /= nums[left];
            left++;
        }
        if (nums[right] < k) {
            ans += left - right + 1;
        }
    }
    return ans;
}
