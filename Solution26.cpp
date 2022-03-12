//
// Created by luzh on 2021/4/18.
//

#include "Solution26.h"


int Solution26::removeDuplicates(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}
