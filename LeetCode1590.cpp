//
// Created by 陆泽辉 on 2023/3/10.
//

#include "LeetCode1590.h"
#include <numeric>
#include <unordered_map>

int LeetCode1590::minSubarray(vector<int> &nums, int p) {
    int x = accumulate(nums.begin(), nums.end(), 0L) % p;
    if (x == 0) return 0; // 移除空子数组（这行可以不要）
    int n = nums.size();
    long prefix = 0;
    int res = n;
    unordered_map<int, int> uM = {{0, -1}};
    for (int i = 0; i < n; i++) {
        prefix += nums[i];
        int mod = prefix % p;
        uM[mod] = i;
        int key = (mod - x + p) % p;
        if (uM.count(key)) {
            res = min(res, i - uM[key]);
        }
    }
    return res;
}
