//
// Created by luzehui on 25-4-3.
//

#include "LeetCode2874.h"

long long LeetCode2874::maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefixMaxNum(n, 0);
    vector<int> suffixMaxNum(n, 0);
    prefixMaxNum[0] = nums[0];
    suffixMaxNum[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) {
        prefixMaxNum[i] = max(prefixMaxNum[i - 1], nums[i]);
        suffixMaxNum[n - i - 1] = max(suffixMaxNum[n - i], nums[n - i - 1]);
    }
    long long res = 0ll;
    for (int i = 1; i < n - 1; i++) {
        res = max(res, (long long)(prefixMaxNum[i - 1] - nums[i]) * suffixMaxNum[i + 1]);
    }
    return res;
}
