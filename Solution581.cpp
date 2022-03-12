//
// Created by luzh on 2021/8/3.
//

#include "Solution581.h"

int Solution581::findUnsortedSubarray(vector<int> &nums) {
    vector<int> numsCopy(nums);
    std::sort(numsCopy.begin(), numsCopy.end());
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        if (nums[left] != numsCopy[left]) {
            break;
        }
        left++;
    }
    while (left <= right) {
        if (nums[right] != numsCopy[right]) {
            break;
        }
        right--;
    }
    return right - left + 1;
}
