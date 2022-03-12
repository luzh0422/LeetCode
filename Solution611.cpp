//
// Created by luzh on 2021/8/4.
//

#include "Solution611.h"

int Solution611::triangleNumber(vector<int> &nums) {
    int ans = 0;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int k = nums[i] + nums[j];
            int index = lower_bound(nums.begin() + j + 1, nums.end(), k) - nums.begin();
            ans += (index - 1 - j);
        }
    }
    return ans;
}
