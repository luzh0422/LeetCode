//
// Created by luzehui on 25-1-29.
//

#include "LeetCode219.h"
#include <unordered_map>

bool LeetCode219::containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> cache{};
    for (int i = 0; i < nums.size(); i++) {
        if (cache.count(nums[i])) {
            if (i - cache[nums[i]] <= k) {
                return true;
            }
        }
        cache[nums[i]] = i;
    }
    return false;
}
