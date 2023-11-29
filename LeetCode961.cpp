//
// Created by 陆泽辉 on 2022/5/21.
//

#include "LeetCode961.h"
#include <unordered_set>

int LeetCode961::repeatedNTimes(vector<int> &nums) {
    unordered_set<int> records;
    int n = nums.size() / 2;
    for (int i = 0; i <= n + 1; i++) {
        if (records.count(nums[i])) {
            return nums[i];
        }
        records.emplace(nums[i]);
    }
    return 0;
}
