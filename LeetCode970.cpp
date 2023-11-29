//
// Created by 陆泽辉 on 2023/5/4.
//

#include "LeetCode970.h"

vector<int> LeetCode970::powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> cache{};
    int value1 = 1;
    for (int i = 0; i < 21; i++) {
        int value2 = 1;
        for (int j = 0; j < 21; j++) {
            if (value1 + value2 > bound) {
                break;
            }
            cache.insert(value1 + value2);
            value2 *= y;
        }
        value1 *= x;
        if (value1 > bound) {
            break;
        }
    }
    vector<int> res(cache.begin(), cache.end());
    return res;
}

void LeetCode970::powerfulIntergers(int currX, int currY, int x, int y, int bound, unordered_set<int> &cache) {
    if (currX + currY > bound) {
        return;
    }
    cache.emplace(currX + currY);
    powerfulIntergers(currX * x, currY, x, y, bound, cache);
    powerfulIntergers(currX, currY * y, x, y, bound, cache);
    return;
}
