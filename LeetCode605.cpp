//
// Created by 陆泽辉 on 2023/9/30.
//

#include "LeetCode605.h"

bool LeetCode605::canPlaceFlowers(vector<int> &flowerbed, int n) {
    int target = 0, m = flowerbed.size(), i = 0;
    if (flowerbed[i] == 0) {
        if (m == 1 || flowerbed[i + 1] == 0) {
            target++;
        }
    }
    for (i = 1; i < m - 1; i++) {
        if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && (i + 2 == m || flowerbed[i + 2] == 0)) {
            target++;
            i += 1;
        }
        if (target >= n) {
            return true;
        }
    }
    if (target >= n) {
        return true;
    }
    return false;
}
