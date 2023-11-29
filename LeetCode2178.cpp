//
// Created by 陆泽辉 on 2023/7/6.
//

#include "LeetCode2178.h"

vector<long long> LeetCode2178::maximumEvenSplit(long long finalSum) {
    if (finalSum & 1 != 0) {
        return {};
    }
    vector<long long> res;
    for (long long curr = 2; curr <= finalSum; curr += 2) {
        res.push_back(curr);
        finalSum -= curr;
    }
    if (finalSum > 0) {
        res.back() += finalSum;
    }
    return res;
}
