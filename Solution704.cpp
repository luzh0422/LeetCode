//
// Created by luzh on 2021/9/6.
//

#include "Solution704.h"

int Solution704::search(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (nums[middle] > target) {
            end = middle - 1;
        } else if (nums[middle] < target) {
            start = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}
