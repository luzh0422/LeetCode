//
// Created by 陆泽辉 on 2022/6/7.
//

#include "LeetCode875.h"

int LeetCode875::minEatingSpeed(vector<int> &piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int middle = (left + right) / 2;
    while (left < right) {
        int hour = totalHour(piles, middle);
        if (hour <= h) {
            right = middle;
        } else {
            left = middle + 1;
        }
        middle = (left + right) / 2;
    }
    return right;
}

int LeetCode875::totalHour(vector<int> &piles, int speed) {
    int n = piles.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret += piles[i] / speed;
        if (piles[i] % speed != 0) {
            ret += 1;
        }
    }
    return ret;
}
