//
// Created by 陆泽辉 on 2023/3/31.
//

#include "LeetCode2367.h"
#include <unordered_set>

int LeetCode2367::arithmeticTriplets(vector<int> &nums, int diff) {
    unordered_set<int> uS;
    for (auto num : nums) {
        uS.insert(num);
    }
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (uS.count(num + diff) && uS.count(num + diff + diff)) {
            res++;
        }
    }
    return res;
}
