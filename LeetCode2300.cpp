//
// Created by luzehui on 2023/11/9.
//

#include "LeetCode2300.h"

vector<int> LeetCode2300::successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
    std::sort(potions.begin(), potions.end());
    int n = spells.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        long long temp = (success + (long long)spells[i] - 1ll) / spells[i];
        auto iter = lower_bound(potions.begin(), potions.end(), temp);
        int res = distance(iter, potions.end());
        ans[i] = res;
    }
    return ans;
}
