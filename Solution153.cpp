//
// Created by luzh on 2021/4/8.
//

#include "Solution153.h"

int Solution153::findMin(vector<int> &nums) {
    int index = 0;
    int size = nums.size();
    if (size == 0) return 0;
    int left = 0;
    int right = size - 1;
    while (left <= right && nums[left] > nums[right]) {
        left++;
        right--;
    }
    return nums[(right + 1) % size];
}
