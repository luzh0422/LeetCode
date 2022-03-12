//
// Created by luzh on 2021/11/19.
//

#include "Solution397.h"
#include <algorithm>
#include <math.h>

int Solution397::integerReplacement(int n) {
    if (n >= 0x7fffffff) {
        return 32; // 枚举出来的值；
    }
    int ans = 0;
    while (n != 1) {
        if (isOdd(n)) {
            ans += 1;
            ans += std::min(integerReplacement(n + 1), integerReplacement(n - 1));
            n = 1;
        } else {
            ans += 1;
            n /= 2;
        }
    }
    return ans;
}

bool Solution397::isOdd(int n) {
    return n % 2 != 0;
}
