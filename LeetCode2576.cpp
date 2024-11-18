//
// Created by luzehui on 2024/9/12.
//

#include "LeetCode2576.h"

int LeetCode2576::maxNumOfMarkedIndices(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int middle = nums.size() / 2, left = middle - 1, right = nums.size() - 1, res = 0;
    while (left >= 0 && right >= middle) {
        if (nums[left] * 2 <= nums[right]) {
            res += 2;
            left--;
            right--;
        } else {
            left--;
        }
    }
    return res;
}
