//
// Created by 陆泽辉 on 2023/5/10.
//

#include "LeetCode1015.h"
#include <unordered_set>

int LeetCode1015::smallestRepunitDivByK(int k) {
    int curr = 1 % k, res = 1;
    std::unordered_set<int> cache{};
    while (curr != 0) {
        if (cache.count(curr)) {
            return -1;
        }
        cache.emplace(curr);
        curr = (curr * 10 + 1) % k;
        res++;
    }
    return res;
}
