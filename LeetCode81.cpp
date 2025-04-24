//
// Created by luzehui on 25-2-1.
//

#include "LeetCode81.h"

bool LeetCode81::search(vector<int> &nums, int target) {
    int index = 0, n = nums.size();
    while (index < n - 1) {
        if (nums[index] > nums[index + 1]) {
            break;
        }
        index++;
    }
    return binarySearch(nums, 0, index, target) || binarySearch(nums, index + 1, n - 1, target);
}

bool LeetCode81::binarySearch(vector<int> &nums, int left, int right, int target) {
    while (left <= right) {
        int middle = (left + right) / 2;
        if (nums[middle] == target) {
            return true;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }

    }
    return false;
}
