//
// Created by luzehui on 2024/10/12.
//

#include "LeetCode3158.h"

int LeetCode3158::duplicateNumbersXOR(vector<int> &nums) {
    vector<int> cache(51, 0);
    for (auto num : nums) {
        cache[num]++;
    }
    int res = 0;
    for (int i = 1; i < 51; i++) {
        if (cache[i] == 2) {
            res ^= i;
        }
    }
    return res;
}
