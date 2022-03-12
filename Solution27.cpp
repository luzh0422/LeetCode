//
// Created by luzh on 2021/4/19.
//

#include "Solution27.h"

int Solution27::removeElement(vector<int> &nums, int val) {
    int left = 0;
    int right = 0;
    for (right = 0; right < nums.size(); right++) {
        if (nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }
    return left + 1;
}
