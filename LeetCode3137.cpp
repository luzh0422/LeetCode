//
// Created by luzehui on 2024/8/17.
//

#include "LeetCode3137.h"

#include <unordered_map>

int LeetCode3137::minimumOperationsToMakeKPeriodic(std::string word, int k) {
    int n = word.size();
    unordered_map<string, int> cache{};
    int maxCount = 0, totalCount = 0;
    for (int i = 0; i <= n; i += k) {
        if (i + k < n) {
            string temp = word.substr(i, k);
            int curr = 1;
            if (cache.count(temp)) {
                curr += cache[temp];
            }
            cache[temp] = curr;
            maxCount = max(maxCount, curr);
            totalCount++;
        }
    }
    return totalCount - maxCount;
}
