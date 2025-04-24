//
// Created by luzehui on 25-4-24.
//

#include "LeetCode2799.h"
#include <unordered_map>

int LeetCode2799::countCompleteSubarrays(vector<int> &nums) {
    int left = 0, right = 1, n = nums.size(), res = 0;
    unordered_map<int, int> allNumCount{};
    unordered_map<int, int> deltaNumCount{};
    for (int i = 0; i < n; i++) {
        allNumCount[nums[i]]++;
    }
    deltaNumCount[nums[left]]++;
    while (left < n) {
        while (right < n && deltaNumCount.size() < allNumCount.size()) {
            deltaNumCount[nums[right++]]++;
        }
        if (deltaNumCount.size() == allNumCount.size())
            res += n - right + 1;
        deltaNumCount[nums[left]]--;
        if (deltaNumCount[nums[left]] == 0)
            deltaNumCount.erase(nums[left]);
        left++;
    }
    return res;
}
