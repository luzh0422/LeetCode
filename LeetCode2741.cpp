//
// Created by luzehui on 2024/6/26.
//

#include "LeetCode2741.h"
#include <functional>

int LeetCode2741::specialPerm(vector<int> &nums) {
    int n = nums.size();
    const long long MOD = 1e9 + 7;
    vector<vector<int>> cache(1 << n, vector<int>(n, -1));
    function<int(int, int)> dfs = [&](int tag, int index) -> int {
        if (cache[tag][index] != -1) {
            return cache[tag][index];
        }
        if (tag == (1 << index)) {
            return 1;
        }
        cache[tag][index] = 0;
        for (int i = 0; i < n; i++) {
            if (i == index || ((tag >> i) & 1) == 0) {
                continue;
            }
            if (nums[index] % nums[i] != 0 && nums[i] % nums[index] != 0) {
                continue;
            }
            cache[tag][index] = (cache[tag][index] + dfs(tag ^ (1 << index), i)) % MOD;
        }
        return cache[tag][index];
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = (res + dfs((1 << n) - 1, i)) % MOD;
    }
    return res;
}
