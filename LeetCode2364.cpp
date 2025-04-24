//
// Created by luzehui on 25-4-18.
//

#include "LeetCode2364.h"
#include <unordered_map>

long long LeetCode2364::countBadPairs(vector<int> &nums) {
    unordered_map<int, int> cache;
    int n = nums.size();
    long long notBadCase = 0ll;
    for (int i = 0; i < n; i++) {
        notBadCase += cache[nums[i] - i];
        cache[nums[i] - i]++;
    }
    long long res = (long long)(n) * (long long)(n - 1) / 2 - notBadCase;
    return res;
}
