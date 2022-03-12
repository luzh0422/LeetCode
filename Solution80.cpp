//
// Created by luzh on 2021/4/6.
//

#include "Solution80.h"

int Solution80::removeDuplicates(vector<int> &nums) {
    /**
     * 初始化；
     */
    int size = nums.size();
    if (size == 0) return 0;
    int curr = nums[0];
    int left = 0, right = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == curr) {
            right = i;
        } else {
            if (right - left >= 2) {
                nums.erase(nums.begin() + left + 2, nums.begin() + right + 1);
                i -= right - left - 1;
            }
            curr = nums[i];
            left = i;
            right = i;
        }
    }
    if (right - left >= 2) {
        nums.erase(nums.begin() + left + 2, nums.begin() + right + 1);
    }
    return nums.size();
}
