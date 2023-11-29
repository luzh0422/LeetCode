//
// Created by 陆泽辉 on 2023/1/15.
//

#include "LeetCode2293.h"

int LeetCode2293::minMaxGame(vector<int> &nums) {
    while (nums.size() > 1) {
        int n = nums.size();
        vector<int> temp{};
        for (int i = 0; i < n / 2; i++) {
            if (i % 2 == 0) {
                temp.push_back(min(nums[2 * i], nums[2 * i + 1]));
            } else {
                temp.push_back(max(nums[2 * i], nums[2 * i + 1]));
            }
        }
        nums = temp;
    }
    return nums[0];
}
