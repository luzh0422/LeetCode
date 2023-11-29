//
// Created by luzehui on 2023/10/24.
//

#include "LeetCode2698.h"

int LeetCode2698::punishmentNumber(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (backtrace(i * i, 0, i)) {
            ans += i * i;
        }
    }
    return ans;
}

bool LeetCode2698::backtrace(int n, int curr, int target) {
    if (n == 0) {
        if (curr == target) {
            return true;
        }
        return false;
    }
    int temp = 10, num = n;
    while (num != 0) {
        if (backtrace(n / temp, curr + (n % temp), target)) {
            return true;
        }
        num /= 10;
        temp *= 10;
    }
    return false;
}
