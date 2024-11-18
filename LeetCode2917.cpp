//
// Created by luzehui on 2024/3/6.
//

#include "LeetCode2917.h"

int LeetCode2917::findKOr(vector<int> &nums, int k) {
    int n = nums.size();
    int res = 0;
    vector<int> bits(32, 0);
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        countBit(num, bits);
    }
    for (int i = 0; i < 32; i++) {
        if (bits[i] >= k) {
            res += (1 << i);
        }
    }
    return res;
}

void LeetCode2917::countBit(int num, vector<int>& bits) {
    int currIndex = 0;
    while (num != 0) {
        if ((num & 1) == 1) {
            bits[currIndex]++;
        }
        num = (num >> 1);
        currIndex++;
    }
}
