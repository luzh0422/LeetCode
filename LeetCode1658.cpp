//
// Created by 陆泽辉 on 2023/1/7.
//

#include "LeetCode1658.h"
#include <numeric>

int LeetCode1658::minOperations(vector<int> &nums, int x) {
    int n = nums.size();
    int left = -1, right = 0;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < x) {
        return -1;
    }
    int res = n + 1;
    for (; left < n; left++) {
        if (left != -1) {
            sum += nums[left];
        }
        while (right < n && sum > x) {
            sum -= nums[right];
            right++;
        }
        if (sum == x) {
            res = min(res, (left + 1) + (n - right));
        }
    }
    return res == n + 1 ? -1 : res;
}
