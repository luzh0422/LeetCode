//
// Created by luzh on 2021/9/15.
//

#include "Solution162.h"

int Solution162::findPeakElement(vector<int> &nums) {
    int n = nums.size() - 1;
    int left = 0, right = n;
    int middle = (left + right) / 2;
    while (left <= right) {
        /**
         * 只有一个数字的处理；
         */
        if (middle == 0 && middle == n) {
            return middle;
        } else if (middle == 0) {
            if (nums[middle] > nums[middle + 1]) {
                return middle;
            } else {
                left = middle + 1;
            }
        } else if (middle == n) {
            if (nums[middle] > nums[middle - 1]) {
                return middle;
            } else {
                right = middle - 1;
            }
        } else {
            if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1]) {
                return middle;
            } else if (nums[middle] > nums[middle - 1] && nums[middle] < nums[middle + 1]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        middle = (left + right) / 2;
    }
    return middle;
}
