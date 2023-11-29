//
// Created by 陆泽辉 on 2023/3/26.
//

#include "LeetCode2395.h"
#include <unordered_set>

bool LeetCode2395::findSubarrays(vector<int> &nums) {
    int cache = nums[0] + nums[1];
    unordered_set<int> uS;
    uS.emplace(cache);
    int n = nums.size();
    for (int i = 2; i < n; i++) {
        cache -= nums[i - 2];
        cache += nums[i];
        if (uS.count(cache)) {
            return true;
        }
        uS.emplace(cache);
    }
    return false;
}
