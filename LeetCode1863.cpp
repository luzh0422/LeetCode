//
// Created by luzehui on 25-4-5.
//

#include "LeetCode1863.h"

int LeetCode1863::subsetXORSum(vector<int> &nums) {
    int n = nums.size();
    vector<bool> visits(n, false);
    int res = subsetXORSum(nums, visits, 0, 0);
    return res;
}

int LeetCode1863::subsetXORSum(vector<int> &nums, vector<bool> &visits, int num, int index) {
    int n = nums.size();
    int res = num;
    for (int i = index; i < n; i++) {
        if (!visits[i]) {
            num ^= nums[i];
            visits[i] = true;
            res += subsetXORSum(nums, visits, num, i + 1);
            visits[i] = false;
            num ^= nums[i];
        }
    }
    return res;
}
