//
// Created by 陆泽辉 on 2023/10/10.
//

#include "LeetCode2731.h"

int LeetCode2731::sumDistance(vector<int> &nums, string s, int d) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            nums[i] -= d;
        } else {
            nums[i] += d;
        }
    }
    long res = 0;
    const int MOD = 1e9 + 7;
    std::sort(nums.begin(), nums.end());
    long long prefix = nums[0];
    /**
     * 遍历到pos[i]，会有pos[i] - pos[i - 1] + pos[i] - pos[i - 2] + ... + pos[i] - pos[0];
     * 所以可以简化运算：i * pos[i] - prefix(pos[i - 1]);
     */
    for (int i = 1; i < n; i++) {
        res += (long)(i) * nums[i] - prefix;
        res %= MOD;
        prefix += nums[i];
        prefix %= MOD;
    }
    return int(res);
}
