//
// Created by 陆泽辉 on 2022/6/28.
//

#include "LeetCode324.h"

void LeetCode324::wiggleSort(vector<int> &nums) {
    vector<int> tmp(nums.begin(), nums.end());
    std::sort(tmp.begin(), tmp.end());
    int n = static_cast<int>(nums.size());
    int left = n / 2, right = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            nums[i] = tmp[left];
            left--;
        } else {
            nums[i] = tmp[right];
            right--;
        }
    }
    return;
}
