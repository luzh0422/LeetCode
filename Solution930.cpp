//
// Created by luzh on 2021/7/8.
//

#include "Solution930.h"

#include <unordered_map>

int Solution930::numSubarraysWithSum(vector<int> &nums, int goal) {
    unordered_map<int, int> unorderedMap;
    int sum = 0;
    unorderedMap[sum] = 1;
    int ret = 0;
    for (auto& num : nums) {
        sum += num;
        int temp = sum - goal;
        if (unorderedMap.count(temp)) {
            ret += unorderedMap[temp];
        }
        if (unorderedMap.count(sum)) {
            unorderedMap[sum]++;
        } else {
            unorderedMap[sum] = 1;
        }
    }
    return ret;
}
