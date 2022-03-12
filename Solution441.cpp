//
// Created by luzh on 2021/10/10.
//

#include "Solution441.h"

int Solution441::arrangeCoins(int n) {
    long ans = 0;
    long curr = ans * (ans + 1) / 2;
    while (curr <= n) {
        ans++;
        curr = ans * (ans + 1) / 2;
    }
    return ans - 1;
}
