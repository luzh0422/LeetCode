//
// Created by luzehui on 25-1-22.
//

#include "LeetCode1561.h"

int LeetCode1561::maxCoins(vector<int> &piles) {
    std::sort(piles.begin(), piles.end());
    int left = 0, right = piles.size() - 1, res = 0;
    while (left < right) {
        left++;
        right--;
        if (left <= right) {
            res += piles[right--];
        }
    }
    return res;
}
