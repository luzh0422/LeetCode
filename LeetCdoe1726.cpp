//
// Created by luzehui on 2023/10/18.
//

#include "LeetCdoe1726.h"
#include <unordered_map>

int LeetCdoe1726::tupleSameProduct(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> uM{};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int num = nums[i] * nums[j];
            if (uM.count(num)) {
                uM[num]++;
            } else {
                uM[num] = 1;
            }
        }
    }
    int ans = 0;
    for (auto iter = uM.begin(); iter != uM.end(); iter++) {
        if (iter->second != 1) {
            int num = iter->second;
            ans += num * (num - 1) / 2 * 8;
        }
    }
    return ans;
}

