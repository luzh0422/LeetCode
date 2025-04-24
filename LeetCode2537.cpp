//
// Created by luzehui on 25-4-16.
//

#include "LeetCode2537.h"
#include <unordered_map>

long long LeetCode2537::countGood(vector<int> &nums, int k) {
    int l = 0, r = 1, n = nums.size(), count = 0;
    long long res = 0ll;
    unordered_map<int, int> cache{};
    cache[nums[l]]++;
    while (l < n) {
        while (r < n && count < k) {
            count += cache[nums[r]];
            cache[nums[r]]++;
            r++;
        }
        if (count >= k) {
           res += n - r + 1;
        }
        cache[nums[l]]--;
        count -= cache[nums[l]];
        l++;
    }
    return res;
}
