//
// Created by 陆泽辉 on 2023/6/5.
//

#include "LeetCode2460.h"

vector<int> LeetCode2460::applyOperations(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            nums[i] = 2 * nums[i];
            nums[i + 1] = 0;
        }
    }
    vector<int> res{}, zero{};
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            res.push_back(nums[i]);
        } else {
            zero.push_back(0);
        }
    }
    res.insert(res.end(), zero.begin(), zero.end());
    return res;
}
