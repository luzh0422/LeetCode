//
// Created by 陆泽辉 on 2023/4/30.
//

#include "LeetCode1031.h"

int LeetCode1031::maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);
    int curr = 0;
    for (int i = 0; i < firstLen; i++) {
        curr += nums[i];
    }
    prefix[firstLen - 1] = curr;
    for (int i = firstLen; i < n; i++) {
        curr += nums[i];
        curr -= nums[i - firstLen];
        prefix[i] = max(curr, prefix[i - 1]);
    }
    curr = 0;
    for (int i = 0; i < firstLen; i++) {
        curr += nums[n - i - 1];
    }
    suffix[n - firstLen] = curr;
    for (int i = n - firstLen - 1; i >= 0; i--) {
        curr += nums[i];
        curr -= nums[i + firstLen];
        suffix[i] = max(curr, suffix[i + 1]);
    }
    int res = 0;
    curr = 0;
    for (int i = 0; i < secondLen; i++) {
        curr += nums[i];
    }
    res = curr + suffix[secondLen];
    for (int i = secondLen; i < n; i++) {
        curr += nums[i];
        curr -= nums[i - secondLen];
        int temp1 = curr + prefix[i - secondLen];
        int temp2 = curr + suffix[i + 1];
        res = max({res, temp1, temp2});
    }
    return res;
}
