//
// Created by luzh on 2021/4/7.
//

#include "Solution81.h"

bool Solution81::search(vector<int> &nums, int target) {
    int index = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            index = i;
            break;
        }
    }
    return binarySearch(nums, 0, index, target) || binarySearch(nums, index + 1, nums.size() - 1, target);
}

bool Solution81::binarySearch(vector<int> &nums, int left, int right, int target) {
    if (left > right) {
        return false;
    }
    int middle = (left + right) / 2;
    if (nums[middle] == target) {
        return true;
    } else if (nums[middle] > target) {
        right = middle - 1;
        return binarySearch(nums, left, right, target);
    } else {
        left = middle + 1;
        return binarySearch(nums, left, right, target);
    }
}
