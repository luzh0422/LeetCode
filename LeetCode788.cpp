//
// Created by 陆泽辉 on 2022/9/25.
//

#include "LeetCode788.h"

int LeetCode788::rotatedDigits(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (isGoodNum(i)) {
            ret++;
        }
    }
    return ret;
}

bool LeetCode788::isGoodNum(int num) {
    bool tag = false;
    while (num != 0) {
        int curr = num % 10;
        num /= 10;
        if (curr == 2 || curr == 5 || curr == 6 || curr == 9) {
            tag = true;
        }
        if (curr == 3 || curr == 4 || curr == 7) {
            return false;
        }
    }
    return tag;
}
