//
// Created by luzh on 2022/1/25.
//

#include "Solution1688.h"

int Solution1688::numberOfMatches(int n) {
    int ans = 0;
    while (n > 1) {
        ans += n / 2;
        if (n % 2 != 0) {
            n = n / 2 + 1;
        } else {
            n = n / 2;
        }
    }
    return ans;
}
