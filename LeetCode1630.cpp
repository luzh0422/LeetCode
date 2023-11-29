//
// Created by 陆泽辉 on 2023/3/23.
//

#include "LeetCode1630.h"

vector<bool> LeetCode1630::checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
    int n = l.size();
    vector<bool> res;
    for (int i = 0; i < n; i++) {
        int lNum = l[i], rightNum = r[i];
        vector<int> temp(nums.begin() + lNum, nums.begin() + rightNum + 1);
        res.push_back(checkArithmeticSubarrays(temp));
    }
    return res;
}

bool LeetCode1630::checkArithmeticSubarrays(vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] - arr[i - 1] != arr[i + 1] - arr[i]) {
            return false;
        }
    }
    return true;
}
