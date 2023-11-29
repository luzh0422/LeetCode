//
// Created by luzehui on 2023/11/24.
//

#include "LeetCode2824.h"

int LeetCode2824::countPairs(vector<int> &nums, int target) {
    int res = 0;
    std::sort(nums.begin(), nums.end());
    for (auto iter = nums.begin(); iter != nums.end(); iter++) {
        int temp = target - *iter;
        auto nextIter = lower_bound(iter + 1, nums.end(), temp);
        res += distance(iter, nextIter) - 1;
    }
    return res;
}
