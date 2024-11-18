//
// Created by luzehui on 2024/10/21.
//

#include "LeetCode910.h"

int LeetCode910::smallestRangeII(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    // 遍历节点i，从i 及 i之前全部 + k；从i之后全部 - k;
    int n = nums.size(), res = nums.back() - nums.front();
    for (int i = 0; i < n - 1; i++) {
        // nums[0] + k, nums[i + 1] - k;
        int minVal = min(nums[0] + k, nums[i + 1] - k);
        int maxVal = max(nums[i] + k, nums[n - 1] - k);
        res = min(maxVal - minVal, res);
    }
    return res;
}
