//
// Created by 陆泽辉 on 2023/4/13.
//

#include "LeetCode2404.h"

int LeetCode2404::mostFrequentEven(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = -1, maxCount = 0, currCount = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            currCount++;
        } else {
            if (nums[i - 1] % 2 == 0 && currCount > maxCount) {
                res = nums[i - 1];
                maxCount = currCount;
            }
            currCount = 1;
        }
    }
    if (nums.back() % 2 == 0 && currCount > maxCount) {
        res = nums.back();
    }
    return res;
}
