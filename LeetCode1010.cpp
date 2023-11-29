//
// Created by 陆泽辉 on 2023/5/7.
//

#include "LeetCode1010.h"
#include <unordered_map>

int LeetCode1010::numPairsDivisibleBy60(vector<int> &time) {
    unordered_map<double, int> cache{};
    int res = 0;
    for (auto t : time) {
        double delta = t % 60;
        if (delta != 0) {
            if (cache.count(60 - delta)) {
                res += cache[60 - delta];
            }
            if (cache.count(delta)) {
                cache[delta]++;
            } else {
                cache.emplace(delta, 1);
            }
        } else {
            if (cache.count(delta)) {
                res += cache[delta];
                cache[delta]++;
            } else {
                cache.emplace(delta, 1);
            }
        }
    }
    return res;
}
