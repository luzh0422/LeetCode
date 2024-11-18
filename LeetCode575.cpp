//
// Created by luzehui on 2024/6/2.
//

#include "LeetCode575.h"

#include <unordered_set>

int LeetCode575::distributeCandies(vector<int> &candyType) {
    int n = candyType.size();
    int candyTypeCount = 0;
    unordered_set<int> candyTypeRecord{};
    for (int i = 0; i < n; i++) {
        if (!candyTypeRecord.count(candyType[i])) {
            candyTypeCount++;
            candyTypeRecord.emplace(candyType[i]);
        }
    }
    return min(n / 2, candyTypeCount);
}
