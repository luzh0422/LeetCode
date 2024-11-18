//
// Created by luzehui on 2024/3/14.
//

#include "LeetCode2789.h"

long long LeetCode2789::maxArrayValue(vector<int> &nums) {
    int n = nums.size() - 1;
    long long res = nums.back();
    vector<long long> temp(nums.begin(), nums.end());
    for (int i = n; i >= 1; i--) {
        if (temp[i] >= temp[i - 1]) {
            temp[i - 1] = temp[i] + temp[i - 1];
        }
        if (temp[i - 1] > res) {
            res = temp[i - 1];
        }
    }
    return res;
}
