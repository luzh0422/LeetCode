//
// Created by luzehui on 25-4-8.
//

#include "LeetCode3396.h"
#include <unordered_map>

int LeetCode3396::minimumOperations(vector<int> &nums) {
    unordered_map<int, int> uM{};
    for (int num : nums) {
        uM[num]++;
    }
    auto check = [&]() -> bool {
        for (auto iter : uM) {
            if (iter.second > 1) {
                return false;
            }
        }
        return true;
    };
    int index = 0, n = nums.size(), res = 0;
    while (index < n) {
        if (check()) {
            return res;
        }
        for (int i = 0; i < 3 && index + i < n; i++) {
            uM[nums[index + i]]--;
        }
        res++;
        index += 3;
    }
    return res;
}
