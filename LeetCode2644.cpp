//
// Created by luzehui on 2024/5/18.
//

#include "LeetCode2644.h"

#include <unordered_set>

int LeetCode2644::maxDivScore(vector<int> &nums, vector<int> &divisors) {
    int count = 0, res = divisors.front();
    unordered_set<int> uS;
    for (auto divisor : divisors) {
        int currCount = 0;
        if (uS.count(divisor))
            continue;
        uS.insert(divisor);
        for (auto num : nums) {
            if (num % divisor == 0)
                currCount++;
        }
        if (currCount > count) {
            res = divisor;
            count = currCount;
        } else if (currCount == count) {
            res = min(res, divisor);
        }
    }
    return res;
}
