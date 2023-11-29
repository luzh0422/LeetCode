//
// Created by luzehui on 2023/11/16.
//

#include "LeetCode2760.h"

int LeetCode2760::longestAlternatingSubarray(vector<int> &nums, int threshold) {
    int l = 0, r = l, n = nums.size(), ans = 0;
    while (l < n) {
        if (nums[l] > threshold || nums[l] % 2 == 1) {
            l++;
        } else {
            r = l + 1;
            while (r < n && nums[r] <= threshold && nums[r] % 2 != nums[r - 1] % 2) {
                r++;
            }
            ans = max(ans, r - l);
            l = r;
        }
    }
    return ans;
}
