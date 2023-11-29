//
// Created by 陆泽辉 on 2022/8/4.
//

#include "LeetCode1403.h"
#include <numeric>

vector<int> LeetCode1403::minSubsequence(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    std::sort(nums.begin(), nums.end(), greater<int>());
    int n = nums.size();
    vector<int> ret = {};
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += nums[i];
        ret.push_back(nums[i]);
        if (curr > sum / 2) {
            break;
        }
    }
    return ret;
}
