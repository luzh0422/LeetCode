//
// Created by 陆泽辉 on 2022/9/12.
//

#include "LeetCode1608.h"

int LeetCode1608::specialArray(vector<int> &nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int n = nums.size();
    for (int i = 1; i <= n; ++i) {
        if (nums[i - 1] >= i && (i == n || nums[i] < i)) {
            return i;
        }
    }
    return -1;
}
