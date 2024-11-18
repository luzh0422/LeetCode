//
// Created by luzehui on 2024/9/15.
//

#include "LeetCode2848.h"

int LeetCode2848::numberOfPoints(vector<vector<int>> &nums) {
    std::sort(nums.begin(), nums.end(), [&](vector<int>& nums1, vector<int>& nums2) -> bool {
        if (nums1[0] < nums2[0]) {
            return true;
        } else if (nums1[0] == nums2[0] && nums1[1] < nums2[1]) {
            return true;
        } else {
            return false;
        }
    });
    int res = 0, i = 0, n = nums.size();
    while (i < n) {
        int left = nums[i][0], right = nums[i][1];
        int j = i + 1;
        while (j < n && nums[j][0] <= right) {
            right = max(nums[j][1], right);
            j++;
        }
        res += (right - left);
        i = j;
    }
    return res;
}
